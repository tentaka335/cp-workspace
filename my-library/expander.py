#!/usr/bin/env python3

import argparse
import re
from pathlib import Path
from os import environ, pathsep
from logging import Logger, basicConfig, getLogger
from typing import List, Set

logger = getLogger(__name__)  # type: Logger


class Expander:
    include_pattern = re.compile(r'^\s*#include\s*["<](my-library/[A-Za-z0-9_./-]+)[">]')

    def __init__(self, lib_paths: List[Path]):
        self.lib_paths = lib_paths
        self.included = set()  # type: Set[Path]

    def find_lib(self, rel_path: str) -> Path:
        for lib_path in self.lib_paths:
            candidate = lib_path / rel_path
            if candidate.exists():
                return candidate
        logger.error("cannot find: %s", rel_path)
        raise FileNotFoundError(rel_path)

    def expand_file(self, file_path: Path) -> List[str]:
        if file_path in self.included:
            logger.info("already included: %s", file_path.name)
            return []
        self.included.add(file_path)
        logger.info("include: %s", file_path.name)

        source = file_path.read_text()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.include_pattern.match(line)
            if m:
                result.extend(self.expand_file(self.find_lib(m.group(1))))
                continue
            result.append(line)
        return result

    def expand(self, source: str, origname: str) -> str:
        self.included = set()
        result = []  # type: List[str]
        linenum = 0
        for line in source.splitlines():
            linenum += 1
            m = self.include_pattern.match(line)
            if m:
                result.extend(self.expand_file(self.find_lib(m.group(1))))
                if origname:
                    result.append('#line ' + str(linenum + 1) + ' "' + origname + '"')
                continue
            result.append(line)
        return "\n".join(result)


if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=environ.get("LOG_LEVEL", "INFO"),
    )

    parser = argparse.ArgumentParser(description="My library expander")
    parser.add_argument("source", help="Source file")
    parser.add_argument("-c", "--console", action="store_true", help="Print to console")
    parser.add_argument("-o", "--output", default="combined.cpp", help="Output file")
    parser.add_argument("--lib", help="Path to library root (parent of my-library)")
    parser.add_argument(
        "--origname",
        help="report line numbers from the original source file in GCC/Clang error messages",
    )
    opts = parser.parse_args()

    lib_paths: List[Path] = []
    if opts.lib:
        lib_paths.append(Path(opts.lib))
    if "CPLUS_INCLUDE_PATH" in environ:
        lib_paths.extend(
            map(Path, filter(None, environ["CPLUS_INCLUDE_PATH"].split(pathsep)))
        )

    script_root = Path(__file__).resolve().parent.parent
    lib_paths.append(script_root)
    lib_paths.append(Path.cwd())

    expander = Expander(lib_paths)
    source = Path(opts.source).read_text()
    output = expander.expand(source, opts.origname)

    if opts.console:
        print(output)
    else:
        Path(opts.output).write_text(output)

#!/usr/bin/env python3

"""
Parse the svg files generated by the tests and calculate the average.
This will also calculate the difference between the steps if the files are named correctly. The csv files should be
named as the array size. for example `100.csv` the .csv at the end will be removed and the 100 will be used as the array
test size.

The script can be easily used by just passing in the csv files as command line arguments.
The files have complete GLOB support so if you use `output/*csv` it will read all the files ending with `.csv` in the
output folder.

The script ends with a little table that can easily be used in a markdown file.
"""

import argparse
import glob
from typing import List
from pathlib import Path


def average(items: List[int]) -> float:
    accumulator = 0
    for item in items:
        accumulator += item
    return accumulator / len(items)


def parse_file(file) -> float:
    print("Trying to open file: %s" % file)
    items = []
    with open(file, "r") as fp:
        lines = fp.readlines()
        for line in lines:
            items.append(int(line))
    print("Read in %d items" % len(items))
    return average(items)


def csv_file_sort_key(file: str) -> int:
    file_stem = Path(file).stem
    try:
        return int(file_stem)
    except ValueError:
        return 0


def main():
    parser = argparse.ArgumentParser(description="process the output csv files generated by one of the tests")
    parser.add_argument('files', metavar='csv-files', type=str, nargs='+', help='The input csv files. Glob supported.')

    files = []
    args = parser.parse_args()
    for file in args.files:
        globs = glob.glob(file)
        globs.sort(key=csv_file_sort_key, reverse=False)
        for item in globs:
            files.append(item)

    files.sort(key=csv_file_sort_key)
    print(files)
    averages = {}
    for file in files:
        key = csv_file_sort_key(file)
        averg = parse_file(file)
        if key != 0:
            averages[key] = averg
        else:
            print("%7d: %12.2f ns, %8.2f μs, %5.2f ms" % (file, averg, (averg / 1000), (averg / 1000000)))

    if len(averages) <= 0:
        print("No averages")
        exit()

    print("\nAverages:")
    for (key, value) in averages.items():
        print("%7d: %12.2f ns, %8.2f μs, %5.2f ms" % (key, value, (value / 1000), (value / 1000000)))
    print()

    # Create the table at the end of the file.
    print("|   N   | run time(ns) |   diff   | factor |")
    print("|-------|--------------|----------|--------|")
    last_item = None
    for (key, value) in averages.items():
        diff = "    --    "
        factor = "   --   "
        if last_item is not None:
            diff = ("%d" % (value - last_item[1]))
            factor = ("%.4f" % (value / last_item[1]))
        print("|%7d|%14.2f|%10s|%8s|" % (key, value, diff, factor))
        last_item = (key, value)


if __name__ == '__main__':
    main()

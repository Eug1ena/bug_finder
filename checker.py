import sys
import subprocess
from subprocess import PIPE

def nth_ordinal(i): return str(i) + ({1: "st", 2: "nd", 3: "rd"}.get(i if i <= 13 else i % 10) or "th")

if len(sys.argv) <= 1:
    print("Input the number of times to try test cases.")
    sys.exit()

loop = int(sys.argv[1])

subprocess.run(["g++", "-std=c++14", "-O2", "-o", "work/bug_code", "bug_code.cpp"])
subprocess.run(["g++", "-std=c++14", "-O2", "-o", "work/correct_code", "correct_code.cpp"])
subprocess.run(["g++", "-std=c++14", "-O2", "-o", "work/testcase_maker", "testcase_maker.cpp"])

for i in range(0, loop):
    testcase = subprocess.run(["./work/testcase_maker"], stdout=PIPE, text=True).stdout
    wrong_out = subprocess.run(["./work/bug_code"], input=testcase, stdout=PIPE, text=True).stdout
    correct_out = subprocess.run(["./work/correct_code"], input=testcase, stdout=PIPE, text=True).stdout

    if wrong_out != correct_out:
        print("[" + nth_ordinal(i + 1) + " testcase]")
        print("testcase:")
        print(testcase)
        print("wrong:")
        print(wrong_out)
        print("correct:")
        print(correct_out)
        sys.exit()

print("No bug is found.")

import sys
import subprocess
from subprocess import PIPE
import argparse

def nth_ordinal(i): return str(i) + ({1: "st", 2: "nd", 3: "rd"}.get(i if i <= 13 else i % 10) or "th")


parser = argparse.ArgumentParser()
parser.add_argument("case", type=int, help="Number of test cases")
parser.add_argument("-j", "--judge", action="store_true", help="Option for special judge")

args = parser.parse_args()
loop = args.case
is_judge = args.judge

if not is_judge:
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/testcase", "code/testcase.cpp"])
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/wrong", "code/wrong.cpp"])
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/correct", "code/correct.cpp"])
else:
    print("MESSAGE: Special Judge Mode")
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/testcase", "code/testcase.cpp"])
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/wrong", "code/wrong.cpp"])
    subprocess.run(["g++", "-std=c++17", "-O2", "-o", "work/judge", "code/judge.cpp"])

print("MESSAGE: Compilation Finished")

for i in range(0, loop):
    if not is_judge:
        testcase = subprocess.run(["./work/testcase"], stdout=PIPE, text=True).stdout
        wrong_out = subprocess.run(["./work/wrong"], input=testcase, stdout=PIPE, text=True).stdout
        correct_out = subprocess.run(["./work/correct"], input=testcase, stdout=PIPE, text=True).stdout

        if wrong_out != correct_out:
            print("[" + nth_ordinal(i + 1) + " testcase]")
            print("testcase:")
            print(testcase)
            print("wrong:")
            print(wrong_out)
            print("correct:")
            print(correct_out)
            sys.exit()
    else:
        testcase = subprocess.run(["./work/testcase"], stdout=PIPE, text=True).stdout
        wrong_out = subprocess.run(["./work/wrong"], input=testcase, stdout=PIPE, text=True).stdout
        judge_out = subprocess.run(["./work/judge"], input=(testcase + wrong_out), stdout=PIPE, text=True).stdout

        if "ok" not in judge_out:
            print("[" + nth_ordinal(i + 1) + " testcase]")
            print("testcase:")
            print(testcase)
            print("wrong:")
            print(wrong_out)
            print("judge output:")
            print(judge_out)
            sys.exit()

print("MESSAGE: No Bug Found")

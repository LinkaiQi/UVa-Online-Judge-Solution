# /* UVa problem: 113
#  *
#  * Topic: Arithmetic
#  *
#  * Level: easy
#  *
#  * Brief problem description:
#  *    The input consists of a sequence of integer pairs 1 ≤ n ≤ 200 and
#  *    1 ≤ p < 10^101 with each integer on a line by itself.
#  *    Find the integer k that k^n=p.
#  *
#  * Solution Summary:
#  *    We can convert this problem as p^(1/n) and calculate the result.
#  *
#  * Used Resources:
#  *    None
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * --------------------- Linkai Qi
#  */

import sys, math

def main():
    tests = sys.stdin.readlines()

    i = 0
    while i <= (len(tests)-1):
        result = int(round(math.pow(int(tests[i+1]),1/int(tests[i]))))
        i += 2
        sys.stdout.write(str(result)+"\n")

if __name__ == '__main__':
    main()

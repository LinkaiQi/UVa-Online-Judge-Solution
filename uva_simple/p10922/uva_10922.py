# /* UVa problem: 10922
#  *
#  * Topic: Other
#  *
#  * Level: easy
#  *
#  * Brief problem description:
#  *   Given a file where each line contains a positive number. Each given number
#  *   can contain up to 1000 digits. The problem asks if the number is a multiple
#  *   of 9 and, if it is, its 9-degree. The 9-degree means the depth of the
#  *   recursion needed to obtain the answer on the number.
#  *
#  * Solution Summary:
#  *   This problem can be solved by computing the sum of the digits of each number.
#  *   If the sum is a multiple of nine, then so is the number. If the sum still
#  *   contains more than one digit, we can do the same steps for the sum to see if
#  *   the sum is a multiple of nine. Repeat until we get a 1-digit sum. Record
#  *   the depth of recursion at the same time. Then check if the 1-digit is 9
#  *   or not, if yes, then the original number is a multiple of 9.
#  *
#  * Used Resources:
#  *   None
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * --------------------- Linkai Qi
#  */

import sys

def is_multiple(num):
    deep = 1
    sum = calc_sum(num)
    while sum > 9:
        sum = calc_sum(str(sum))
        deep += 1
    if sum == 9:
        # Show result to stdout
        sys.stdout.write("%s is a multiple of 9 and has 9-degree %d.\n"%(num, deep))
    else:
        sys.stdout.write("%s is not a multiple of 9.\n"%(num))

def calc_sum(num):
    sum = 0
    for char in num:
        sum += int(char)
    return sum

def main():
    tests = sys.stdin.readlines()
    for i in range(0, len(tests)-1):
        input_num = str.strip(tests[i])
        is_multiple(input_num)

if __name__ == '__main__':
    main()

# /* UVa problem: 454
#  *
#  * Topic: Combinatorics
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Generate a left justified Pascal’s Triangle.
#  *    When any number in the triangle is exceeds or equals 1060,
#  *    the program should finish printing the current row and exit.
#  *    Example:
#  *    1
#  *    1 1
#  *    1 2 1
#  *    1 3 3 1
#  *    1 4 6 4 1
#  *    ...
#  *
#  * Solution Summary:
#  *    This is a fairly simple question. We don't need to handle very
#  *    large number likes 10^60 in python, since python supports a "bignum"
#  *    integer type which can work with arbitrarily large numbers.
#  *    In the question, we can keep a 'previous row' of the Pascal’s Triangle
#  *    used for current row computation. After sums up all two numbers of the
#  *    'previous row', we can print the result, and overwrite the current row
#  *    as 'previous row', until we have any generated number larger than 10^60.
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

import sys

prev_row = [1, 1]
end = False

# maximum number: 10^60
max_num = 10**60

sys.stdout.write("1\n")
sys.stdout.write("1 1\n")
while not end:
    row = [1]
    for i in range(len(prev_row)-1):
        num = prev_row[i] + prev_row[i+1]
        if num > max_num:
            end = True
        row.append(prev_row[i] + prev_row[i+1])
    row.append(1)

    sys.stdout.write(str(row[0]))
    for i in range(1, len(row)):
        sys.stdout.write(' '+str(row[i]))
    sys.stdout.write('\n')

    prev_row = row

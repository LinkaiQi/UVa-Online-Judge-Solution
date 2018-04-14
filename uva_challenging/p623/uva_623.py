# /* UVa problem: 623
#  *
#  * Topic: Others
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Write a programs which calculates a factorial of a given number.
#  *    The input number could be large.
#  *    Considering the fact that 500! gives 1135-digit number.
#  *
#  * Solution Summary:
#  *    This is a easy question if we using python. We don't need to handle
#  *    very large number in python, since python supports a "bignum" integer
#  *    type which can work with arbitrarily large numbers.
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
    num = sys.stdin.readline()
    while num:
        num = int(num)
        sys.stdout.write(str(num)+'!\n')
        sys.stdout.write(str(math.factorial(num))+'\n')
        num = sys.stdin.readline()

if __name__ == '__main__':
    main()

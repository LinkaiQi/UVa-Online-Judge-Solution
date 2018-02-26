'''
UVa problem: 11955

Topic: Arithmetic

Level: easy

Brief problem description:
    Expand any power of a sum into a sum of powers

Solution Summary:
    The binomial coefficient is C(k, i) = (k!) / (i! * (k-1)!)

Used Resources:
    None

I hereby certify that I have produced the following solution myself
using only the resources listed above in accordance with the CMPUT
403 collaboration policy.


--------------------- Linkai Qi
'''

import sys
# import math
from math import factorial

def solve(a, b, k):
    result = []
    for i in range(k+1):
        c = factorial(k)//(factorial(i)*factorial(k-i))
        if c == 1:
            c = ''

        # get power of a
        if k-i == 0:
            out_a = ''
        elif k-i == 1:
            out_a = a
        else:
            out_a = a + '^' + str(k-i)

        # get power of b
        if i == 0:
            out_b = ''
        elif i == 1:
            out_b = b
        else:
            out_b = b + '^' + str(i)

        mult1 = ''; mult2 = ''
        if c != '' and out_a != '':
            mult1 = '*'
        if out_a != '' and out_b != '':
            mult2 = '*'

        result.append(str(c) + mult1 + out_a + mult1 + out_b)
    print('+'.join(result))


def main():
    tests = sys.stdin.readlines()[1:]
    i = 1
    for test in tests:
        bi, k = test.split('^'); k = int(k)
        a, b = bi.strip('()').split('+')
        print('Case {}: '.format(i), end='')
        solve(a, b, k)
        i+=1



if __name__ == '__main__':
    main()

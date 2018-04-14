# /* UVa problem: 10007
#  *
#  * Topic: Combinatorics
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Determine the number of different labeled binary trees that can be built
#  *    using exactly n different elements.
#  *
#  * Solution Summary:
#  *    The number of shapes of unlabeled rooted binary tree with N nodes are
#  *    exactly the Catalan numbers
#  *    C(n) = (2n)! / ((n+1)!n!)
#  *    After we have the number of shapes of the tree, there are N! ways to
#  *    add labels to the tree.
#  *
#  * Used Resources:
#  *    Catalan_number formula reference:
#  *        https://en.wikipedia.org/wiki/Catalan_number
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * --------------------- Linkai Qi
#  */

import sys, math

def catalan(n):
    return math.factorial(2*n) // (math.factorial(n+1) * math.factorial(n))

def main():
    num = int(sys.stdin.readline())
    while num:
        sys.stdout.write(str(catalan(num) * math.factorial(num)) + '\n')
        num = int(sys.stdin.readline())

if __name__ == '__main__':
    main()

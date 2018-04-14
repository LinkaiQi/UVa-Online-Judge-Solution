# /* UVa problem: 10303
#  *
#  * Topic: Combinatorics
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given a number n, calculate how many different binary search trees may
#  *    be constructed with a set of numbers of size n such that each element of
#  *    the set will be associated to the label of exactly one node in a binary
#  *    search tree?
#  *
#  * Solution Summary:
#  *    Let BT(i) be the number of BST if we have i node.
#  *    We have base case:
#  *        BT(0) = 1
#  *        BT(1) = 1
#  *    For i>1, select each one of the k-th node as root node. then we have
#  *    (k-1) nodes smaller than the k-th node which are in the left edge,
#  *    and (i-k) nodes that larger than the k-th node which are in the right edge.
#  *    Thus, we have combination of BT(k-1) * BT(i-k) if we select node k
#  *    as the root node
#  *    Therefore, we have the following equation:
#  *        BT(n) = Summation(BT(k-1) * BT(n-k)) for 0 < k <= n
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

MAX = 1001
BT = [0] * MAX

def main():
    global MAX, BT
    BT[0] = 1
    BT[1] = 1
    for i in range(2, MAX):
        for j in range(i):
            BT[i] += BT[j] * BT[i-j-1]

    num = sys.stdin.readline()
    while num:
        num = int(num)
        sys.stdout.write(str(BT[num])+'\n')
        num = sys.stdin.readline()

if __name__ == '__main__':
    main()

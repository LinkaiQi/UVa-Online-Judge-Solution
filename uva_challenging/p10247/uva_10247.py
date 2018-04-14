# /* UVa problem: 10247
#  *
#  * Topic: Combinatorics
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given the depth and branching factor of such a tree, determine in how
#  *    many different ways you can number the nodes of the tree so that the
#  *    label of each node is less that that of its descendants.
#  *    Assume that for numbering a tree with N nodes we have the (1, 2, 3,
#  *    N − 1, N ) labels available.
#  *
#  * Solution Summary:
#  *    "Let f(k, d) denote the number of labelings of the k-ary tree of depth d.
#  *    Moreover, let n(k, d) denote the number of nodes of the tree.
#  *    The tree contains k subtrees, each contains n(k, d-1) nodes.
#  *    There are totally  (n(k, d)-1)! / (n(k, d-1)!)^k ways to partition
#  *    the n(k, d)-1 labels into k different subsets, each have the same size
#  *     of n(k, d-1), therefore we can draw this recurrence:
#  *       f(k, d) = (n(k, d) - 1)! / (n(k, d-1)!)^k * f(k, d-1)^k
#  *    with base cases of
#  *       f(k, 0) = 1 " -- CSDN liukaipeng "https://blog.csdn.net/liukaipeng"
#  *
#  * Used Resources:
#  *    Algorithm reference:
#  *    https://blog.csdn.net/liukaipeng/article/details/3441413
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * --------------------- Linkai Qi
#  */

import sys, math

F = [[0]*22 for _ in range(22)]
N = [[0]*22 for _ in range(22)]

# Given a k-ary tree with depth d,
# calculate the total number of node the tree has.
def calc_n(k, d):
    n = 0
    prev = 1
    for _ in range(d+1):
        n += prev
        prev = prev * k
    return n;


def main():
    global F, N

    # Calculate n(k, d)
    for k in range(1, 22):
        for d in range(1, 22):
            if k * d < 22:
                N[k][d] = calc_n(k, d)

    # Calculate f(k, d)
    for k in range(1, 22):
        # base cases: f(k, 0) = 1
        F[k][0] = 1
        for d in range(1, 22):
            if k * d < 22:
                ways = math.factorial(N[k][d]-1) // (math.factorial(N[k][d-1]) ** k)
                F[k][d] = ways * F[k][d-1]**k

    test = sys.stdin.readline()
    while test:
        k, d = test.split()
        k = int(k); d = int(d)
        # sys.stdout.write(str(N[3][4])+'\n')
        sys.stdout.write(str(F[k][d])+'\n')

        test = sys.stdin.readline()

if __name__ == '__main__':
    main()

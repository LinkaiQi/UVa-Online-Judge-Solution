# /* UVa problem: 116
#  *
#  * Topic: Dynamic Programming
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given an m×n matrix of integers, write a program that computes a path
#  *    of minimal weight.
#  *    A step consists of traveling from column i to column i + 1 in an adjacent
#  *    (horizontal or diagonal) row. The first and last rows (rows 1 and m) of
#  *    a matrix are considered adjacent.
#  *
#  * Solution Summary:
#  *    This is a standard DP problem.
#  *    Let C(row, col) be the optimal cost that ends at matrix cell (row, col),
#  *    and M be an m×n matrix of integers.
#  *    We have equation:
#  *        C(i, j) = min(C(i-1, j-1), C(i, j-1), C(i+1, j-1)) + M(i,j)
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

def find_shortest_path(row, column, matrix):
    cost = [[0]*column for _ in range(row)]
    min_path = [[0]*column for _ in range(row)]
    # base case: initialize cost of the last column
    for i in range(row):
        cost[i][column-1] = matrix[i][column-1]
    # calculate minimum cost/path
    for i in range(column-2, -1, -1):
        for j in range(row):
            pos = [(j-1)%row, j, (j+1)%row]
            pos.sort()
            path = pos[0]
            if cost[pos[1]][i+1] < cost[path][i+1]:
                path = pos[1]
            if cost[pos[2]][i+1] < cost[path][i+1]:
                path = pos[2]
            min_path[j][i] = path
            cost[j][i] = matrix[j][i] + cost[path][i+1]
    # print(cost)
    # find minimum cost/path from the matrix
    min_start_row = 0
    for r in range(1, row):
        if cost[r][0] < cost[min_start_row][0]:
            min_start_row = r

    p = min_start_row
    sys.stdout.write(str(p+1))
    for col in range(column-1):
        p = min_path[p][col]
        sys.stdout.write(' ' + str(p+1))
    sys.stdout.write('\n')
    sys.stdout.write(str(cost[min_start_row][0])+'\n')

def main():
    test = sys.stdin.readline()
    while test:
        matrix = []
        row, column = test.split()
        row = int(row); column = int(column)
        # read next row * column integers
        num_list = []
        while len(num_list) < row * column:
            num_list += [int(num) for num in sys.stdin.readline().split()]
        # form matrix
        for idx in range(0, row*column, column):
            matrix.append(num_list[idx:idx+column])
        # print(matrix)
        # for _ in range(row):
        #     row_list = [int(num) for num in sys.stdin.readline().split()]
        #     matrix.append(row_list)
        find_shortest_path(row, column, matrix)

        test = sys.stdin.readline()

if __name__ == '__main__':
    main()

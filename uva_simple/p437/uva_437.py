# /* UVa problem: 437
#  *
#  * Topic: Graph Traversal
#  *
#  * Level: easy
#  *
#  * Brief problem description:
#  *   Given n types of blocks, and an unlimited supply of blocks of each type.
#  *   Each type blick was a rectangular solid with linear dimensions (x, y, z).
#  *   A block could be reoriented so that any dimension can be the height.
#  *   One blick could only be placed on top of another block as long as the two
#  *   base dimension of the upper block were both strictly smaller than the corresponding
#  *   base dimension of the lower block.
#  *   The problem asks the maximum height of tower that can be built using blocks available.
#  *
#  * Solution Summary:
#  *   This problem can be solved by constructing a DAG graph, each block orientation
#  *   is a node. An edge exists from a block to another if it can be built over
#  *   the other.
#  *   Find the longest path(weight) in the DAG.
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

# Global Variable
V = []
E = []
Max_dist = []
Visited = set()


def dfs(v):
    global V, E, Max_dist, Visited

    current_max = 0
    for child in E[v]:
        if Max_dist[child] == -1:
            # explore
            dist = dfs(child)
            Visited.add(child)
            Max_dist[child] = dist
            if current_max < dist:
                current_max = dist
        elif Max_dist[child] > current_max:
            current_max = Max_dist[child]

    return current_max + V[v][2]



def main():
    global V, E, Max_dist, Visited

    case = 1
    n = int(sys.stdin.readline())
    while n:
        # Construct all vertice
        V = []
        for i in range(n):
            b = [int(axis) for axis in sys.stdin.readline().split()]
            b.sort()
            V.append([b[0], b[1], b[2]])
            V.append([b[0], b[2], b[1]])
            V.append([b[1], b[2], b[0]])

        # Find edge
        E = [[] for _ in range(n*3)]
        for i in range(n*3):
            for j in range(n*3):
                if V[i][0] < V[j][0] and V[i][1] < V[j][1]:
                    E[j].append(i)

        Max_dist = [-1]*n*3
        Visited = set()

        # Graph Traversal
        for v in range(n*3):
            if v in Visited:
                continue
            Max_dist[v] = dfs(v)
            Visited.add(v)

        # Find longest path
        res = 0
        for i in range(n*3):
            if Max_dist[i] > res:
                res = Max_dist[i]

        # Show result to stdout
        sys.stdout.write("Case %d: maximum height = %d\n"%(case, res))

        # Next test case
        case+=1
        n = int(sys.stdin.readline())


if __name__ == '__main__':
    main()

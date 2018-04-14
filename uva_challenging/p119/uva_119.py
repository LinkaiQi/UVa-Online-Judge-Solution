# /* UVa problem: 119
#  *
#  * Topic: Other
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Determining for a group of gift-giving friends, how much more each
#  *    person gives than they receive (and vice versa for those that view
#  *    gift-giving with cynicism).
#  *
#  * Solution Summary:
#  *    This is a straight forward question. We can use the dictionary data
#  *    structure to keep track of current balance of each person. The result
#  *    would be the total amount of gift values they received minus the total
#  *    amount of money they give out.
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

def get_results(friends_li, detail_li):
    # initialize results
    results = {}
    for item in friends_li:
        results[item] = 0

    for detail in detail_li:
        if detail[1] != 0 and detail[2] != 0:
            # subtract the amount of money from his record
            results[detail[0]] = results[detail[0]] - detail[1]

            # add the amount of money per friend from his friends' records
            per_friend = detail[1] // detail[2]
            gifted_friends = detail[3].split()
            for friend in gifted_friends:
                results[friend] = results[friend] + per_friend

            # Any money not given is kept
            results[detail[0]] = results[detail[0]] + detail[1] - detail[2] * per_friend

    for friend in friends_li:
        sys.stdout.write("%s %d\n"%(friend, results[friend]))

def main():
    n = sys.stdin.readline()
    # while not end-of-file
    first_case = True;
    while n:
        if first_case:
            first_case = not first_case
        else:
            sys.stdout.write('\n')
        n = int(n)
        friends = {}
        friends_list = sys.stdin.readline().split()
        # continue to read n lines
        detail_list = []
        for _ in range(n):
            detail = sys.stdin.readline().strip().split(maxsplit=3)
            detail[1] = int(detail[1])
            detail[2] = int(detail[2])
            detail_list.append(detail)

        get_results(friends_list, detail_list)

        n = sys.stdin.readline()

if __name__ == '__main__':
    main()

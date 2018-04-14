# /* UVa problem: 561
#  *
#  * Topic: Geometry
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given the number of slot machines s, and the slot that the machines has,
#  *    find the pay-rate of each machine (pay-rate is defined as the
#  *    average (or expected) amount of money paid by the machine on each play).
#  *
#  * Solution Summary:
#  *    First, get the distinct symbols of all slots.
#  *    Calculate the probilability of getting the same symbols in one row for
#  *    all distinct symbols. Then, the solution would be multiply it with the
#  *    total amount of coins we can win, which is (10+2*5+7+7).
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

def get_results(num_list, symbol_list):
    # get distinct chars
    distrinct_symbols = list(set(symbol_list[0]) & set(symbol_list[1]) & set(symbol_list[2]))
    if len(distrinct_symbols) == 1:
        sys.stdout.write("%.4f\n"%(10+5*2+7*2))
        return

    prob = 0
    for item in distrinct_symbols:
        current_prob = 1
        for i in range(3):
            count = 0
            for char in symbol_list[i]:
                if char == item:
                    count += 1
            current_prob *= count/int(num_list[i])
        prob += current_prob * 34
    sys.stdout.write("%.4f\n"%(prob))


def main():
    n = int(sys.stdin.readline().strip())

    for _ in range(n):
        # get [x, y, z]
        nums = sys.stdin.readline().strip().split()
        symbols = []
        for _ in range(3):
            symbols.append(sys.stdin.readline().strip())

        get_results(nums, symbols)


if __name__ == '__main__':
    main()

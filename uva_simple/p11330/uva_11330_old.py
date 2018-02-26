# Python3 implementation won't pass the uva-online-judge system since it excceds
# the problem time limit.

import sys

def solve(test):
    # print(test)
    swipes = 0
    len_test = len(test)
    for i in range(0, len_test, 2):
        if test[i] != test[i+1]:
            left_shoe = test[i]
            for j in range(i+2, len_test, 2):
                if test[i] == test[j+1]:
                    test[j+1] = test[i+1]
                    swipes += 1
                    break;
    print(swipes)

'''
def solve(test):
    # print(test)
    swipes = 0
    # len_test = len(test)
    while True:
        # find a shoe need to be swiped
        left_shoe = None
        for i in range(0, len(test), 2):
            if test[i] != test[i+1]:
                left_shoe = i
                break;
        # all sheo has been sorted in order
        if left_shoe == None:
            return swipes
        # find a right shoe with the same color to swipe
        for i in range(1, len(test), 2):
            if test[i] == test[left_shoe]:
                # swipe
                test[i] = test[left_shoe+1]
                test[left_shoe+1] = test[left_shoe]
                swipes += 1
                break
'''

def main():
    tests = sys.stdin.readlines()[1:]
    for test in tests:
        test = [int(t) for t in test.split()[1:]]
        # test = test.split()[1:]
        # pairs = []
        # for i in range(0, len(test), 2):
        #     pairs.append([int(test[i]), int(test[i+1])])
        solve(test)
        # print(swipes)
        # sys.stdout.write(str(swipes)+'\n')
    # sys.stdout.flush()


if __name__ == '__main__':
    main()

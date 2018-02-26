import sys

def calc_mod(B, P, M):
    current_mod = 1;
    for i in range(P):
        current_mod = (current_mod * B) % M
    print(current_mod)

def main():
    tests = sys.stdin.readlines()
    for i in range(0, len(tests), 4):
        B = int(tests[i])
        P = int(tests[i+1])
        M = int(tests[i+2])
        calc_mod(B, P, M)

if __name__ == '__main__':
    main()

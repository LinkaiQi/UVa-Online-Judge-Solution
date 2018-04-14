# /* UVa problem: 551
#  *
#  * Topic: Other
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given a expresions that containing brackets
#  *    In this problem, check whether the brackets are properly nested.
#  *
#  * Solution Summary:
#  *    We can use a stack data structure to check whether the brackets are
#  *    properly nested. Push symbols to the stack when it is a left bracket
#  *    non-bracket symbol. Pop symbols from the stack when we encounter a
#  *    closing bracket. Check if every closing bracket has a left bracket
#  *    pairing to it, vice versa.
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

# Brackets = {'(':')', '[':']', '{':'}', '<':'>', '(*':'*)', \
#             ')':'(', ']':'[', '}':'{', '>':'<', '*)':'(*'}
Brackets = {')':'(', ']':'[', '}':'{', '>':'<', '*)':'(*'}

import sys

def main():
    expression = sys.stdin.readline()
    while expression:
        exp_symbols = []
        i = 0;
        len_exp = len(expression)
        while i < len_exp:
            # split expression to list of symbols
            if expression[i] == '(' and i+1 < len_exp and expression[i+1] == '*':
                exp_symbols.append(expression[i:i+2])
                i += 2
            elif expression[i] == '*' and i+1 < len_exp and expression[i+1] == ')':
                exp_symbols.append(expression[i:i+2])
                i += 2
            else:
                exp_symbols.append(expression[i])
                i += 1

        # check if the expression is properly nested
        stack = []
        ok = True
        for i in range(len(exp_symbols)):
            if exp_symbols[i] in Brackets:
                # print(exp_symbols[i])
                if not stack:
                    ok = False
                    break;
                symbol = stack.pop()
                while symbol != Brackets[exp_symbols[i]] and stack:
                    if symbol in ['(', '[', '{', '<', '(*']:
                        ok = False
                        break;
                    symbol = stack.pop()
                if symbol != Brackets[exp_symbols[i]]:
                    ok = False
                    break;
            else:
                stack.append(exp_symbols[i])

        for bkt in ['(', '[', '{', '<', '(*']:
            if bkt in stack:
                ok = False

        if ok:
            sys.stdout.write('YES\n')
        else:
            sys.stdout.write('NO '+str(i+1)+'\n')

        expression = sys.stdin.readline()


if __name__ == '__main__':
    main()

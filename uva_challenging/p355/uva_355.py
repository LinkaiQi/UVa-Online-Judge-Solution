# /* UVa problem: 355
#  *
#  * Topic: Arithmetic
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    "Write a program to convert a whole number specified in any base (2..16)
#  *    to a whole number in any other base (2..16). “Digits” above 9 are represented
#  *    by single capital letters; e.g. 10 by A, 15 by F, etc." -- UVa_Online_Judge
#  *
#  * Solution Summary:
#  *    First check if the input number is illegal.
#  *    If the given number is legal, convert it to a base-10 number.
#  *    and then convert it to a required base number.
#  *    The base-10 convertion equation:
#  *        ten_base += digit_value * (original_base ** digit_position)
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

def change_base(nums):
    base_digits = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']

    # check if it is illegal
    input_legal_digits = base_digits[0:(nums[0])]
    for char in nums[2]:
        if char not in input_legal_digits:
            sys.stdout.write("%s is an illegal base %d number\n"%(nums[2], nums[0]))
            return

    # reverse the string first
    reversed_str = nums[2][::-1]

    # change to ten_base num
    ten_base = 0
    pos = 0
    for char in reversed_str:
        index = base_digits.index(char)
        ten_base += index * nums[0]**pos
        pos += 1

    if nums[1] == 10:
        sys.stdout.write("%s base %d = %d base %d\n"%(nums[2], nums[0], ten_base, nums[1]))
        return
    elif ten_base == 0:
        # check if the num is 0
        sys.stdout.write("%s base %d = 0 base %d\n"%(nums[2], nums[0], nums[1]))
        return

    # change ten_base number to other base
    output_legal_digits = base_digits[0:(nums[1])]
    reversed_other_base = ""
    quotient = ten_base
    while str(quotient) not in output_legal_digits:
        reversed_other_base += output_legal_digits[quotient%nums[1]]
        quotient = quotient//nums[1]
    if quotient != 0:
        reversed_other_base += str(quotient)
    other_base = reversed_other_base[::-1]
    sys.stdout.write("%s base %d = %s base %d\n"%(nums[2], nums[0], other_base, nums[1]))

def main():
    lines = sys.stdin.readlines()
    for i in range(0, len(lines)):
        inputs = lines[i].strip().split()
        inputs[0] = int(inputs[0])
        inputs[1] = int(inputs[1])
        change_base(inputs)

if __name__ == '__main__':
    main()

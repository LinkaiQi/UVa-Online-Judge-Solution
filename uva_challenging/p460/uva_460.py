# /* UVa problem: 460
#  *
#  * Topic: Geometry
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Given the coordinates of two rectangular windows. If the windows do not
#  *    overlap, produce a message to that effect. If they do overlap, compute
#  *    the coordinates of the overlapping region.
#  *
#  * Solution Summary:
#  *    Overlapping region should be a rectangular.
#  *    The lower left corner of the overlapping region is the maximum coordinates
#  *    of the lower left corners of the two rectangular windows.
#  *    The upper right corner of the overlapping region is the minimum coordinates
#  *    of the upper right corners of the two rectangular windows.
#  *    If the lower left and upper right corners of the overlapping region can form
#  *    a rectangular with positive area, they do overlap. Otherwise, they does
#  *    not overlapping.
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

def main():
    k = int(sys.stdin.readline())
    while k:
        r1 = sys.stdin.readline()
        while r1 in ('\n', '\r\n'):
            r1 = sys.stdin.readline()
        xll1, yll1, xur1, yur1 = [int(num) for num in r1.split()]

        r2 = sys.stdin.readline()
        xll2, yll2, xur2, yur2 = [int(num) for num in r2.split()]

        xll_s = max(xll1, xll2)
        yll_s = max(yll1, yll2)
        xur_s = min(xur1, xur2)
        yur_s = min(yur1, yur2)

        if xll_s < xur_s and yll_s < yur_s:
            sys.stdout.write('{} {} {} {}\n'.format(xll_s, yll_s, xur_s, yur_s))
        else:
            sys.stdout.write('No Overlap\n')

        k = k - 1
        if k:
            sys.stdout.write('\n')

if __name__ == '__main__':
    main()

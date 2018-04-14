# /* UVa problem: 190
#  *
#  * Topic: Geometry
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Write a program that, given the Cartesian coordinates of three points on
#  *    a plane, will find the equation of the circle through them all. The three
#  *    points will not be on a straight line.
#  *    The solution is to be printed as an equation of the form:
#  *        (x−h)^2 + (y−k)^2 = r^2
#  *    and an equation of the form:
#  *        x^2 + y^2 + cx + dy − e = 0
#  *
#  * Solution Summary:
#  *    Select any two points, and find the line L1 that perpendicular to it
#  *    Select another two points, and find the line L2 that perpendicular to it
#  *    The intersection point between L1 and L2 is the center of the circle.
#  *    After we have the cirle coordinates, it's easy to calculate the equation.
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

def convert_format(num):
    if num <= 0:
        return "- %.3f" % abs(num)
    else:
        return "+ %.3f" % num

def solve(x1, y1, x2, y2, x3, y3):
    x_mid1 = (x1 + x2) / 2
    y_mid1 = (y1 + y2) / 2
    if y1 - y2 == 0:
        slope_mid1 = 100000
    elif x1 - x2 == 0:
        slope_mid1 = 0
    else:
        slope_mid1 = -1 / ((y1 - y2) / (x1 - x2))
    b1 = y_mid1 - slope_mid1 * x_mid1
    # print('y = {m}x + {b}'.format(m=slope_mid1, b=b1))

    x_mid2 = (x2 + x3) / 2
    y_mid2 = (y2 + y3) / 2
    if y2 - y3 == 0:
        slope_mid2 = 100000
    elif x2 - x3 == 0:
        slope_mid2 = 0
    else:
        slope_mid2 = -1 / ((y2 - y3) / (x2 - x3))
    b2 = y_mid2 - slope_mid2 * x_mid2
    # print('y = {m}x + {b}'.format(m=slope_mid2, b=b2))

    h = (b2 - b1) / (slope_mid1 - slope_mid2)
    k = slope_mid1 * h + b1
    r = math.sqrt((h-x1)**2 + (k-y1)**2)

    c = -2 * h
    d = -2 * k
    e = h**2 + k**2 - r**2
    h = convert_format(round(-h,3))
    k = convert_format(round(-k,3))
    r = convert_format(round(r,3))
    c = convert_format(round(c,3))
    d = convert_format(round(d,3))
    e = convert_format(round(e,3))

    sys.stdout.write('(x {})^2 + (y {})^2 = {}^2\n'.format(h, k, r[2:]))
    sys.stdout.write('x^2 + y^2 {}x {}y {} = 0\n\n'.format(c, d, e))

def main():
    test = sys.stdin.readline()
    while test:
        x1, y1, x2, y2, x3, y3 = test.split()
        x1 = float(x1); y1 = float(y1);
        x2 = float(x2); y2 = float(y2);
        x3 = float(x3); y3 = float(y3);
        solve(x1, y1, x2, y2, x3, y3)
        test = sys.stdin.readline()


if __name__ == '__main__':
    main()

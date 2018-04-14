# /* UVa problem: 158
#  *
#  * Topic: Others
#  *
#  * Level: challenging
#  *
#  * Brief problem description:
#  *    Implement a reminder that could remind us of when the important dates
#  *    are approaching.
#  *    The input will specify the year for which the calendar is relevant
#  *    (in the range 1901 to 1999). This will be followed by a series of lines
#  *    representing anniversaries or days for which the service is requested.
#  *
#  * Solution Summary:
#  *    This is a straight forward question. We need calculate the number of
#  *    days before the event. And using dictionary data structure to keep
#  *    track of the events. Sort according to the importance of the event.
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

def sort_reminders(rems):
    for rem_days, anns in rems.items():
        anns = sorted(anns, key=lambda ann: ann[3], reverse = True)
        for ann in anns:
            sys.stdout.write("{:3d}{:3d} {:7s}".format(int(ann[1]), int(ann[2]), "*"*ann[3]) \
                + " %s"%(ann[4]))

def get_reminders(date, anns, mon_day):
    # anns with format ['A', D, M, P, name]
    # Show result to stdout
    reminders = {}
    sys.stdout.write("Today is:{:3d}{:3d}\n".format(date[1], date[2]))
    for ann in anns:
        if ann[2] == date[2]:
            # same month
            if ann[1] == date[1]:
                # today's anniversaries
                sys.stdout.write("{:3d}{:3d}".format(ann[1], ann[2]) \
                    + " *TODAY* %s"%(ann[4]))
            elif ann[1] - date[1] > 0:
                remaining_days = ann[1] - date[1]
                # print("aaaa "+ str(remaining_days))
                if remaining_days <= ann[3]:
                    # the reminder service has started
                    if not remaining_days in reminders:
                        reminders[remaining_days] = []
                    # print("bbbb "+ ann[3])
                    tmp = ann[:]
                    tmp[3] = ann[3] - remaining_days + 1
                    reminders[remaining_days].append(tmp)
        elif (ann[2] == date[2] + 1) or (ann[2] == 1 and date[2] == 12):
            remaining_days = ann[1] + mon_day[date[2]] - date[1]
            if 0 < remaining_days <= ann[3]:
                # the reminder service has started
                if not remaining_days in reminders:
                    reminders[remaining_days] = []
                tmp = ann[:]
                tmp[3] = ann[3] - remaining_days + 1
                reminders[remaining_days].append(tmp)
    sort_reminders(reminders)

def main():
    tests = sys.stdin.readlines()
    year = tests[0]
    month_day = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if int(year)%4 == 0:
        month_day[2] = 29
    anniversaries = []
    for i in range(1, len(tests)-1):
        inputs = tests[i].split(maxsplit = 4)
        if inputs[0] == 'A':
            for j in range(1, 4):
                inputs[j] = int(inputs[j])
            anniversaries.append(inputs)
        else:
            for j in range(1, 3):
                inputs[j] = int(inputs[j])
            get_reminders(inputs, anniversaries, month_day)
            if i != len(tests)-2:
                sys.stdout.write("\n")

if __name__ == '__main__':
    main()

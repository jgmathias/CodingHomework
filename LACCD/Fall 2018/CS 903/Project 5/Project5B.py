#Name: James Mathias
#Assignment: Project 5-B
#Date: Nov 12, 2018

#Description: ask user to select a month, and the program output the number of days in that month

Days = [31,28,31,30,31,30,31,31,30,31,30,31]

Month = raw_input("Enter a month: ").upper()

num = -1

if Month == "JANUARY":
    num = 0
elif Month == "FEBRUARY":
    num = 1
elif Month == "MARCH":
    num = 2
elif Month == "APRIL":
    num = 3
elif Month == "MAY":
    num = 4
elif Month == "JUNE":
    num = 5
elif Month == "JULY":
    num = 6
elif Month == "AUGUST":
    num = 7
elif Month == "SEPTEMBER":
    num = 8
elif Month == "OCTOBER":
    num = 9
elif Month == "NOVEMBER":
    num = 10
elif Month == "DECEMBER":
    num = 11

if num == -1:
    print "There is no such month."
else:
    print "The numbr of days in that month is " + str(Days[num]) + "."
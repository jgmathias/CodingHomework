#Name: James Mathias
#Assignment: Project 1-B
#Date: Sep 7, 2018

#Description: Ask user for the number of males and females, and then calculates that percentage.

mnum = float(input("Enter number of males: "))
fnum = float(input("Enter number of females: "))

scale = 100

total = mnum + fnum
print "There are", total, "people total."

mper = mnum / total * scale
print format(mper,'.2f'),"% is male."

fper = fnum / total * scale
print format(fper,'.2f'),"% is female."
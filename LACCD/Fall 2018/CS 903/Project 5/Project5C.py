#Name: James Mathias
#Assignment: Project 5-C
#Date: Nov 12, 2018

#Description: ask user to input number of miles for each day in a week, then count days user ran a certain number of miles

Days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

count1 = 0
count2 = 0
count3 = 0

for i in range(0, 7):
    miles = float(input("Miles for "+ Days[i] +": "))
    if miles < 5:
        count1 = count1 + 1
    elif miles > 10:
        count3 = count3 + 1
    else:
        count2 = count2 + 1

print "Number of day ran less than 5 miles: " + str(count1)
print "Number of day ran inbetween 5 and 10 miles: " + str(count2)
print "Number of day ran more than 10 miles: " + str(count3)
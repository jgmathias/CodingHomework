#Name: James Mathias
#Assignment: Project 5-D
#Date: Nov 12, 2018

#Description: count, record, and display the bursts of zeros in a list.

List = []
BurstLengths = []

Num = int(input("Size of list of numbers: "))

print "Enter " + str(Num) + " numbers."
lastnum = 1

for i in range(0, Num):
    num = int(input())
    List.append(num)
    if (lastnum != 0 and num == 0):
        BurstLengths.append(1)
    elif (lastnum == 0 and num == 0):
        BurstLengths[len(BurstLengths) - 1] = BurstLengths[len(BurstLengths) - 1] + 1
    lastnum = num

print "Burst  Length"
for i in range(0, len(BurstLengths)):
    print str(i+1) + "      " + str(BurstLengths[i])

print "Average burst length: " + str(float(sum(BurstLengths))/len(BurstLengths))
print "Minimum burst length: " + str(min(BurstLengths))
print "Maximum burst length: " + str(max(BurstLengths))
print "Total numbr of zeros: " + str(sum(BurstLengths))
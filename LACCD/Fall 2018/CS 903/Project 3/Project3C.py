#Name: James Mathias
#Assignment: Project 3-C
#Date: Oct 6, 2018

#Description: ask user to input 3 exam scores, then calculate and output grade

score1 = float(input("First exam score:  "))
score2 = float(input("Second exam score: "))
score3 = float(input("Third exam score:  "))

average = (score1 + score2 + score3) / 3

if average > 90:
    Grade = "A"
elif average >= 88:
    Grade = "A-"
elif average >= 80:
    Grade = "B"
elif average >= 70:
    Grade = "C"
elif average > 60:
    Grade = "D"
else:
    Grade = "F"

print "Your grade is", Grade 
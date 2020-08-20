#Name: James Mathias
#Assignment: Project 5-A
#Date: Nov 12, 2018

#Description: ask user to input a list of student names, then 3 exam scores for each student, then calculate and output grade for each student

Names = []
Exam1 = []
Exam2 = []
Exam3 = []

Num = int(input("Number of students: "))

for i in range(0, Num):
    scale = str(i + 1)
    name = raw_input("Name of student "+ scale +": ")
    Names.append(name)

for i in range(0, Num):
    score1 = float(input("First Exam score for " + Names[i] + ": "))
    Exam1.append(score1)
    score2 = float(input("Second Exam score for " + Names[i] + ": "))
    Exam2.append(score2)
    score3 = float(input("Third Exam score for " + Names[i] + ": "))
    Exam3.append(score3)

for i in range(0, Num):
    score1 = Exam1[i]
    score2 = Exam2[i]
    score3 = Exam3[i]
    
    Average = (score1 + score2 + score3) / 3
    
    if Average >= 90:
        Grade = "A"
    elif Average >= 80:
        Grade = "B"
    elif Average >= 70:
        Grade = "C"
    elif Average >= 60:
        Grade = "D"
    else:
        Grade = "F"
    
    print Names[i] + "'s average score is " + str(Average) + "."
    print Names[i] + "'s letter grade is " + Grade + "."
#Name: James Mathias
#Assignment: Project 4-B
#Date: Oct 21, 2018

#Description: calculating a talent competition contestant's score

def getJudgeData(x):
    num = -1
    while num < 0 or num > 10:
        num = float(input("Judge #" + x + ": "))
    return num;

def calcScore(score1, score2, score3, score4, score5):
    Low = findLowest(score1, score2, score3, score4, score5)
    High = findHighest(score1, score2, score3, score4, score5)
    ScoreSum = score1 + score2 + score3 + score4 + score5 - Low - High
    finalScore = ScoreSum / 3
    return finalScore;
    
def findLowest(score1, score2, score3, score4, score5):
    low = score1
    if score2 < low:
        low = score2
    if score3 < low:
        low = score3
    if score4 < low:
        low = score4
    if score5 < low:
        low = score5
    return low;
    
def findHighest(score1, score2, score3, score4, score5):
    high = score1
    if score2 > high:
        high = score2
    if score3 > high:
        high = score3
    if score4 > high:
        high = score4
    if score5 > high:
        high = score5
    return high;

################################################################################

Score1 = getJudgeData("1")
Score2 = getJudgeData("2")
Score3 = getJudgeData("3")
Score4 = getJudgeData("4")
Score5 = getJudgeData("5")

FinalScore = calcScore(Score1, Score2, Score3, Score4, Score5)

print "The contestant's final score is", format(FinalScore,'.1f')
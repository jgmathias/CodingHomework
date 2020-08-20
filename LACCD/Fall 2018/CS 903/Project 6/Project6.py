#Name: James Mathias
#Assignment: Project 6
#Date: Dec 8, 2018

#Description: simulate a banking application with information stored in text files

def getUser(names):
    index = -2
    while True:
        if index == -2:
            name = raw_input("Enter customer name: ").upper()
            index = -1
        else:
            name = raw_input("Unknown name; try again: ").upper()
            
        for i in range(0, len(names)):
            if name == names[i]:
                index = i
                return index

def Menu(oldBalance, selection):
    newBalance = 0

    if selection == "D":
        newBalance = deposit(oldBalance)
    elif selection == "W":
        newBalance = withdraw(oldBalance)
    elif selection == "B":
        newBalance = oldBalance
    
    print "The balance is now $" + str(newBalance) + "."
    return newBalance

def deposit(oldbalance):
    num = int(input("Amount to deposit: "))
    newbalance = oldbalance + num
    return newbalance

def withdraw(oldbalance):
    num = int(input("Amount to withdraw: "))
    while num > oldbalance:
        num = int(input("Not enough balance; try again: "))
    newbalance = oldbalance - num
    return newbalance

################################################################################

Names = []
Balances = []

UserInfo = open("UserInformation.txt", "r")

nextName = str(UserInfo.readline().replace("\n", ""))
nextBalance = str(UserInfo.readline().replace("\n", ""))

while nextName:
    Names.append(nextName)
    Balances.append(nextBalance)
    nextName = str(UserInfo.readline().replace("\n", ""))
    nextBalance = str(UserInfo.readline().replace("\n", ""))

UserInfo.close()

for i in range(0, len(Balances)):
    Balances[i] = int(Balances[i])

#############################################

# Names = ["MIKE", "JANE", "STEVE"]
# Balances = [300, 400, 500]

#############################################

Index = getUser(Names)
    
print "Type D to deposit into account."
print "Type W to withdraw into account."
print "Type B to display current balance."
print "Type C to change the customer."
print "Type E to save all tranactions and exit."

Selection = raw_input("Selection: ").upper()
while Selection != "D" and Selection != "W" and Selection != "B" and Selection != "C" and Selection != "E":
    Selection = raw_input("Invalid selection; try again: ").upper()

while Selection != "E":
    if Selection == "C":
        print ""
        Index = getUser(Names)
    else:
        NewBalance = Menu(Balances[Index], Selection)
        Balances[Index] = NewBalance
        print ""
        print "The current customer is " + Names[Index] + "."
    
    print "Type D to deposit into account."
    print "Type W to withdraw into account."
    print "Type B to display current balance."
    print "Type C to change the customer."
    print "Type E to save all tranactions and exit."
    
    Selection = raw_input("Selection: ").upper()
    while Selection != "D" and Selection != "W" and Selection != "B" and Selection != "C" and Selection != "E":
        Selection = raw_input("Invalid Selection; try again: ").upper()

UserInfo = open("UserInformation.txt", "w")

for i in range(0, len(Names)):
    UserInfo.write(Names[i] + "\n")
    UserInfo.write(str(Balances[i]) + "\n")

UserInfo.close()
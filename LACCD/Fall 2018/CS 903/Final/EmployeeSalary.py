#Name: James Mathias
#Assignment: Final
#Date: Dec 11, 2018

#Description: Read from a txt file, calculate tax,and write to a new txt file

def CalculateNetSalary(gross, state):
    HighIncome = 0.2
    LowIncome = 0.15
    
    if gross > 100000:
        FedTax = HighIncome
    else:
        FedTax = LowIncome
    
    StandardState = 0.12
    ExceptionState = 0.1
       
    if (state == "CA" or state == "NV" or state == "AZ" or state == "WA"):
        StateTax = ExceptionState
    else:
        StateTax = StandardState
    
    net = gross - gross * (FedTax + StateTax)
    
    return net

################################################################################

Lines = []

LastNames = []
FirstNames = []
States = []
GrossSalaries = []

EmployeeInfo = open("EmployeeInfo.txt", "r")

junk = str(EmployeeInfo.readline())
junk = str(EmployeeInfo.readline())

nextline = str(EmployeeInfo.readline().replace("\n", ""))

while nextline:
    Lines.append(nextline)
    nextline = str(EmployeeInfo.readline().replace("\n", ""))
    
EmployeeInfo.close()

for i in range(0, len(Lines)):
    line = Lines[i].split()
    LastNames.append(line[0])
    FirstNames.append(line[1])
    States.append(line[2])
    GrossSalaries.append(float(line[3]))

NetSalaries = []

for i in range(0, len(GrossSalaries)):
    NetSalaries.append(CalculateNetSalary(GrossSalaries[i], States[i]))

NetSalary = open("NetSalary.txt", "w")

NetSalary.write("Last Name   First Name  Net Salary" + "\n")
NetSalary.write("==================================" + "\n")

for i in range(0, len(LastNames)):
    NetSalary.write(LastNames[i] + "\t")
    if len(LastNames[i]) < 4:
        NetSalary.write("\t\t")
    elif len(LastNames[i]) < 8:
        NetSalary.write("\t")
    
    NetSalary.write(FirstNames[i] + "\t")
    if len(FirstNames[i]) < 4:
        NetSalary.write("\t\t")
    elif len(FirstNames[i]) < 8:
        NetSalary.write("\t")
    
    if NetSalaries[i] < 100000:
        NetSalary.write("  ")
    elif NetSalaries[i] < 1000000:
        NetSalary.write(" ")
    NetSalary.write(str(format(NetSalaries[i], '.2f')) + "\t")
    
    NetSalary.write("\n")

NetSalary.close()
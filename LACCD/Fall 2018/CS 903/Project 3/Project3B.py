#Name: James Mathias
#Assignment: Project 3-B
#Date: Oct 6, 2018

#Description: Ask user for salary info on 6 people, then calculate federal and state taxes, and net salary

HighIncome = 0.2
LowIncome = 0.15

StandardState = 0.12
ExceptionState = 0.1

for i in range(0, 6):
    
    Name = raw_input("Enter Name:   ")
    Salary = float(input("Enter Salary: $"))
    State = raw_input("Enter State:  ")
    
    if Salary > 100000:
        FedTax = HighIncome
    else:
        FedTax = LowIncome
    if (State == "CA" or State == "NV" or State == "AZ" or State == "WA"):
        StateTax = ExceptionState
    else:
        StateTax = StandardState
        
    print "For", Name,":"
    print "     Federal Tax: $", format(Salary * FedTax,'.2f')
    print "     State Tax:   $", format(Salary * StateTax,'.2f')
    print "     Net Pay:     $", format(Salary - Salary * (FedTax + StateTax),'.2f')
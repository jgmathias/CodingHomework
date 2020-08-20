#Name: James Mathias
#Assignment: Project 2-A
#Date: Sep 21, 2018

#Description: User "inputs" money and gets item and change back if funds are enough.

Price = 1.25

print "Price of drink is", format(Price,'.2f')

Input = float(input("Enter inputed amount: $"))

if Input >= Price:
    Change = Input - Price
    print "Thank you for your purchase. Your change is $" ,format(Change,'.2f'), "."
else:
    Change = Price - Input
    print "Insufficient funds. You are short $" ,format(Change,'.2f'), "."
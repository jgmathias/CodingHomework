#Name: James Mathias
#Assignment: Project 1-A
#Date: Sep 7, 2018

#Description: Ask user for the price of 5 items, then calculate subtotal, tax, and total.

item1 = float(input("Enter 1st item: "))
item2 = float(input("Enter 2nd item: "))
item3 = float(input("Enter 3rd item: "))
item4 = float(input("Enter 4th item: "))
item5 = float(input("Enter 5th item: "))

taxRate = 0.07

subTotal = item1 + item2 + item3 + item4 + item5
print "Subtotal:", format(subTotal,'.2f')

tax = subTotal * taxRate
print "Tax:", format(tax,'.2f')

total = subTotal + tax
print "Total:", format(total,'.2f')
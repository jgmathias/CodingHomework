#Name: James Mathias
#Assignment: Project 3-A
#Date: Oct 6, 2018

#Description: calculating sale price of an item and the amount earned by each party as the item price drops

Input = float(input("Enter original sale price amount: $"))

PriceCut = 0.8
owner = 0.6
shop = 0.4

for i in range(0, 4):
    print "For Month",i,":"
    print "     Sale price:  $", format(Input,'.2f')
    print "     Owner's cut: $", format(Input * owner,'.2f')
    print "     Shop's cut:  $", format(Input * shop,'.2f')
    Input *= PriceCut
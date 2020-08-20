#Name: James Mathias
#Assignment: Project 2-D
#Date: Sep 21, 2018

#Description: Combination of the previous 3 programs.
#The order of the programs is 2-C, 2-B, then 2-A.

Price1 = 1.25
Price2 = 1.75
Price3 = 1.00
Price4 = 1.50

print "1. Iced Tea:       Small $", format(Price1,'.2f'), " Medium $", format(Price1*2,'.2f'), " Large $", format(Price1*3,'.2f')
print "2. Iced Coffee:    Small $", format(Price2,'.2f'), " Medium $", format(Price2*2,'.2f'), " Large $", format(Price2*3,'.2f')
print "3. Soda:           Small $", format(Price3,'.2f'), " Medium $", format(Price3*2,'.2f'), " Large $", format(Price3*3,'.2f')
print "4. Bottled Water:  Small $", format(Price4,'.2f'), " Medium $", format(Price4*2,'.2f'), " Large $", format(Price4*3,'.2f')

DrinkNum = int(input("Enter the number for your desired drink: "))

if DrinkNum == 1:
    DrinkName = "iced tea"
    Price = Price1
elif DrinkNum == 2:
    DrinkName = "iced coffee"
    Price = Price2
elif DrinkNum == 3:
    DrinkName = "soda"
    Price = Price3
elif DrinkNum == 4:
    DrinkName = "bottled water"
    Price = Price4
else:
    print "Invalid selection"
    quit()

print "You have selected a", DrinkName, "."

################################################################################

Size = input("Enter 'S', 'M', or 'L': ").upper()
#The line of code above only seems to accept an input if it is surrounded in quotes. I don't know why.

if Size == "S":
    DrinkSize = "small"
    Servings = 1
elif Size == "M":
    DrinkSize = "medium"
    Servings = 2
elif Size == "L":
    DrinkSize = "large"
    Servings = 3
else:
    print "Invalid drink size"
    quit()
    
print "You have selected a", DrinkSize, DrinkName, "."

################################################################################

Total = Price * Servings

print "The price of a", DrinkSize, DrinkName, "is", format(Total,'.2f'), "."

Money = float(input("Enter inputed amount: $"))

if Money >= Total:
    Change = Money - Total
    print "Thank you for your purchase. Your change is $" ,format(Change,'.2f'), "."
else:
    Change = Total - Money
    print "Insufficient funds. You are short $" ,format(Change,'.2f'), "."
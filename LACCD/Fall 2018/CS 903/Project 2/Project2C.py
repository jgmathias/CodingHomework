#Name: James Mathias
#Assignment: Project 2-C
#Date: Sep 21, 2018

#Description: User selects type of drink.

Price1 = 1.25
Price2 = 1.75
Price3 = 1.00
Price4 = 1.50

print "1. Iced Tea: Small $", format(Price1,'.2f'), "Medium $", format(Price1*2,'.2f'), "Large $", format(Price1*3,'.2f')
print "2. Iced Cofee: Small $", format(Price2,'.2f'), "Medium $", format(Price2*2,'.2f'), "Large $", format(Price2*3,'.2f')
print "3. Soda: Small $", format(Price3,'.2f'), "Medium $", format(Price3*2,'.2f'), "Large $", format(Price3*3,'.2f')
print "4. Bottled Water: Small $", format(Price4,'.2f'), "Medium $", format(Price4*2,'.2f'), "Large $", format(Price4*3,'.2f')

Input = int(input("Enter the number for your desired drink: "))

if Input == 1:
    print "You have ordered an iced tea."
    Price = Price1
elif Input == 2:
    print "You have ordered an iced cofee."
    Price = Price2
elif Input == 3:
    print "You have ordered a soda."
    Price = Price3
elif Input == 4:
    print "You have ordered a bottled water."
    Price = Price4
else:
    print "Invalid selection"
    quit()
    
print format(Price,'.2f')
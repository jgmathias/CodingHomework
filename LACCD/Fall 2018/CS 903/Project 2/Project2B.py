#Name: James Mathias
#Assignment: Project 2-B
#Date: Sep 21, 2018

#Description: User inputs size of drink.

Input = input("Enter 'S', 'M', or 'L': ").upper()
#The line of code above only seems to accept an input if it is surrounded in quotes. I don't know why.

if Input == "S":
    print "You have ordered a small drink."
    Size = 1
elif Input == "M":
    print "You have ordered a medium drink."
    Size = 2
elif Input == "L":
    print "You have ordered a large drink."
    Size = 3
else:
    print "Invalid drink size"
    quit()
    
print "Multiplier:", Size
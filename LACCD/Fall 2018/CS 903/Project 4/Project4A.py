#Name: James Mathias
#Assignment: Project 4-A
#Date: Oct 21, 2018

#Description: calculating the charge of a hospital stay

def NonNegativeInput(message):
    num = -1
    while num < 0:
        num = float(input(message))
    return num;

def CostIn(days, rate, services, meds):
    cost = days * rate + services + meds
    return cost;
    
def CostOut(services, meds):
    cost = services + meds
    return cost;

################################################################################

PatientType = ""
while PatientType != "IN" and PatientType != "OUT":
    PatientType = raw_input("In-Patient or Out-Patient: ").upper()

if PatientType == "IN":
    Days = NonNegativeInput("Number of days spent in the hospital: ")
    Rate = NonNegativeInput("Daily Rate: $")

Services = NonNegativeInput("Charges for hospital services: $")
Meds = NonNegativeInput("Charges for medications: $")

if PatientType == "IN":
    Cost = CostIn(Days, Rate, Services, Meds)
else:
    Cost = CostOut(Services, Meds)

print "Your charges are $", format(Cost,'.2f')
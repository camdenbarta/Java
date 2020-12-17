"""
Camden Barta
Assignment 7
March 19th 2019

PreCondition: User intputs any date in the format of month day year 
with a space in between and using the full year. ex 1 30 2001
PostCondition: Prints of the day in the year that the date is. 
"""
def main():
	date = input("Enter Date in Month Day Year form ex. 1 30 2010: ")
	dateString = date.split()
	dateList = []

	dateList = list(map(int, dateString))

	leap = leapYear(dateList)
	days = day(leap, dateList)
	leapYear(dateList)
	day(leap, dateList)
	display(days,dateList)

def leapYear(dateList):
	year = dateList[2]
	leap = False

	if year % 4 == 0: 
		if year % 100 !=0:
			leap = True
	if year % 400 == 0 & year % 100 ==0:
		leap = True
	return leap

def day(leap, dateList):
	normalYear = {1:31,2:28,3:31,4:30,5:31,6:29,7:31,8:31,9:30,10:31,11:30,12:31}
	leapYear = {1:31,2:29,3:31,4:30,5:31,6:29,7:31,8:31,9:30,10:31,11:30,12:31}
	month = dateList[0]
	day = 0
	
	if leap:
		for i in range(1, month):
			day += leapYear[i]
		day += dateList[1]
	else:
		for i in range(1, month):
			day += normalYear[i]
		day += dateList[1]
	return day
	
def display(days, dateList):
	print(dateList[0], "/", dateList[1],"/", dateList[2], " is the ", days, " day in the year.")
main()

"""
The Results
Camdens-MacBook-Air:programs camdenbarta$ python3 assignment7.py
Enter Date in Month Day Year form ex. 1 30 2010: 3 1 2000
3 / 1 / 2000  is the  61  day in the year.
"""
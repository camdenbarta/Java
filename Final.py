class Employee():
	
	def __init__(self, name, title):
		self._name = name
		self._title = title

	def getName(self): return self._name		
	def getTitle(self):return self._title
	def setTitle(self, newTitle): self._title = newTitle

	def __str__(self):
		print("Name: %s Title: %s")%(getName(),getTitle())

class PartTimeEmployee(Employee):
	def __init__(self, name, title, hourlyRate, hoursWorked):
		Employee.__init__(self,name,title)
		self._hourlyRate = hourlyRate
		self._hoursWorked = hoursWorked #per week

	def getHourlyRate(self): return self._hourlyRate
	def getHoursWorked(self): return self._hoursWorked
	def setHoursWorked(self, hours): self._hoursWorked = hours

	def weeklyPay(self):
		if self._hoursWorked > 40:
			OT=self._hoursWorked - 40
		else:
			OT = 0
		return ((self._hourlyRate * self._hoursWorked) + (OT * (self._hourlyRate*1.5)))

	def raiseSalary(self, ratio):
		self._hourlyRate *= 1+(ratio/100)
		return self._hourlyRate

	def __str__(self):
		print("Name: %s Title: %s Hourly Rate: %.2f Hours Worked: %.2f")%(getName(),getTitle(),getHourlyRate(),getHoursWorked())

class FullTimeEmployee(Employee):
	def __init__(self, name, title, yearlySalary):
		Employee.__init__(self,name,title)
		self._yearlySalary = yearlySalary

	def getYearlySalary(self): return self._yearlySalary

	def weeklyPay(self):
		return self._yearlySalary/ 52.0

	def raiseSalary(self, ratio):
		self._yearlySalary *= 1+ratio/100
		return self._yearlySalary

	def __str__(self):
		print("Name: %s Title: %s Yearly Salary: %.2f")%(getName(),getTitle(),getYearlySalary())

def printCheck4Employees(emps, status):
	print("\n\n", status, "\n")
	print("%16s %14s %-16s"%("Name","Tile", "WeeklyCheck\n"))
	for e in emps:
		print("%16s %14s $%-16.2f"%(e.getName(),e.getTitle(), e.weeklyPay()))

def main():
	PartTimeEmpNames = ("Bob","Amy","Tom","Beth")
	titles = ("Waiter","Waitress","Waiter","Waitress")
	hourlyRate = (12,15,14,11)
	hours = (45,30,42,50)

	fullTimeEmps = [("Alice","Accountant",39000),("Rich","Manager",52000), ("Ron","Cook",512000)]

	partEmps = list()
	fullEmps = list()

	for i in range (len(PartTimeEmpNames)):
		partEmps.append(PartTimeEmployee(PartTimeEmpNames[i],titles[i],hourlyRate[i],hours[i]))

	for e in fullTimeEmps:
		fullEmps.append(FullTimeEmployee(e[0],e[1],e[2]))

	printCheck4Employees(partEmps,"Part time employees:")
	printCheck4Employees(fullEmps,"Full time employees:")

	print("\n\nNow everybody gets 10% raise as Christmas gifts.\n")

	for e in partEmps:
		e.raiseSalary(10)		#give the salary raise
	for e in fullEmps:
		e.raiseSalary(10)		#give the salary raise

	printCheck4Employees(partEmps,"Part time employees:")
	printCheck4Employees(fullEmps,"Full time employees")

if __name__ == '__main__':
	main()

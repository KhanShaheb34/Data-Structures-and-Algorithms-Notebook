"""
@author Rafiul
"""

from math import *

# driver function
def  main():
	# input the raw equation
	equation = input('f(x): x^2+4*x-2: ')

	# replace python exponent syntax with general
	equation = equation.replace("^","**")

	# input the interval as string
	a, b = input('Interval: ').split()

	# convert the interval as float
	a = float(a)
	b = float(b)

	# initial middle point 
	x = (a+b)/2

	# continously check for an defined functional value
	while abs(b-a) > 0.00001:
		# shifting the interval left
		if(eval(equation) > 0) :
			b = x

		# shifting the interval right
		else:
			a = x

		# next mid point
		x = (a+b)/2

	# print out the approximate root
	print('approximate root: ',x)

# driver call
if __name__ == "__main__":
	main()

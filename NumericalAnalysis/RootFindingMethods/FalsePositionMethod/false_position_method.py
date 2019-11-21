"""
@author Rafiul
"""

from math import *

# next iteration of x
def next(a, b, equation):
	# set b as x
	x = b

	# evaluate the equation with the value of b
	p = eval(equation)

	# set a as x
	x = a

	# evaluate the equation with the value of a
	q = eval(equation)

	# falsi method said: x = {a*f(b)-b*f(a)}/{f(b)-f(a)}
	return (a*p - b*q)/(p-q)

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

	# iterate initial x
	x = next(a, b, equation)

	# continously check for an defined functional value
	while abs(b-a) > 0.00001:
		# shifting the interval left
		if(eval(equation) > 0) :
			b = x

		# shifting the interval right
		else:
			a = x
		# next iteration

		x = next(a, b, equation)

	# print out the approximate root
	print('approximate root: ',x)

# driver call
if __name__ == "__main__":
	main()

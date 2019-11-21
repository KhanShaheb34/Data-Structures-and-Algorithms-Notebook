"""
@author Rafiul
"""

from math import *

# next iteration of x
def next(x, f_of_x, f_of_x_prime):
	# evaluate the f_of_x with the value of b
	p = eval(f_of_x)

	# evaluate the f_of_x_prime
	q = eval(f_of_x_prime)
	
	# newton raphson said : next_x = x- {f(x)/f`(x)}
	return x - (p/q)

# driver function
def  main():
	# input the function of x
	f_of_x = input('f(x): x^2+4*x-2: ')

	# input first derivative of the function
	f_of_x_prime = input('First Derivative: ')

	# replace python exponent syntax with regular expression
	f_of_x = f_of_x.replace("^","**")
	f_of_x_prime = f_of_x_prime.replace("^","**")

	# input the interval as string
	a, b = input('Interval: ').split()

	# convert the interval as float
	a = float(a)
	b = float(b)


	# iterate initial x
	x = (a+b)/2

	# continously check for an defined functional value
	while True:
		next_x = next(x, f_of_x, f_of_x_prime)
		if(abs(next_x-x) < 0.00001):
			break
		x = next_x
	# print out the approximate root
	print('approximate root: ',x)

# driver call
if __name__ == "__main__":
	main()

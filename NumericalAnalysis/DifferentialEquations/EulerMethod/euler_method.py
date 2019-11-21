#! /usr/bin/env python

"""
@author Rafiul
@require numpy 

"""
from numpy import arange
from numpy import array


"""
Function of euler method

@param f = function
@param xr = x range or x interval
@param y0 = x0 corresponding y0
@param h = constant difference between 2 corresponding x
@return x array and y array
""" 
def euler(f, xr, y0, h):

	# create an empty list of y values
	y = []
	# append y0 into y as fitst value
	y.append(y0)

	# x array using constant difference in interval
	x = arange(xr[0], xr[1]+h, h)

	# loop through for xi -> yi
	for i in range(1, len(x)):
		# append yi into y list
		y.append(y[i-1]+h*f(y[i-1], x[i-1]))

	# return x and y values in numpy array format
	return x, array(y)

# driver 
def main():

	# define the function
	f = lambda x, y : x+y

	# call euler with params
	ans = euler(f, [0,1], 1, 0.1)

	# print x and y array
	print(ans[0])
	print(ans[1])

if __name__ == '__main__':
	main()
	
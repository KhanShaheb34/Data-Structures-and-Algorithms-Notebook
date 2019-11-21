#! /usr/bin/env python

"""
@author Rafiul
@require numpy 

"""
from numpy import arange
from numpy import array


"""
Function of runga kutta method

@param f = function
@param xr = x range or x interval
@param y0 = x0 corresponding y0
@param h = constant difference between 2 corresponding x
@return x array and y array
""" 
def runga_kutta(f, xr, y0, h):

	# create an empty list of y values
	y = []
	# append y0 into y as fitst value
	y.append(y0)

	# x array using constant difference in interval
	x = arange(xr[0], xr[1]+h, h)

	# runga kutta method:
 	# y1 = y0 + 1/6(k1+k2+k3+k4)

	# loop through for xi -> yi
	for i in range(1, len(x)):

	    k1 = h*f (x[i-1],y[i-1])
	    k2 = h*f (x[i-1]+(h/2), y[i-1]+(h/2*k1))
	    k3 = h*f (x[i-1]+(h/2), y[i-1]+(h/2*k2))
	    k4 = h*f (x[i-1]+h, y[i-1]+(h*k3))

	    # append yi into y array
	    y.append(y[i-1] +(1/6)*(k1+(2*k2)+(2*k3)+k4))

	# return x and y values in numpy array format
	return x, array(y)

# driver 
def main():

	# define the function
	f = lambda x, y : x+y

	# call runga kutta with params
	ans = runga_kutta(f, [0,1], 1, 0.1)

	# print x and y array
	print(ans[0])
	print(ans[1])

if __name__ == '__main__':
	main()
	
from numpy import array
from numpy import zeros
from numpy import int16

def  forward_elimination(mat, n):
	for it in range(0, n-1):
		for row in range(it+1, n):
			alpha = mat[row][it]/mat[it][it]
			for col in range(0, n+1):
				mat[row][col] -= alpha*mat[it][col]

	return mat

def backward_substitution(mat, n):
	var = zeros(shape=(n), dtype=int16)
	var[n-1] = mat[n-1][n]/mat[n-1][n-1]

	for row in range(n-2,-1,-1):
		total = 0
		for col in range(row+1, n):
			total += mat[row][col]*var[col]
		var[row] = (mat[row][n]-total)/mat[row][row]

	return var

def driver():
	# take the dimension of the co-efficient matrix
	n = int(input('Co-efficient matrix n: '))

	# input as 1D array 
	# [[1,2],[3,4]] will be input as 1 2 3 4
	mat = array([int(i) for i in input('Matrix: ').split()])

	# reshape to n * n+1
	mat = mat.reshape(n,n+1)

	# make upper triangle
	mat = forward_elimination(mat, n)

	# variable value
	var = backward_substitution(mat, n)

	print(var)

	
if __name__ == '__main__':
	driver()
# Python3 program to do range
# minimum query in O(1) time with
# O(n*n) extra space and O(n*n)
# preprocessing time.
MAX = 500

# lookup[i][j] is going to store
# index of minimum value in
# arr[i..j]
lookup = [[0 for j in range(MAX)]
			for i in range(MAX)]

# Structure to represent
# a query range
class Query:
	
	def __init__(self, L, R):
		
		self.L = L
		self.R = R

# Fills lookup array lookup[n][n]
# for all possible values
# of query ranges
def preprocess(arr, n):

	# Initialize lookup[][] for the
	# intervals with length 1
	for i in range(n):
		lookup[i][i] = i

	# Fill rest of the entries in
	# bottom up manner
	for i in range(n):
		for j in range(i + 1, n):

			# To find minimum of [0,4],
			# we compare minimum
			# of arr[lookup[0][3]] with arr[4].
			if (arr[lookup[i][j - 1]] < arr[j]):
				lookup[i][j] = lookup[i][j - 1]
			else:
				lookup[i][j] = j

# Prints minimum of given m
# query ranges in arr[0..n-1]
def RMQ(arr, n, q, m):

	# Fill lookup table for
	# all possible input queries
	preprocess(arr, n)

	# One by one compute sum of
	# all queries
	for i in range(m):

		# Left and right boundaries
		# of current range
		L = q[i].L
		R = q[i].R

		# Print sum of current query range
		print("Minimum of [" + str(L) + ", " +
			str(R) + "] is " +
			str(arr[lookup[L][R]]))

# Driver code
if __name__ == "__main__":
	
	a = [7, 2, 3, 0, 5,
		10, 3, 12, 18]
	n = len(a)
	q = [Query(0, 4),
		Query(4, 7),
		Query(7, 8)]
	m = len(q)
	RMQ(a, n, q, m)

# This code is contributed by Rutvik_56

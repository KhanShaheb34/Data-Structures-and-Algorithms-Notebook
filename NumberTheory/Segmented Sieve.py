# This functions finds all primes smaller than 'limit'
# using simple sieve of eratosthenes.
def simpleSieve(limit):

	# Create a boolean array "mark[0..limit-1]" and
	# initialize all entries of it as true. A value
	# in mark[p] will finally be false if 'p' is Not
	# a prime, else true.
	mark = [True for i in range(limit)]

	# One by one traverse all numbers so that their
	# multiples can be marked as composite.
	for p in range(p * p, limit - 1, 1):

		# If p is not changed, then it is a prime
		if (mark[p] == True):

			# Update all multiples of p
			for i in range(p * p, limit - 1, p):
				mark[i] = False

	# Print all prime numbers and store them in prime
	for p in range(2, limit - 1, 1):
		if (mark[p] == True):
			print(p, end=" ")

# This code is contributed by Dharanendra L V.

# Python Code for Interval tree
class Interval:
	def __init__(self, low, high):
		self.low = low
		self.high = high

	def __str__(self):
		return "[" + str(self.low) + "," + str(self.high) + "]"


class Node:
	def __init__(self, range, max):
		self.range = range
		self.max = max
		self.left = None
		self.right = None

	def __str__(self):
		return "[" + str(self.range.low) + ", " + str(self.range.high) + "] " + "max = " + str(self.max) + "\n"


def insert(root, x):
	if root == None:
		return Node(x, x.high)

	if x.low < root.range.low:
		root.left = insert(root.left, x)
	else:
		root.right = insert(root.right, x)

	if root.max < x.high:
		root.max = x.high

	return root


def inOrder(root):
	if root == None:
		return

	inOrder(root.left)
	print(root, end="")
	inOrder(root.right)


def isOverlapping(root, x):
	if root == None:
		# return a dummy interval range
		return Interval(-1, -1)

	# if x overlaps with root's interval
	if (x.low > root.range.low and x.low < root.range.high or (x.high > root.range.low and x.high < root.range.high)):
		return root.range

	elif (root.left != None and root.left.max > x.low):
		# the overlapping node may be present in left child
		return isOverlapping(root.left, x)

	else:
		return isOverlapping(root.right, x)


if __name__ == '__main__':
	root = None
	root = insert(None, Interval(15, 20))
	root = insert(root, Interval(10, 30))
	root = insert(root, Interval(17, 19))
	root = insert(root, Interval(5, 20))
	root = insert(root, Interval(12, 15))
	root = insert(root, Interval(30, 40))

	print("Inorder traversal of constructed Interval Tree is")
	inOrder(root)
	print()
	i = Interval(6, 7)
	print("Searching for interval", i)
	print("Overlaps with ", isOverlapping(root, i))

# This code is contributed by Tapesh (tapeshdua420)

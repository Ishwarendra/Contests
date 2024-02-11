def isOdd(x):
	return (x % 2 == 1)
def isEven(x):
	return (x % 2 == 0)
for _ in range(int(input())):
	a, b, c, d, k= [int(x) for x in input().split()]
	right = abs(c - a); down = abs(d - b)
	# print(right + down)
	if (right + down <= k):
		if (isOdd(right + down) and isOdd(k)) or (isEven(right + down) and isEven(k)):
			print("YES")
		else:
			print("NO")
	else:
		print("NO")

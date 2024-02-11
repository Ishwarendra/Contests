"""
1
23
4567
8912345
67891234567891
"""
def unit(x):
	return x % 10

n = 5
x = 1
for i in range(n):
	for j in range(1, (2**i)+1):
		if unit(x) == 0:
			pass
		else:
			print(unit(x), end = "")
		x += 1		
	print()

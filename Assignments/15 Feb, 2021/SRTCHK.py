t = int(input())
for i in range(t):
	n = int(input())
	a = [int(x) for x in input().split()]
	b = [int(x) for x in input().split()]
	a.sort()
	if a == b:
		print("yes")
	else:
		print("no")
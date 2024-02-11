for _ in range(int(input())):
	n = int(input())
	arr = [int(x) for x in input().split()]
	even, odd = [], []
	for i in arr:
		if (i % 2 == 0):
			even.append(i)
		else:
			odd.append(i)

	e, o = len(even), len(odd)
	if (n == 2 and (arr[0] - arr[1])%2 == 0):
		print(-1)
		continue
	if (e == 0 or o == 0):
		print(-1)
		continue
	else:
		for i in range(o):
			print(odd[i], end = " ")
		for i in range(e):
			print(even[i], end = " ")
		print()



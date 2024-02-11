def dec_to_binary(n):
	sum = 0
	while n != 0:
		x = 0
		while n >= 2**x:
			x += 1
		n -= 2**(x - 1)
		sum += 10**(x - 1)	 	
	return list(str(sum))

t = int(input())
for i in range(t):
	n = 4
	li = [] # for storing elements

	for i in range(1, n + 1):
		li.append(i)

	for j in range(2**n):
		arr = dec_to_binary(j)
		arr.reverse()
		for k in range(len(arr)):
			if arr[k] == '1':
				print(li[k], end = " ")
		print()


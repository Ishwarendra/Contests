t = int(input())
for x in range(t):
	n = int(input())
	m = int(input())
	classes = {}
	times = []
	for i in range(n):
		s, e = [int(x) for x in input().split()] # s -> start, e -> end
		if s in classes:
			classes[s] += 1
		else:
			classes[s] = 1
			times.append(s)

		if (e+1) in classes:
			classes[e+1] -= 1
		else:
			times.append(e+1)
			classes[e+1] = -1
		print(classes)
	result = 0
	sum = 0
	times.sort()	
	for i in times:
		sum += classes[i]
		result = max(result, sum)
		print(sum, result)
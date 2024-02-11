for _ in range(int(input())):
	n, k = [int(x) for x in input().split()]
	s = list(input())
	q = [int(x) for x in input().split()]
	d = 0
	s1 = [0]*n
	for i in range(1, n):
		if (s[i] == "0" and s[i-1]=="0") or (s[i] == "1" and s[i-1] == "1"):
			d += 2
		else:
			d += 1

		if (s[i] == "0"):
			s1[i] = 0
		elif (s[i] == "1"):
			s1[i] = 1

	if s[0] == "0": s1[0] = 0
	else: s1[0] = 1

	for i in range(0, k):
		j = q[i] - 1 

		if s1[j] == 0:
			s1[j] = 1
			if (s1[j-1] == 0 and j != 0): d -= 1
			elif (s1[j-1] == 1 and j != 0): d += 1
			if j != n-1 and s1[j+1] == 0 :
				d -= 1
			elif j != n-1 and s1[j+1] == 1 :
				d += 1

		elif s1[j] == 1:
			s1[j] = 0
			if (s1[j-1] == 0 and j != 0): d += 1
			elif (s1[j-1] == 1 and j != 0): d -= 1
			if  j != n-1 and s1[j+1] == 0 :
				d += 1
			elif j != n-1 and s1[j+1] == 1:
				d -= 1

		print(d)
		
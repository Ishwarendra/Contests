def getprime(n):
	prime = [2]
	for i in range(3, 10000):
		for j in range(2, i):
			if i % j == 0:
				break
		else:
			prime.append(i)
		if len(prime) == n:
			return prime
n = int(input())
for i in getprime(n):
	print(i, end = " ")

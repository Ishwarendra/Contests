def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a%b)

def getArr(n, k):
	arr = []
	for i in range(1, 2*n+1):
		arr.append(k + i**2)
	return arr
a = getArr(5, 1)
print(len(a))
for _ in range(int(input())):
	k = int(input())
	arr = getArr(k + 1, k)
	s = 0
	for i in range(1, 2*k + 1):
		s += gcd(arr[i], arr[i+1])

	print(s)
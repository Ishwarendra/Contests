def getGCD(a, b):
	if b == 0:
		return a
	if b > a:
		return getGCD(b, a)
	return getGCD(a%b, b)
    
for _ in range(int(input())):
    n = int(input())
    s = set([1,])
    for i in range(2, n):
        if getGCD(i, n) == 1:
            s.add(i)
    print(len(s))
    print(*list(s))
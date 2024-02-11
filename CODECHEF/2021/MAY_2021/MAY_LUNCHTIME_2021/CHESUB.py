for _ in range(int(input())):
	n, k = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	ans = 0
	for i in range(n):
		if a[i] > 0:
			ans += a[i]*(i+1) 

	print(ans)
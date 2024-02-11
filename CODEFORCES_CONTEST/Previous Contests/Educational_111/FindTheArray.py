def good(n, s):
	return (n*n - s >= 0)

for _ in range(int(input())):
	s = int(input())
	
	low = 0; high = s; ans = -1;
	while(low <= high):
		mid = (low + high)//2
		if good(mid, s):
			high = mid - 1
			ans = mid

		else:
			low = mid + 1

	print(ans)
	
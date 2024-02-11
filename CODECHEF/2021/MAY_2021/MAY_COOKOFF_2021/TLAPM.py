def yterm(y):
	return y*(y + 1)//2

def iTerm(x, y):
	x -= 1
	return (yterm(y) + (y)*x + x*(x-1)//2)

# print(iTerm(17, 10))

for _ in range(int(input())):
	x1, y1, x2, y2 = [int(x) for x in input().split()]
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	down = (y2 - y1 + 1); right = (x2 - x1 + 1)
	ans = 0
	for y in range(y1, y2 + 1):
		# print(iTerm(x1, y))
		ans += iTerm(x1, y)
	for x in range(x1 + 1, x2 + 1):
		# print(iTerm(x, y2))
		ans += iTerm(x, y2)
	print(ans)
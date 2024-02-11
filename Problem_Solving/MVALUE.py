def give_max_value(a,b):
	return a*b + max(a-b, b-a)

def max_val(li, n):
	maximum = 0
	for i in range(0, n):
		for j in range(i + 1, n):
			ans = give_max_value(li[i], li[j])
			if ans > maximum:
				maximum	= ans 
	return maximum

t = int(input())
for _ in range(t):
	n = int(input())
	arr = [int(x) for x in input().split()]
	print(max_val(arr, n))

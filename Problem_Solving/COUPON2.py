def sum_coupon(arr, d):
	if (sum(arr)) < 150:
		return sum(arr) + d
	return sum(arr)

def choose_couponP(arr1, arr2, c, d):
	sum_without_coupon = 2*d + sum(arr1) + sum(arr2)
	sum_with_coupon = c + sum_coupon(arr1, d) + sum_coupon(arr2, d)
	print(sum(arr2, d) ) 
	if sum_with_coupon < sum_without_coupon:
		return "YES"
	else:
		return "NO"

t = int(input())
for _ in range(t):
	d, c = [int(x) for x in input().split()]
	a = [int(x) for x in input().split()]
	b = [int(y) for y in input().split()]
	print(choose_couponP(a, b, c, d))
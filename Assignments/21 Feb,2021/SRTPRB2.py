def tournament(arr):
	if len(arr) == 2:
		if arr[0] != arr[1]:
			return 1
		else:
			return 0

	mid = len(arr)//2
	left_half = tournament(arr[:mid])
	right_half = tournament(arr[mid:])

	match1 = set(arr[:mid])
	match2 = set(arr[mid:])

	if match1 & match2:
		return left_half + right_half
	else:
		return 1 + left_half + right_half
n = int(input())
arr = [int(x) for x in input().split()]
print(tournament(arr))
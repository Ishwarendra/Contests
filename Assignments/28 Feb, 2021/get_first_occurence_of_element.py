def first_occurence(arr, x,):
	low = 0
	high = len(arr) - 1
	ans = 0
	while (low <= high) :
		mid = low + (high - low)//2
		if arr[mid] == x and x > arr[mid - 1]:
		    return mid
		if x > arr[mid]:
		    low = mid + 1
		else:
		    high = mid - 1
	return ans

arr = [1,2,3,3,3,3,3,4,5,6]
print(first_occurence(arr, 3))

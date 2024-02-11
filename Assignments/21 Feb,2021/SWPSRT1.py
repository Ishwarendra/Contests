def find_min_element_idx(arr, start):
	min_index = start
	start += 1
	while start < len(arr):
		if arr[start] < arr[min_index]:
			min_index = start
		start += 1
	return min_index

def selection_sort(arr):
	i = 0
	swaps = []
	while i < len(arr):
		min_index = find_min_element_idx(arr, i)
		if i != min_index:
			arr[i], arr[min_index] = arr[min_index], arr[i]
			swaps.append((i, min_index))
		i += 1
	return swaps
n = int(input())
a = [int(x) for x in input().split()]
swap_array = selection_sort(a)
print(len(swap_array))
for i in swap_array:
	print(*i)


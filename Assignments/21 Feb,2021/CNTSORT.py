def countingSort(array):
    size = len(array)
    output = [0] * size
    max_element = max(array)
    count = [0] * (max_element + 1)

    for i in range(0, size):
        count[array[i]] += 1

    for i in range(1, len(count)):
        count[i] += count[i - 1]
    i = size - 1
    while i >= 0:
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1
        i -= 1
    return output


t = int(input())

for _ in range(t):
	arr = []
	n = int(input())
	a = map(int, input().split())
	for i in a:
		arr.append(i)
	print(countingSort(arr))

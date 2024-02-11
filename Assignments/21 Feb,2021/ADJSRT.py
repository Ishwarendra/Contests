def Bubble_sort(arr):
    indices = []
    for i in range(0, len(arr)):
        swapped = False
        for j in range(0, len(arr)-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                indices.append(j)
                swapped = True

        if not swapped:
            return indices
    return indices

arr = [int(x) for x in input().split()]
Bubble_sort(arr)
print(arr)
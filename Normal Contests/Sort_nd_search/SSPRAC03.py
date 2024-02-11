def find_min_element_idx(arr, start):
    min_index = start
    start += 1
    while start < len(arr):
        if arr[start] < arr[min_index]:
            min_index = start
        start += 1
    return min_index

def selectionSort(arr):
    i = 0
    while i < len(arr) - 1: # since if we sort list[0:end] then element is end will be in its correct position.
        min_index = find_min_element_idx(arr, i)
        if i != min_index:
            arr[i], arr[min_index] = arr[min_index], arr[i]
        print(*arr)
        i += 1

    return
n = int(input())
arr = [int(x) for x in input().split()]
selectionSort(arr)

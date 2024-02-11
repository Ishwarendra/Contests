def last_occurence(arr, x, low, high):
    while low <= high:
        mid = low + (high - low)//2
        if arr[mid] == x and x < arr[mid + 1]:
            return mid
        if x < arr[mid]:
            return last_occurence(arr, x, low, mid - 1)
        else:
            return last_occurence(arr, x, mid + 1, high)
    return None
arr = [1,2,3,3,3,4,5,6]
print(last_occurence(arr, 7, 0, len(arr)-1))

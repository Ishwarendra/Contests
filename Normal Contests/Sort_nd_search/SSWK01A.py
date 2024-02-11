# find minimum number of operation to sort an array
def insertionSort(arr, n):
    count = 0
    for i in range(1, n):
        key = arr[i] # choosing 2nd element as key as single element is always sorted
        j  = i - 1 # checking behind index(key)
        while j >= 0 and key < arr[j]: # while key is smaller than previous element
            arr[j + 1] = arr[j] # change element at (j + 1) with (j)
            count += 1
            j -= 1
        arr[j + 1] = key # choose new key and increment i
#need to think something better than insertion.

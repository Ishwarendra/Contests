import random
 
def lessthan(x, y):
    return x[0] < y[0]
 
def quick_sort(arr, l, r):
    if r <= l:
        return
    # print(l, r)
    # # selection of pivot that is stable
    pivot_index = l
 
    # # selection of pivot that is **not** stable
    # pivot_index = random.randint(l, r)
 
    # # if your solution to this problem when the input is the subarry [arr[l], arr[l+1], ... arr[r]] (contd in next line)
    # # prints the indices candidates then this choice of pivot should be stable
    # candidates = choose_pivot(arr[l:r+1])
    # pivot_index = candidates[random.randint(0, len(candidates)-1)] + l
 
    pivot = arr[pivot_index]
 
    left_array = [] #left_array is all the elements (in order) strictly less than pivot
    right_array = [] #right_array has all the elements (in order) greater than or equal to pivot
    for index in range(l, r+1):
        if index != pivot_index and lessthan(arr[index], pivot):
            left_array.append(arr[index])
        elif index != pivot_index:
            right_array.append(arr[index])
 
    # place all elements less than pivot in the beginning
    for index in range(0, len(left_array)):
        arr[index + l] = left_array[index]
 
    # place the pivot
    arr[l + len(left_array)] = pivot
 
    # place all elements greater than or equal to pivot at the end
    for index in range(0, len(right_array)):
        arr[l + index + len(left_array) + 1] = right_array[index]
 
    # recursively sort the portion to the left of the pivot
    quick_sort(arr, l, l + len(left_array) - 1)
    # recursively sort the portion to the right of the pivot
    quick_sort(arr, l + len(left_array) + 1, r)
 
# using the function
arr = [(0, 3), (0, 1),(2,1),(1,2)]
quick_sort(arr, 0, len(arr)-1)
print(arr)
import random

def greaterThanPair(a, b): # tells if pairA < pairB
    if a[1] == b[1]:
        return a[0] < b[0]
    return a[1] > b[1]
#Quick sort giving TLE
def partition(arr, p, r):
    x = random.randrange(p,r) # pivot
    i = p - 1
    for j in range(p, r):
        if greaterThanPair(arr[j], arr[x]): # arr[j] right position is behind x or not.
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[x] = arr[x], arr[i+1]
    return (i + 1)
def QuickSort(arr, p, r):
    if p >= r:
        return
    q = partition(arr, p, r)
    QuickSort(arr, p, q-1)
    QuickSort(arr, q+1, r)

#Merge Sort
def merge(a, b):
    n = len(a); m = len(b)
    output = [0]*(n + m)
    i, j, k = 0, 0, 0
    while (i < n) and (j < m):
        if greaterThanPair(a, b):
            output[k] = a[i]
            i += 1; k += 1
        else:
            output[k] = b[j]
            j += 1; k += 1

    while j < m:
        output[k] = b[j]
        j += 1; k += 1
    while i < n:
        output[k] = a[i]
        i += 1; k += 1
    return output
def mergeSort(arr, left, right):
    if left == right:
        return arr[left]
    mid = left + (right - left)//2
    left_half = mergeSort(arr, left, mid)
    right_half = mergeSort(arr, mid + 1, right)
    return merge(left_half, right_half) 

# Making number negative so sorting in asc order is same as sorting in desc order for positive num
n = int(input())
a = [int(x) for x in input().split()]
b = [int(y) for y in input().split()]
pairs = list(zip(a,b))
pairs.sort(reverse=True)
for i in pairs:
    b, a = i
    print(-a, b, end = " ")

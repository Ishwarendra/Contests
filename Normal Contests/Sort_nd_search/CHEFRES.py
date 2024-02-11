from bisect import bisect_right as br
def func(arr, x):
    a = br(arr, x)
    if arr[a - 1] == x:
        return 0
    elif a == len(arr):
        return -1
    else:
        return arr[a] - x

for uv in range(int(input())):
    n, m = [int(x) for x in input().split()]
    element = []
    for _ in range(n):
        l, r = [int(x) for x in input().split()]
        for i in range(l, r + 1):
            element.append(i)
    element.sort()
    for _ in range(m):
        x = int(input())
        print(func(element, x))
def cutTheSticks(arr):
    li = []
    while len(arr) >= 1:
        li.append(len(arr))
        min_ = min(arr)
        arr = [i-min_ for i in arr if i!=min_]
    return li
n = int(input())
lengths = [int(x) for x in input().split()]
arr = cutTheSticks(lengths)
for i in arr:
    print(i)
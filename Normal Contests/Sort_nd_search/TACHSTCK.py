def givePairs(arr, n, d):
    pair_count = 0; i = 0
    while i < n - 1:
        if arr[i+1] - arr[i] <= d:
            pair_count += 1
            i += 2
        else:
            i += 1
    return pair_count
n, d = [int(x) for x in input().split()]
arr = []
for _ in range(n):
    x = int(input())
    arr.append(x)
arr.sort()
print(givePairs(arr, n, d))
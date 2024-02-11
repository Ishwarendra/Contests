for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    arr.sort()
    i = 1; j = k; ans = arr[k-1] - arr[0]
    while k < len(arr):
        if ans > arr[j] - arr[i]:
            ans = arr[j] - arr[i]
        j += 1; i += 1
    print(ans)
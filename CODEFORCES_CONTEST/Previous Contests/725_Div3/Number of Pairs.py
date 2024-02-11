for _ in range(int(input())):
    n, l, r = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    ans = 0; idx = n-1

    b = sorted(a)
    d = {}
    
    for i in range(n):
        d[]
    
    i = 0

    while i < n:
        j = idx
        while (j >= 0 and j != i):
            if  a[i] + a[j] <= r and l <= a[i] + a[j]:
                ans += 1
                print((i, j))
            if not(a[i] + a[j] <= r):
                idx = j - 1
            j -= 1
        i += 1

    print(ans)
            


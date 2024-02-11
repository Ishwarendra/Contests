for _ in range(int(input())):
    n = int(input())
    a = [0] + [int(x) for x in input().split()]
    ans = 0
    # print(a)
    for i in range(1, n, 1):
        for j in range(a[i] - i, n+1, a[i]):
            # print(i, j)
            if j >= 0 and a[i]*a[j] == i + j and i < j:
                ans += 1

    print(ans)

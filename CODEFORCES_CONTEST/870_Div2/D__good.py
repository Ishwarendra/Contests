def get(a):
    b = sorted(a)
    return b[-1] + b[-2] + b[-3] - len(b) + 1

# a = [1, 4, 10, 2, 2, 2, 2, 2, 2, 10, 5, 3]
# a = [5, 1, 4, 2, 4, 5, 10]
# n = len(a)
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = 0
    for l in range(0, n - 2):
        for r in range(l + 2, n):
            ans = max(ans, get(a[l:r+1]))
    print(ans)

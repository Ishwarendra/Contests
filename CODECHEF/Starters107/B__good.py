def f(x, n, k):
    return (x%k) * ((n-x)%k)

for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = (n%k)//2
    what = (k+n%k)//2
    print(n%k, k, ans, what, f(what, n, k), f(ans, n, k))
    if what <= n and f(what, n, k) > f(ans, n, k): ans = what
    print(ans)

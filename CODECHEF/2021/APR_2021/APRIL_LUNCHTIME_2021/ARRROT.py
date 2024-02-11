
n = int(input())
arr = [int(x) for x in input().split()]
ans = 0; mod = int(1e9 + 7)
for i in range(n):
    ans = (ans + arr[i] + mod)%mod
qu = int(input())
q = [int(x) for x in input().split()]
for i in range(qu):
    ans = ans*2
    print(ans%mod)

    
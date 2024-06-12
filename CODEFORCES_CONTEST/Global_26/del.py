def getSum(x):
    ans = 0
    while x > 0:
        ans += x % 10
        x //= 10
    return ans

a = 24241719478160 
print("".join(sorted(str(a))))
print(500%7)
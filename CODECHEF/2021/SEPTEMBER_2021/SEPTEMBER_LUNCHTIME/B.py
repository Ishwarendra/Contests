def sgnum3(l):
    return l if l % 3 == 0 else sgnum3(l+1)

def gsnum3(r):
    return r if r % 3 == 0 else gsnum3(r-1)

def ndiv3(l, r):
    return (r - l + 3) // 3 if l <= r else 0

def solve(l, r):
    return ndiv3(sgnum3(l), gsnum3(r))

N = int(input())
for _ in range(N):
    l, r = [int(x) for x in input().split()]
    print(solve(l, r))
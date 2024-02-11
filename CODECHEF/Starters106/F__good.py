from math import lcm 

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    def getBit(x, pos): return (x >> pos) & 1

    s = set()

    for mask in range(1 << n):
        l = 1
        for i in range(n):
            if getBit(mask, i) == 1:
                l = lcm(a[i], l)

        s.add(l)

    ans = 1
    while ans in s:
        ans += 1
    print(ans)
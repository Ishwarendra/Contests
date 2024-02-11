# a^a = 0 and a^a^a = a (0^a = a)
t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    x = 0
    for i in arr:
        x = x^i
    print(x)
from random import randint

t = 1

print(t)
for _ in range(t):
    n = 5
    a = [randint(1, 10) for i in range(n)]
    print(n)
    print(*a)
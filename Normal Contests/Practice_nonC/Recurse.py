def make1(n):
    count = 0
    if n == 2:
        return 2
    if n % 2 != 0:
        count += make1(n-1)
    else:
        count += make1(n-1)
        count += make1(n//2)
    return count

for _ in range(int(input())):
    n = int(input())
    print(make1(n))
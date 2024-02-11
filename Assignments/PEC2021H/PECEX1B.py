from math import sqrt

for _ in range(int(input())):
    n = int(input())
    result = []
    for i in range(1, int(sqrt(n)) + 1):
        for j in range(1, int(sqrt(n) + 1)):
            if i*i + j*j == n and i <= j:
                result.append([i,j])
    if len(result) >= 2:
        result.sort(key = lambda a : a[1])
        print(result[0][0], result[0][1], result[1][0], result[1][1])
    else:
        print(-1, -1, -1, -1)
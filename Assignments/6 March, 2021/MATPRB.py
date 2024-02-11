def isSymmetric(a, n):
    for i in range(0, n):
        for j in range(0, n):
            if a[i][j] != a[j][i]:
                return False
    return True
    
def isLowerTriangle(a, n):
    for i in range(0, n - 1):
        for j in range(n - 1, i, -1):
            if a[i][j] != 0:
                return False
    return True

def isUpperTriangle(a, n):
    for j in range(0, n - 1):
        for i in range(j + 1, n):
            if a[i][j] != 0:
                return False
    return True

t = int(input())
for _ in range(t):
    n = int(input())
    mat = []
    for x in range(n):
        row = [int(x) for x in input().split()]
        mat.append(row)
    
    s, t, d = 0, 0, 0
    if isSymmetric(mat, n):
        s = 1
    if isUpperTriangle(mat, n) or isLowerTriangle(mat, n):
        t = 1
    if isUpperTriangle(mat, n) and isLowerTriangle(mat, n):
        d = 1
    
    print(s + 2*t + 4*d)
def sameString(x, y):
    return set(x) == set(y)

def checkScore(key, ans, m):
    count = 0
    for i in range(m):
        if sameString(key[i], ans[i]):
            count += 1
    return count

n, m = [int(x) for x in input().split()]
key = input().split()
for i in range(n):
   ans = input().split() 
   print(checkScore(key, ans, m))

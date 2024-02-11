def nCr(n, r):
    if r == 0:
        return 1
    return n*(nCr(n-1, r-1))//r

def giveAns(n, x):
    return nCr(n-1, x-1)

for _ in range(int(input())):
    

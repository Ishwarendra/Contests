def giveTrailZeroes(n): # give trail zeroes in factorial(n)
    result = 0
    while n != 0:
        result += n//5
        n = n//5
    return result

def searchNum(n):
    low = 0; high = int(1e8); ans = "No solution"
    while low <= high:
        mid = low + (high - low)//2
        if n == giveTrailZeroes(mid):
            ans = mid
            high = mid - 1
        elif n > giveTrailZeroes(mid):
            low = mid + 1
        else:
            high = mid - 1
    return ans
n = int(input())
if n == 0:
    print(1) #no idea why they expect 1 instead of 0
else:
    print(searchNum(n))


def giveHours(total, speed):
    if total % speed == 0:
        return (total // speed)
    return (total // speed) + 1

def good(arr, mid, timeLimit):
    time = 0
    for i in arr:
        time += giveHours(i, mid)
    return (time <= timeLimit)
    
def giveK(arr, n, h):
    low = 0; high = int(1e10); ans = 0
    while low <= high:
        mid = low + (high - low)//2
        if good(arr, mid, h):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

for _ in range(int(input())):
    n, h = [int(x) for x in input().split()]
    arr = [int(x) for x in input().split()]
    print(giveK(arr, n, h))
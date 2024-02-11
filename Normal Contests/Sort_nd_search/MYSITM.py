    def good(n, h, w, mid):
        return ((mid//w)*(mid//h) >= n)


    def giveSquareEdge(n, h, w):
        low = 0; high = max(h,w)*n; ans = 0
        while low <= high:
            mid = low + (high - low)//2
            if good(n, h, w, mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans
    t = int(input())
    for _ in range(t):
        n, h, w = [int(x) for x in input().split()]
        print(giveSquareEdge(n, h, w))
for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    count = 0
    arr = [1]*(n+1)
    for b in range(2, n+1): 
        x = m%b
        print(f" b = {b} || m%b = {x}|| count = {count}  || arr = {arr} ")
        count += arr[x] 
        for p in range(x, n+1, b):
            arr[p] += 1
        print("-----------------------------------------------------------------------")
    print(count)
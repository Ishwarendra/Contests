for _ in range(int(input())):
    x, y = [int(x) for x in input().split()]
    if (y % x) != 0:
        print(-1)
    else:
        ans = 0;
        options = [2**i - 1 for i in range(1, 64)]
        ab = y//x
        for i in range(len(options) - 1, -1, -1):
            if (ab - options[i]) >= 0: # if true, biggest possible number found
                ab -= options[i]
                ans += (i + 1) 
                if ab > 0:
                    ans += 1 #1 min for break time
        #even after loop ends y "may be" a positive number (but not of the form 2**i - 1)
        if ab == 0:
            print(ans)
        else:
            print(-1)

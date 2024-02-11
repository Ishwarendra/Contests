def interval_scheduling(stimes, ftimes):
    index = list(range(len(stimes)))
    index.sort(key=lambda i: ftimes[i])
    
    maximal_set = set()
    prev_finish_time = 0
    for i in index:
        if stimes[i] >= prev_finish_time:
            maximal_set.add(i)
            prev_finish_time = ftimes[i]
 
    return maximal_set
 
 
n = int(input('Enter number of activities: '))
stimes = []
ftimes = []
for _ in range(n):
	s, e = [int(x) for x in input().split()]
	stimes.append(s)
	ftimes.append(e)
 
ans = interval_scheduling(stimes, ftimes)
print(len(ans))
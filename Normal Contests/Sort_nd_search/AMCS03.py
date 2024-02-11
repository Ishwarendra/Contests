def findDifference(s, d, t, n):
    min_ = min([s[i]*t + d[i] for i in range(n)])
    max_ = max([s[i]*t + d[i] for i in range(n)])
    return (max_ - min_) # f(t) value at any particular instant

n, k = [int(x) for x in input().split()]
s = []; d=[]
for _ in range(n):
    Si, Di = [int(x) for x in input().split()]
    s.append(Si); d.append(Di)
low = 0; high = k

for _ in range(100):
    t1 = (2*low + high)/3; t2 = (2*high +low)/3 #ternary search
    if findDifference(s, d, t1, n) < findDifference(s, d, t2, n): # if f(t2) > f(t1) then seach space is from 0 to t2
        high = t2
    else: # if f(t1) > f(t2) then search space if from t1 to end 
        low = t1
print("%.6f" %findDifference(s, d, (low + high)/2, n)) # average of low and high
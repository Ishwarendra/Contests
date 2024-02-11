n = int(input())
s = [int(x) for x in input().split()]
m = max(s)
sum = 0
for i in s: 
    sum += m - i
print(sum)
def findStar(str, nos):
	count=0
	i=0
	while(i<len(str)):
		if str[i]=="*":
			count+=1
		else:
			count=0
		if count==nos:
			return True
		i+=1
	return count>=nos


for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    s = input()
    if findStar(s, k):
        print("YES")
    else:
        print("NO")

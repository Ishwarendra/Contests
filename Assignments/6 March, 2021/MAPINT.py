def setPointPos(d, v, pos, s_name): 
    if v not in d:
        d[v] = ["", "", "", ""]
    d[v][pos] = s_name 

def processList(d, lst): 
    if lst[3] == 'W':
        lst[0], lst[1] = lst[1], lst[0]; lst[3] = 'E'
    if lst[3] == 'S':
        lst[0], lst[1] = lst[1], lst[0]; lst[3] = 'N'

    if lst[3] == 'E':
        setPointPos(d, lst[0], 0, lst[2])
        setPointPos(d, lst[1], 1, lst[2])
    else:
        setPointPos(d, lst[0], 2, lst[2])
        setPointPos(d, lst[1], 3, lst[2])


def isIntersected(lst): 
    return (lst[0] == lst[1]) and (lst[2] == lst[3]) and (lst[0] != "" and lst[2] != "")
    

def returnIntersections(d):
    sum = 0
    for i in d:
        if isIntersected(d[i]):
            sum += 1
    return sum

n = int(input())
my_dict = {}
for _ in range(n):
    a, b, c, d = input().split()
    a = int(a); b = int(b)
    arr = list([a,b,c,d])
    processList(my_dict, arr)

print(returnIntersections(my_dict))

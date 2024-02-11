a = int(input())
b = int(input())
c = int(input())

list = [a,b,c]
list.remove(max(a,b,c))

print(max(list))

/"""Way - 1: No function; only Loops
n = int(input())
a = []
for i in range(n):
    x  = int(input())
    a.append(x)
while len(a) != 1:
    x = min(a)
    a.remove(x)
    y = min(a)
    a.remove(y)
    a.append((3*x + 2*y) % 100)

print(*a)    
"""
# Way -2 : Using recursion
def Replace_recursion(lst):
    if len(lst) == 1:
        return lst
    x = min(lst)
    lst.remove(x)
    y = min(lst)
    lst.remove(y)
    value = (3*x + 2*y) % 100
    lst.append(value)
    Replace_recursion(lst)

n = int(input())
a = []
for i in range(n):
    b = int(input()) # elements of lst one by one
    a.append(b)
print(Replace_recursion(a))













import sys

def add(a, b):
    print('1', a, b) 
    sys.stdout.flush()
    return int(input())
# --------------------- Do not touch anything above this line ----------------------

# The return value of this function is wrong, write the correct version of this function using the add(a, b) ...
# function defined above.

# Note that this function should return (a ** b) % m, you are guaranteed that add(a, b) returns (a + b) % m

def mul(a, b):
    res = 0
    for i in range(0, b):
        res = add(res, a)
    return res

def pwr(a, b):
    res = 1
    for j in range(0, b):
        res = mul(res, a)
    return res


# --------------------- Do not touch anything below this line ----------------------

a, b = map(int, input().split())
ans = pwr(a, b)
print('2', ans)

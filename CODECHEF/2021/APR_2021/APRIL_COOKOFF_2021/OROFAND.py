import sys
from functools import reduce

def get_inpt(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))

def BitOR(array):
    res = reduce(lambda x, y: x | y, array)
    return res

for _ in range(get_int()):
    n, q = get_array()
    a = get_array()
    print(BitOR(a))
    for _i in range(q):
        x, v = get_array()
        a[x] = v        
        print(BitOR(a))
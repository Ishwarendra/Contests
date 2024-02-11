import time
st = time.time()
t = int(input())
count = 0
def wait(d,v):
    return (d/v)
while count < t:
    n, v1, v2 = [int(x) for x in input().split()]
    count +=1
    d_stair = n*(2**0.5)
    d_elevator = 2*n
    t_stair = wait(d_stair,v1)
    t_elevator = wait(d_elevator, v2)

    if t_stair < t_elevator:
        print("Stairs")
    else:
        print("Elevator")
e = time.time()
print(e-st)

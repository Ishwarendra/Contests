def estimate(f):
    if int(f) == f:
        return f
    return (f//1 + 1)
    
def cost(time):
    if time == 0:
        return 0
    elif time == 1:
        return 60
    else:
        return (60 + 30 * (time - 1))
t = int(input())
a = {}
price = 0

for i in range(t):
        choice = input()
        if choice == "entry":
                plate = input()
                a[plate] = int(input())
        else:
                plate = input()
                t_f = int(input())
                time = estimate((t_f - a[plate])/60)
                
                price += cost(time) 

print(int(price))   

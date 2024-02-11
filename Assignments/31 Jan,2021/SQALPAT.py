def straight(low, li):
        li.clear()
        high = low + 4
        for i in range(low, high + 1):
                li.append(i)
        return li
def reverse(low, li):
        li.clear()
        high = low + 4
        for i in range(high, low-1, -1):
                li.append(i)
        return li

n = int(input())
for i in range(1, n*5 + 1, 5):
        if i % 2 != 0:
                print(*straight(i, []))
        else:
                print(*reverse(i, []))

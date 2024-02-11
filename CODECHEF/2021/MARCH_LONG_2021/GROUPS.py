t = int(input())
for _ in range(t):
    s = input().split('0')
    count = 0
    for i in s:
        if i != '':
            count += 1
    print(count)
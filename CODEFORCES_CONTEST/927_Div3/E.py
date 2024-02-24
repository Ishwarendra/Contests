for _ in range(int(input())):
    n = int(input())
    s = input()

    length = len(s)
    cnt = [1 for i in range(length)]
    for i in range(length - 1, 0, -1):
        add = i
        while add != 0:
            cnt[add] += add
            add -= 1

    print(cnt)
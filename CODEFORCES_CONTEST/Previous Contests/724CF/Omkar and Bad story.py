for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans_found = False
    for i in a:
        if i < 0:
            ans_found = True
            break
    if ans_found:
        print("NO")
        continue

    set100 = []

    for i in range(101):
        set100.append(i)
    print("YES")
    print(101)
    print(*set100)
    print()
def C(n, r):
    if r == 0:
        return 1
    return n*(C(n-1, r-1))//r

def broken_keyboard(string, valid_letters):
    temp = 0; ans = 0; binary = []
    for char in string:
        if char in valid_letters:
            binary.append(1)
        else:
            binary.append(0)

    for i in binary:
        if i == 1:
            temp += 1
        else:
            ans += temp*(temp + 1)//2
            temp = 0

    ans += temp*(temp + 1)//2

    return ans

n, k = list(map(int, input().split()))
string = input()
valid = input().split()
print(broken_keyboard(string=string, valid_letters=valid))


# cook your dish here
def diagonalWin(a):
    return (a[0][0] == a[1][1] == a[2][2] and a[0][0] != "_") or (a[0][2]!= "_" and a[0][2] == a[1][1] == a[2][0])
def verticalWin(a):
    return (a[0][0] != "_" and a[0][0] == a[1][0] == a[2][0]) or (a[0][1] != "_" and a[0][1] == a[1][1] == a[2][1]) or (a[0][2] != "_" and a[0][2] == a[1][2] == a[2][2])
def horizontalWin(a):
    return (a[0][0] != "_" and a[0][0] == a[0][1] == a[0][2]) or (a[1][0] != "_" and a[1][0] == a[1][1] == a[1][2]) or (a[2][0] != "_" and a[2][0] == a[2][1] == a[2][2])

#--------------------------------------------------------------------------------------------#

def diagonalWinX(a):
    return (a[0][0] == a[1][1] == a[2][2] and a[0][0] == "X" and a[0][0] != "_") or (a[0][2]!= "_" and a[0][2] == a[1][1] == a[2][0] and a[0][2] == "X")
def verticalWinX(a):
    return (a[0][0] == "X" and a[0][0] != "_" and a[0][0] == a[1][0] == a[2][0]) or (a[0][1] == "X" and a[0][1] != "_" and a[0][1] == a[1][1] == a[2][1]) or (a[0][2] == "X" and a[0][2] != "_" and a[0][2] == a[1][2] == a[2][2])
def horizontalWinX(a):
    return (a[0][0] == "X" and a[0][0] != "_" and a[0][0] == a[0][1] == a[0][2]) or (a[1][0] == "X" and a[1][0] != "_" and a[1][0] == a[1][1] == a[1][2]) or (a[2][0] == "X" and a[2][0] != "_" and a[2][0] == a[2][1] == a[2][2])

#--------------------------------------------------------------------------------------------#

def diagonalWinO(a):
    return (a[0][0] == a[1][1] == a[2][2] and a[0][0] == "O" and a[0][0] != "_") or (a[0][2]!= "_" and a[0][2] == a[1][1] == a[2][0] and a[0][2] == "O")
def verticalWinO(a):
    return (a[0][0] == "O" and a[0][0] != "_" and a[0][0] == a[1][0] == a[2][0]) or (a[0][1] == "O" and a[0][1] != "_" and a[0][1] == a[1][1] == a[2][1]) or (a[0][2] == "O" and a[0][2] != "_" and a[0][2] == a[1][2] == a[2][2])
def horizontalWinO(a):
    return (a[0][0] == "O" and a[0][0] != "_" and a[0][0] == a[0][1] == a[0][2]) or (a[1][0] == "O" and a[1][0] != "_" and a[1][0] == a[1][1] == a[1][2]) or (a[2][0] == "O" and a[2][0] != "_" and a[2][0] == a[2][1] == a[2][2])

#--------------------------------------------------------------------------------------------#

def win(a):
    return diagonalWin(a) or verticalWin(a) or horizontalWin(a)
def winX(a):
    return win(a) and (diagonalWinX(a) or verticalWinX(a) or horizontalWinX(a))
def winO(a):
    return win(a) and (diagonalWinO(a) or verticalWinO(a) or horizontalWinO(a))

#--------------------------------------------------------------------------------------------#

def count(a):
    x = 0; o = 0
    for i in range(3):
        for j in range(3):
            if a[i][j] == "X":
                x += 1
            elif a[i][j] == "O":
                o += 1
    return (x, o)
def is_valid(a):
    xcount, ocount = count(a)
    # print(xcount, ocount)
    if(xcount == ocount+1 or xcount == ocount):
        if winO(a):
            if winX(a):
                return False
            if xcount == ocount:
                return True 

        if winX(a) and xcount != ocount+1:
            return False
          
        if not winO(a):
            return True

    return False

#--------------------------------------------------------------------------------------------#

for _ in range(int(input())):
    a = []
    for i in range(3):
        x = list(input())
        a.append(x)
    xcount, ocount = count(a)
    if not is_valid(a):
        print(3)
    elif winX(a) or winO(a) or (xcount + ocount == 9):
        print(1)
    else:
        print(2)






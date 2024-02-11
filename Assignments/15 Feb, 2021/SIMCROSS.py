import copy


def checkHorizontal(word, board, x, y):
    if BOARD[x][y] == "R" or BOARD[x][y] == "B":
        endY = y+len(word)-1
        if endY < len(board[0]) and (BOARD[x][endY] == "B" or BOARD[x][endY] == "R"):
            for i in range(len(word)):
                if board[x][y+i] == "." or board[x][y+i] == word[i] or board[x][y+i] == "C":
                    continue
                elif board[x][y] == "B" or board[x][y] == "R":
                    continue
                elif (board[x][y+i] == "B" or board[x][y+i] == "R") and i == len(word)-1:
                    continue
                else:

                    return False
            return True
        else:
            return False
    else:
        return False


def checkVertical(word, board, x, y):
    if BOARD[x][y] == "C" or BOARD[x][y] == "B":
        endX = x+len(word)-1
        if endX < len(board) and (BOARD[endX][y] == "B" or BOARD[endX][y] == "C"):
            for i in range(len(word)):
                if board[x+i][y] == "." or board[x+i][y] == word[i] or board[x+i][y] == "R":
                    continue
                elif board[x][y] == "B" or board[x][y] == "C":
                    continue
                elif (board[x+i][y] == "B" or board[x+i][y] == "C") and i == len(word)-1:
                    continue
                else:
                    return False
            return True
        else:
            return False
    else:
        return False


def fillHorizontal(word, board, x, y):

    board[x] = board[x][:y] + word + board[x][y+len(word):]
    return board


def fillVertical(word, board, x, y):

    for i in range(len(word)):
        board[x+i] = board[x+i][:y] + word[i] + board[x+i][y+1:]

    return board





n, m = list(map(int, input().split()))

BOARD = []
for i in range(n):
    row = input()
    row = row.replace("b", "B")
    row = row.replace("c", "C")
    row = row.replace("r", "R")
    BOARD.append(row)

w =  int(input())
words = {}

for i in range(w):
    word = input()
    words[len(word)] = word

board = copy.deepcopy(BOARD)

for x in range(n):
    for y in range(m):
        if BOARD[x][y] == "B" or BOARD[x][y] == "R":
            Y = y+1
            while BOARD[x][Y]!="B" and BOARD[x][Y]!="R":
                Y+=1
            length = Y-y+1
            if checkHorizontal(words[length], board, x, y):
                board = fillHorizontal(words[length], board, x, y)
                break
            else:
                print("Invalid")
                exit()
    
for y in range(m):
    for x in range(n):
        if BOARD[x][y] == "B" or BOARD[x][y] == "C":
            X =x+1
            while BOARD[X][y] != "B" and BOARD[X][y] != "C":
                X+=1
            length = X-x+1
            if checkVertical(words[length], board, x, y):
                board = fillVertical(words[length], board, x, y)
                break
            else:
                print("Invalid")
                exit()

for row in board:
    print(row)
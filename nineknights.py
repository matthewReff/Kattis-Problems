def nineKnights():
    numKnights = 0
    board = []
    boardString = ""
    board.append(".........")
    board.append(".........")
    valid = True
    for i in range(0, 5):
        boardString = raw_input()
        board.append(".." + boardString + "..")
    board.append(".........")
    board.append(".........")
    for i in range(2,7, 1):
        for j in range(2,7,1):
            if board[i][j] == 'k':
                numKnights += 1
                if board[i+2][j+1] == 'k':
                    valid = False
                if board[i+2][j-1] == 'k':
                    valid = False
                if board[i-2][j+1] == 'k':
                    valid = False
                if board[i-2][j-1] == 'k':
                    valid = False
                if board[i+1][j+2] == 'k':
                    valid = False
                if board[i+1][j-2] == 'k':
                    valid = False
                if board[i-1][j+2] == 'k':
                    valid = False
                if board[i-1][j-2] == 'k':
                    valid = False
    if numKnights != 9:
        valid = False
    if valid:
        print "valid"
    else:
        print "invalid"
nineKnights()
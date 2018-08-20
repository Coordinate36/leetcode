def input():
    string = raw_input("")
    M, N = [int(num) for num in string.split(',')]
    board = []
    for i in xrange(M):
        string = raw_input("")
        row = [int(num) for num in string.split(',')]
        board.append(row)
    return M, N, board

def get_one(M, N, x, board):
    for i in xrange(x, M):
        for j in xrange(N):
            if board[i][j] == 1:
                return i, j
    return None, None

def dfs(M, N, x, y, board):
    stack = [(x, y)]
    board[x][y] = 0
    count = 0
    while stack:
        x, y = stack.pop()
        count += 1
        if x - 1 >= 0:
            if board[x - 1][y]:
                stack.append((x - 1, y))
                board[x - 1][y] = 0
            if y - 1 >= 0 and board[x - 1][y - 1]:
                stack.append((x - 1, y - 1))
                board[x - 1][y - 1] = 0
            if y + 1 < N and board[x - 1][y + 1]:
                stack.append((x - 1, y + 1))
                board[x - 1][y + 1] = 0
        if x + 1 < M:
            if board[x + 1][y]:
                stack.append((x + 1, y))
                board[x + 1][y] = 0
            if y - 1 >= 0 and board[x + 1][y - 1]:
                stack.append((x + 1, y - 1))
                board[x + 1][y - 1] = 0
            if y + 1 < N and board[x + 1][y + 1]:
                stack.append((x + 1, y + 1))
                board[x + 1][y + 1] = 0
        if y - 1 >= 0 and board[x][y - 1]:
            stack.append((x, y - 1))
            board[x][y - 1] = 0
        if y + 1 < N and board[x][y + 1]:
            stack.append((x, y + 1))
            board[x][y + 1] = 0
    return count

def main():
    M, N, board = input()
    group_num = 0
    max_count = 0
    last_x, last_y = 0, 0
    while True:
        x, y = get_one(M, N, last_x, board)
        if x is None:
            print("%s,%s" % (group_num, max_count))
            return
        group_num += 1
        max_count = max(max_count, dfs(M, N, x, y, board))
        last_x, last_y = x, y

main()

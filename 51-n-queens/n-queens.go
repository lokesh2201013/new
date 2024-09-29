func isSafe(board []string, row, col, n int) bool {
    for i := 0; i < col; i++ {
        if board[row][i] == 'Q' {
            return false
        }
    }
    for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
        if board[i][j] == 'Q' {
            return false
        }
    }
    for i, j := row, col; i < n && j >= 0; i, j = i+1, j-1 {
        if board[i][j] == 'Q' {
            return false
        }
    }
    return true
}

func give(res *[][]string, board []string, col, n int) {
    if col == n {
        solution := make([]string, n)
        copy(solution, board)
        *res = append(*res, solution)
        return
    }
    for i := 0; i < n; i++ {
        if isSafe(board, i, col, n) {
            row := []rune(board[i])
            row[col] = 'Q'
            board[i] = string(row)
            give(res, board, col+1, n)
            row[col] = '.'
            board[i] = string(row)
        }
    }
}

func solveNQueens(n int) [][]string {
    res := [][]string{}
    board := make([]string, n)
    for i := range board {
        board[i] = string(make([]rune, n))
        for j := range board[i] {
            board[i] = board[i][:j] + "." + board[i][j+1:]
        }
    }
    give(&res, board, 0, n)
    return res
}

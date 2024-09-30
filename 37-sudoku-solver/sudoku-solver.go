func isvalid(b *[][]byte, st int, i, j int) bool {
    c := byte(st + '0')
    for row := 0; row < len((*b)); row++ {
        if (*b)[row][j] == c {
            return false
        }
    }
    for col := 0; col < len((*b)[0]); col++ {
        if (*b)[i][col] == c {
            return false
        }
    }
    boxRowStart := (i / 3) * 3
    boxColStart := (j / 3) * 3
    for row := boxRowStart; row < boxRowStart+3; row++ {
        for col := boxColStart; col < boxColStart+3; col++ {
            if (*b)[row][col] == c {
                return false
            }
        }
    }
    return true
}

func solve(b *[][]byte) bool {
    for i := 0; i < len(*b); i++ {
        for j := 0; j < len((*b)[0]); j++ {
            if (*b)[i][j] == '.' {
                for st := 1; st <= 9; st++ {
                    if isvalid(b, st, i, j) {
                        (*b)[i][j] = byte(st + '0')
                        if solve(b) {
                            return true
                        }
                        (*b)[i][j] = '.'
                    }
                }
                return false
            }
        }
    }
    return true
}

func solveSudoku(b [][]byte) {
    solve(&b)
}
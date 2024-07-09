
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func give(n []int, dp []int, i int) int {
    if i < 0 {
        return 0
    }
    if i == 0 {
        return n[0]
    }
    if dp[i] != -1 {
        return dp[i]
    }
    robCurrent := n[i] + give(n, dp, i-2)
    skipCurrent := give(n, dp, i-1)
    dp[i] = max(robCurrent, skipCurrent)
    return dp[i]
}

func rob(n []int) int {
    if len(n) == 0 {
        return 0
    }
    if len(n) == 1 {
        return n[0]
    }
    dp := make([]int, len(n))
    for i := range dp {
        dp[i] = -1
    }
    return give(n, dp, len(n)-1)
}

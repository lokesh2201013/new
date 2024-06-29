func give(i int,n []int,dp []int)int{
    if i < 0 {
       return 0
    }
    if dp[i] != -1{
        return dp[i]
    }
    rob:=n[i] + give(i-2,n,dp)
    notrob := give(i-1,n,dp)
    dp[i]=max(rob,notrob)
    return dp[i]
}
func rob(n []int) int {
    dp:=make([]int ,len(n))
    for i:= range dp{
        dp[i]=-1
    }
    return give(len(n)-1,n,dp)
}
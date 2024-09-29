func getPermutation(n int, k int) string {
    fact := 1
    num := []int{}
    
    for i := 1; i < n; i++ {
        fact *= i
        num = append(num, i)
    }
    num = append(num, n)
    
    a := ""
    k--
    
    for {
        a += strconv.Itoa(num[k/fact])
        num = append(num[:k/fact], num[k/fact+1:]...)
        if len(num) == 0 {
            break
        }
        k %= fact
        fact /= len(num)
    }
    
    return a
}
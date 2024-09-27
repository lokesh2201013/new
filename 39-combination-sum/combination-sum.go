package main

func give(i, t int, arr []int, a *[][]int, ds []int) {
    if i == len(arr) {
        if t == 0 {
            com := append([]int{}, ds...) // copy ds to avoid reference issues
            *a = append(*a, com)
        }
        return
    }

    if arr[i] <= t {
        ds = append(ds, arr[i])   // choose current element
        give(i, t-arr[i], arr, a, ds) // explore with the current element
        ds = ds[:len(ds)-1]       // backtrack
    }

    give(i+1, t, arr, a, ds)  // explore without the current element
}

func combinationSum(c []int, t int) [][]int {
    var a [][]int
    var ds []int
    give(0, t, c, &a, ds)
    return a
}

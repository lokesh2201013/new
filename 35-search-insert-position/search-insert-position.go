
func searchInsert(n []int, t int) int {
    l := 0
    r := len(n) - 1
    for l <= r {
        mid := l + (r - l) / 2
        if n[mid] == t {
            return mid
        } else if n[mid] > t {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l
}
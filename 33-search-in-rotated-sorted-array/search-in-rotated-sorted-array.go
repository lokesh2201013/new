func search(n []int, t int) int {
    l, r := 0, len(n)-1
    for l <= r {
        mid := l + (r-l)/2
        if n[mid] == t {
            return mid
        } else if n[l] <= n[mid] {
            if n[l] <= t && t < n[mid] {
                r = mid - 1
            } else {
                l = mid + 1
            }
        } else {
            if n[mid] < t && t <= n[r] {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
    return -1
}
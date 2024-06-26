func minDays(b []int, m, k int) int {
	l := math.MaxInt32
	r := math.MinInt32

	for _, num := range b {
		if num < l {
			l = num
		}
		if num > r {
			r = num
		}
	}
mx:=r
	for l <= r {
		mid := l + (r-l)/2
		days := 0
		for i := 0; i < len(b); i++ {
			if b[i] <= mid {
				consecutive := 0
				for j := i; j < len(b) && j-i < k; j++ {
					if b[j] <= mid {
						consecutive++
					} else {
						break
					}
				}
				i += consecutive - 1 
				if consecutive >= k {
					days++
				}
			}
		}
		if days >= m {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
     if l>mx{
        return -1
     }
	return l
}

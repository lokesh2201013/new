func minEatingSpeed(p []int, h int) int {
	sort.Ints(p)
	l, r := 1, p[len(p)-1]

	for l <= r {
		mid := l + (r-l)/2
		c := 0

		for i := 0; i < len(p); i++ {
			c += (p[i] + mid - 1) / mid
		}

		if c > h {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	return l
}

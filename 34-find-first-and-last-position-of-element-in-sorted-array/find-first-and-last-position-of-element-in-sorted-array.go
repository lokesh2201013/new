func searchRange(n []int, t int) []int {
	lower := sort.SearchInts(n, t)
	upper := sort.SearchInts(n, t+1) - 1
	f, l := -1, -1
	
	if lower < len(n) && n[lower] == t {
		f = lower
		l = upper
	}
	
	return []int{f, l}
}
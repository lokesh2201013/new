
func maxAdjacentDistance(n []int) int {
	if len(n) < 2 {
		return 0 
	}

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	abs := func(x int) int {
		if x < 0 {
			return -x
		}
		return x
	}

	s := 0
	for i := 0; i < len(n)-1; i++ {
		s = max(s, abs(n[i]-n[i+1]))
	}

	if len(n) >= 3 {
		ps := abs(n[0] - n[len(n)-1])
		if ps > s {
			return ps
		}
	}

	return s
}

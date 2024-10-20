func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}


func scoreOfString(s string) int {
	sum := 0
	for i := 0; i < len(s)-1; i++ {
		part := abs(int(s[i]) - int(s[i+1])) 
		sum += part
	}
	return sum
}
func maxFrequency(nums []int, k int) int {
	sort.Ints(nums)
	total := 0
	left := 0
	maxFreq := 1

	for right := 0; right < len(nums); right++ {
		total += nums[right]
		for nums[right]*(right-left+1) > total+k {
			total -= nums[left]
			left++
		}
		if maxFreq < right-left+1 {
			maxFreq = right - left + 1
		}
	}

	return maxFreq
}

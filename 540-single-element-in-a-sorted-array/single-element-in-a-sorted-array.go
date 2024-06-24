func singleNonDuplicate(nums []int) int {
    l, r := 0, len(nums)-1
    
    if len(nums) == 1 {
        return nums[0]
    }
    if nums[0] != nums[1] {
        return nums[0]
    }
    if nums[len(nums)-1] != nums[len(nums)-2] {
        return nums[len(nums)-1]
    }
    
    l++
    r--
    
    for l <= r {
        mid := l + (r - l) / 2
        
        if nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1] {
            return nums[mid]
        }
        
        if (mid % 2 == 0 && nums[mid] == nums[mid+1]) || (mid % 2 == 1 && nums[mid] == nums[mid-1]) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    
    return -1 
}

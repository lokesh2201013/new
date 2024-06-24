func longestSubarray(n []int, li int) int {
    i := list.New() 
    d := list.New() 
    m, l := 0, 0

    for r := 0; r < len(n); r++ {
 
        for i.Len() > 0 && n[r] < i.Back().Value.(int) {
            i.Remove(i.Back())
        }
        i.PushBack(n[r])

        for d.Len() > 0 && n[r] > d.Back().Value.(int) {
            d.Remove(d.Back())
        }
        d.PushBack(n[r])

        for d.Front().Value.(int)-i.Front().Value.(int) > li {
            if n[l] == d.Front().Value.(int) {
                d.Remove(d.Front())
            }
            if n[l] == i.Front().Value.(int) {
                i.Remove(i.Front())
            }
            l++
        }

        if m < r-l+1 {
            m = r - l + 1
        }
    }

    return m
}

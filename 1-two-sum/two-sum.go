func twoSum(n []int, t int) []int {
    for i:=0;i<len(n)-1;i++{
        for j:=i+1;j<len(n);j++{
            if n[i]+n[j]==t{
                var ne []int
                ne=append(ne,i)
                 ne=append(ne,j)
                return ne
            }
        }
      
    }
      return []int{}
}
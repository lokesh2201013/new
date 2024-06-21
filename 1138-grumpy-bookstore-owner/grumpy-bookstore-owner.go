func maxSatisfied(c []int, g []int, mi int) int {
    n:=len(c)
    bc:=0
    for i:=0 ;i<n ; i++{
        if g[i]==0{
            bc+=c[i]
        }
    }
    es:=0
    for i:=0 ; i<mi ; i++{
        if g[i]==1{
            es+=c[i]
        }
    }
   mxs :=es
   for i:=mi ;i<n; i++{
    if g[i]==1{
        es+=c[i]
    }
    if g[i-mi]==1{
        es-=c[i-mi]
    }
    if es>mxs{
        mxs=es
    }
   }
return bc+mxs

}
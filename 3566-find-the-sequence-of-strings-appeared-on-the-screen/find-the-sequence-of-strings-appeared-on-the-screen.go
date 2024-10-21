func stringSequence(t string) []string {
    a := make([]string, 0)
    s := "a"
    a = append(a, s)
    i := 0

    for s != t {
        if s[i] == t[i] {
            i++
            s += "a"
            a = append(a, s)
        } else {
            for s[i] != t[i] {
                s = s[:i] + string(s[i]+1) + s[i+1:] 
                a = append(a, s)
            }
        }
    }
    return a
}

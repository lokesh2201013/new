func reverseParentheses(s string) string {
    var stack []rune
    for _, ch := range s {
        if ch == ')' {
            var temp []rune
            for len(stack) > 0 && stack[len(stack)-1] != '(' {
                temp = append(temp, stack[len(stack)-1])
                stack = stack[:len(stack)-1]
            }
            if len(stack) > 0 {
                stack = stack[:len(stack)-1]
            }
            stack = append(stack, temp...)
        } else {
            stack = append(stack, ch)
        }
    }
    return string(stack)
}
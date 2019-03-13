func isValid(s string) bool {
    if s == "" {
        return true
    }
    
    if len(s) % 2 == 1 {
        return false
    }
    
    match_map := map[rune]rune{'(': ')', '{': '}', '[': ']'}
    pop_stack := []rune{}
    
    for _, chr := range(s) {
        if _, ok := match_map[chr]; ok {
            pop_stack = append(pop_stack, chr)
        } else if len(pop_stack) >= 1 && chr == match_map[pop_stack[len(pop_stack) - 1]] {
            pop_stack = pop_stack[:len(pop_stack) - 1]       
        } else {
            return false
        }
    }
    
    return len(pop_stack) == 0
}
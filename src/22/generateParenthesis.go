func recursive(left, right int, num int, item string, res *[]string) {
    if left == num && right == num {
        *res = append(*res, item)
        return
    }
    
    if left < num {
        recursive(left + 1, right, num, item + "(", res)
    }
    if right < left {
        recursive(left, right + 1, num, item + ")", res)
    }
    
}

func generateParenthesis(n int) []string {
    res := []string{}
    recursive(0, 0, n, "", &res)
    return res
}
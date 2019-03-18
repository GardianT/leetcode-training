import "sort"

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func longestValidParentheses(s string) int {
    if len(s) == 0 {
        return 0
    }
    
    st, bitmap := []int{}, []int{}
    for i, val := range(s) {
        if (val == '(') {
            st = append(st, i)
        } else if (len(st) > 0) {
            bitmap = append(bitmap, st[len(st) - 1])
            bitmap = append(bitmap, i)
            st = st[:len(st) - 1]
        }
    }
    if len(bitmap) == 0 {
        return 0
    }
    sort.Sort(sort.IntSlice(bitmap))
    tmp, res := 1, 0
    for i := 1; i < len(bitmap); i++ {
        if bitmap[i] == bitmap[i - 1] + 1 {
           tmp += 1 
        } else {
            res = max(res, tmp)
            tmp = 1
        }
    }
    return max(tmp, res)
}
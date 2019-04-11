func dfs(k, n int, current []int, res *[][]int) {
    if k < 0 {
        return
    }
    if n == 0 {
        if k == 0 {
			// go复制数组的一种比较好做的方法
			// 另一种方法arr := []int{1, 2, 3}
			// tmp := make([]int, len(arr))
			// copy(tmp, arr)
			// 类似python的方法，比如 tmp := current[:], 是不行的
            tmp := append([]int{}, current...)
            *res = append(*res, tmp)
        }
    } else {
        i := 0
        if len(current) > 0 {
            i = current[len(current) - 1]
        }
        for i = i + 1; i <= 9; i++ {
            if i > n {
                break
            } else {
                current = append(current, i)
                dfs(k - 1, n - i, current, res)
                current = current[:len(current) - 1]
            }
        }
    }
}

func combinationSum3(k int, n int) [][]int {
    res := [][]int{}
    dfs(k, n, []int{}, &res)
    return res
}
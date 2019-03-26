import "strconv"

func getFactorial(n int) int {
    res := 1
    for i := 2; i <= n; i++ {
        res *= i
    }
    return res
}

func makeRange(min, max int) []int {
    res := make([]int, max - min + 1)
    for i := range res {
        res[i] = min + i
    }
    return res
}

func remove(target []int, i int) []int {
    return append(target[:i], target[i + 1:]...)
}

func getPermutation(n int, k int) string {
    rangeSlice := makeRange(1, n)
    res := ""
    for {
        if len(rangeSlice) == 0 {
            break
        } else if len(rangeSlice) == 1 {
            res += strconv.Itoa(rangeSlice[0])
            break
        } else {
            count := getFactorial(n - 1)
            i := (k - 1) / count 
            res += strconv.Itoa(rangeSlice[i])
            rangeSlice = remove(rangeSlice, i)
            k -= i * count
            n--
        }
    }
    return res
}
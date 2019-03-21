import "math"

func min(nums ...int) int {
    res := math.MaxInt64
    for _, val := range nums {
        if val < res {
            res = val
        }
    }
    return res
}

func minDistance(word1 string, word2 string) int {
    len1, len2 := len(word1), len(word2)
    if len1 == 0 && len2 == 0 {
        return 0
    }
    array1 := []int{} 
    for i := 0; i < len1 + 1; i++ {
        array1 = append(array1, i)
    }
    for i := 1; i < len2 + 1; i++ {
        array2 := []int{i}
        for j := 1; j < len1 + 1; j++ {
            if word1[j - 1] == word2[i - 1] {
                array2 = append(array2, array1[j - 1])                
            } else {
                array2 = append(array2, min([]int{array1[j], array1[j - 1], array2[j - 1]}...) + 1)
            }
        }
        array1 = array2
    }
    return array1[len(array1) - 1]
}
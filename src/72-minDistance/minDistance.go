// Q：
// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
// 示例 1:
// 输入: word1 = "horse", word2 = "ros"
// 输出: 3
// 解释: 
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2:
// 输入: word1 = "intention", word2 = "execution"
// 输出: 5
// 解释: 
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

// 思路：动态规划。主要是这里的方程是什么意思，怎么解释很难。
// 很容易想到的是，先拉一个二维 i*j的数组。i和j分别代表两个字符串长度。
// 那每一行（or每一列）怎么解释
// 比如第一行，就是把长度为i的那个字符串转换成 j的第一个字符 所需要的操作步骤。
// 比如hello world，那就是把hello转换成w 所需要的操作步骤
// 同理第二行就是把长度为i那个字符转换成j的前两个字符 所需要的操作步骤。对应hello转换成wo这样。
// 可以得知我们需要的就是这个 i*j 数组最后一个元素的最小值。
// 那这个方程如何解：
// f(i, j) = f(i - 1, j - 1) if str[i] == str[j] 当两个字符相等的时候，可以不需要额外操作，所以就直接等于斜对角那个操作的值
// else
// f(i, j) = min(f(i - 1, j - 1), f(i - 1, j), f(i, j - 1)) + 1
// 分别代表 
// f(i - 1, j - 1) + 1: 通过i - 1, j - 1的状态，更新一个字符操作实现
// f(i - 1, j) + 1: 通过i - 1, j的状态，在i字符串增加一个字符实现
// f(i, j - 1) + 1: 通过i， j - 1的状态，在j字符串增加一个字符实现
// 这里还可以做更进一步的内存优化。比如我们不需要直接new出来整个二维数组。我们只需要每次index变换的前面那行数据即可了。
// 不过这个说起来简单，实现起来可能还需要很多细节注意
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
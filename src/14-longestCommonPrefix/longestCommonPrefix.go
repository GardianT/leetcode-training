// Q：
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"
// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""
// 解释: 输入不存在公共前缀。

// 思路：按照len排序，按照最短的那个跟其他的去比较最大前缀。
// 还有个更简单的思路：直接字符串排序，比较最大和最小的公共前缀。
import "sort"

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	sort.Slice(strs, func(i, j int) bool {
		return len(strs[i]) < len(strs[j])
	})

	res := []byte{}

	for i := 0; i < len(strs[0]); i++ {
		for j := 1; j < len(strs); j++ {
			if strs[j][i] != strs[0][i] {
				return string(res)
			}
		}
		res = append(res, strs[0][i])
	}

	return string(res)
}


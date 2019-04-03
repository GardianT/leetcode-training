// Q：
// 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 被读作  "one 1"  ("一个一") , 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
// 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
// 注意：整数顺序将表示为一个字符串。
// 示例 1:
// 输入: 1
// 输出: "1"
// 示例 2:
// 输入: 4
// 输出: "1211"
import "strconv"

func countRepeat(target string, index int) (string, int) {
    element, count := target[index], 1
    for {
        index++
        if index < len(target) {
            if target[index] != element {
                break
            } else {
                count++
            }
        } else {
            break
        }
	}
    return string(element), count
}

func countAndSay(n int) string {
    if n <= 4 {
        return map[int]string{
            1: "1",
            2: "11",
            3: "21",
            4: "1211",
        }[n]
    } else {
        last := countAndSay(n - 1)
        index, res := 0, ""
        for {
            if index >= len(last) {
                return res
            }
            element, repeatedCount := countRepeat(last, index)
            res += strconv.Itoa(repeatedCount)
            res += element
            index += repeatedCount
        }
    }
}


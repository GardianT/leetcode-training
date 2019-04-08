// Q:
// 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

// 思路1：基础解法
func hammingWeight(num uint32) int {
    res := 0
    for {
        if num != 0 {
            res += int(num & 1)
            num = num >> 1
        } else {
            break
        }
    }
    return res
}
// 思路2：取余
// func hammingWeight(num uint32) int {
//     res := 0
//     for {
//         if num != 0 {
//             res += int(num % 2)
//             num = num >> 1
//         } else {
//             break
//         }
//     }
//     return res
// }
// 思路3：直接去掉位置靠后的1
// func hammingWeight(num uint32) int {
//     res := 0
//     for {
//         if num != 0 {
//             res++
//             num &= num - 1
//         } else {
//             break
//         }
//     }
//     return res
// }
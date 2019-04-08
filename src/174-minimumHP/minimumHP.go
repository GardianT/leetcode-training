// Q:
// 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
// 为了尽快到达公主，骑士决定每次只向右或向下移动一步。
// 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
// 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。
// -2 (K)	-3	3
// -5	-10	1
// 10	30	-5 (P)
// 说明:
// 骑士的健康点数没有上限。
// 任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

// 思路：dp，但是从k到p的dp实在太难写了，所以反向dp，从p出发到k，数组中的状态代表到这个位置的时候你应该剩下的最少血量
// 很明显（1）这个血量不应该在1以下。（2）下方和右方的最小血量值，决定的这个位置自身的最小血量值。
// 牵扯到一个优化的操作，就是dp你不需要init整个二维数组，你实际操作的只有两行。

// import "math"
// func min(nums ...int) int {
//     res := math.MaxInt64
//     for _, val := range nums {
//         if val < res {
//             res = val
//         }
//     }
//     return res
// }

// func max(nums ...int) int {
//     res := -(math.MaxInt64 - 1)
//     for _, val := range nums {
//         if val > res {
//             res = val
//         }
//     }
//     return res
// }

func min(i, j int) int {
    if i > j {
        return j
    }
    return i
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func calculateMinimumHP(dungeon [][]int) int {
    // 分别表示当前行和上一行
    dp_last, dp := []int{}, []int{}    
    last_raw := dungeon[len(dungeon) - 1]
    dp_last = []int{max(1, 1 - last_raw[len(last_raw) - 1])}
	// 初始化最后一行的状态
	for i := len(last_raw) - 2; i >= 0; i-- {
        dp_last = append([]int{max(1, dp_last[0] - last_raw[i])}, dp_last...)
    }
    for i:= len(dungeon) - 2; i >= 0; i-- {
        for j := len(dungeon[i]) - 1; j >= 0; j-- {
            if len(dp) == 0 {
                dp = []int{max(1, dp_last[j] - dungeon[i][j])}
            } else {
                dp = append([]int{max(1, min(dp[0], dp_last[j]) - dungeon[i][j])}, dp...)
            }
        }
        dp_last = dp
        dp = []int{}
    }
    return dp_last[0]
}
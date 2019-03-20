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


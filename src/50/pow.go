func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func myPow(x float64, n int) float64 {
    res := 1.0
    an := abs(n)
    for {
        if an != 0 {
            if an % 2 != 0 {
                res *= x
            }
            x *= x
            an /= 2
        } else {
            break
        }
    }
    
    if n < 0 {
        return 1.0 / res
    }
    return res
}
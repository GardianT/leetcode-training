/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    tmp := &ListNode{Val: 0}
    res := tmp
    carry := 0
    
    for {
        if l1 == nil && l2 == nil {
            break
        }
        l1val, l2val := 0, 0
        if l1 != nil {
            l1val = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            l2val = l2.Val
            l2 = l2.Next
        }
        val := carry + l1val + l2val
        if val >= 10 {
            val %= 10
            carry = 1
        } else {
            carry = 0
        }
        tmp.Next = &ListNode{Val: val}
        tmp = tmp.Next
    }
    if carry == 1 {
        tmp.Next = &ListNode{Val: 1}
    }
    return res.Next
}
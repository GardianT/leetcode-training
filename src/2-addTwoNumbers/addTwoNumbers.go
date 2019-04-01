// Q:
// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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
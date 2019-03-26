/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func partition(head *ListNode, x int) *ListNode {
    dummyHead1, dummyHead2 := &ListNode{Val: 0}, &ListNode{Val: 0}
    n1, n2 := dummyHead1, dummyHead2
    for {
        if head != nil {
            if head.Val < x {
                n1.Next = head
                head = head.Next
                n1 = n1.Next
                n1.Next = nil
            } else {
                n2.Next = head
                head = head.Next
                n2 = n2.Next
                n2.Next = nil
            }
        } else {
            break
        }
    }
    n1.Next = dummyHead2.Next
    return dummyHead1.Next
}
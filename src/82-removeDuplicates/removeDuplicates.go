/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func deleteDuplicates(head *ListNode) *ListNode {
    dummyHead := &ListNode{Val: 0}
    dummyHead.Next = head
    head = dummyHead
    for {
        if dummyHead.Next != nil {
            n1, n2 := dummyHead.Next, dummyHead.Next
            for {
                if n2.Next != nil && n2.Next.Val == n1.Val {
                    n2 = n2.Next
                } else {
                    break
                }
			}
			if n1 != n2 {
				dummyHead.Next = n2.Next
			} else {
				dummyHead = dummyHead.Next
			}
        } else {
            break
        }
    }
    return head.Next
}

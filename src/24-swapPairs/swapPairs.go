/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func swapPairs(head *ListNode) *ListNode {
    dummyHead := &ListNode{}
    dummyHead.Next = head
    
    p := dummyHead
    for p.Next != nil && p.Next.Next != nil {
        node1, node2, node3 := p.Next, p.Next.Next, p.Next.Next.Next
        node2.Next, node1.Next, p.Next = node1, node3, node2
        p = node1
    }
    
    return dummyHead.Next
}
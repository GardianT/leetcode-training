// Q：
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
// 示例:
// 给定 1->2->3->4, 你应该返回 2->1->4->3.

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
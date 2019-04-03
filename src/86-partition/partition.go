// Q：
// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
// 你应当保留两个分区中每个节点的初始相对位置。
// 示例:
// 输入: head = 1->4->3->2->5->2, x = 3
// 输出: 1->2->2->4->3->5

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
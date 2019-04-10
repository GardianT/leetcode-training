// Q:
// 删除链表中等于给定值 val 的所有节点。
// 示例:
// 输入: 1->2->6->3->4->5->6, val = 6
// 输出: 1->2->3->4->5

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeElements(head *ListNode, val int) *ListNode {
    dummy := &ListNode{Val: 0}
    res := dummy
    dummy.Next = head
    for {
        if dummy != nil && dummy.Next != nil {
            if dummy.Next.Val == val {
                dummy.Next = dummy.Next.Next
            } else {
                dummy = dummy.Next
            }
        } else {
            break
        }
    }
    return res.Next
}
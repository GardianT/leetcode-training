// Q：
// 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
// 示例 1:
// 输入: 1->2->3->3->4->4->5
// 输出: 1->2->5
// 示例 2:
// 输入: 1->1->1->2->3
// 输出: 2->3
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

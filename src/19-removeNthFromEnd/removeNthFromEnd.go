// Q：
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
// 示例：
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
// 当删除了倒数第二个节点后，链表变为 1->2->3->5.

// 思路：快慢指针，让一个指针先跑n，然后两个指针同时跑。
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
    first, second := head, head
    for i := 0; i < n; i++ {
        if first.Next == nil {
            return second.Next
        }
        first = first.Next
    }
    
    for ; first.Next != nil; first = first.Next {
        second = second.Next
    }
    
    second.Next = second.Next.Next;
    return head
}
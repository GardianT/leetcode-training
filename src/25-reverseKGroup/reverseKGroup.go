// Q：
// 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
// 示例 :
// 给定这个链表：1->2->3->4->5
// 当 k = 2 时，应当返回: 2->1->4->3->5
// 当 k = 3 时，应当返回: 3->2->1->4->5
// 说明 :
// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 思路：交换k个链表节点的首尾关系即可
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reverseKGroup(head *ListNode, k int) *ListNode {
    dummy := head
    
    for i := 0; i < k; i++ {
        if dummy == nil {
            return head
        }
        dummy = dummy.Next
    }
    
    dummy = head
    for i := 0; i < k - 1; i++ {
        n2 := dummy.Next
        dummy.Next, head, n2.Next = n2.Next, n2, head
    }
    
    dummy.Next = reverseKGroup(dummy.Next, k)
    return head
}
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
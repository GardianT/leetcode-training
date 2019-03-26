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
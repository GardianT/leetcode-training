/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func rotateRight(head *ListNode, k int) *ListNode {
    listLen := 0 
    for tmp := head; tmp != nil; tmp = tmp.Next {
        listLen++
    }
    
    if listLen == 0 {
        return head
    }
    
    k = k % listLen
    if k == 0 {
        return head
    }
    
    n1, n2 := head, head
    for i := 0; i < k; i++ {
        n2 = n2.Next
    }
    for {
        if n2.Next == nil {
            res := n1.Next
            n2.Next = head
            n1.Next = nil
            return res
        } else {
            n1 = n1.Next
            n2 = n2.Next
        }
    }
}
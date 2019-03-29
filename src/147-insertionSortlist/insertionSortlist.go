/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func insertionSortList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    dummyHead := &ListNode{Val: 0}
    dummyHead.Next = head
    for {
        if head.Next != nil {
            if head.Next.Val < head.Val {
                need_insert := head.Next
                head.Next = head.Next.Next
                tmp := dummyHead.Next
                for {
                    if tmp.Next == nil || tmp.Next.Val > need_insert.Val {
                        break
                    } else {
                        tmp = tmp.Next
                    }
                }    
                if tmp == dummyHead.Next && tmp.Val > need_insert.Val {
                    need_insert.Next = tmp
                    dummyHead.Next = need_insert
                } else {
                    need_insert.Next = tmp.Next
                    tmp.Next = need_insert
                }
            } else {
                head = head.Next
            }
        } else {
            break
        }
    }
    return dummyHead.Next
}
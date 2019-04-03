// Q:
// 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func findListMid(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    n1, n2, res := head, head, head
    for {
        if n2 != nil && n2.Next != nil {
            res = n1
            n1 = n1.Next
            n2 = n2.Next.Next
        } else {
            break
        }
    }
    return res
}

func merge(l1, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    } else if l2 == nil {
        return l1
    }
    dummyHead := &ListNode{Val: 0}
    res := dummyHead
    for {
        if l1 != nil && l2 != nil {
            if l1.Val < l2.Val {
                dummyHead.Next, l1 = l1, l1.Next
            } else {
                dummyHead.Next, l2 = l2, l2.Next
            }
            dummyHead = dummyHead.Next
        } else {
            if l1 != nil {
                dummyHead.Next = l1
            } else {
                dummyHead.Next = l2
            }
            break
        }
    }
    return res.Next
}

func mergeSort(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    dummyHead, mid := head, findListMid(head)
    slicepoint := mid.Next
    mid.Next = nil
    left := mergeSort(dummyHead)
    right := mergeSort(slicepoint)
    return merge(left, right)
}

func sortList(head *ListNode) *ListNode {
    return mergeSort(head)
}
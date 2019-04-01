// 编写一个程序，找到两个单链表相交的起始节点。

// 思路：遍历两个链表，求出两个链表长度；然后长链表走k步，与短链表的长度同步。
// 然后两个链表同步往下走，如果相同就是相交；如果一直不同说明没有交点。
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getIntersectionNode(headA, headB *ListNode) *ListNode {
    dummyA, dummyB := headA, headB
    lenA, lenB := 0, 0
    for ; headA != nil; headA = headA.Next {
        lenA++
    }
    for ; headB != nil; headB = headB.Next {
        lenB++
    }
    if lenA > lenB {
        for i := 0; i < (lenA - lenB); i++ {
            dummyA = dummyA.Next
        }
    } else {
        for i := 0; i < (lenB - lenA); i++ {
            dummyB = dummyB.Next
        }
    }
    
    for ; dummyA != nil; dummyA, dummyB = dummyA.Next, dummyB.Next {
        if dummyA == dummyB {
            return dummyA
        }
    }
    return nil
}
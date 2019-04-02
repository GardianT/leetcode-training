// Q：
// 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
// 示例 1:
// 输入: 1->2->3->4->5->NULL, k = 2
// 输出: 4->5->1->2->3->NULL
// 解释:
// 向右旋转 1 步: 5->1->2->3->4->NULL
// 向右旋转 2 步: 4->5->1->2->3->NULL
// 示例 2:
// 输入: 0->1->2->NULL, k = 4
// 输出: 2->0->1->NULL
// 解释:
// 向右旋转 1 步: 2->0->1->NULL
// 向右旋转 2 步: 1->2->0->NULL
// 向右旋转 3 步: 0->1->2->NULL
// 向右旋转 4 步: 2->0->1->NULL

// 思路：直接找到k的位置，打断链表，重新连接就可以了。
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
// Q:
// 请判断一个链表是否为回文链表。
// 示例 1:
// 输入: 1->2
// 输出: false
// 示例 2:
// 输入: 1->2->2->1
// 输出: true

// 思路：快慢指针找到中点，从中点往后链表进行倒序。然后遍历对比即可。
// 也可以快慢指针找到中点后，同时进行stack操作。通过stack操作来判定回文。
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func isPalindrome(head *ListNode) bool {
    slow, fast := head, head
    for fast != nil {
        slow = slow.Next
        fast = fast.Next
        if fast != nil {
            fast = fast.Next
        }
    }
    var prev *ListNode
    for slow != nil {
        slow.Next, prev, slow = prev, slow, slow.Next
    }
    for head != nil && prev != nil {
        if head.Val != prev.Val {
            return false
        }
        head = head.Next
        prev = prev.Next
    }
    return true
}
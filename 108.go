/* package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
} */

func sortedArrayToBST(nums []int) *TreeNode {
	if nums == nil || len(nums) == 0 {
		return nil
	}

	mid := len(nums) >> 1
	node := &TreeNode{Val: nums[mid]}
	node.Left = sortedArrayToBST(nums[:mid])
	node.Right = sortedArrayToBST(nums[mid+1:])
	return node
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}

	return isTwoSymmetric(root.Left, root.Right)
}

func isTwoSymmetric(root1 *TreeNode, root2 *TreeNode) bool {
	if root1 == nil {
		return root2 == nil
	}

	if root2 == nil || root1.Val != root2.Val {
		return false
	}

	return isTwoSymmetric(root1.Left, root2.Right) && isTwoSymmetric(root1.Right, root2.Left)
}
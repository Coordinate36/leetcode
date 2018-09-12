/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func kthSmallest(root *TreeNode, k int) int {
	if root == nil {
		return -1
	}

	node := dfs(root, &k)
	if node == nil {
		return -1
	}

	return node.Val
}

func dfs(root *TreeNode, k *int) *TreeNode {
	if root == nil {
		return nil
	}

	node := dfs(root.Left, k)
	if node != nil {
		return node
	}
	if *k == 1 {
		return root
	}
	*k -= 1
	return dfs(root.Right, k)
}
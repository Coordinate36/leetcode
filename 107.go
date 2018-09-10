// package leetcode

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }

func levelOrderBottom(root *TreeNode) [][]int {
	var ans [][]int
	levelRecursion(root, &ans, 0)
	mid := len(ans) >> 1
	for i := 0; i < mid; i++ {
		ans[i], ans[len(ans)-i-1] = ans[len(ans)-i-1], ans[i]
	}
	return ans
}

func levelRecursion(node *TreeNode, ans *[][]int, level int) {
	if node == nil {
		return
	}

	if level >= len(*ans) {
		*ans = append(*ans, []int{})
	}

	(*ans)[level] = append((*ans)[level], node.Val)
	levelRecursion(node.Left, ans, level+1)
	levelRecursion(node.Right, ans, level+1)
}

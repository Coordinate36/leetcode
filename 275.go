package main

/* func hIndex(citations []int) int {
	N := len(citations)
	for i := N; i > 0; i-- {
		if citations[N-i] >= i {
			return i
		}
	}
	return 0
} */

func hIndex(citations []int) int {
	N := len(citations)
	left, right := 0, N
	var index int
	for left < right {
		index = (left + right + 1) >> 1
		if citations[N-index] >= index {
			left = index
		} else {
			right = index - 1
		}
	}
	return left
}

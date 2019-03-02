package main

import (
	"fmt"
	"sort"
)

// func canPartition(nums []int) bool {
// 	sum := 0
// 	for _, n := range nums {
// 		sum += n
// 	}
// 	if sum&1 == 1 {
// 		return false
// 	}
// 	half := sum >> 1
// 	dp := make([]bool, half+1)
// 	dp[0] = true

// 	for _, n := range nums {
// 		for i := half - n; i >= 0; i-- {
// 			if dp[i] && i+n <= half {
// 				dp[i+n] = true
// 			}
// 		}
// 	}
// 	return dp[half]
// }

// func canPartition(nums []int) bool {
// 	sum := 0
// 	for _, n := range nums {
// 		sum += n
// 	}
// 	if sum&1 == 1 {
// 		return false
// 	}
// 	half := sum >> 1
// 	dp := make([]bool, half+1)
// 	dp[0] = true

// 	keys := []int{0}

// 	for _, n := range nums {
// 		for i := len(keys) - 1; i >= 0; i-- {
// 			if keys[i]+n < half && !dp[keys[i]+n] {
// 				keys = append(keys, keys[i]+n)
// 				dp[keys[i]+n] = true
// 			}
// 			if keys[i]+n == half {
// 				return true
// 			}
// 		}
// 	}
// 	return false
// }

func canPartition(nums []int) bool {
	sum := 0
	for _, n := range nums {
		sum += n
	}
	if sum&1 == 1 {
		return false
	}
	sort.Ints(nums)
	return canSumTo(nums, sum>>1, len(nums)-1)
}

func canSumTo(nums []int, target int, end int) bool {
	if target == 0 {
		return true
	}
	if end < 0 {
		return false
	}

	for i := end; i >= 0; i-- {
		if target < nums[i] {
			break
		}
		if canSumTo(nums, target-nums[i], i-1) {
			return true
		}
	}

	return false
}

func main() {
	var nums [200]int
	for i := 0; i < 100; i++ {
		nums[i] = 1
	}
	fmt.Println(canPartition([]int{100, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}))
}

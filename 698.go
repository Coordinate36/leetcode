package main

import (
	"fmt"
	"sort"
)

func canPartitionKSubsets(nums []int, k int) bool {
	sum := 0
	for _, n := range nums {
		sum += n
	}
	k_divided := sum / k
	if k_divided*k != sum {
		return false
	}

	sort.Ints(nums)
	used := make([]bool, len(nums))
	return helper(nums, k, k_divided, 0, len(nums)-1, used)
}

func helper(nums []int, k int, target int, curSum int, end int, used []bool) bool {
	if k == 1 {
		return true
	}
	if target == curSum {
		return helper(nums, k-1, target, 0, len(nums)-1, used)
	}
	for i := end; i >= 0; i-- {
		if used[i] {
			continue
		}
		if target < nums[i] {
			break
		}
		used[i] = true
		if helper(nums, k, target, curSum+nums[i], i-1, used) {
			return true
		}
		used[i] = false
	}
	return false
}

func main() {
	//fmt.Println(canPartitionKSubsets([]int{4, 3, 2, 3, 5, 2, 1}, 4))
	fmt.Println(canPartitionKSubsets([]int{10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6}, 3))
}

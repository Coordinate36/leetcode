package main

import "fmt"

func minSubArrayLen(s int, nums []int) int {
	l, r := 0, 0
	ans := len(nums) + 1
	sum := 0
	for l < len(nums) {
		if r < len(nums) && sum < s {
			sum += nums[r]
			r++
		} else {
			sum -= nums[l]
			l++
		}
		if sum >= s && ans > r-l {
			ans = r - l
		}
	}
	if ans == len(nums)+1 {
		ans = 0
	}
	return ans
}

func main() {
	fmt.Println(minSubArrayLen(11, []int{1, 2, 3, 4, 5}))
}

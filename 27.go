package main

import "fmt"

func findPeakElement(nums []int) int {
	left, right := 0, len(nums)-1
	if right > 0 && nums[0] > nums[1] {
		return 0
	}
	if right > 0 && nums[right] > nums[right-1] {
		return right
	}
	mid := (right + left) >> 1
	for left < mid {
		if nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1] {
			left = mid
		} else if nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1] {
			right = mid
		} else if nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1] {
			left = mid
		} else {
			return mid
		}
		mid = (right + left) >> 1
	}
	return 0
}

func main() {
	nums := []int{1, 2, 1, 2, 1}
	fmt.Println(findPeakElement(nums))
}

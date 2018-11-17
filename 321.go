package main

import "fmt"

func maxNumber(nums1 []int, nums2 []int, k int) []int {
	var ans []int

	for i := 0; i <= k && i <= len(nums1); i++ {
		if i+len(nums2) < k {
			continue
		}
		rst1 := maxKNumber(nums1, i)
		rst2 := maxKNumber(nums2, k-i)
		if ans == nil {
			ans = merge(rst1, rst2)
		} else {
			fmt.Println(ans, merge(rst1, rst2), largeSlice(ans, merge(rst1, rst2)))
			ans = largeSlice(ans, merge(rst1, rst2))
		}
	}

	return ans
}

func largeSlice(s1 []int, s2 []int) []int {
	for i := 0; i < len(s1); i++ {
		if s1[i] > s2[i] {
			return s1
		} else if s2[i] > s1[i] {
			return s2
		}
	}
	return s2
}

func merge(nums1 []int, nums2 []int) []int {
	var rst []int
	m, n := 0, 0
	for m < len(nums1) && n < len(nums2) {
		if greater(nums1, nums2, m, n) {
			rst = append(rst, nums1[m])
			m++
		} else {
			rst = append(rst, nums2[n])
			n++
		}
	}
	rst = append(rst, nums1[m:len(nums1)]...)
	rst = append(rst, nums2[n:len(nums2)]...)
	return rst
}

func greater(nums1 []int, nums2 []int, m int, n int) bool {
	for m < len(nums1) && n < len(nums2) && nums1[m] == nums2[n] {
		m++
		n++
	}
	return n == len(nums2) || (m < len(nums1) && nums1[m] > nums2[n])
}

func maxKNumber(nums []int, k int) []int {
	var rst []int
	start := 0
	for i := k - 1; i >= 0; i-- {
		for j := start; j < len(nums)-i; j++ {
			if nums[start] < nums[j] {
				start = j
			}
		}
		rst = append(rst, nums[start])
		start++
	}
	return rst
}

func main() {
	nums1 := []int{6, 3, 9, 0, 5, 6}
	nums2 := []int{2, 2, 5, 2, 1, 4, 4, 5, 7, 8, 9, 3, 1, 6, 9, 7, 0}
	fmt.Println(maxNumber(nums1, nums2, 23))
	// fmt.Println(merge([]int{6, 7}, []int{6, 0, 4}))
}

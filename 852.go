package main

import "fmt"

func peakIndexInMountainArray(A []int) int {
	left, right := 0, len(A)-1
	var ans int
	for {
		mid := (left + right) >> 1
		if A[mid-1] < A[mid] && A[mid] < A[mid+1] {
			left = mid
		} else if A[mid-1] > A[mid] && A[mid] > A[mid+1] {
			right = mid
		} else {
			ans = mid
			break
		}
	}
	return ans
}

func main() {
	A := []int{40, 48, 61, 75, 100, 99, 98, 39, 30, 10}
	fmt.Println(peakIndexInMountainArray(A))
}

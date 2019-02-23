package main

func totalHammingDistance(nums []int) int {
	var ones, zeros [32]int
	var bit int
	for i := 0; i < 32; i++ {
		bit = 1 << uint(i)
		for _, n := range nums {
			if n&bit == 0 {
				zeros[i]++
			} else {
				ones[i]++
			}
		}
	}
	ans := 0
	for i := 0; i < 32; i++ {
		ans += zeros[i] * ones[i]
	}
	return ans
}

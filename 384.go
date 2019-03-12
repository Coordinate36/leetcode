package main

import "math/rand"

type Solution struct {
	original []int
	shuffled []int
}

func Constructor(nums []int) Solution {
	solution := Solution{nums, make([]int, len(nums))}
	for i, n := range nums {
		solution.shuffled[i] = n
	}
	return solution
}

/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
	return this.original
}

/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
	size := len(this.shuffled)
	for i := range this.shuffled {
		j := rand.Intn(size)
		tmp := this.shuffled[i]
		this.shuffled[i] = this.shuffled[j]
		this.shuffled[j] = tmp
	}
	return this.shuffled
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */

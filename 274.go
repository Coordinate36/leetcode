package main

/* func hIndex(citations []int) int {
	N := len(citations)
	sort.Ints(citations)
	for i := N; i > 0; i-- {
		if citations[N-i] >= i {
			return i
		}
	}
	return 0
} */

func hIndex(citations []int) int {
	N := len(citations)
	buckets := make([]int, N+1)
	for _, n := range citations {
		if n >= N {
			buckets[N]++
		} else {
			buckets[n]++
		}
	}
	for i := N; i >= 0; i-- {
		if buckets[i] >= i {
			return i
		}
		buckets[i-1] += buckets[i]
	}
	return 0
}

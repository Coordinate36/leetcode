func hammingDistance(x int, y int) int {
	diff := x ^ y
	ans := 0
	for i := 0; i < 32; i++ {
		if diff&1 == 1 {
			ans++
		}
		diff >>= 1
	}
	return ans
}
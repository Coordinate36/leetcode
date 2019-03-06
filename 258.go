func addDigits(num int) int {
	if num == 0 {
		return 0
	}
	ans := num % 9
	if ans == 0 {
		ans = 9
	}
	return ans
}
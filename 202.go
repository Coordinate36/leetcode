package main

import "fmt"

func isHappy(n int) bool {
	M := make(map[int]bool)
	for !M[n] {
		M[n] = true
		n = getSquareSum(n)
		if n == 1 {
			return true
		}
	}
	return false
}

func getSquareSum(n int) int {
	rst := 0
	var tmp int
	for n > 0 {
		tmp = n % 10
		n /= 10
		rst += tmp * tmp
	}
	return rst
}

func main() {
	fmt.Println(isHappy(12))
}

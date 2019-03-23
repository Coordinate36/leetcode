package main

import "fmt"

func rangeBitwiseAnd(m int, n int) int {
	var bit int
	for i := 30; i >= 0; i-- {
		bit = 1 << uint(i)
		if (m&bit)^(n&bit) != 0 {
			return m >> uint(i+1) << uint(i+1)
		}
	}
	return m
}

func main() {
	fmt.Println(rangeBitwiseAnd(5, 7))
}

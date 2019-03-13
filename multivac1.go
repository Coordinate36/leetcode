package main

import "fmt"

func solution(a, b []int) []int {
	var ans []int
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		if a[i] < b[j] {
			i++
		} else if a[i] > b[j] {
			j++
		} else {
			ans = append(ans, a[i])
			i++
			j++
		}
	}
	return ans
}

func main() {
	a := []int{1, 3, 5, 7, 9, 10, 100, 101}
	b := []int{2, 4, 6, 7, 9, 100, 110}
	fmt.Println(solution(a, b))
}

package main

import "fmt"

const Cattle = 11

func transferInput(s *string) (out []int) {
	for _, c := range *s {
		if c >= '0' && c <= '9' {
			out = append(out, int(c-'0'))
		} else if c == 'A' {
			out = append(out, 1)
		} else {
			out = append(out, 10)
		}
	}
	return
}

func maxValue(s *string) int {
	nums := transferInput(s)
	sum := 0
	max := 0
	for _, n := range nums {
		sum += n
		if n > max {
			max = n
		}
	}
	var cur int
	for i := 0; i < 4; i++ {
		for j := i + 1; j < 5; j++ {
			sumOf2 := nums[i] + nums[j]
			sumOf3 := sum - sumOf2
			if sumOf3 == 10 || sumOf3 == 20 || sumOf3 == 30 {
				sumOf2 %= 10
				if sumOf2 == 0 {
					cur = Cattle << 1
				} else {
					cur = Cattle + sumOf2
				}
				if cur > max {
					max = cur
				}
			}
		}
	}
	return max
}

func solution(a, b string) int {
	maxA, maxB := maxValue(&a), maxValue(&b)
	fmt.Println(maxA, maxB)
	if maxA > maxB {
		return 1
	} else if maxA < maxB {
		return -1
	}
	return 0
}

func main() {
	fmt.Println(solution("4579K", "AAAA2"))
}

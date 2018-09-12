package main

import "fmt"

func maxProfit(prices []int) int {
	size := len(prices)
	if size < 2 {
		return 0
	}
	buy := make([]int, size)
	sell := make([]int, size)

	buy[0] = -prices[0]
	buy[1] = max(buy[0], -prices[1])
	sell[1] = max(sell[0], prices[1]+buy[0])
	for i := 2; i < size; i++ {
		buy[i] = max(buy[i-1], sell[i-2]-prices[i])
		sell[i] = max(sell[i-1], buy[i-1]+prices[i])
	}

	return sell[size-1]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	input := []int{1, 2, 3, 0, 2}
	fmt.Println(maxProfit(input))
}

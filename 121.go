func maxProfit(prices []int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}

	minPrice := prices[0]
	profit := 0

	for _, price := range prices[1:] {
		minPrice = min(minPrice, price)
		profit = max(profit, price-minPrice)
	}

	return profit
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
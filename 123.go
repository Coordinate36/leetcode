func maxProfit(prices []int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}

	size := len(prices)
	dpEnd := make([]int, size)
	dpStart := make([]int, size)

	minPrice := prices[0]

	for i := 1; i < size; i++ {
		minPrice = min(minPrice, prices[i])
		dpEnd[i] = max(dpEnd[i-1], prices[i]-minPrice)
	}

	maxPrice := prices[size-1]

	for i := size - 2; i >= 0; i-- {
		maxPrice = max(maxPrice, prices[i])
		dpStart[i] = max(dpStart[i+1], maxPrice-prices[i])
	}

	ret := dpStart[0]
	for i := 0; i < size; i++ {
		ret = max(ret, dpStart[i]+dpEnd[i])
	}

	return ret
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
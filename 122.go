// func maxProfit(prices []int) int {
// 	if prices == nil || len(prices) == 0 {
// 		return 0
// 	}

// 	min, max := 0, -1
// 	profit := 0
// 	for {
// 		for min = max + 1; min < len(prices)-1 && prices[min+1] < prices[min]; min++ {
// 		}
// 		for max = min + 1; max < len(prices)-1 && prices[max+1] > prices[max]; max++ {
// 		}
// 		if max < len(prices) {
// 			profit += prices[max] - prices[min]
// 		} else {
// 			break
// 		}
// 	}

// 	return profit
// }

func maxProfit(prices []int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}

	profit := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] > prices[i-1] {
			profit += prices[i] - prices[i-1]
		}
	}

	return profit
}
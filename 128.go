// import "sort"

// func longestConsecutive(nums []int) int {
// 	sort.Ints(nums)

// 	ans := 0
// 	count := 1

// 	for i := 1; i < len(nums); i++ {
// 		if nums[i-1]+1 == nums[i] {
// 			count++
// 		} else if nums[i-1] != nums[i] {
// 			ans = max(ans, count)
// 			count = 1
// 		}
// 	}

// 	ans = max(ans, count)
// 	return ans
// }

// func max(a, b int) int {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }

func longestConsecutive(nums []int) int {
	mp := make(map[int]int)
	ans := 0

	for _, n := range nums {
		if mp[n] == 0 {
			mp[n] = mp[n-1] + 1 + mp[n+1]
			mp[n-mp[n-1]] = mp[n]
			mp[n+mp[n+1]] = mp[n]

			if mp[n] > ans {
				ans = mp[n]
			}
		}
	}

	return ans
}

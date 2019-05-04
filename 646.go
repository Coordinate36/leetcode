package main

import (
	"fmt"
	"math"
	"sort"
)

type PairSlice [][]int

func (p PairSlice) Less(i, j int) bool { return p[i][1] < p[j][1] }
func (p PairSlice) Len() int           { return len(p) }
func (p PairSlice) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }

func findLongestChain(pairs [][]int) int {
	Pairs := PairSlice(pairs)
	sort.Sort(Pairs)
	ans := 0
	end := math.MinInt32
	for _, pair := range Pairs {
		if end < pair[0] {
			end = pair[1]
			ans++
		}
	}
	return ans
}

func main() {
	pairs := [][]int{{2, 3}, {1, 2}, {3, 4}}
	fmt.Println(findLongestChain(pairs))
}

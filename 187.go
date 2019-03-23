package main

import "fmt"

/* func findRepeatedDnaSequences(s string) []string {
	var ans []string
	record := make(map[string]int)
	for i := 0; i <= len(s)-10; i++ {
		record[s[i:i+10]] += 1
	}
	for k, v := range record {
		if v > 1 {
			ans = append(ans, k)
		}
	}
	return ans
} */

func char2int(b byte) int {
	switch b {
	case 'A':
		return 0
	case 'C':
		return 1
	case 'G':
		return 2
	default:
		return 3
	}
}

func findRepeatedDnaSequences(s string) []string {
	var ans []string
	if len(s) <= 10 {
		return ans
	}
	record := make(map[int]int)
	h := 0
	for i := 0; i < 10; i++ {
		h <<= 3
		h |= char2int(s[i])
	}
	record[h] = 1
	for i := 0; i < len(s)-10; i++ {
		h &= 0x7ffffff
		h = (h << 3) | char2int(s[i+10])
		record[h] += 1
		if record[h] == 2 {
			ans = append(ans, s[i+1:i+11])
		}
	}
	return ans
}

func main() {
	fmt.Println(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
}

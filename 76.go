package main

import "fmt"

func minWindow(s string, t string) string {
	target := make(map[byte]int)
	available := make(map[byte]int)
	l, r := 0, len(s)+1
	for _, c := range t {
		target[byte(c)]++
	}
	i, j := 0, 0
	count := 0
	for i < len(s) {
		if j < len(s) && count != len(t) {
			if target[s[j]] > 0 {
				available[s[j]]++
				if available[s[j]] <= target[s[j]] {
					count++
				}
			}
			j++
		} else {
			if available[s[i]] > 0 {
				available[s[i]]--
				if available[s[i]] < target[s[i]] {
					count--
				}
			}
			i++
		}
		if count == len(t) {
			if r-l > j-i {
				r, l = j, i
			}
		}
	}
	if r == len(s)+1 {
		r = 0
	}
	return s[l:r]
}

func main() {
	fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
	fmt.Println(minWindow("a", "aa"))
	fmt.Println(minWindow("bba", "ab"))
}

func isPalindrome(s string) bool {
	var transfered []rune
	for _, c := range s {
		if c >= 'a' && c <= 'z' || c >= '0' && c <= '9' {
			transfered = append(transfered, c)
		} else if c >= 'A' && c <= 'Z' {
			transfered = append(transfered, c+32)
		}
	}

	for l, r := 0, len(transfered)-1; l < r; {
		if transfered[l] != transfered[r] {
			return false
		}
		l++
		r--
	}

	return true
}
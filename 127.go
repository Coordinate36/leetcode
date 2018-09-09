type pair struct {
	first  string
	second int
}

func ladderLength(beginWord string, endWord string, wordList []string) int {
	var queue []pair
	wordSet := make(map[string]int)

	for _, word := range wordList {
		wordSet[word] = 1
	}
	delete(wordSet, beginWord)

	queue = append(queue, pair{beginWord, 1})
	for len(queue) > 0 {
		elem := queue[0]
		queue = queue[1:]

		for i := 0; i < len(elem.first); i++ {
			s := []byte(elem.first)
			for j := 0; j < 26; j++ {
				s[i] = byte('a' + j)
				str := string(s)
				_, ok := wordSet[str]
				if ok {
					if str == endWord {
						return elem.second + 1
					}
					queue = append(queue, pair{str, elem.second + 1})
					delete(wordSet, str)
				}
			}
		}
	}

	return 0
}

//package leetcode

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	wordSet := make(map[string]int)
	wordLength := make(map[string]int)

	for _, word := range wordList {
		wordSet[word] = 1
	}
	delete(wordSet, beginWord)

	ladderLength(beginWord, endWord, wordSet, wordLength)
	_, ok := wordLength[endWord]
	if !ok {
		return [][]string{}
	}

	for _, word := range wordList {
		wordSet[word] = 1
	}
	delete(wordSet, beginWord)

	var ladder []string
	var ladders [][]string
	dfs(ladder, &ladders, endWord, wordSet, wordLength, beginWord)

	return ladders
}

func ladderLength(beginWord string, endWord string, wordSet map[string]int, wordLength map[string]int) {
	queue := []string{beginWord}
	wordLength[beginWord] = 1

	for len(queue) > 0 {
		word := queue[0]
		queue = queue[1:]

		for i := 0; i < len(word); i++ {
			bytes := []byte(word)
			for j := byte('a'); j < 'z'; j++ {
				bytes[i] = j
				str := string(bytes)

				_, ok := wordSet[str]
				if ok {
					wordLength[str] = wordLength[word] + 1
					if str == endWord {
						return
					}
					queue = append(queue, str)
					delete(wordSet, str)
				}
			}
		}
	}
}

func dfs(ladder []string, ladders *[][]string, endWord string, wordSet map[string]int, wordLength map[string]int, word string) {
	ladder = append(ladder, word)

	if len(ladder) == wordLength[endWord] {
		if word == endWord {
			ladderCopy := make([]string, wordLength[endWord])
			copy(ladderCopy, ladder)
			*ladders = append(*ladders, ladderCopy)
		}
		return
	}

	delete(wordSet, word)
	for i := 0; i < len(word); i++ {
		for j := byte('a'); j <= 'z'; j++ {
			bytes := []byte(word)
			bytes[i] = j
			str := string(bytes)
			_, ok := wordSet[str]
			if ok && wordLength[word]+1 == wordLength[str] {
				dfs(ladder, ladders, endWord, wordSet, wordLength, str)
			}
		}
	}
	wordSet[word] = 1
}

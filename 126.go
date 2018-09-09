//package leetcode

type pair struct {
	word   string
	length int
}

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	wordSet := make(map[string]int)

	for _, word := range wordList {
		wordSet[word] = 1
	}
	delete(wordSet, beginWord)

	minLength := ladderLength(beginWord, endWord, wordSet)

	for _, word := range wordList {
		wordSet[word] = 1
	}
	delete(wordSet, beginWord)

	var ladder []string
	var ladders [][]string
	dfs(ladder, &ladders, endWord, wordSet, minLength, beginWord)

	return ladders
}

func ladderLength(beginWord string, endWord string, wordSet map[string]int) int {
	queue := []pair{pair{beginWord, 1}}

	for len(queue) > 0 {
		elem := queue[0]
		queue = queue[1:]

		for i := 0; i < len(elem.word); i++ {
			word := []byte(elem.word)
			for j := 'a'; j < 'z'; j++ {
				word[i] = byte(j)
				str := string(word)

				_, ok := wordSet[str]
				if ok {
					if str == endWord {
						return elem.length + 1
					}
					queue = append(queue, pair{str, elem.length + 1})
					delete(wordSet, str)
				}
			}
		}
	}
	return 0
}

func dfs(ladder []string, ladders *[][]string, endWord string, wordSet map[string]int, minLength int, word string) {
	ladder = append(ladder, word)

	if len(ladder) == minLength {
		if word == endWord {
			ladderCopy := make([]string, minLength)
			copy(ladderCopy, ladder)
			*ladders = append(*ladders, ladderCopy)
		}
		return
	}

	delete(wordSet, word)
	for i := 0; i < len(word); i++ {
		for j := 'a'; j <= 'z'; j++ {
			if byte(j) == word[i] {
				continue
			}

			bytes := []byte(word)
			bytes[i] = byte(j)
			str := string(bytes)
			_, ok := wordSet[str]
			if ok {
				dfs(ladder, ladders, endWord, wordSet, minLength, str)
			}
		}
	}
	wordSet[word] = 1
}

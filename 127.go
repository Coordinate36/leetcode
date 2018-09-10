//package leetcode

// func ladderLength(beginWord string, endWord string, wordList []string) int {
// 	wordSet := make(map[string]int)
// 	wordLength := make(map[string]int)

// 	for _, word := range wordList {
// 		wordSet[word] = 1
// 	}
// 	delete(wordSet, beginWord)

// 	queue := []string{beginWord}
// 	wordLength[beginWord] = 1
// 	for len(queue) > 0 {
// 		word := queue[0]
// 		queue = queue[1:]

// 		for i := 0; i < len(word); i++ {
// 			runes := []rune(word)
// 			for j := 'a'; j < 'z'; j++ {
// 				runes[i] = j
// 				str := string(runes)
// 				_, ok := wordSet[str]
// 				if ok {
// 					if str == endWord {
// 						return wordLength[word] + 1
// 					}
// 					queue = append(queue, str)
// 					wordLength[str] = wordLength[word] + 1
// 					delete(wordSet, str)
// 				}
// 			}
// 		}
// 	}

// 	return 0
// }

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
		if elem.first == endWord {
			return elem.second
		}
		for i := 0; i < len(elem.first); i++ {
			bytes := []byte(elem.first)
			for j := byte('a'); j < 'z'; j++ {
				bytes[i] = j
				str := string(bytes)
				_, ok := wordSet[str]
				if ok {
					queue = append(queue, pair{str, elem.second + 1})
					delete(wordSet, str)
				}
			}
		}
	}

	return 0
}

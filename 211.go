package main

import "fmt"

/* type WordDictionary struct {
	root Trie
}

type Trie struct {
	children map[rune]*Trie
	isEnd    bool
}

func Constructor() WordDictionary {
	return WordDictionary{root: Trie{children: make(map[rune]*Trie), isEnd: false}}
}

func (this *WordDictionary) AddWord(word string) {
	tmp := &this.root
	for _, c := range word {
		_, ok := tmp.children[c]
		if !ok {
			tmp.children[c] = &Trie{children: make(map[rune]*Trie), isEnd: false}
		}
		tmp = tmp.children[c]
	}
	tmp.isEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	return this.RecurSearch([]rune(word), &this.root)
}

func (this *WordDictionary) RecurSearch(word []rune, node *Trie) bool {
	for i, c := range word {
		if c == '.' {
			for _, t := range node.children {
				if this.RecurSearch(word[i+1:], t) {
					return true
				}
			}
			return false
		} else {
			_, ok := node.children[c]
			if !ok {
				return false
			}
			node = node.children[c]
		}
	}
	return node.isEnd
} */

/* type WordDictionary struct {
	root Trie
}

type Trie struct {
	children [26]*Trie
	isEnd    bool
}

func Constructor() WordDictionary {
	return WordDictionary{}
}

func (this *WordDictionary) AddWord(word string) {
	tmp := &this.root
	for _, c := range word {
		idx := c - 'a'
		if tmp.children[idx] == nil {
			tmp.children[idx] = &Trie{}
		}
		tmp = tmp.children[idx]
	}
	tmp.isEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	return this.RecurSearch([]rune(word), &this.root)
}

func (this *WordDictionary) RecurSearch(word []rune, node *Trie) bool {
	for i, c := range word {
		if c == '.' {
			for _, t := range node.children {
				if t != nil && this.RecurSearch(word[i+1:], t) {
					return true
				}
			}
			return false
		} else {
			idx := c - 'a'
			if node.children[idx] == nil {
				return false
			}
			node = node.children[idx]
		}
	}
	return node.isEnd
} */

type WordDictionary struct {
	children [26]*WordDictionary
	isEnd    bool
}

func Constructor() WordDictionary {
	return WordDictionary{}
}

func (this *WordDictionary) AddWord(word string) {
	tmp := this
	for _, c := range word {
		idx := c - 'a'
		if tmp.children[idx] == nil {
			tmp.children[idx] = &WordDictionary{}
		}
		tmp = tmp.children[idx]
	}
	tmp.isEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	return this.RecurSearch([]rune(word))
}

func (this *WordDictionary) RecurSearch(word []rune) bool {
	node := this
	for i, c := range word {
		if c == '.' {
			for _, t := range node.children {
				if t != nil && t.RecurSearch(word[i+1:]) {
					return true
				}
			}
			return false
		} else {
			idx := c - 'a'
			if node.children[idx] == nil {
				return false
			}
			node = node.children[idx]
		}
	}
	return node.isEnd
}

func main() {
	word := "pad"
	obj := Constructor()
	obj.AddWord(word)
	fmt.Println(obj.Search("pbd"))
}

package main

import "fmt"

type LRUCache struct {
	Map      map[int]*node
	List     *node
	Capacity int
}

type node struct {
	Key  int
	Val  int
	Prev *node
	Next *node
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		Map:      make(map[int]*node),
		Capacity: capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	pNode, ok := this.Map[key]
	if ok {
		this.moveHead(pNode)
		return pNode.Val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	var pNode *node

	pNode, ok := this.Map[key]
	if ok {
		pNode.Val = value
		this.moveHead(pNode)
		return
	}

	switch len(this.Map) {
	case 0:
		pNode = &node{
			Key: key,
			Val: value,
		}
		pNode.Prev = pNode
		pNode.Next = pNode

	case this.Capacity:
		if this.Capacity == 0 {
			return
		}
		tail := this.List.Prev
		delete(this.Map, tail.Key)
		tail.Key = key
		tail.Val = value
		pNode = tail

	default:
		pNode = &node{
			Key:  key,
			Val:  value,
			Prev: this.List.Prev,
			Next: this.List,
		}
		pNode.Next.Prev = pNode
		pNode.Prev.Next = pNode
	}

	this.List = pNode
	this.Map[key] = pNode
}

func (this *LRUCache) moveHead(pNode *node) {
	switch pNode {
	case this.List:
	case this.List.Prev:
		this.List = pNode
	default:
		pNode.Prev.Next = pNode.Next
		pNode.Next.Prev = pNode.Prev
		pNode.Prev = this.List.Prev
		pNode.Next = this.List
		pNode.Prev.Next = pNode
		pNode.Next.Prev = pNode
		this.List = pNode
	}
}

func main() {
	obj := Constructor(2)
	fmt.Println(obj.Get(1))
	obj.Put(1, 2)
	obj.Put(3, 4)
	fmt.Println(obj.Get(1))
	obj.Put(1, 3)
	fmt.Println(obj.Get(1))
	obj.Put(32, 1)
	fmt.Println(obj.Get(1), obj.Get(3), obj.Get(32))
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

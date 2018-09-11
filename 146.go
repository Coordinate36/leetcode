package main

import "fmt"

// type LRUCache struct {
// 	Map      map[int]*node
// 	ListHead *node
// 	Capacity int
// }

// type node struct {
// 	Key  int
// 	Val  int
// 	Prev *node
// 	Next *node
// }

// func Constructor(capacity int) LRUCache {
// 	return LRUCache{
// 		Map:      make(map[int]*node),
// 		Capacity: capacity,
// 	}
// }

// func (this *LRUCache) Get(key int) int {
// 	pNode, ok := this.Map[key]
// 	if ok {
// 		this.move2Head(pNode)
// 		return pNode.Val
// 	}
// 	return -1
// }

// func (this *LRUCache) Put(key int, value int) {
// 	var pNode *node

// 	pNode, ok := this.Map[key]
// 	if ok {
// 		pNode.Val = value
// 		this.move2Head(pNode)
// 		return
// 	}

// 	switch len(this.Map) {
// 	case 0:
// 		pNode = &node{
// 			Key: key,
// 			Val: value,
// 		}
// 		pNode.Prev = pNode
// 		pNode.Next = pNode

// 	case this.Capacity:
// 		if this.Capacity == 0 {
// 			return
// 		}
// 		tail := this.ListHead.Prev
// 		delete(this.Map, tail.Key)
// 		tail.Key = key
// 		tail.Val = value
// 		pNode = tail

// 	default:
// 		pNode = &node{
// 			Key:  key,
// 			Val:  value,
// 			Prev: this.ListHead.Prev,
// 			Next: this.ListHead,
// 		}
// 		pNode.Next.Prev = pNode
// 		pNode.Prev.Next = pNode
// 	}

// 	this.ListHead = pNode
// 	this.Map[key] = pNode
// }

// func (this *LRUCache) move2Head(pNode *node) {
// 	switch pNode {
// 	case this.ListHead:
// 	case this.ListHead.Prev:
// 		this.ListHead = pNode
// 	default:
// 		pNode.Prev.Next = pNode.Next
// 		pNode.Next.Prev = pNode.Prev
// 		pNode.Prev = this.ListHead.Prev
// 		pNode.Next = this.ListHead
// 		pNode.Prev.Next = pNode
// 		pNode.Next.Prev = pNode
// 		this.ListHead = pNode
// 	}
// }

type LRUCache struct {
	Map      map[int]*node
	ListHead *node
	ListTail *node
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
		this.move2Head(pNode, false)
		return pNode.Val
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	var pNode *node

	pNode, ok := this.Map[key]
	if ok {
		pNode.Val = value
		this.move2Head(pNode, false)
		return
	}

	switch len(this.Map) {
	case 0:
		pNode = &node{
			Key: key,
			Val: value,
		}
		this.ListHead = pNode
		this.ListTail = pNode
		this.move2Head(pNode, true)

	case this.Capacity:
		if this.Capacity == 0 {
			return
		}
		pNode = this.ListTail
		delete(this.Map, pNode.Key)
		pNode.Key = key
		pNode.Val = value
		this.move2Head(pNode, false)

	default:
		pNode = &node{
			Key: key,
			Val: value,
		}
		this.move2Head(pNode, true)
	}

	this.Map[key] = pNode
}

func (this *LRUCache) move2Head(pNode *node, isNew bool) {
	if pNode != this.ListHead {
		if pNode == this.ListTail {
			this.ListTail = pNode.Prev
		} else if !isNew {
			pNode.Prev.Next = pNode.Next
			pNode.Next.Prev = pNode.Prev
		}

		pNode.Next = this.ListHead
		this.ListHead.Prev = pNode
		this.ListHead = pNode
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

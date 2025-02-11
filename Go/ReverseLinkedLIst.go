package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func ReverseList(pNode *ListNode) (*ListNode, *ListNode) {
	if pNode.next == nil {
		return pNode, pNode
	}

	pHead, pNewNode := ReverseList(pNode.next)
	pNewNode.next = pNode
	return pHead, pNode
}

func ReverseLinkedList(head *ListNode) *ListNode {
	pHead, _ := ReverseList(head)
	head.next = nil
	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pHead := GetListFromArray(vec)

		pHead = ReverseLinkedList(pHead)
		pHead.Print()
	}
}

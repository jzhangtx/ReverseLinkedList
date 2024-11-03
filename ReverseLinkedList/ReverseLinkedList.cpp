// ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

ListNode* ReverseNodes(ListNode* pNode)
{
    if (pNode->next == nullptr)
        return pNode;
    else
        ReverseNodes(pNode->next)->next = pNode;
    return pNode;
}

ListNode* ReverseLinkedList(ListNode* pHead)
{
    ListNode* pNewHead = pHead;
    while (pNewHead->next != nullptr)
        pNewHead = pNewHead->next;

    ListNode* pNode = ReverseNodes(pHead);
    pNode->next = nullptr;
    return pNewHead;
}

void PrintList(ListNode* pHead)
{
    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data ;
        pHead = pHead->next;
    }

    std::cout << std::endl;
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count == 0)
            break;

        ListNode* pOrignalHead = nullptr;
        ListNode* pOriginalTail = GetListFromInput(&pOrignalHead, count);

        std::cout << "Original: ";
        PrintList(pOrignalHead);

        ListNode* pReversed = ReverseLinkedList(pOrignalHead);

        std::cout << "Reversed: ";
        PrintList(pReversed);
        FreeList(pReversed);
    }
}

#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = { nullptr,0 };
	cnt = 0;
}

int LinkedList::InsertNode(int data,int index)
{
	Node* node = new Node();
	node->data = data;

	if (index < 0 || cnt < index) return -1;

	Node* currentNode = &head;
	Node* nextNode = currentNode->next;

	while (index != 0 && nextNode != nullptr) {
		--index;
		currentNode = nextNode;
		nextNode = nextNode->next;
	}

	currentNode->next = node;
	node->next = nextNode;
	return ++cnt;
}

int LinkedList::DeleteNode(int index)
{
	if (index < 0 || cnt <= index) return -1;

	Node* currrentNode = &head;
	Node* nextNode = head.next;

	while (index != 0 && nextNode != nullptr) {
		--index;
		currrentNode = nextNode;
		nextNode = nextNode->next;
	}

	if (nextNode == nullptr) {
		currrentNode->next = nullptr;
	}
	else {
		currrentNode->next = nextNode->next;
	}

	delete nextNode;
	return --cnt;
}

int LinkedList::AddNode(int data)
{
	Node* node = new Node();
	node->data = data;

	Node* tmp = head.next;
	head.next = node;
	node->next = tmp;

	return ++cnt;
}

void LinkedList::Show()
{
	Node* n = head.next;
	for (int i = 0; i < cnt; i++)
	{
		std::cout << n->data << " -> ";
		n = n->next;
	}
	std::cout << "end\n";
}

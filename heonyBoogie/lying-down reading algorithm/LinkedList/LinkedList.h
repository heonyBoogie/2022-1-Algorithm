#pragma once
#include<iostream>

struct Node
{
	Node* next;
	int data;
};
class LinkedList
{
private:
	Node head;
	int cnt;
public:
	LinkedList();
	int InsertNode(int data,int index);//index번째에 인자로 받은 node insert
	int DeleteNode(int index);//index번째 노드 delete
	int AddNode(int data);//리스트 제일 앞에 노드 Add
	void Show(); //리스트 전체 출력
};


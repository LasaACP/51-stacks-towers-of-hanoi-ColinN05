#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Node::Node()
{
  
}

Stack::Stack()
{

}

/*
Stack::~Stack()
{
	// delete data;
}
*/

void Stack::push(void* inData)
{
  Node* newNode = new Node();
  newNode->data = inData;
  newNode->pPrev = pTop;
  if (pTop)
    pTop->pNext = newNode;
  pTop = newNode;
}
void* Stack::pop()
{
	void* returnData = pTop->data;
  pTop = pTop->pPrev;
  if (pTop)
    pTop->pNext = nullptr;
  return returnData;
}

void* Stack::top()
{
	return pTop->data;
}

bool Stack::empty()
{
	return !pTop;
}

void Stack::display()
{
	Node* p1;
	p1 = pTop;
	while (p1)
	{
		cout << ((Disc*)(p1->data))->toString() << "\t";
		p1 = p1->pPrev;
	}
	cout<<'\n';
}


#ifndef _Stack_H_
#define _Stack_H_

struct Node
{
  Node();
  
  void* data = nullptr;
  Node* pNext = nullptr;
  Node* pPrev = nullptr;
};

class Stack
{
	Node* pTop = nullptr;


	public:
		Stack();					// Construct stack
		void push(void* inData);	// Add element to top of stack
		void* pop();				// Return element at top of stack and remove from top
		void* top();				// Return element at top of stack
		bool empty();
		void display();

};

#endif 		//_Stack_H_

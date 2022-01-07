#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

void toh(int n)
{
  int i, x;
	Disc* a;
	Disc* b;
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();

  for (i = n; i >= 1; i--)
  {
    Disc* d = new Disc(i);
    t1->push(d);
  }

	// ****  Your Tower of Hanoi solution!
  while (!t1->empty() || !t2->empty())
  {
    // Case n even
    if (n % 2 == 0)
    {
      int discA = n+1, discB = n+1, discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}


      // AB 
      if (discA > discB) {t1->push(t2->pop());}
      else if (discA < discB) {t2->push(t1->pop());}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();

      discA = n+1; discB = n+1; discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}

      // AC
      if (discA > discC) {t1->push(t3->pop());}
      else if (discA < discC) {t3->push(t1->pop());}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();

      discA = n+1; discB = n+1; discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}

      // BC 
      if (discB > discC) {t2->push(t3->pop());}
      if (discB < discC) {t3->push(t2->pop());}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();
    }
    
    // Case n odd
    if (n % 2 == 1)
    {
      int discA = n+1, discB = n+1, discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}
      
      // AC
      if (discA > discC) {t1->push(t3->pop());}
      else if (discA < discC) {t3->push(t1->pop());}
      if (t1->empty() && t2->empty()) {break;}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();

      discA = n+1; discB = n+1; discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}

      // AB 
      if (discA > discB) {t1->push(t2->pop());}
      else if (discA < discB) {t2->push(t1->pop());}
      if (t1->empty() && t2->empty()) {break;}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();

      discA = n+1; discB = n+1; discC = n+1;
      if (!t1->empty()) {discA = ((Disc*)t1->top())->getSize();}
      if (!t2->empty()) {discB = ((Disc*)t2->top())->getSize();}
      if (!t3->empty()) {discC = ((Disc*)t3->top())->getSize();}

      // BC 
      if (discB > discC) {t2->push(t3->pop());}
      if (discB < discC) {t3->push(t2->pop());}
      if (t1->empty() && t2->empty()) {break;}

      std::cout << "===================\n";
      std::cout << "-"; t1->display();
      std::cout << "-"; t2->display();
      std::cout << "-"; t3->display();
    }
  }

  std::cout << "\n FINISHED \n";
  std::cout << "Peg C (left is top of stack)\n";
  t3->display();
  
}
int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin>>n;
    toh(n);
    return 0;
}

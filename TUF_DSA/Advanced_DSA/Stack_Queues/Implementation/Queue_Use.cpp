// #include "QueueImplementationArrays.h"
#include "QueueImplementationLL.h"

int main()
{
  // QueueImple q(10);
  // q.push(1);
  // q.push(2);
  // q.push(3);
  // q.push(4);
  // q.push(5);
  // q.push(6);
  // q.push(7);
  // cout << q.pop() << endl;
  // cout << q.top() << endl;
  // cout << q.size() << endl;
  // q.push(8);
  // q.push(9);
  // q.push(10);
  // cout << q.pop() << endl;
  // cout << q.top() << endl;
  // cout << q.size() << endl;

  QueueLL q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  cout << q.pop() << endl;
  cout << q.top() << endl;
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  cout << q.top() << endl;
}
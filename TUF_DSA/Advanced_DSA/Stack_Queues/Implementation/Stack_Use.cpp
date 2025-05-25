// #include "StackImplementaionArrays.h"
// #include "StackImplementationArraysDynamic.h"
#include "StackImplementationLL.h"

int main()
{
  // StackImpleDynamic st;
  // stackImple st1(100);
  // cout << st.isEmpty() << endl;
  // st.push(1);
  // cout << st.pop() << endl;
  // cout << st.isEmpty() << endl;

  // st.push(10);
  // st.push(12);
  // st.push(13);
  // st.push(14);
  // st.push(15);
  // st.push(16);
  // cout << st.size() << endl;
  // cout << st.top() << endl;
  // cout << st.pop() << endl;
  // cout << st.top() << endl;
  // cout << st.size() << endl;
  // cout << st.isEmpty() << endl;

  StackLL st;
  st.push(1);
  st.push(2);
  st.push(3);
  cout << st.top() << endl;
  cout << st.pop() << endl;
  cout << st.size() << endl;
  cout << st.top() << endl;
}

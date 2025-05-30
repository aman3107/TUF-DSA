#include "LRU_Cache.h"

int main()
{
  LRUCache lc(2);
  lc.put(1, 1);
  lc.put(2, 2);
  // lc.put(8, 11);
  // lc.put(7, 10);
  cout << lc.get(1) << endl;
  // cout << lc.get(8) << endl;
  lc.put(3, 3);
  lc.put(4, 4);
  cout << lc.get(2) << endl;
  // lc.put(5, 7);
  cout << lc.get(4) << endl;
}
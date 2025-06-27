#include "Disjoint_Set_Union_By_Rank.h"

int main()
{
  DisjointSet set(7);
  set.unionByRank(1, 2);
  set.unionByRank(2, 3);
  set.unionByRank(4, 5);
  cout << set.find(1, 4) << endl;
  set.unionByRank(6, 7);
  set.unionByRank(5, 6);
  set.unionByRank(3, 7);
  cout << set.find(3, 7) << endl;
}
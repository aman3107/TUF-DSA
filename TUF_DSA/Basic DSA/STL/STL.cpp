#include <bits/stdc++.h>
using namespace std;

void explainPair()
{
  pair<int, int> pr1 = {2, 8};
  cout << pr1.first << " " << pr1.second << endl;

  pair<int, char> pr2 = make_pair(1, 'a');
  cout << pr2.first << " " << pr2.second << endl;
}

void explainVector()
{
  vector<int> vec = {7, 8};
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  cout << vec.size() << endl;

  // Using Normal for loop
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }
  cout << endl;

  // Using Iterator
  for (vector<int>::iterator itr = vec.begin(); itr < vec.end(); itr++)
  {
    cout << *itr << " ";
  }
  cout << endl;

  // Using forEach

  for (auto a : vec)
  {
    cout << a << " ";
  }
  cout << endl;

  // Reverse Iterator
  auto reverseBegin = vec.rbegin();
  auto reverseEnd = vec.rend();
  for (auto i = reverseBegin; i < reverseEnd; i++)
  {
    cout << *i << " ";
  }
  cout << endl;

  // Duplicate vector
  vector<int> dupVec(vec.begin() + 1, vec.end());
  for (auto i : dupVec)
    cout << i << " ";
  cout << endl;

  // front
  cout << vec.front() << endl;

  // back
  cout << vec.back() << endl;

  // erase
  vec.erase(vec.begin() + 2, vec.end() - 1);
  for (auto a : vec)
  {
    cout << a << " ";
  }
  cout << endl;

  // clear
  vec.clear();
  for (auto a : vec)
  {
    cout << a << " ";
  }
  cout << endl;

  // swap
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4};
  swap(v1, v2);
  for (auto a : v1)
  {
    cout << a << " ";
  }
  cout << endl;

  // insert
  vector<int> vec1 = {1, 2, 3, 4};
  vec1.insert(vec1.begin() + 2, 5);
  for (auto a : vec1)
  {
    cout << a << " ";
  }
  cout << endl;
}

void explainList()
{
  list<int> ls = {1, 2};
  ls.emplace_front(-1);
  ls.push_front(0);
  ls.push_back(3);
  for (auto a : ls)
  {
    cout << a << " ";
  }
  cout << endl;
  ls.pop_front();
  ls.pop_back();
  for (auto a : ls)
  {
    cout << a << " ";
  }
  cout << endl;
}

void explainDeque()
{
  deque<int> dq = {1, 2, 3};
  dq.push_back(10);
  dq.push_front(0);
  for (auto a : dq)
  {
    cout << a << " ";
  }
  cout << endl;
}

void explainStack()
{
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  cout << st.size() << endl;
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

void explainQueue()
{
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  cout << q.size() << endl;
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

void explainPQ()
{
  // Max Heap
  priority_queue<int> pq;
  pq.push(1);
  pq.push(20);
  pq.push(4);
  pq.push(22);
  pq.push(7);

  cout << pq.size() << endl;
  while (!pq.empty())
  {
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;

  // Min Heap

  priority_queue<int, vector<int>, greater<int>> pq1;
  pq1.push(1);
  pq1.push(20);
  pq1.push(4);
  pq1.push(22);
  pq1.push(7);

  cout << pq1.size() << endl;
  while (!pq1.empty())
  {
    cout << pq1.top() << " ";
    pq1.pop();
  }
  cout << endl;
}

void explainSet()
{
  set<int> s;
  s.insert(1);
  s.insert(21);
  s.insert(21);
  s.insert(21);
  s.insert(2);
  s.insert(0);
  s.insert(4);

  for (auto a : s)
  {
    cout << a << " ";
  }
  cout << endl;

  // find
  auto it = s.find(22);
  if (it != s.end())
  {
    cout << *it << endl;
  }

  // count
  cout << s.count(1) << endl;

  // erase
  auto itr1 = s.begin();
  itr1++;

  auto itr2 = s.end();
  itr2--;
  s.erase(itr1, itr2);
  for (auto a : s)
  {
    cout << a << " ";
  }
  cout << endl;

  s.insert(2);
  s.insert(0);
  s.insert(4);

  // lower bound
  auto lit = s.lower_bound(4);
  if (lit != s.end())
    cout << *lit << endl;
  else
    cout << "end" << endl;

  // upper bound
  auto uit = s.upper_bound(4);
  if (uit != s.end())
    cout << *uit << endl;
  else
    cout << "end" << endl;
}

void explainMultiSet()
{
  multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(0);
  ms.insert(21);
  ms.insert(21);

  for (auto a : ms)
  {
    cout << a << " ";
  }
  cout << endl;

  // find
  auto it = ms.find(1);
  cout << *it << endl;

  // erase
  // ms.erase(1);
  ms.erase(ms.find(1));
  for (auto a : ms)
  {
    cout << a << " ";
  }
  cout << endl;

  // count
  cout << ms.count(1) << endl;
}

void explainUnorderedSet()
{
  unordered_set<int> ust;
  ust.insert(1);
  ust.insert(2);
  ust.insert(1);
  ust.insert(4);
  ust.insert(3);
  ust.insert(5);

  for (auto a : ust)
  {
    cout << a << " ";
  }
  cout << endl;
}

void explainMap()
{
  map<int, string> m;
  m[1] = "aman";
  m[2] = "amit";
  m[3] = "akash";
  m[4] = "arnav";

  m.insert({5, "shiva"});
  for (auto it : m)
  {
    cout << it.first << " " << it.second << endl;
  }

  // find
  auto it = m.find(3);
  if (it != m.end())
    cout << (*it).first << " " << (*it).second << endl;
  else
    cout << "Not Found" << endl;
}

void explainUnorderedMap()
{
  unordered_map<int, string> m;
  m[1] = "aman";
  m[2] = "amit";
  m[3] = "akash";
  m[4] = "arnav";

  m.insert({5, "shiva"});
  for (auto it : m)
  {
    cout << it.first << " " << it.second << endl;
  }

  // find
  auto it = m.find(3);
  if (it != m.end())
    cout << (*it).first << " " << (*it).second << endl;
  else
    cout << "Not Found" << endl;
}

void explainMultiMap()
{
  multimap<int, char> mp;
  mp.insert({1, 'a'});
  mp.insert({3, 'b'});
  mp.insert({1, 'b'});
  mp.insert({1, 'a'});
  mp.insert({2, 'a'});
  mp.insert({2, 'a'});
  mp.insert({2, 'b'});

  for (auto a : mp)
  {
    cout << a.first << " " << a.second << endl;
  }

  // equal range
  auto it = mp.equal_range(2);
  for (auto i = it.first; i != it.second; i++)
  {
    cout << (*i).first << " " << (*i).second << endl;
  }
}

void explainSort()
{
  int arr[5] = {6, 8, 2, 1, 0};
  sort(arr + 1, arr + 4);
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  vector<int> vec = {6, 8, 2, 1, 0};
  // sort(vec.begin(), vec.end());
  sort(vec.begin() + 1, vec.begin() + 4);
  for (auto i : vec)
  {
    cout << i << " ";
  }
  cout << endl;
}

void explainAccumulate()
{
  int arr[5] = {6, 8, 2, 1, 0};
  cout << accumulate(arr, arr + 5, 0) << endl;
}

void explainCount()
{
  int arr[5] = {6, 8, 2, 1, 0};
  cout << count(arr, arr + 5, 1) << endl;
}

void explainFind()
{
  int arr[5] = {6, 8, 2, 1, 0};
  auto it = find(arr, arr + 5, 1);
  if (it != (arr + 5))
    cout << *it << endl;
  else
    cout << "Not found" << endl;
}

void explainNextPermutation()
{
  string str = "abc";
  do
  {
    cout << str << endl;
  } while (next_permutation(str.begin(), str.end()));
}

void explainPrevPermutation()
{
  string str = "cba";
  do
  {
    cout << str << endl;
  } while (prev_permutation(str.begin(), str.end()));
}

void explainMax()
{
  vector<int> v = {7, 6, 5, 9, 10};
  auto it = max_element(v.begin(), v.end());
  cout << *it << endl;
}

void explainMin()
{
  vector<int> v = {7, 6, 5, 9, 10};
  auto it = min_element(v.begin(), v.end());
  cout << *it << endl;
}

void explainReverse()
{
  vector<int> v = {7, 6, 5, 9, 10};
  reverse(v.begin(), v.end());
  for (auto a : v)
  {
    cout << a << " ";
  }
  cout << endl;
}

bool internalComparator(pair<int, int> a, pair<int, int> b)
{
  if (a.second < b.second)
    return false;
  if (a.second > b.second)
  {
    return true;
  }
  if (a.first < b.first)
  {
    return true;
  }
  return false;
}

void explainComparator()
{
  // vector<int> v = {5, 6, 1, 2};
  // sort(v.begin(), v.end(), internalComparator);
  // for (auto a : v)
  // {
  //   cout << a << " ";
  // }
  // cout << endl;

  vector<pair<int, int>> vect = {{1, 6}, {1, 5}, {2, 6}, {2, 9}, {3, 9}};
  sort(vect.begin(), vect.end(), internalComparator);
  for (auto a : vect)
  {
    cout << a.first << " " << a.second << endl;
  }
}

int main()
{
  // explainPair();
  // explainVector();
  // explainList();
  // explainDeque();
  // explainStack();
  // explainQueue();
  // explainPQ();
  // explainSet();
  // explainMultiSet();
  // explainUnorderedSet();
  // explainMap();
  // explainUnorderedMap();
  // explainMultiMap();
  // explainSort();
  // explainAccumulate();
  // explainCount();
  // explainFind();
  // explainNextPermutation();
  // explainPrevPermutation();
  // explainMax();
  // explainMin();
  // explainReverse();
  explainComparator();

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int findMaximumCookieStudents(vector<int> &Student, vector<int> &Cookie)
{
  sort(Student.begin(), Student.end());
  sort(Cookie.begin(), Cookie.end());

  int l = 0;
  int r = 0;
  while (l < Student.size() && r < Cookie.size())
  {
    if (Cookie[r] >= Student[l])
    {
      l++;
    }
    r++;
  }
  return l;
}

int main()
{
  int s;
  cin >> s;
  vector<int> student;
  for (int i = 0; i < s; i++)
  {
    int data;
    cin >> data;
    student.push_back(data);
  }

  int c;
  cin >> c;
  vector<int> cookie;
  for (int i = 0; i < c; i++)
  {
    int data;
    cin >> data;
    cookie.push_back(data);
  }
  cout << findMaximumCookieStudents(student, cookie) << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> search(string pat, string txt)
{
  int n = txt.size();
  int m = pat.size();
  int hashTxt = 0;
  int hashPat = 0;
  int pRight = 1;
  int pLeft = 1;
  int mod = 101;
  int p = 7;
  vector<int> ans;
  for (int i = 0; i < m; i++)
  {
    hashTxt += ((txt[i] - 'a' + 1) * pRight) % mod;
    hashPat += ((pat[i] - 'a' + 1) * pRight) % mod;
    pRight = (pRight * p) % mod;
  }

  for (int i = 0; i <= n - m; i++)
  {
    if (hashTxt == hashPat)
    {
      ans.push_back(i);
    }
    hashTxt = (hashTxt - ((txt[i] - 'a' + 1) * pLeft) % mod + mod) % mod;
    hashTxt = (hashTxt + ((txt[i + m] - 'a' + 1) * pRight) % mod) % mod;
    hashPat = (hashPat * p) % mod;
    pLeft = (p * pLeft) % mod;
    pRight = (p * pRight) % mod;
  }
  return ans;
}

vector<int> searchBrute(string pat, string txt)
{
  vector<int> ans;
  int n = txt.size();
  int m = pat.size();
  for (int i = 0; i <= n - m; i++)
  {
    bool flag = true;
    for (int j = 0; j < m; j++)
    {
      if (pat[j] != txt[i + j])
      {
        flag = false;
        break;
      }
    }
    if (flag == true)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

int main()
{
  string txt, pat;
  cin >> txt >> pat;

  vector<int> ans = search(pat, txt);
  for (auto &it : ans)
  {
    cout << it << " ";
  }
}
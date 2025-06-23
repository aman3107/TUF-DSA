#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
  unordered_set<string> st(wordList.begin(), wordList.end());
  queue<vector<string>> q;
  q.push({beginWord});
  st.erase(beginWord);
  vector<string> usedOnLevel;
  usedOnLevel.push_back(beginWord);
  int level = 0;
  vector<vector<string>> ans;
  while (!q.empty())
  {
    vector<string> str = q.front();
    q.pop();
    if (str.size() > level)
    {
      level++;
      for (auto it : usedOnLevel)
      {
        st.erase(it);
      }
      usedOnLevel.clear();
    }
    string word = str.back();
    if (word == endWord)
    {
      if (ans.size() == 0)
        ans.push_back(str);
      else if (ans[0].size() == str.size())
        ans.push_back(str);
    }
    for (int i = 0; i < word.size(); i++)
    {
      char original = word[i];
      for (char ch = 'a'; ch <= 'z'; ch++)
      {
        word[i] = ch;
        if (st.find(word) != st.end())
        {
          str.push_back(word);
          q.push(str);
          usedOnLevel.push_back(word);
          str.pop_back();
        }
      }
      word[i] = original;
    }
  }
  return ans;
}

int main()
{

  int n;
  cin >> n;
  vector<string> wordList;
  for (int i = 0; i < n; i++)
  {
    string data;
    cin >> data;
    wordList.push_back(data);
  }
  string startWord;
  string targetWord;
  cout << "Enter startWord, targetWord" << endl;
  cin >> startWord >> targetWord;
  vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);
  for (auto str : ans)
  {
    for (auto it : str)
    {
      cout << it << " ";
    }
    cout << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
  unordered_set<string> st;
  // Insert all the words into the set
  for (auto it : wordList)
  {
    st.insert(it);
  }
  queue<pair<string, int>> q;
  q.push({startWord, 1});
  st.erase(startWord);
  int ans = 0;
  while (!q.empty())
  {
    string str = q.front().first;
    int level = q.front().second;
    if (str == targetWord)
    {
      return level;
    }
    q.pop();
    // Check for each word
    for (int i = 0; i < str.size(); i++)
    {
      char original = str[i];
      // Check for each words character
      for (int j = 0; j < 26; j++)
      {
        str[i] = 'a' + j;
        // If word exists in the set
        if (st.find(str) != st.end())
        {
          q.push({str, level + 1});
          st.erase(str);
        }
      }
      str[i] = original;
    }
  }
  return 0;
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
  cout << wordLadderLength(startWord, targetWord, wordList) << endl;
}
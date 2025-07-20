#include <bits/stdc++.h>
using namespace std;

/*
Intuition
A Trie is a specialized tree-like data structure that organizes and stores words in an efficient manner. Each node in a Trie represents a single character of a word, allowing for efficient addition, retrieval, and deletion of words.
In simpler terms, a Trie is an advanced information retrieval data structure. It outperforms more conventional data structures like Hashmaps and Trees in terms of the time complexity for various operations, making it particularly useful for tasks involving large sets of strings or words.
The Trie data structure is designed to store and quickly retrieve a collection of strings.
It arranges strings so that shared prefixes are stored once, which makes it very efficient for operations like searching for words with a specific prefix. This ability to quickly find all strings that start with a given prefix makes Tries particularly useful for applications like autocomplete and predictive text. Trie Node Structure
A Trie node is a fundamental element used to build a Trie. Each node consists of the following parts:

Child Node Links: A Trie node has an array of pointers, often referred to as "links" or "children pointers," for every letter of the lowercase alphabet. These pointers create connections to child nodes that represent each letter of the alphabet. For example, the link at index 0 corresponds to the child node for the letter 'a', the link at index 1 corresponds to 'b', and so on.
End-of-Word Flag: Each Trie node includes a boolean flag that signifies whether the node marks the end of a word. This flag is crucial for differentiating between prefixes and full words stored in the Trie.

Each node in the Trie supports several key operations:

Contains Key: This operation checks if a specific letter (or key) exists as a child node of the current Trie node. It returns true if the letter is present, indicating a valid path in the Trie.
Get Child Node: Given a letter, this operation retrieves the corresponding child node from the current Trie node. If the letter is present, it returns a pointer to the child node; otherwise, it returns null, indicating the letter is absent.
Put Child Node: This operation creates a link between the current Trie node and a child node representing a specific letter. It sets the link at the corresponding index to point to the given child node.
Set End Flag: This operation marks the current Trie node as the end of a word. This flag is essential for determining if a string stored in the Trie ends at this node, indicating a complete word.
Is End of Word: This operation checks if the current Trie node marks the end of a word by examining the end flag. It returns true if the node signifies the end of a word; otherwise, it returns false.

Approach
To insert a Node in The Trie
Begin at the root node.
For each character in the word:
Check if the current node has a child node for the character.
If the child node doesn't exist, create a new node and link it to the current node.
Move to the child node that corresponds to the character.
After inserting all characters, mark the end of the word by setting the end flag of the last node to true.

To search for a word in Trie
Begin at the root node.
For each character in the word:
Verify if the current node has a child node for the character.
If not, the word is not present in the Trie.
Move to the child node corresponding to the character.
After processing all characters, check if the end flag of the last node is set to true. If it is, the word is found; if not, the word is not in the Trie.

Check if Trie contains Prefix
Begin at the root node.
For each character in the prefix:
Check if the current node has a child node for the character.
If it doesn't, there is no word with the given prefix.
Move to the child node that corresponds to the character.
If all characters of the prefix are found, return true to indicate that there are words with the given prefix.


*/

class Node
{
  Node *links[26] = {nullptr};
  bool flag = false;

public:
  bool containsKey(char ch)
  {
    return (links[ch - 'a'] != nullptr);
  }

  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }

  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  void setEnd()
  {
    flag = true;
  }

  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool search(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
    }
    if (node->isEnd() == true)
      return true;
    return false;
  }

  bool startsWith(string prefix)
  {
    Node *node = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      if (!node->containsKey(prefix[i]))
      {
        return false;
      }

      node = node->get(prefix[i]);
    }
    return true;
  }
};
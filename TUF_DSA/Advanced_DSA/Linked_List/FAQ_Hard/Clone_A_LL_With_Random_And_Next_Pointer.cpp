#include <bits/stdc++.h>

using namespace std;

// Definition of singly linked list
struct ListNode
{
  int val;
  ListNode *next;
  ListNode *random;
  ListNode()
  {
    val = 0;
    next = NULL;
    random = NULL;
  }
  ListNode(int data1)
  {
    val = data1;
    next = NULL;
    random = NULL;
  }
  ListNode(int data1, ListNode *next1, ListNode *r)
  {
    val = data1;
    next = next1;
    random = r;
  }
};

class Solution
{

private:
  ListNode *connectNext(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *dummyNode = new ListNode(-1);
    ListNode *res = dummyNode;

    while (temp != nullptr)
    {
      res->next = temp->next;
      res = res->next;
      temp->next = temp->next->next;
      temp = temp->next;
    }
    return dummyNode->next;
  }

public:
  ListNode *copyRandomListOpti(ListNode *head)
  {
    ListNode *temp = head;
    while (temp != nullptr)
    {
      ListNode *nextElement = temp->next;
      ListNode *copyNode = new ListNode(temp->val);
      copyNode->next = temp->next;
      temp->next = copyNode;
      temp = nextElement;
    }
    temp = head;
    while (temp != nullptr)
    {
      ListNode *copyNode = temp->next;
      if (temp->random)
      {
        copyNode->random = temp->random->next;
      }
      else
      {
        copyNode->random = nullptr;
      }
      temp = temp->next->next;
    }
    return connectNext(head);
  }
  // Function to clone linked list with random pointers
  ListNode *copyRandomList(ListNode *head)
  {
    // If the head is null, return null
    if (!head)
      return NULL;

    /*Create an unordered_map to map
    original nodes to their corresponding copied nodes*/
    unordered_map<ListNode *, ListNode *> mpp;
    ListNode *temp = head;

    // Create copies of each node
    while (temp != NULL)
    {
      // Create new node with same value as original
      ListNode *newNode = new ListNode(temp->val);
      // Map to original node
      mpp[temp] = newNode;
      // Move to next node
      temp = temp->next;
    }

    // Reset temp
    temp = head;

    /*Connect the next and
    random pointers of the
    copied nodes using the map*/
    while (temp != NULL)
    {
      // Get copied node from the map
      ListNode *copyNode = mpp[temp];
      /*Set next pointer of copied node
      to the copied node of the next
      original node*/
      copyNode->next = mpp[temp->next];
      /*Set the random pointer of the
      copied node to the copied node of
      the random original node*/
      copyNode->random = mpp[temp->random];
      temp = temp->next;
    }

    // Return the head
    return mpp[head];
  }
};

// Function to print the linked list
void printClonedLinkedList(ListNode *head)
{
  while (head != nullptr)
  {
    // Print the data of the current node
    cout << "Data: " << head->val;
    // Print the data of the random pointer, if it exists
    if (head->random != nullptr)
    {
      cout << ", Random: " << head->random->val;
    }
    else
    {
      cout << ", Random: nullptr";
    }
    cout << endl;
    // Move to the next node
    head = head->next;
  }
}

int main()
{
  // Example linked list: 7 -> 14 -> 21 -> 28
  ListNode *head = new ListNode(7);
  head->next = new ListNode(14);
  head->next->next = new ListNode(21);
  head->next->next->next = new ListNode(28);

  // Assigning random pointers
  head->random = head->next->next;                   // 7 -> 21
  head->next->random = head;                         // 14 -> 7
  head->next->next->random = head->next->next->next; // 21 -> 28
  head->next->next->next->random = head->next;       // 28 -> 14

  // Print the original linked list
  cout << "Original Linked List with Random Pointers:" << endl;
  printClonedLinkedList(head);

  // Clone the linked list
  Solution solution;
  ListNode *clonedList = solution.copyRandomList(head);

  // Print the cloned linked list
  cout << "\nCloned Linked List with Random Pointers:" << endl;
  printClonedLinkedList(clonedList);

  return 0;
}
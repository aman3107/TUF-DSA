#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list:
struct ListNode
{
  int val;
  ListNode *next;
  ListNode *child;
  ListNode()
  {
    val = 0;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1)
  {
    val = data1;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1, ListNode *next1, ListNode *next2)
  {
    val = data1;
    next = next1;
    child = next1;
  }
};

class Solution
{
private:
  // Function to convert a vector to a linked list
  ListNode *convertArrToLinkedList(vector<int> &arr)
  {
    /* Create a dummy node to serve as
     the head of the linked list */
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    /* Iterate through the vector and
     create nodes with vector elements */
    for (int i = 0; i < arr.size(); i++)
    {
      // Create a new node with the vector element
      temp->child = new ListNode(arr[i]);

      // Update the temporary pointer
      temp = temp->child;
    }

    /* Return the linked list starting
     from the next of the dummy node */
    return dummyNode->child;
  }

  ListNode *mergeLL(ListNode *l1, ListNode *l2)
  {
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;
    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val < l2->val)
      {
        temp->child = l1;
        temp = l1;
        l1 = l1->child;
      }
      else
      {
        temp->child = l2;
        temp = l2;
        l2 = l2->child;
      }
      temp->next = nullptr;
    }
    if (l1 != nullptr)
    {
      temp->child = l1;
    }
    else
    {
      temp->child = l2;
    }
    return dummyNode->child;
  }

public:
  ListNode *flattenLinkedListOptimal(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }
    ListNode *newHead = flattenLinkedListOptimal(head->next);
    head = mergeLL(head, newHead);
    return head;
  }
  // Function to flatten a linked list with child pointers
  ListNode *flattenLinkedList(ListNode *head)
  {
    vector<int> arr;

    // Traverse through the linked list
    while (head != nullptr)
    {
      /* Traverse through the child
       nodes of each head node */
      ListNode *t2 = head;

      while (t2 != nullptr)
      {
        // Store each node's data in the array
        arr.push_back(t2->val);

        // Move to the next child node
        t2 = t2->child;
      }
      // Move to the next head node
      head = head->next;
    }

    // Sort the array containing node values
    sort(arr.begin(), arr.end());

    // Convert the sorted array back to a linked list
    return convertArrToLinkedList(arr);
  }
};

// Function to print the linked list
void printLinkedList(ListNode *head)
{
  while (head != nullptr)
  {
    cout << head->val << " ";
    head = head->child;
  }
  cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode *head, int depth)
{
  while (head != nullptr)
  {
    cout << head->val;

    /* If child exists, recursively
     print it with indentation */
    if (head->child)
    {
      cout << " -> ";
      printOriginalLinkedList(head->child, depth + 1);
    }

    // Add vertical bars for each level in the grid
    if (head->next)
    {
      cout << endl;
      for (int i = 0; i < depth; ++i)
      {
        cout << "| ";
      }
    }
    head = head->next;
  }
}

int main()
{
  // Create a linked list with child pointers
  ListNode *head = new ListNode(5);
  head->child = new ListNode(14);

  head->next = new ListNode(10);
  head->next->child = new ListNode(4);

  head->next->next = new ListNode(12);
  head->next->next->child = new ListNode(20);
  head->next->next->child->child = new ListNode(13);

  head->next->next->next = new ListNode(7);
  head->next->next->next->child = new ListNode(17);

  // Print the original linked list structure
  cout << "Original linked list:" << endl;
  printOriginalLinkedList(head, 0);

  // Creating an instance of Solution class
  Solution sol;

  // Function call to flatten the linked list
  ListNode *flattened = sol.flattenLinkedListOptimal(head);

  // Printing the flattened linked list
  cout << "\nFlattened linked list: ";
  printLinkedList(flattened);
  delete head;

  return 0;
}
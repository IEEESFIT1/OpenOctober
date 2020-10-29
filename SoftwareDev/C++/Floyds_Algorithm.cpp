// Contributed by Kartikey Sharma
// Contributed to OpenOctober
#include <bits/stdc++.h>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

void push(Node*& headRef, int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = headRef;
	headRef = newNode;
}

bool detectCycle(Node *head)
{
	Node *curr = head;
	unordered_set<Node*> set;

	while (curr)
	{
		if (set.find(curr) != set.end())
			return true;
		set.insert(curr);
		curr = curr->next;
	}
	return false;
}

int main()
{
	int keys[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(keys) / sizeof(keys[0]);

	Node* head = nullptr;
	for (int i = n - 1; i >= 0; i--)
		push(head, keys[i]);

	head->next->next->next->next->next = head->next->next;

	if (detectCycle(head))
		cout << "Cycle Found";
	else
		cout << "No Cycle Found";

	return 0;
}

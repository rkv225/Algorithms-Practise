/*
* Problem: Clone a linked list with next pointer and a random pointer pointing to a node within the linked list
* Solution: We will have new nodes created after every node and 
* we will read the random pointer and point new node's random to the respective position of new node.
* finally we will detach the new nodes to form a new linked list which will be replica of the original linked list
* Time Complexity: O(n) and O(1) space complexity
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node
{
	int value;
	node* next;
	node* random;
};

node* clone_linked_list(node* head)
{
	// step 1 - create dummy nodes
	node* curr = head;
	while (curr != NULL)
	{
		node* tmp = curr->next;
		curr->next = new node{ curr->value, tmp, NULL };
		curr = tmp;
	}

	// step2 - fill in random pointers
	curr = head;
	while (curr != NULL && curr->next != NULL)
	{
		curr->next->random = curr->random->next;
		curr = curr->next->next;
	}

	// step 3 - detach dummy nodes to create new linked list
	curr = head;
	node* cloned_head = curr->next;
	while (curr != NULL && curr->next != NULL)
	{
		node* tmp = curr->next;
		curr->next = curr->next->next;
		curr = curr->next;
		tmp->next = curr == NULL ? NULL : curr->next;
	}
	return cloned_head;
}

node* create_linked_list_random(int n, vector<pair<int, int>>& random)
{
	unordered_map<int, node*> map;
	node* head = new node{ 1, NULL, NULL };
	node* curr = head;
	map[1] = curr;
	for (int i = 2; i <= n; i++)
	{
		curr->next = new node{ i, NULL, NULL };
		curr = curr->next;
		map[i] = curr;
	}
	for (vector<pair<int, int>>::iterator it = random.begin(); it != random.end(); it++)
		map[(*it).first]->random = map[(*it).second];
	return head;
}

void print_linked_list(node* head)
{
	node* curr = head;
	while (curr != NULL)
	{
		cout << curr->value << "^" << curr->random->value << "|" << "->";
		curr = curr->next;
	}
	cout << endl;
}

int main()
{
	vector<pair<int, int>> randoms = { make_pair(1, 3), make_pair(2, 4), make_pair(3, 2), make_pair(4, 5), make_pair(5, 1) };
	node* head = create_linked_list_random(5, randoms);
	node* cloned_head = clone_linked_list(head);
	cout << "original list" << endl;
	print_linked_list(head);
	cout << "cloned list" << endl;
	print_linked_list(cloned_head);
}
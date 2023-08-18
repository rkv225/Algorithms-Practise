/*
* Tries are n-ary trees used for efficient searching. As compared to binary tress where branching factor is 2,
* here we increase the branching factor as per the data requirements. The time for search is then reduced to Olog(base t)n where t is branching factor.
* We are making trie for searching plain english words
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Node
{
public:
	char v;
	Node* child[26]; // 26 alphabets in english language
	int terminatingWord;
	Node(char x)
	{
		v = x;
		terminatingWord = 0;
		memset(child, NULL, sizeof(child[0]) * 26);
	}
};

class Trie 
{
public: 
	Trie()
	{
		rootNode = new Node('\0');
	}
	void Insert(string w) 
	{
		Node* currNode = rootNode;
		for (string::iterator ch = w.begin(); ch != w.end(); ch++)
		{
			int index = (*ch) - 'a';
			if (currNode->child[index] == NULL)
				currNode->child[index] = new Node((*ch));
			currNode = currNode->child[index];
		}
		currNode->terminatingWord++;
	}
	int Query(string w)
	{
		Node* currNode = rootNode;
		bool found = true;
		for (string::iterator ch = w.begin(); ch != w.end(); ch++)
		{
			int index = (*ch) - 'a';
			if (currNode->child[index] != NULL)
			{
				currNode = currNode->child[index];
			}
			else
			{
				found = false;
				break;
			}
		}
		if (found)
			return currNode->terminatingWord;
		return 0;
	}
private:
	Node* rootNode;
};

int main()
{
	Trie* t = new Trie();
	t->Insert("pqrs");
	t->Insert("pprt");
	t->Insert("psst");
	t->Insert("qqrs");
	t->Insert("pqrs");
	t->Insert("pqrd");
	cout << t->Query("pqr");
	return 0;
}

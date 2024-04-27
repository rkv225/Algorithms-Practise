// using linear probing
#include<iostream>
#include<vector>

using namespace std;

class hash_table
{
public:
	hash_table(int n)
	{
		size = n;		
		hash_set.assign(n, NULL);
	}
	bool insert(int k)
	{
		int p = hash_function(k);
		for (int i = 0; i < size; i++)
		{
			if (hash_set[pos(p + i)] == NULL)
			{
				hash_set[pos(p + i)] = k;
				return true;
			}
		}
		return false; //table is full
	}
	bool search(int k)
	{
		int p = hash_function(k);
		for (int i = 0; i < size; i++)
		{
			if (hash_set[pos(p + i)] == k)
				return true;
		}
		return false;
	}
	void remove(int k)
	{
		int p = hash_function(k);
		for (int i = 0; i < size; i++)
		{
			if (hash_set[pos(p + i)] == k)
			{
				hash_set[pos(p + i)] = NULL;
				return;
			}
		}
	}
private:
	int size;
	vector<int> hash_set;
	int hash_function(int x)
	{
		return x % size;
	}
	int pos(int p)
	{
		return p % size;
	}
};

int main()
{
	hash_table* probed_hash_table = new hash_table(8);
	probed_hash_table->insert(0);
	probed_hash_table->insert(7);
	probed_hash_table->insert(34);
	probed_hash_table->insert(87);
	probed_hash_table->insert(2);
	probed_hash_table->insert(54);
	probed_hash_table->insert(11);
	probed_hash_table->insert(21);

	bool found = probed_hash_table->search(87);
	found = probed_hash_table->search(6);

	probed_hash_table->remove(87);

	found = probed_hash_table->search(87);
}
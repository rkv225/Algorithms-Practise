#include<iostream>
#include<vector>

using namespace std;

class hash_table
{
public:
	hash_table(int n)
	{
		size = n;		
		hash_set.assign(n, vector<int>());
	}
	void insert(int k)
	{
		int p = hash_function(k);
		hash_set[p].push_back(k);
	}
	bool search(int k)
	{
		int p = hash_function(k);

		if (!hash_set[p].empty())
		{
			vector<int>::iterator it = hash_set[p].begin();
			while (it != hash_set[p].end())
			{
				if (*it == k)
                    return true;
				it++;
			}
		}
		return false;
	}
	void remove(int k)
	{
		int p = hash_function(k);

		if (!hash_set[p].empty())
		{
			vector<int>::iterator it = hash_set[p].begin();
			while (it != hash_set[p].end())
			{
				if (*it == k)
				{
					hash_set[p].erase(it);
					return;
				}
				it++;
			}
		}
	}
private:
	int size;
	vector<vector<int>> hash_set;
	int hash_function(int x)
	{
		return x % size;
	}
};

int main()
{
	hash_table* chained_hash_table = new hash_table(8);
	chained_hash_table->insert(0);
	chained_hash_table->insert(7);
	chained_hash_table->insert(34);
	chained_hash_table->insert(87);
	chained_hash_table->insert(2);
	chained_hash_table->insert(54);
	chained_hash_table->insert(11);
	chained_hash_table->insert(21);

	bool found = chained_hash_table->search(87);
	found = chained_hash_table->search(6);

	chained_hash_table->remove(87);

	found = chained_hash_table->search(87);
}
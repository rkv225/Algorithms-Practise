#include <iostream>
#include <unordered_map>

using namespace std;

class DisjointSet
{
private:
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
public:
	void MakeSet(int x) {
		if (parent.find(x) != parent.end()) 
			return;
		parent[x] = x;
		rank[x] = 0;
	}
	int FindSet(int x) {
		if (x != parent[x])
			parent[x] = FindSet(parent[x]);
		return parent[x];
	}
	void UnionSet(int x, int y) {
        int sx = FindSet(x);
        int sy = FindSet(y);
        if (sx == sy)
            return;
        if (rank[sx] >= rank[sy]) { 
            parent[sy] = sx; 
            rank[sx]++; 
        }
        else { 
            parent[sx] = sy; 
            rank[sy]++; 
        }
    }
};

int main()
{
	DisjointSet ds;
	ds.MakeSet(1);
	ds.MakeSet(2);
	ds.MakeSet(3);
	ds.MakeSet(4);
	ds.MakeSet(5);
	ds.MakeSet(6);
	ds.MakeSet(7);
	ds.MakeSet(8);
	int x;
	x = ds.FindSet(5); // 5
	x = ds.FindSet(3); // 3
	ds.UnionSet(5, 3);
	x = ds.FindSet(5); // 5
	x = ds.FindSet(3); // 5
	return 0;
}
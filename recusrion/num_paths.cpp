/*
* Find the number of paths in an nxm matrix, where from start you can only move right and down to reach end
*/

#include <iostream>

using namespace std;

class Maze
{
public:
	Maze(int r, int c)
	{
		rows = r;
		cols = c;
	}
	int find_path(int i, int j)
	{
		if (i >= rows || j >= cols) // if out of bounds
			return 0;
		if (i == rows - 1 && j == cols - 1) // reached end
			return 1; 
		return find_path(i, j + 1) + find_path(i + 1, j); // explore right and bottom and add paths discovered from both
	}
private:
	int rows;
	int cols;
};

int main()
{
	Maze m(1, 8);
	int paths = m.find_path(0, 0);
	cout << "Number of paths: " << paths << endl;
	return 0;
}
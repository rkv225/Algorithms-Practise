/*
Problem: 
Find the number of paths in an nxm matrix, where from start you can only move right and down to reach end
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Time Complexity: exponential

Link: https://leetcode.com/problems/unique-paths
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
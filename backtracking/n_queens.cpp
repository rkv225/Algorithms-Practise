/*
* N Queens problem of backtracking
* TimeComplexity: O(n^2)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> matrix;
int n;

bool check_matrix(int row, int col)
{
	int i = row, j = col;
	// up
	while (i >= 0)
	{
		if (matrix[i][j])
			return false;
		i--;
	}
	// down
	i = row;
	while (i < n)
	{
		if (matrix[i][j])
			return false;
		i++;
	}

	// left
	i = row;
	while (j >= 0)
	{
		if (matrix[i][j])
			return false;
		j--;
	}

	//right
	j = col;
	while (j < n)
	{
		if (matrix[i][j])
			return false;
		j++;
	}

	// top right
	j = col;
	while (i >= 0 && j < n)
	{
		if (matrix[i][j])
			return false;
		i--; 
		j++;
	}

	// top left
	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (matrix[i][j])
			return false;
		i--;
		j--;
	}
	// bottom right
	i = row;
	j = col;
	while (i < n && j < n)
	{
		if (matrix[i][j])
			return false;
		i++;
		j++;
	}
	// bottom left
	i = row;
	j = col;
	while (i < n && j >= 0)
	{
		if (matrix[i][j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool place_queen(int row, int col)
{
	if (row >= n)
		return true;
	bool safe = false;
	while (col < n && !safe)
	{
		safe = check_matrix(row, col);
		if (safe)
		{
			matrix[row][col] = true;
			safe = place_queen(row + 1, 0);
		}
		if (!safe)
			matrix[row][col] = false;
		col++;
	}
	return safe;
}

void print_matrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void NQueens(int nq)
{
	n = nq;
	matrix.resize(n);
	for (int i = 0; i < n; i++)
		matrix[i].assign(n, false);
	bool possible = place_queen(0, 0);
	if (possible)
		print_matrix();
	else
		cout << "Placing queens is not possible";
}

int main()
{
	NQueens(10);
	return 0;
}
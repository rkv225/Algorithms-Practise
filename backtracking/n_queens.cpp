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
	// check up down left right
	for (int k = 0; k < n; k++)
		if (matrix[k][col] || matrix[row][k])
			return false;

	// top right
	for (int i = row, j = col; i >= 0 && j < n; i--, j++)
		if (matrix[i][j])
			return false;

	// top left
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (matrix[i][j])
			return false;

	// bottom right
	for (int i = row, j = col; i < n && j < n; i++, j++)
		if (matrix[i][j])
			return false;

	// bottom left
	for (int i = row, j = col; i < n && j >= 0; i++, j--)
		if (matrix[i][j])
			return false;

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
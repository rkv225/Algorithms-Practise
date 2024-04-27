/*
* Find all the segments of days on which you buy and sell the stock so that in between those days for which profit can be generated.
* Note: You can buy stocks multiple times
* TimeComplexity: O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> stockBuySell(vector<int> &A, int n) {
    vector<vector<int>> res;
    int index = -1;
    bool hold = false;
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i] > A[i - 1])
        {
            if (!hold)
            {
                hold = true;
                res.push_back(vector<int> {i - 1, -1});
                index++;
            }
            res[index][1] = i;
            profit += A[i] - A[i - 1];
        }
        else
        {
            hold = false;
        }
    }
    res.push_back(vector<int> { n, profit });
    return res;
}

void print_result(vector<int>& A, int n, vector<vector<int>>& R, int rn)
{
    cout << "Stock Prices:" << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << "Buy Sell on" << endl;
    for (int i = 0; i < rn - 1; i++)
        cout << "buy-" << R[i][0] << ", sell-" << R[i][1] << endl;
    cout << "Total Profit:" << endl;
    cout << R[rn - 1][1];
}

int main()
{
    vector<int> A = { 100, 180, 260, 310, 40, 535, 695 };
    vector<vector<int>> R = stockBuySell(A, A.size());
    print_result(A, A.size(), R, R.size());
    return 0;
}
/*
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle in a fixed direction.
After each operation, the count will start from k+1th person.
The task is to choose the safe place in the circle so that when you perform these operations starting from 1st place in the circle, you are the last one remaining and survive.

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so
skipping 1 person i.e 1st person 2nd
person will be killed. Thus the safe
position is 3.

Link: https://www.scaler.com/topics/josephus-problem/
*/

#include <iostream>

using namespace std;

int josephus(int n, int k)
{
    if(n == 1)
        return 1;
    return ((josephus(n - 1, k) + k - 1) % n) + 1;
}

int main()
{
    int n = 3, k = 2;
    cout << "Safe Position: " << josephus(n, k) << endl;
}


/*
Solution: Using a list
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int josephusProblem(int n, int k){
    
    // creating a list of n people
    vector<int> person;
    for(int i =0;i<n;i++){
        person.push_back(i+1);
    }
    int n1 = n;
    int pos = 0;
    
    // in each iteration one person is eliminated
    // until only one person is left
    while(n1!=1){
        // position of next person to be killed
        pos = (pos+k-1)%n1;
        person.erase(person.begin()+pos);
        n1-=1;
    }
    
    // returning the position of last person remaining
    pos = pos%n1;
    return person.at(pos);
}
int main()
{
    // taking user input
    cout << "Enter number of people: ";
    int n, k;
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;
    
    // returning answer
    int ans = josephusProblem(n,k);
    cout << "The safe position for the Josephus problem is: " << ans;
}

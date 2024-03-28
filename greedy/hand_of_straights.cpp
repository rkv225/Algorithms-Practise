/*
Problem:
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:
Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

Solution:
1. Check the base condition that the number of cards must be divisible by groupSize
2. Make a set from the array of cards
3. As we know that we need to form a group of consecutive cards, taking the minimum and incrementing by 1 each time we find cards till group size 
4. if all cards of group are found then increment the group count
5. if any of the card belonging to group not found, then we return false

Time Complexity: O(n log n) , each operation take O(log n) on multiset for each number in array
Space Complexity: O(n) for multiset

Link: https://leetcode.com/problems/hand-of-straights/
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        int groups = n / groupSize;
        if(n % groupSize > 0)
            return false;
        multiset<int> set;
        for(int i = 0; i < n; i++)
            set.insert(hand[i]);
        int grp = 0;
        while(!set.empty()) {
            multiset<int>::iterator minit = set.begin();
            int minv = *minit;
            set.erase(minit);
            for(int i = 1; i < groupSize; i++) {
                multiset<int>::iterator x = set.find(minv + i);
                if(x == set.end())
                    return false;
                set.erase(x);
            }
            grp++;
        }
        return grp == groups;
    }
};
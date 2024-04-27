/*
Problem: You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.

Example:
Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.
Output: 3
Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.

Link: https://www.codingninjas.com/studio/problems/longest-common-substring_1235207

solution: if s[i] == t[j]   return 1 + f(i - 1, j - 1)
        else return 0;
It signifies that we only add the previous one if both are equal. otherwise we store current as 0. 
*/

/*
space optimized solution
*/

int lcs(string s, string t)
{
	vector<int> prev(t.size() + 1, 0);
	vector<int> curr(t.size() + 1, 0);
    int ans = 0;
	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
            if (s[i - 1] == t[j - 1]) {
            curr[j] = 1 + prev[j - 1];
            ans = max(ans, curr[j]);
            } else
            curr[j] = 0;
		}
		prev = curr;
	}
	return ans;
}
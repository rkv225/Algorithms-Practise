/*
Problem:
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.

Link: https://leetcode.com/problems/k-closest-points-to-origin/
*/

class Solution {
public:
    struct point {
        int x;
        int y;
        long long d; // distance from origin
    };
    class comparator {
        public:
            bool operator()(point a, point b) {
            return a.d < b.d;
        }
    };
    void calculate(point& a) {
        a.d = (a.x * a.x) + (a.y * a.y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<point, vector<point>, comparator> max_heap;
        for(int p = 0; p < points.size(); p++) {
            point a = { points[p][0], points[p][1], 0};
            calculate(a);
            max_heap.push(a);
        }
        while(max_heap.size() > k) {
            max_heap.pop();
        }
        vector<vector<int>> result;
        while(!max_heap.empty()) {
            point a = max_heap.top();
            max_heap.pop();
            result.push_back({a.x, a.y});
        }
        return result;
    }
};
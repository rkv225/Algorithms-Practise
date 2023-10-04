/*
* To calculate the distance between two points p & q we have the formula sqrt[(Px-Qx)^2 + (Py-Qy^2)]
* We use the divide and conquer strategy by repeatedly dividing the plane to 2 halves and 
* then finding the minimum distance i.e.  D1 from left plane and D2 from right plane and d = min(D1, D2)
* Now we draw a line in the middle of the plane and draw a strip having width of distance d to both sides
* (as we already found the minimum from both planes, so if we see no two points having distance < d will be on either side)
* next we find the minimum distance for all the points lying within the strip, and finally we return smallest distance
* Analysis: O(n log n) divide and conquer O(log n) and each time we find minimum of strip taking O(n)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999

struct point
{
	int x, y;
};

float calculate(point a, point b)
{
	return sqrt(pow((a.x - b.x), 2) + pow(a.y - b.y, 2));
}

bool point_comparator(point a, point b)
{
	return a.x < b.x;
}

// O(n) as the second loop doesn't run for more than 6 times
float find_closest_strip(vector<point> &s, float d)
{
	float min = d;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size() && abs(s[j].y - s[i].y) < min; j++)
		{
			float dist = calculate(s[i], s[j]);
			if (dist < min)
				min = dist;
		}
	}
	return min;
}

vector<point> find_strip(vector<point> &p, int left, int mid, int right, float d)
{
	vector<point> strip;

	// pushing points from left half within distance d on x-axis
	for (int j = mid; j >= left && abs(p[j].x - p[mid].x) <= d; j--)
		strip.push_back(p[j]);
	// pushing points from right half within distance d on x-axis
	for (int j = mid + 1; j <= right && abs(p[j].x - p[mid].x) <= d; j++)
		strip.push_back(p[j]);
	return strip;
}

float closest_finder(vector<point> &p, int u, int v)
{
	if (v == u)
		return INF;
	if (v - u == 1)
		return calculate(p[u], p[v]);

	int mid = (u + v) / 2;
	float d1 = closest_finder(p, u, mid);
	float d2 = closest_finder(p, mid + 1, v);
	float d = min(d1, d2);
	vector<point> strip = find_strip(p, u, mid, v, d);
	return find_closest_strip(strip, d);
}

float closest(vector<point> &p)
{
	sort(p.begin(), p.end(), point_comparator); // sort points on x-axis
	return closest_finder(p, 0, p.size() - 1);
}

int main()
{
	vector<point> p = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
	float closest_value = closest(p);
	cout << "Smallest distance between two points: " << closest_value << endl;
	return 0;
}
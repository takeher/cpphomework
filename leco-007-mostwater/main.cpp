#include<iostream>
#include<vector> 
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
	int area = 0;
	int l = height.size();
	if(l == 2){area = (height[0] > height[1]?height[1]:height[0]);return area;}
	for(int i = 0; i < l;++i){
		for(int j = i + 1; j < l;++j){
			int min = (height[i] > height[j]?height[j]:height[i]);
			area = (min*(j - i) > area)?(min*(j - i)):area;
		}
	}
	return area;
    }
};
int main(int argc, char *argv[])
{
	vector<int> height = {1,2,1};
	Solution sol;
	int area = sol.maxArea(height);
	cout << "area is:"<<area<<endl;
	return 0;
}
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};
*/

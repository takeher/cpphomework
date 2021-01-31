#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	int l = nums.size();
	bool same = false;
	if(l < 3){return ans;}
	for(int i = 0;i < l - 2;++i){
		for(int j = i + 1;j < l - 1;++j){
			int need = 0 - nums[i] - nums[j];
			for(int k = j + 1;k < l;++k){
				if( nums[k] == need ){
					vector<int> nu = {nums[i],nums[j],nums[k]};
					sort(nu.begin(),nu.end());	
					if(ans.size() >= 1){
						for (int n = 0;n < ans.size();++n){
							if(ans[n][0] == nu[0] && ans[n][1] == nu[1]){
								same = true;
								break;
							}	
						}
					}
					if(!same){
						ans.push_back(nu);
					}
					same = false;
				}
			}
		}
	}
	return ans;
    }
};
void print_vector(vector<vector<int>>& nums);
int main(int argc, char *argv[])
{
	vector<int> nums = {-1,0,1,2,-1,-4};
	Solution sol;
	vector<vector<int>> ans;
	ans = sol.threeSum(nums);
	print_vector(ans);
	return 0;
}
void print_vector( vector<vector<int>>& nums){
	for(int i = 0; i < nums.size();++i){
		for (int j = 0;j < nums[0].size();++j){
			cout<<nums[i][j]<<" ";
		}
		cout<<endl;
	}
}
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};
 */

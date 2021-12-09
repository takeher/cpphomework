#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int left = 0, right = people.size() - 1;
    int count = 0;
    while (left <= right) {
      if (left == right) {
        count++;
        break;
      } else if (people[left] + people[right] <= limit) {
        count++;
        left++;
        right--;
      } else if (people[left] + people[right] > limit) {
        count++;
        right--;
      }
    }
    return count;
  }
};
int main(){
  vector<int> people{1,2};
  cout<<"ans is:"<<(new Solution())->numRescueBoats(people, 3)<<endl;
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution0 {
private:
    long dist(const vector<int>& a, const vector<int>& b) {
        return (b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]);
    }
public:
    bool validSquare(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
        vector<vector<int>> p(4, vector<int>());
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        p[3] = p4;

        sort(p.begin(), p.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? b[1] < a[1] : b[0] < a[0];
        });

        long d01 = dist(p[0], p[1]);
        long d13 = dist(p[1], p[3]);
        long d32 = dist(p[3], p[2]);
        long d20 = dist(p[2], p[0]);
        // 对角线必须相等
        long d03 = dist(p[0], p[3]);
        long d12 = dist(p[1], p[2]);
        return d01 == d13 && d13 == d32 && d32 == d20 && d03 == d12;
    }
};

class Solution {
public:
    bool validSquare(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4) {
        if(p1==p2||p1==p3||p1==p4)return false;
        vector<vector<int>>points={p1,p2,p3,p4};
        auto cmp=[&](vector<int>&a,vector<int>&b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        };
        sort(points.begin(),points.end(),cmp);
        int dist01=getDist(points[0],points[1]);
        int dist13=getDist(points[1],points[3]);
        if(dist13!=dist01)return false;
        int dist32=getDist(points[3],points[2]);
        if(dist32!=dist01)return false;
        int dist20=getDist(points[2],points[0]);
        if(dist20!=dist01)return false;
        int dist12=getDist(points[1],points[2]);
        int dist03=getDist(points[0],points[3]);
        if(dist03!=dist12)return false;
        return true;
    }
    int getDist(vector<int>&a,vector<int>&b){
        return pow(a[0]-b[0],2)+pow(a[1]-b[1],2);
    }
};

int main(){
  cout << "ans is:"
       << (new Solution())->validSquare(vector<int>{0,0}, vector<int> {1,1}, vector<int> {1,0},vector<int> {0,1});
  return 0;
}

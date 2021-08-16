#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double rad, xc, yc;
    //c++11 random floating point number generation
    mt19937 rng{random_device{}()};
    uniform_real_distribution<double> uni{0, 1};

    Solution(double radius, double x_center, double y_center) {
        rad = radius, xc = x_center, yc = y_center;
    }

    vector<double> randPoint() {
        double d = rad * sqrt(uni(rng));
        double theta = uni(rng) * (2 * M_PI);
        return {d * cos(theta) + xc, d * sin(theta) + yc};
    }
};
int main(int argc, char *argv[])
{
	double radius = 1;
	double x_center = 0;
	double y_center = 0;
	Solution* obj = new Solution(radius, x_center, y_center);
	vector<double> param_1 = obj->randPoint();
	cout<<"ans is:";
	for(int i = 0;i< param_1.size();++i){
		cout<<param_1[i]<<" ";
	}
	return 0;
}

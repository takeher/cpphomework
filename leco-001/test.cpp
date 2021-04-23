#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
	vector<vector<int>> m;
	m[0].push_back(1);
	m[1].push_back(2);
	cout<<m[0][0]<<endl;
	cout<<m[1][0]<<endl;
	return 0;
}

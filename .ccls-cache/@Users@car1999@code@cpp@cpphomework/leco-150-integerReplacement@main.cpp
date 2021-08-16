#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findf(vector<int>& f, vector<double>& w, int x) {
        if (f[x] != x) {
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        }
        vector<int> f(nvars);
        vector<double> w(nvars, 1.0);
        for (int i = 0; i < nvars; i++) {
            f[i] = i;
        }

        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            merge(f, w, va, vb, values[i]);
        }
        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
                int ia = variables[q[0]], ib = variables[q[1]];
                int fa = findf(f, w, ia), fb = findf(f, w, ib);
                if (fa == fb) {
                    result = w[ia] / w[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
	//equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
	vector<vector<string>> equations;
	vector<string> s1 {"a","b"};
	vector<string> s2 {"b","c"};
	equations.push_back(s1);
	equations.push_back(s2);
	vector<double> values {2.0,3.0};
	vector<vector<string>> queries;
	vector<string> q1 {"a","c"};
	vector<string> q2 {"b","a"};
	vector<string> q3 {"a","e"};
	vector<string> q4 {"a","a"};
	vector<string> q5 {"x","x"};
	queries.push_back(q1);
	queries.push_back(q2);
	queries.push_back(q3);
	queries.push_back(q4);
	queries.push_back(q5);
	Solution sol;
	auto ans = sol.calcEquation(equations, values, queries);
	cout<<"ans is:";
	for(int i = 0;i < ans.size();++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}

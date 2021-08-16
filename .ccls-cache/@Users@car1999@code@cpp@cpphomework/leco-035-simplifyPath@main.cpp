#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> strs;
        strs.reserve(20);
        string curr;
        while (getline(ss, curr, '/'))
        {
            if (curr != "." && curr != "")
            {
                if (curr != "..")
                {
                    strs.push_back(curr);
                }
                else if (!strs.empty())
                {
                    strs.pop_back();
                }
            }
        }

        if (!strs.empty())
        {
            string res = "";
            for (string str : strs)
            {
                res.append("/");
                res.append(str);
            }
            return res;
        }
        else
        {
            return "/";
        }
    }
};
int main(int argc, char *argv[])
{
	string path = "/a/./b/../../c/";
	Solution sol;
	cout<<"path is:"<<path<<endl;
	string ans = sol.simplifyPath(path);
	cout<<"after simplify:"<<ans<<endl;
	return 0;
}

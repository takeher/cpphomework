#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int transfer(string s)
    {
        int n = s.length();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res = res * 10 + s[i]-'0';
        }
        return res;
    }

    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        int l = 0, r = 0;
        int a = 0, b = 0;
        while(r < n1 && b < n2)
        {
            while(r < n1 && version1[r] != '.')
                r++;
            int num1 = transfer(version1.substr(l, r-l));
            l = r+1;
            r++;
            while(b < n2 && version2[b] != '.')
                b++;
            int num2 = transfer(version2.substr(a, b-a));
            a = b+1;
            b++;
            if(num1 > num2)
                return 1;
            if(num1 < num2)
                return -1;
        }
        if(r < n1)
        {
            while(r < n1)
            {
                if(version1[r] > '0' && version1[r] <= '9')
                    return 1;
                r++;
            }
        }
        else
        {
            while(b < n2)
            {
                if(version2[b] > '0' && version2[b] <= '9')
                    return -1;
                b++;
            }
        }
        return 0;
    }
};
int main(int argc, char *argv[])
{
	string version1 = "1.01";
	string version2 = "1.001";
	Solution sol;
	int ans = sol.compareVersion(version1, version2);
	cout<<"ans is:"<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;


string stringReplace (const string& source,
                      const string& toReplace,
                      const string& replaceWith)
{
  size_t pos = 0;
  size_t cursor = 0;
  int repLen = toReplace.length();
  stringstream builder;

  do
  {
    pos = source.find(toReplace, cursor);

    if (string::npos != pos)
    {
        //copy up to the match, then append the replacement
        builder << source.substr(cursor, pos - cursor);
        builder << replaceWith;

        // skip past the match 
        cursor = pos + repLen;
    }
  } 
  while (string::npos != pos);

  //copy the remainder
  builder << source.substr(cursor);

  return (builder.str());
}

class Solution {
public:
    bool canTransform(string start, string end) {
        if (stringReplace(start, "X", "") != stringReplace(end, "X", ""))
        {
            return false;
        }

        // 依次遍历去判断L和R是否满足相对位置需要
        // end里对应的序号
        int d = 0;
        for (int i = 0; i < start.size(); ++i)
        {
            if (start[i] == 'L')
            {
                while (end[d] != 'L')
                {
                    ++d;
                }
                if (i < d)
                {
                    // cout << "L " << i << " " << d << endl;
                    return false;
                }
                ++d;
            }
        }

        d = 0;
        for (int i = 0; i < start.size(); ++i)
        {
            if (start[i] == 'R')
            {
                while (end[d] != 'R')
                {
                    ++d;
                }
                if (i > d)
                {
                    // cout << "R " << i << " " << d << endl;
                    return false;
                }
                ++d;
            }
        }

        return true;
    }
};
int main(){
  cout << "ans is:"
       << (new Solution())->canTransform("RXXLRXRXL", "XRLXXRRLX")<<endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int emailsCount = 0;
        for (auto& account : accounts) {
            string& name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++) {
                string& email = account[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = emailsCount++;
                    emailToName[email] = name;
                }
            }
        }
        UnionFind uf(emailsCount);
        for (auto& account : accounts) {
            string& firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++) {
                string& nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                uf.unionSet(firstIndex, nextIndex);
            }
        }
        map<int, vector<string>> indexToEmails;
        for (auto& [email, _] : emailToIndex) {
            int index = uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index] = account;
        }
        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            string& name = emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto& email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};
int main(){
  //[["John", "johnsmith@mail.com", "john00@mail.com"],
  //[ "John", "johnnybravo@mail.com"],
  //[ "John", "johnsmith@mail.com", "john_newyork@mail.com"],
  //[ "Mary", "mary@mail.com"]]
  vector<vector<string>> accounts{
    vector<string>{"John", "johnsmith@mail.com", "john00@mail.com"},
        vector<string>{"John", "johnnybravo@mail.com"},
        vector<string>{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        vector<string> {"Mary", "mary@mail.com"}};
  auto ans = (new Solution())->accountsMerge(accounts);
  cout<<"ans is:"<<endl;
  for_each(ans.begin(), ans.end(),[](vector<string> &str){for_each(str.begin(),str.end(),[](string s){cout<<s<<endl;}) ;cout<<endl;});
  return 0;
}

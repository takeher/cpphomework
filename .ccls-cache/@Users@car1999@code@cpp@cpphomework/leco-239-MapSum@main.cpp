#include <bits/stdc++.h>
using namespace std;
struct TrieNode {
    int val;
    vector<TrieNode*> v;
    TrieNode(int val) {
        this->val = 0;
        this->v.resize(26);
    }
};

class MapSum {
private:
    int dfs(TrieNode* curr) {
        if(curr == nullptr) return 0;

        int res = curr->val;
        for(auto& c : curr->v) {
            if(c != nullptr) {
                res += dfs(c);
            }
        }
        return res;
    }

public:
    TrieNode* root;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(0);
    }
    void insert(string key, int val) {
        TrieNode* curr = root;
        for(auto& k : key) {
            if(curr->v[k - 'a'] == nullptr) {
                curr->v[k - 'a'] = new TrieNode(0);
            }
            curr = curr->v[k - 'a'];
        }
        curr->val = val;
    }
    int sum(string prefix) {
        int res = 0;
        TrieNode* curr = root;
        for(auto& p : prefix) {
            if(curr->v[p - 'a'] == nullptr) return 0;
            curr = curr->v[p - 'a'];
        }
        res += curr->val;
        for(auto& c : curr->v) res += dfs(c);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
int main(){
  MapSum* obj = new MapSum();
  cout<<"ans is:";
  obj->insert("apple", 3);
  cout<<obj->sum("ap")<<" ";
  obj->insert("app", 2);
  cout<<obj->sum("ap")<<endl;
  return 0;
}

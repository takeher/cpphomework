#include <bits/stdc++.h>
using namespace std;
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<string>> container;
    MagicDictionary() {
    }
    void buildDict(vector<string> dictionary) {
        for (auto e : dictionary) {
            auto proto = e;
            for (int i = 0; i < e.size(); ++i) {
                char c = e[i];
                e[i] = '_';
                container[e].emplace_back(proto);
                e[i] = c;
            }
        }
    }
    bool search(string searchWord) {
        auto e = searchWord;
        for (int i = 0; i < searchWord.size(); ++i) {
            char c = searchWord[i];
            searchWord[i] = '_';
            if (container.find(searchWord) != container.end() && (container[searchWord].size() > 1 || container[searchWord][0] != e)) return true;
            searchWord[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main(){
  MagicDictionary *obj = new MagicDictionary();
  vector<string> dictionary{"hello", "leetcode"};
  string searchWord = "hello";
  obj->buildDict(dictionary);
  bool param_2 = obj->search(searchWord);
  cout<<"ans is:"<<param_2<<endl;
  return 0;
}

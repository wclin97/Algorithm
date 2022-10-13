/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start

class TrieNode {
 private:
  vector<TrieNode*> next;
  bool isEnd;

 public:
  TrieNode() : next(26),isEnd(false) {}  //内联函数，因为函数定义在类内部所以可以省略 incline

  string ans;
  int maxn;

  void insert(string word) {
    TrieNode* node = this;
    bool solution = true;
    int n = word.size();
    for (int i = 0; i < n; i++) {
      if (node->next[word[i] - 'a'] == nullptr) {
        node->next[word[i] - 'a'] = new TrieNode();
      }

      node = node->next[word[i] - 'a'];
      //如果当前的字符非 word
      //的末尾字符（即本次应添加的字符），且当前节点非任何之前的字符串的结尾，那么就不是我们要找的答案
      if (i != n - 1 && !node->isEnd) {
        solution = false;
      }
    }
    node->isEnd = true;
    if (solution && n > maxn) {
      ans = word;
      maxn = n;
    }
  }

  string longestWord(vector<string>& words) {
    sort(
        words.begin(), words.end(),
        [](string& a,
           string&
               b) {  //这种写法叫做匿名函数
                     // https://blog.csdn.net/qq_43557907/article/details/125667737
          if (a.size() == b.size()) {
            return a < b;
          } else {
            return a.size() < b.size();
          }
        });
    ans = "";
    maxn = 0;
    TrieNode* node = this;
    for (auto& s : words) {
      insert(s);
    }
    return ans;
  }
};

// @lc code=end

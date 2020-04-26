#define MAP  // 200ms/31.7MB
// #define VECTOR // 192ms/69.9MB

class Trie {
 private:
  class TreeNode {
   private:
    char val;
#ifdef VECTOR
    vector<TreeNode*> children;
#endif
#ifdef MAP
    map<char, TreeNode*> children;
#endif

   public:
    bool is_word;
#ifdef VECTOR
    TreeNode(char val, vector<TreeNode*> children, bool is_word)
        : val(val), children(children), is_word(is_word){};
    TreeNode(char val) : TreeNode(val, vector<TreeNode*>(26, nullptr), false) {}
    TreeNode* get_child(const char c) const { return this->children[c - 'a']; }
    void insert_child(TreeNode* node) {
      this->children[node->val - 'a'] = node;
    }
#endif
#ifdef MAP
    TreeNode(char val, map<char, TreeNode*> children, bool is_word)
        : val(val), children(children), is_word(is_word){};
    TreeNode(char val) : TreeNode(val, map<char, TreeNode*>(), false) {}
    TreeNode* get_child(const char c) const {
      auto child_pair = this->children.find(c);
      if (child_pair != this->children.end()) {
        return child_pair->second;
      } else {
        return nullptr;
      }
    }
    void insert_child(TreeNode* node) { this->children[node->val] = node; }
#endif
  };

  TreeNode* root;

 private:
  TreeNode* searchPrefix(string prefix) {
    TreeNode* curr = this->root;
    for (char c : prefix) {
      TreeNode* child = curr->get_child(c);
      if (child == nullptr) {
        return nullptr;
      }
      curr = child;
    }
    return curr;
  }

 public:
  /** Initialize your data structure here. */
  Trie() : root(new TreeNode('.')) {}
  ~Trie() { delete root; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    TreeNode* curr = this->root;
    for (char c : word) {
      TreeNode* child = curr->get_child(c);
      if (child == nullptr) {
        child = new TreeNode(c);
        curr->insert_child(child);
      }
      curr = child;
    }
    curr->is_word = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TreeNode* last_node = this->searchPrefix(word);
    return (last_node != nullptr) && (last_node->is_word);
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    return (this->searchPrefix(prefix) != nullptr);
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#ifdef DEBUG

REGISTER_TEST(example1) {
  Trie trie = Trie();

  bool ret = true;
  trie.insert("apple");
  ret &= (trie.search("apple") == true);    // returns true
  ret &= (trie.search("app") == false);     // returns false
  ret &= (trie.startsWith("app") == true);  // returns true
  trie.insert("app");
  ret &= (trie.search("app") == true);  // returns true
  return ret;
}

#endif
//https://leetcode.com/problems/implement-trie-prefix-tree/
//https://www.codingninjas.com/codestudio/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
class TrieNode{
public:
  char data;
  TrieNode* children[26];
  bool isTerminate;
  TrieNode(char data){
    this->data=data;
    for(int i=0;i<26;i++){
      children[i]=NULL;
    }
    isTerminate=false;
  }
};
class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root , string word){
        //if word is end
        if(word.length()==0){
          root->isTerminate=true;
          return;
        }
        TrieNode* child;
        int index=word[0]-'a';  //find index for current word
        //if character is found in trie
        if(root->children[index]!=NULL){
          child=root->children[index];
        }
        //if not found
        else{
          child=new TrieNode(word[0]);
          root->children[index]=child;
        }
        //recursion
        insertUtil(child , word.substr(1));
    }
    
    void insert(string word) {
        insertUtil(root , word);
    }
    
    bool searchUtil(TrieNode* root , string word){
        if(word.length()==0){
          return root->isTerminate;
        }
        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
          child=root->children[index];
        }
        else{
          return false;
        }
        return searchUtil(child , word.substr(1));
    }
    
    bool search(string word) {
        return searchUtil(root , word);
    }
    
    bool prefixUtil(TrieNode* root , string word){
        if(word.length()==0){
          return true;
        }
        int index=word[0]-'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
          child=root->children[index];
        }
        else{
          return false;
        }
        return prefixUtil(child , word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root , prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

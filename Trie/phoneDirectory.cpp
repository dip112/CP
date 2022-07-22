//https://practice.geeksforgeeks.org/problems/phone-directory4628/1
//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
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

class Trie{
public:
  TrieNode* root;
  Trie(){
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
  void insertWord(string word){
    insertUtil(root , word);
  }
    
  void printSuggestion(TrieNode* curr , string prefix , vector<string>&temp){
      if(curr->isTerminate){
          temp.push_back(prefix);
      }
      for(char ch='a';ch<='z';ch++){
          TrieNode* next=curr->children[ch-'a'];
          if(next!=NULL){
              prefix.push_back(ch);
              printSuggestion(next , prefix , temp);
              prefix.pop_back();
          }
      }
  }  
    
  vector<vector<string>> contactSuggestion(string queryStr){
      vector<vector<string>>ans;
      TrieNode* prev=root;
      string prefix="";
      for(int i=0;i<queryStr.size();i++){
          char lastCh=queryStr[i];
          prefix.push_back(lastCh);
          TrieNode* curr=prev->children[lastCh-'a'];
          if(curr==NULL){
              break;
          }
          vector<string>temp;
          printSuggestion(curr , prefix , temp);
          ans.push_back(temp);
          temp.clear();
          prev=curr;
      }
      return ans;
  }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t=new Trie();
    for(int i=0;i<contactList.size();i++){
        t->insertWord(contactList[i]);
    }
    return t->contactSuggestion(queryStr);
}

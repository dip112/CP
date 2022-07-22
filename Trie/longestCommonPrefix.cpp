//https://leetcode.com/problems/longest-common-prefix/
//https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
//approach1
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    for(int i=0;i<arr[0].size();i++){
        char ch=arr[0][i];
        bool match=true;
        for(int j=1;j<n;j++){
            if(arr[j].size()<i || ch!=arr[j][i]){
                match=false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
//Time: O(m*n) m-size of string and n-size of array
//Space: O(m) or O(1)

//approach2
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int countNode;
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        countNode=0;
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root , string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->countNode++;
            root->children[index]=child;
        }
        insertUtil(child , word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root , word);
    }
    void lcp(string first , string &ans){
        for(int i=0;i<first.size();i++){
            char ch=first[i];
            if(root->countNode==1){
                ans.push_back(ch[i]);
                int index=ch[i]-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal==true){
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t=new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    
    string first=arr[0];
    string ans="";
    t->lcp(first , ans);
    return ans;
}
//Time: O(m*n)
//Space: O(m*n)

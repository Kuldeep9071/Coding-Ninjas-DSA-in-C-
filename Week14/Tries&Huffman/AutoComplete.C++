#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } 
            else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    TrieNode* SearchWord(TrieNode* root,string word){
        if(word.size()==0){
            return root;
        }
        TrieNode* ans=NULL;
        int childIndex=word[0]-'a';
        TrieNode* child=root->children[childIndex];
        if(child!=NULL) ans=SearchWord(child,word.substr(1));
        return ans;
    }
    TrieNode* search(string word) {
        return SearchWord(root,word);
    }
    void print(TrieNode* root,string s,string &path){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                path.push_back(root->children[i]->data);
                if(root->children[i]->isTerminal) cout<<s+path<<"\n";
                print(root->children[i],s,path);
                path.pop_back();
            }
        }
    }
    void autoComplete(vector<string> input, string pattern) {
        int n=input.size();
        for(int i=0;i<n;i++){
            insertWord(input[i]);
        }
        TrieNode* vertex=search(pattern);
        string path="";
        if(vertex==NULL) return;
        if(vertex->isTerminal) cout<<pattern<<"\n";
        print(vertex,pattern,path);
    }
};

/*
Problem statement
Given n number of words and an incomplete word w. You need to auto-complete that word w.

That means, find and print all the possible words which can be formed using 
the incomplete word w.

Note : Order of words does not matter.

Detailed explanation ( Input/output format, Notes, Images )

Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 1 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"

*/
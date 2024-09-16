#include <bits/stdc++.h> 
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
            } else {
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
    bool SearchWord(TrieNode* root,string word){
        if(word.size()==0){
            return true;
        }
        bool ans=false;
        int childIndex=word[0]-'a';
        TrieNode* child=root->children[childIndex];
        if(child!=NULL) ans=SearchWord(child,word.substr(1));
        return ans;
    }
    bool search(string word) {
        return SearchWord(root,word);
    }
    bool patternMatching(vector<string> vect, string pattern) {
        for(int i=0;i<vect.size();i++){
            for(int j=0;j<vect[i].size();j++){
                insertWord(vect[i].substr(j));
            }
        }
        return search(pattern);
    }
};

/*
Problem statement
    Given a list of n words and a pattern p that we want to search. Check if the pattern p is
    present the given words or not. Return true if the pattern is present and false otherwise.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 1 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
*/
/*
Problem statement
Implement the function Search for the Trie class.

For a Trie, write the function for searching a word. Return true if
 the word is found successfully, otherwise return false.

Note : main function is given for your reference which we are using internally
        to test the code and all characters are from in small case (a-z).
*/

/*-----Trie Class-----*/
#include<bits/stdc++.h>
using namespace std;

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
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }
    bool SearchWord(TrieNode* root,string word){
        if(word.size()==0){
            if( root->isTerminal) return true;
            else return 0;
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
};
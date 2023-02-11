#include <bits/stdc++.h>
using namespace std;

/*
insert, search time : O(key.len)
space : O(26*wordCount*key.len)
*/

struct Node {
    Node *children[26];
    bool isEndOfWord  = false;

    bool containsKey(char key){
        return (children[key-'a'] != NULL);
    }
    void put(char ch){
        children[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return children[ch-'a'];
    }
    void setEnd(){
        isEndOfWord = true;
    }
    bool isEnd(){
        return isEndOfWord;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insertWord(string word){
        Node* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!curr->containsKey(word[i])){
                curr->put(word[i]);
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();
    }

    
    bool searchWord(string word){
        Node *curr = root;
        for(int i=0; i<word.size(); i++){
            if(!curr->containsKey(word[i])){
                return false;
            }
            curr = curr->get(word[i]);
        }
        return curr->isEnd();
    }

    bool startsWith(string prefix){
        Node *curr = root;
        for(int i=0; i<prefix.size(); i++){
            if(!curr->containsKey(prefix[i])){
                return false;
            }
            curr = curr->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    Trie* trie = new Trie();

    trie->insertWord("apple");
    trie->insertWord("app");
    trie->insertWord("abc");

    cout << "\nWord exist: \n";
    trie->searchWord("app");
    trie->searchWord("apple");
    cout << trie->searchWord("apps") << endl;

    cout << "\nStarts with : \n";
    cout << trie->startsWith("ap") << '\n';
    cout << trie->startsWith("a") << '\n';
    cout << trie->startsWith("auto") << '\n';

}
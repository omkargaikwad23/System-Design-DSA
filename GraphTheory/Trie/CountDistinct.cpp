#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26]; 
    bool flag = false; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void setEnd() {
        flag = true; 
    }
    bool isEnd() {
        return flag; 
    }
}; 

int countDistinctSubstrings(string &s)
{
    Node* root = new Node(); 
    int n = s.size(), cnt = 0;
    for(int i = 0; i<n; i++)
    {
        Node* node = root; 
        for(int j = i; j<n; j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node()); 
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1;
}

int main(){
    string str = "abab";
    cout << countDistinctSubstrings(str);
}

/*
INPUT:
2
aa
abab

OUTPUT:
3
8

In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.

In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }
*/
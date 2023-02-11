#include <bits/stdc++.h>
using namespace std;

int count0InString(string s){
    return count(s.begin(), s.end(), '0');
}

void stringToWord(){
    string str = "my name is omkar", word;
    stringstream ss(str);
    while(ss >> word){
        cout << word << "_";
    }

    cout << "\n";
    getline(ss, word, ' ');
    cout << word << "-";

    string line;
    cout << "\nEnter the statement:";
    getline(cin, line);

    cout << line << "\n";
}

void stringStream(){
    string word = "omkar gaikwad (Pune)";
    stringstream ss(word);
    string name;
    getline(ss, name, ' '); // store 'omkar' in name
    cout << name << endl; 
    cout << word.substr(0, word.find('(')) << endl;
}

int main(){
    // stringToWord();
    stringStream();
}
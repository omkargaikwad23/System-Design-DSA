#include <bits/stdc++.h>
using namespace std;
#define ll long long


class RabinKarpSearch{
private:
    int prime = 101;
public:
    int patternSearch(string text, string pattern){
        int m = pattern.length();
        int n = text.length();

        long long patternHash = createHash(pattern, m-1);
        long long textHash = createHash(text, m-1); 
        
        for(int i=1; i<n-m+1; i++){
            if(patternHash == textHash && checkEqual(text, i-1, i+m-2, pattern, 0, m-1)){
                return i-1;
            }
            if(i<n-m+1){
                textHash = recalculateHash(text, i-1, i+m-1, textHash, m);
            }
        }
        return -1;
    }

    //to calculate hash value
    // str[0]*pow(101, 0) + str[1]*pow(101, 1);
    long long createHash(string str, int end){
        long long hash = 0;
        for(int i=0; i<=end; i++){
            hash += str[i]*pow(prime, i);
        }
        for(int i=0; i<=end; i++) 
            cout << str[i];
        cout << ": " << hash << endl;
        return hash;
    }

    //aabc
    //oldHash(aab) = 120, neHash(abc) = 120 - str[0]
    long long recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patternLen){
        ll newHash = oldHash - str[oldIndex];
        newHash += str[newIndex]*pow(prime, patternLen - 1);
        cout << str[oldIndex] << " " << str[newIndex] << endl;
        cout << oldHash << " " << newHash << endl;
        return newHash;
    }

    bool checkEqual(string str1,int start1, int end1, string str2, int start2, int end2){
        if(end1-start1 != end2 - start2){
            return false;
        }
        while(start1 <= end1 && start2 <= end2){
            if(str1[start1] != str2[start2]){
                return false;
            }
            start1++;
            start2++;
        }
        return true;
    }
};

int main(){
    RabinKarpSearch rks;
    string text = "omkar";
    string pattern = "mk";
    char textArr[text.length()], patternArray[pattern.length()];
    strcpy(textArr, text.c_str());
    strcpy(patternArray, pattern.c_str());
    int result = rks.patternSearch(text, pattern);
    cout << result << endl;
    return 0;
}
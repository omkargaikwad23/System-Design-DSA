#include <bits/stdc++.h>
using namespace std;

class  StringCalculator{
public:
    int add(string str){
        int n = str.size(), sum = 0;
        string num = "";

        bool newLine = false, isNeg = false;
        vector<int> negativeNums;

        for(int i=0; i<n; i++){
            char ch = str[i];
            
            if(isdigit(ch)){
                num += ch;
            }
            else if(isalpha(ch)){
                int temp = ch - 'a' + 1;
                num += to_string(temp);
            }
            else if((int)ch == 10 || ch==';'){
                newLine = true;
            }
            else if(ch == '-'){
                isNeg = true;
                continue;
            }
            else if(ch != ','){
                continue;
            }

            if((ch == ',' || i == n-1 || newLine) && num.size()>0){
                // cout << num << " ";
                int number = stoi(num);
                num = "";

                if(isNeg){
                    negativeNums.push_back(-number);
                    isNeg = false;
                    continue;
                }
                newLine = false;

                if(number > 1000) continue;
                sum += number;
            }
        }

        if(negativeNums.size() > 0){
            for(auto& negNum : negativeNums){
                cout << negNum << " ";
            }
            cout << endl;
            throw invalid_argument( "Negatives not allowed" );
        }

        return sum;
    }
};

int main()
{
    StringCalculator sc;
    int result = sc.add("\n1***3**3");
    cout << result << endl;
    return 0;
}
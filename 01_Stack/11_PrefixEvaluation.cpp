#include <bits/stdc++.h>
using namespace std;

// Chances of Mistake:-
// 1. Always reverse the string.  reverse(str.begin(), str.end())    
// 2. Convert character to integer (symbol-'0')
// 3. Firstly Pop a, then b 
// 4. Use pow(a,b) instead of a^b

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    stack<int> S;
    int i=0;

    while(i<str.size()){
        char symbol=str[i];
        i++;
        if(symbol>='0' && symbol<='9'){
            S.push(symbol-'0');
        }
        else{
            // IMPROVEMENT 1: Check stack has 2 operands
            if(S.size()<2){
                cout<<"Invalid Expression!"<<endl;
                return 0;
            }
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            int value;
            if(symbol=='^'){
                value=pow(a,b);
            }
            else if(symbol=='/'){
                // IMPROVEMENT 2: Prevent division by zero
                if(b==0){
                    cout<<"Division by Zero !"<<endl;
                    return 0;
                }
                value=a/b;
            }
            else if(symbol=='*'){
                value=a*b;
            }
            else if(symbol=='+'){
                value=a+b;
            }
            else if(symbol=='-'){
                value=a-b;
            }
            else{
                // IMPROVEMENT 3: Handle invalid operators
                cout<<"Invalid Operator !"<<endl;
                return 0;
            }
            S.push(value);
        }
    }

    // IMPROVEMENT 4: Ensure exactly one final result remains
    if(S.size()!=1){
        cout<<"Invalid Expression !"<<endl;
    }
    else{
        cout<<"Ans: "<<S.top()<<endl;
    }
}
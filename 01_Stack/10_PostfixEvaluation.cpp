#include <bits/stdc++.h>
using namespace std;

// Chances Of Mistake:-
// 1. Convert character to integer
// 2. Use pow(a,b) instead of a^b
// 3. firstly Pop b, then a

int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin, str);
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
            int b=S.top();
            S.pop();
            int a=S.top();
            S.pop();
            int value;
            if(symbol=='^'){
                value=pow(a,b);
            }
            else if(symbol=='/'){
                // IMPROVEMENT 2: Prevent division by zero
                if(b==0){
                    cout<<"Divison by Zero!"<<endl;
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
                cout<<"Invalid Operator!"<<endl;
                return 0;
            }
            S.push(value);
        }
    }

    // IMPROVEMENT 4: Ensure exactly one final result remains
    if(S.size()!=1){
        cout<<"Invalid Expression!"<<endl;
        return 0;
    }
    cout<<"Ans: "<<S.top()<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int prcd(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    return 0;
}
bool isRightAssociative(char c){
    return c == '^';

    // Same
    // if(c=='^') return true;
    // return false;
}
int main(){
    string str;
    cout<<"Enter a String: ";
    getline(cin, str);
    stack<char> S;
    int i=0;
    string ans="";
    while(i<str.size()){
        char curr=str[i];
        i++;
        if((curr>='A' && curr<='Z') || (curr>='a' && curr<='z') || (curr>='0' && curr<='9')){
            ans+=curr;
        }
        else if(curr==' '){
            continue;
        }
        else if(curr=='('){
            S.push(curr);
        }
        else if(curr==')'){
            while(!S.empty() && S.top()!='('){
                ans+=S.top();
                S.pop();
            }
            if(S.empty()){
                cout<<"Unmatched closing parenthesis"<<endl;
                return 1;
            }
            S.pop();
        }
        else if(curr=='+' || curr=='-' || curr=='*' || curr=='/' || curr=='^'){
            while(!S.empty() && S.top()!='(' && (prcd(S.top())>prcd(curr) || (prcd(S.top())== prcd(curr) && !isRightAssociative(curr)))){
                ans+=S.top();
                S.pop();
            }
            S.push(curr);
        }
        else{
            cout<<"Invalid Operator: "<<curr<<endl;
            return 1;          // Program ended because error occurred
        }
    }
    while(!S.empty()){
        if(S.top()=='('){
            cout<<"Unmatched opening parenthesis"<<endl;
            return 1;
        }
        ans+=S.top();
        S.pop();
    }

    cout<<"Ans: "<<ans<<endl;

    return 0;
}
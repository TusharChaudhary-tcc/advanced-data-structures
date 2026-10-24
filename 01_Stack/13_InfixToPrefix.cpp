#include <bits/stdc++.h>
using namespace std;

// Points to remember :-
// 1. firstly reverse the string.
// 2. Then change parentheses { '(' to ')'   and vice versa}.
// 3. Apply InfixTopPostfix algorithm with onlyone change given in point 4.
// 4. for equal prcd:- (prcd(s.top()) == prcd(curr) && isRightAssociative(curr))  then popped (opposite of infixToPostfix).
// 5. After that reverse the ans and then print.

int prcd(char c){
    if(c=='^')  return 3;
    else if(c=='*' || c=='/')  return 2;
    else if(c=='+' || c=='-')  return 1;
    return 0;
}
bool isRightAssociative(char c){
    return c=='^';
}
int main(){
    string str;
    cout<<"Enter a String: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    for(auto &curr:str){
        if(curr=='('){
            curr=')';
        }
        else if(curr==')'){
            curr='(';
        }
    }
    stack<char> s;
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
            s.push(curr);
        }
        else if(curr==')'){
            while(!s.empty() && s.top()!='('){
                ans+=s.top();
                s.pop();
            }
            if(s.empty()){
                cout<<"Mismatched Parentheses"<<endl;
                return 1;
            }
            s.pop();
        }
        else if(curr=='^' || curr=='*' || curr=='/' || curr=='+' || curr=='-'){
            while(!s.empty() && 
            s.top()!='(' && 
            (prcd(s.top())>prcd(curr) || 
            (prcd(s.top())==prcd(curr) && 
            isRightAssociative(curr)))){

                ans+=s.top();
                s.pop();
            }
            s.push(curr);
        }
        else{
            cout<<"Invalid Character: "<<curr<<endl;
            return 1;
        }
    }

    while(!s.empty()){
        if(s.top()=='('){
            cout<<"Mismatched Parentheses"<<endl;
            return 1;
        }
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    cout<<"Ans: "<<ans<<endl;
}
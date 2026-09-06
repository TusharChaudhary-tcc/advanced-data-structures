#include <bits/stdc++.h>
using namespace std;

class Stack{
    vector<char> arr;
    int top;

    public:
    Stack(int s){
        arr.resize(s);
        top=-1;
    }

    void Push(char x){
        if(isFull()){
            cout<<"Stack Overflows"<<endl;
            exit(1);
        }
        top++;
        arr[top]=x;

    }
    char Pop(){
        if(top==-1){
            cout<<"Stack Underflows"<<endl;
            exit(1);
        }
        char x=arr[top];
        top--;
        return x;
    }

    char StackTop(){
        if(top==-1){
            cout<<"Stack Underflows"<<endl;
            exit(1);
        }
        char x=arr[top];
        return x;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top==arr.size()-1){
            return true;
        }
        else{
            return false;
        }
    }

    int Size(){
        return top+1;
    }
    void Display(){
        int temp=top;
        while(temp!=-1){
            cout<<arr[temp]<<" ";
            temp--;
        }
    }

    bool isValidParentheses(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                Push(s[i]);
            }
            
            else{
                if(isEmpty()){
                    return false;
                }
                char ch=StackTop();
                Pop();
                if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='[')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return isEmpty();
    }

    
};

int main(){
    Stack st(100);
    cout<<"isValidParenthesis :- "<<st.isValidParentheses("[()]");

}
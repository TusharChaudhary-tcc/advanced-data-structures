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
};
void isValidParenthesis(string s, Stack &st){
        int i=0;
        bool flag=true;
        while(i<s.size()){
            char x=s[i];
            if(x=='('){
                st.Push(x);
            }
            else if(x==')'){
                if(!st.isEmpty()){
                    st.Pop();
                }
                else{
                    flag=false;
                }
            }
            i++;
        }
        if(flag && st.isEmpty()){
            cout<<"Valid Expression "<<endl;
        }
        else{
            cout<<"Invalid Expression "<<endl;
        }
    }

int main(){
    Stack st(20);

    string s;
    cout<<"Enter a String :- ";
    getline(cin,s);

    isValidParenthesis(s,st);
}
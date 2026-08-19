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

int main(){
    Stack st(20);

    string s;
    cout<<"Enter a String :- ";
    getline(cin, s);

    int i=0;
    while(i<s.size()){
        st.Push(s[i]);
        i++;
    }

    string rev="";
    int j=0;
    while(!st.isEmpty()){
        char x=st.Pop();
        rev+=x;
    }

    cout<<"Reverse String : "<<rev<<endl;


    // We can check Palindrome Also
    if(s==rev){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a Palindrome"<<endl;
    }
}
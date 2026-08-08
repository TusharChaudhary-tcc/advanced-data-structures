#include <bits/stdc++.h>
using namespace std;

class Stack{
    vector<int> vec;
    int top;

    public:
    Stack(int s){
        vec.resize(s);
        top=-1;
    }

    void Push(int x){
        if(top==vec.size()-1){
            cout<<"Stack Overflows"<<endl;
            exit(1);
        }
        top++;
        vec[top]=x;
    }
    int Pop(){
        if(top==-1){
            cout<<"Stack Underflows"<<endl;
            exit(1);
        }
        int x=vec[top];
        top--;
        return x;
    }
    int StackTop(){
        if(top==-1){
            cout<<"Stack Underflows"<<endl;
            exit(1);
        }
        int x=vec[top];
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
        if(top==vec.size()-1){
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
            cout<<vec[temp]<<" ";
            temp--;
        }
    }
};

int main(){
    Stack st(20);
    
    int n;
    cout<<"Enter a Decimal Number :- ";
    cin>>n;

    vector<char> Hex={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while(n>0){
        st.Push(n%16);
        n/=16;
    }

    cout<<"Hexadecimal Form :- ";
    while(!st.isEmpty()){
        int x=st.Pop();
        cout<<Hex[x];
    }

}
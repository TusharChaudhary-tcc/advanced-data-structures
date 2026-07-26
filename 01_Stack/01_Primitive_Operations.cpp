#include <bits/stdc++.h>
using namespace std;

// Stack Implementation using Vector

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
    Stack st(5);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    st.Push(6);
    st.Push(7);
  
    cout<<st.Size()<<endl<<endl<<endl;
    st.Display();
    cout<<endl;
    cout<<st.isFull()<<endl;
    
    // cout<<st.Pop()<<endl;
    // cout<<st.Pop()<<endl;
    // cout<<st.Pop()<<endl;
    // cout<<st.Pop()<<endl;
    // cout<<st.Pop()<<endl;
    // cout<<st.Pop()<<endl<<endl;
    
    // cout<<st.isEmpty()<<endl;
}
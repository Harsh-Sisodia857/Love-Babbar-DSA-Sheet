#include<bits/stdc++.h>
using namespace std;

class MyStack{
    public :
        int n;
        int *arr;
        int top;
        MyStack(int size)
        {
            n = size;
            arr = new int[n];
            top = -1;
        }
        void push(int x){
            if(top == n){
                cout << "Stack Overflow";
                return;
            }
            top++;
            arr[top] = x;
        }
        void pop(){
            if(top == -1){
                cout << "No element to POP";
                return;
            }
            top--;
        }
        int Top(){
            if(top == -1){
                cout << "No element in the stack" << endl;
                return -1;
            }
            int topEle = arr[top];
            return topEle;
        }
        bool empty(){
            if(top == -1)
                return true;
            return false;
        }
};

int main(int argc, char const *argv[])
{
        MyStack st(5);
        st.push(10);
        st.push(20);
        st.push(30);
        cout << st.Top() << endl;
        st.pop();
        cout << st.Top() << endl;
        st.pop();
        cout << st.Top();
        return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Mystack{
    public :
        struct Node{
            int num;
            Node *prev;
            Node *next;
            Node(int val){
                num = val;
                prev = NULL;
                next = NULL;
            }
        };

        // member of Mystack class
        Node *head = NULL;
        Node *mid = NULL;
        int size = 0;

        void push(int x){
            Node *temp = new Node(x);
            if(size == 0){
                head = temp;
                mid = temp;
                size++;
                return;
            }
            head->next = temp;
            temp->prev = head;
            head = head->next;
            // now changing mid pointer
            if(size % 2 == 1){
                mid = mid->next;
            }
            size++;
        }
        void pop(){
            if(size == 1){
                head = NULL;
                mid = NULL;
                size--;
                return;
            }
            head = head->prev;
            head->next = NULL;
            if(size % 2 == 0){
                mid = mid->prev;
            }
            size--;
        }
        int Top(){
            if(head == NULL)
                return -1;
            return head->num;
        }
        int findMiddle(){
            if(size == 0)
                return -1;
            return mid->num;
        }
        void deleteMiddle(){
            if (size == 0)
                return;
            Node *toDelete = mid;
            if(size == 1){
                head = NULL;
                mid = NULL;
                return;
            }
            if(size == 2){
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
                return;
            }
            mid->next->prev = mid->prev;
            mid->prev->next = mid->next;
            if(size % 2 == 0){
                mid = mid->prev;
            }else{
                mid = mid->next;
            }
            size--;
        }
};

int main()
{
        Mystack st;
        st.push(11);
        st.push(22);
        st.push(33);
        st.push(44);
        st.push(55);
        st.push(66);
        st.push(77);
        st.push(88);
        st.push(99);
        cout << "Topped : " << st.Top() << endl;
        st.pop();
        cout << "Topped : " << st.Top() << endl;
        st.pop();
        cout << "Middle Element : " << st.findMiddle() << endl;
        st.deleteMiddle();
        cout << "New Middle Element : " << st.findMiddle() << endl;
        return 0;
}
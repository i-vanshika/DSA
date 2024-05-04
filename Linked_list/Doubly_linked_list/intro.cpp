#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
}; 

/* PRINTING THE LINKED LIST */
void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

/* CONVERTING ARRAY TO DLL */

Node* convertArr2DLL(vector<int>& arr){
     Node* head = new Node(arr[0]);
     Node* prev = head;
     for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
     }
     return head;
}

int main(){
    vector<int>arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    print(head);


    return 0;
}
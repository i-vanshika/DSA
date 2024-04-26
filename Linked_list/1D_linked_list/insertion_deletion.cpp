#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* convertArr2LL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}
 
 /* REMOVING HEAD FROM A LL */
Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
   
}

/* REMOVING TAIL FROM A LL */
Node* removesTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;  // always store a copy of head
    while(temp->next->next != NULL){
        temp = temp->next;
    } 
    delete temp->next;
    temp->next = nullptr;
    return head;

}

/* DELETE Kth ELEMENT FROM A LL */
Node* removeK(Node* head, int k){
    if(head == NULL ) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        count ++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int>arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    //head = removesHead(head); 
    //head = removesTail(head);
    head = removeK(head, 3);
    print(head);
}
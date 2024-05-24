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

/* DELETE HEAD IN A DLL */
Node* DeleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

/* DELETE TAIL IN A DLL */
Node* DeleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

/* REMOVE Kth ELEMENT IN DLL */
Node* RemoveKthElement(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* kNode = head;
    int count = 0;
    while(kNode != NULL){
        count ++;
        if(count == k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;

    //edge cases
    if(prev == NULL && front == NULL){
        return head;
    }
    else if(prev == NULL){
    return DeleteHead(head);
    }
    else if(front ==NULL){
        return DeleteTail(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;
    return head;
}

/* REMOVE NODE IN A DLL */
void DeleteNode(Node* temp){
    // this ques is not asking you to delete head as more and more conditions would be required.

    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        front->back = nullptr;
        free(temp);
        return ;
    }
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;  
    free(temp);
}

/* INSERTING NODE AT HEAD */
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;

}

/* INSERTING BEFORE  AT TAIL*/
Node* insertBeforeTail(Node* head, int val){
    if (head->next == NULL) { 
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
} 

/* INSERTING BEFORE Kth ELEMENT */
Node* insertBeforeKthElement(Node* head, int k, int val){
    if(k==1)  return insertBeforeHead(head,val);

    Node* temp = head;
    int cnt =0;
    while(temp != NULL){
        cnt ++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;

}

/* INSERTING BEFORE A GIVEN NODE */
// it is guranteed that given node!= head, as we are not suppose to change the head
void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
 
}

int main(){
    vector<int>arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    //head = DeleteHead(head);
    //head = DeleteTail(head);
    //head = RemoveKthElement(head ,3);
    //DeleteNode(head->next->next);
    //head = insertBeforeHead(head, 600);
    //head = insertBeforeTail(head, 600);
    //head = insertBeforeKthElement(head, 1,800);
    insertBeforeNode(head->next->next, 100);
    print(head);

    return 0;
}
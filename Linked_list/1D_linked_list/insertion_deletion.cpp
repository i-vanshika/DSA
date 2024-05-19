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
    if(head == NULL || head->next == NULL) return NULL;  //edge case
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
    if (head == NULL) return NULL;
    if(k ==1 ){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;
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


/* REMOVE ELEMENT FROM A LL */
Node* removeEle(Node* head, int ele){
    if(head == NULL) return NULL;
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* prev = nullptr;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == ele){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

/* INSERTION OF HEAD IN A LL */
Node* insertHead(Node* head, int val){
    //Node* temp = new Node(val, head);
    //return temp;
    return new Node(val,head);

}

/* INSERTION OF TAIL IN A LL */
Node* insertTail(Node* head, int val){
    if (head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* new_node = new Node(val);
    temp->next = new_node;
    return head;
}

/* INSERTING AT Kth POSITION */
Node* insertPosition(Node* head, int ele, int k){
    if(head==NULL){
        if(k==1)  return new Node(ele);
        else return NULL;
    }
    if(k==1){
        Node* temp = new Node(ele,head);
        return temp;
    }
    int cnt =0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(ele);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

/* INSERTING ELEMENT BEFORE THE VALUE X */
Node* insertBeforeValue(Node* head, int ele, int val_x){
    //edge case
    if(head == NULL) return NULL; // LL is empty 
    if(head->data == val_x){
        return new Node(ele);
    }
    Node* temp = head;
    while( temp->next != NULL){
        if(temp->next->data == val_x){
            Node* newNode = new Node(ele);
            newNode->next = temp->next;
            temp->next = newNode;
            break;

        }
        temp = temp->next;
    }
    return head;
}
     

int main(){
    vector<int>arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    //head = removesHead(head); 
    //head = removesTail(head);
    //head = removeK(head, 3);
    //head = removeEle(head, 8); 
    //head = insertHead(head,100);
    //head = insertTail(head,100);
    //head = insertPosition(head, 10,3);
    head = insertBeforeValue(head, 100,8);

    print(head);
}
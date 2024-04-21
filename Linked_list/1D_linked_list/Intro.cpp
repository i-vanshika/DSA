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

/* CONVERSION OF ARRAY INTO A LINKED LIST */
Node* convertArr2LL(vector<int>&arr){

    // Initialising head to the first element
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

/* LENGTH OF A LINKED LIST */
int length(Node* head){  // head will always be given 
    int count =0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;

}

/* SEARCH ELEMENT IN A LL */
bool checkIfPresent(Node* head, int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr ={200,5,8,7};
    Node* head = convertArr2LL(arr);
    //cout<<head->data;

    //TRAVERSAL IN A LINKED LIST
    Node* temp = head;
    while(temp){     // temp != null
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    //Printing the length of LL
    cout<<endl;
    cout<<length(head);

    //Check if element is present in a LL
    cout<<endl;
    cout<<checkIfPresent(head,5);

}



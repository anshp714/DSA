#include<BITS/stdc++.h>
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

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node*head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//INSERTION AT VALUE K
Node* insertBeforeValue(Node* head,int el, int val){
    if(head == NULL){
        return NULL;
    }

    if(head->data == val){
        return new Node(el,head);
        
    }

    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;


}

int main(){
    
    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);


    head = insertBeforeValue(head, 100, 5); 
    head = insertBeforeValue(head, 200, 8); 
    print(head);
}
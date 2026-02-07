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

//HEAD INSERTION
Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

//TAIL INSERTION
Node* insertTail(Node* head, int val){
    if (head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

//INSERTION AT POSITION K
Node* insertPosition(Node* head,int el, int k){
    if(head == NULL){
        if(k == 1){                  //if list is empty and k=1, insert at head
            return new Node(el);
        }
        else{
            return head;
        }
    }

    if(k == 1){
        Node* temp = new Node(el, head);
        return temp;                          //insert at head
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt == k-1){                     //insert at position k                                      
            Node* newNode = new Node(el, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;


}

int main(){
    
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr2LL(arr);

    // head = insertHead(head, 100);
    // print(head);

    // head = insertTail(head, 200);
    // print(head);

    head = insertPosition(head, 300, 3);
    head = insertPosition(head, 100, 1);
    head = insertPosition(head, 500, 7);
    print(head);
}
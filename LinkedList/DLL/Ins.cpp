#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node*back;

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

Node* convertarr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//INSERION BEFORE HEAD IN DOUBLY LINKED LIST
Node* insBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

//INSERION BEFORE TAIL IN DOUBLY LINKED LIST
Node* insBeforeTail(Node* head , int val){
    if(head->next == NULL){
        return insBeforeHead(head, val);
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

//INSERTION OF KTH ELEMENT IN THE MIDDLE OF THE DOUBLY LINKED LIST
Node* insBeforeKthElement(Node* head, int k, int val){
    if(k == 1){
        return insBeforeHead(head, val);
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        if (count == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node* node ,int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = convertarr2DLL(arr);

    head = insBeforeKthElement(head, 2, 20);
    print(head);

    insertBeforeNode(head->next->next, 30); // Insert 30 before the 2nd element (index 2)
    print (head);
    return 0;
}

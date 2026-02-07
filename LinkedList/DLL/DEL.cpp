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

//HEAD DELETION IN DOUBLY LINKED LIST
Node* delHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}

//TAIL DELETION IN DOUBLY LINKED LIST
Node* delTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next !=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = NULL;
    tail->back = NULL;
    delete tail;
    return head;
}

//DELETION OF A NODE IN THE MIDDLE OF THE DOUBLY LINKED LIST
Node* removekthElement(Node* head , int k){
    if (head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev ==NULL && front ==NULL){
        delete temp;
        return NULL;
    }
    else if(prev == NULL){
        front->back = NULL;
        delete temp;
        return front;
    }
    else if(front == NULL){
        prev->next = NULL;
        delete temp;
        return head;
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;

    }
}

void delNode(Node* temp){     //Cannot use head pointer here as we are not returning anything from this function and we are passing the node to be deleted as a parameter
    if(temp == NULL){
        return;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev ==NULL && front ==NULL){
        delete temp;
        return;
    }
    else if(prev == NULL){
        front->back = NULL;
        delete temp;
        return;
    }
    else if(front == NULL){
        prev->next = NULL;
        delete temp;
        return;
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        delete temp;
        return;

    }
}


int main(){
    vector<int> arr = {12,5,8,7};
    Node* head = convertarr2DLL(arr);

    delNode(head->next); // Remove the 2nd element (index 2)
    print(head);

    return 0;
}
#include<bits/stdc++.h>
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

int lengthOfLL(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp){
        // cout<< temp->data<<" ";
        temp = temp->next;
        length++;
        
    }
    cout<<endl;
    return length;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;   
}

int main(){
    
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0], nullptr);
    cout << y;
    cout << y->data << endl;

    //convert array to linked list
    Node* head = convertArr2LL(arr);
    cout<< head->data << endl;

    //traverse the linked list     O(n)
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    //length of linked list      O(n)
    cout << "Length of linked list: " << lengthOfLL(head) ;

    cout<<endl;

    //check if a value is present in linked list   O(n)
    cout<<checkIfPresent(head, 7)<<endl;
    cout<<checkIfPresent(head, 10)<<endl;
}
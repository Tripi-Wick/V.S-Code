#include <iostream>
using namespace std;

typedef struct L_L{
    int data;
    struct L_L* next;
}node;

void insert_At_Head(node* &head, int num){
    node* temp = new node;
    temp->data = num;
    temp->next = nullptr;
    head = temp;
}

void insert_At_Tail(node* &head, int num){
    node* temp = new node;
    temp->data = num;
    temp->next = nullptr;

    node* itr = head;
    while(itr->next!=nullptr){
        itr = itr->next;
    }

    itr->next = temp;
}

void display(node* head){
    node* itr = head;
    while(itr!=nullptr){
        cout<<itr->data<<"->";;
        itr= itr->next;
    }
    cout<<"nullptr"<<endl;

}

void merge_LL(node*& head1,node*& head2){
    node* itr1=head1,*itr2=head2,*itr3=nullptr;

    if(itr1->data<itr2->data){
        itr3=itr1;
        itr1=itr1->next;
        itr3->next=nullptr;
    }
    else if(itr2->data<itr1->data){
        itr3=itr2;
        itr2=itr2->next;
        itr3->next=nullptr;
    }
    else if(itr1->data==itr2->data){
        itr3=itr1;
        itr1=itr1->next;
        head1=itr3;
        itr3->next=nullptr;
    }
    while(itr1!=nullptr && itr2!=nullptr){
        if((itr1->data<itr2->data) || (itr1->data==itr2->data)){
            itr3->next=itr1;
            itr3=itr1;
            itr1=itr1->next;
            itr3->next=nullptr;
        }
        else if(itr2->data<itr1->data){
            itr3->next=itr2;
            itr3=itr2;
            itr2=itr2->next;
            itr3->next=nullptr;
        }
   }
   if(itr1!=nullptr){itr3->next=itr1;}
   if(itr2!=nullptr){itr3->next=itr2;}    
}

int main(){
    node* n1=nullptr,*n2=nullptr;
    
    int num1,num2;
    cout<<"Enter the number of elements you want to enter in Linked List 1: ";
    cin>>num1;
    for(int i=0; i<num1; i++){
        int temp;
        cout<<"Enter the "<<i+1<<" Element of Linked List 1: ";
        cin>>temp;
        if(i==0){insert_At_Head(n1,temp);}
        else insert_At_Tail(n1,temp);
    }

    cout<<"Enter the number of elements you want to enter in Linked List 2: ";
    cin>>num2;
    for(int i=0; i<num2; i++){
        int temp;
        cout<<"Enter the "<<i+1<<" Element of Linked List 2: ";
        cin>>temp;
        if(i==0){insert_At_Head(n2,temp);}
        else insert_At_Tail(n2,temp);
    }

    display(n1);
    display(n2);

    merge_LL(n1,n2);
    
    if(n1->data<n2->data || n1->data==n2->data){
        cout<<"n1 is the head of new merged list"<<endl;
        display(n1);
    }
    if(n2->data<n1->data){
        cout<<"n2 is the head of new merged list"<<endl;
        display(n2);
    }

    return 0;
}


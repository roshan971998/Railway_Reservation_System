#include <bits/stdc++.h>
using namespace std;
struct  node{
    int data;
    struct node*next;
};
struct node* head=NULL;
void insertEnd(int x){
    struct node* new_node=(struct node*)malloc
    (sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    struct node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}
void insertBegin(int x){
    struct node*new_node=(struct node*)malloc
    (sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
        return;
    }
    new_node->next=head;
    head=new_node;
}
void insert_at_given_position(int x, int p){
    struct node*new_node=(struct node*)malloc
    (sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    if(p==1){
        //insertBegin(x);
        //   or
        new_node->next=head;
        head=new_node;
        return;
    }
    int count=2;
    struct node*t=head;
    while(count<p){
        count++;
        t=t->next;
    }
    new_node->next=t->next;
    t->next=new_node;

}
void delete_at_beginning(){
    if(head==NULL) {
        cout<<"List is Empty"<<endl;
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    else{
         struct node*temp=head;
         head=head->next;
         free(temp);
    }

}
void delete_at_end(){
    if(head==NULL) {
        cout<<"List is Empty"<<endl;
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    else{
      struct node*temp=head;
      while (temp->next->next != NULL) {
            temp = temp->next;
      }
      free(temp->next);
      temp->next = NULL;
    }
}
void delete_at_given_position(int p){
    if(p==1){
        delete_at_beginning();
        return;
    }
    int count=2;
    struct node*t=head;
    while(count<p){
        count++;
        t=t->next;
    }
    struct node*temp=t->next;
    t->next=t->next->next;
    free(temp);
}
void traverse()
{
    struct node* temp;
    temp=head;
    if (temp == NULL)
       return;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp=temp->next;
    }
}
int main() {
	insertEnd(3);
    insertEnd(1);
    insertEnd(7);
    insertEnd(2);
    insertEnd(9);
    cout<<endl;
    traverse();
    insert_at_given_position(15,4);
    cout<<endl;
    traverse();
    insert_at_given_position(0,1);
    cout<<endl;
    traverse();
    insertBegin(99);
    cout<<endl;
    traverse();
    insertEnd(100);
    cout<<endl;
    traverse();
    delete_at_end();
    cout<<endl;
    traverse();
    delete_at_beginning();
    cout<<endl;
    traverse();

	return 0;
}

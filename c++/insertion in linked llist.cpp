#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*next;
	
};
struct node* insert_at_first(struct node*head,int data){
	struct node*ptr=new struct node[5];
	ptr->data=data;
	ptr->next=head;
	return ptr;
}
struct node*insert_at_index(struct node*head,int data,int index){
	struct node*p=head;
	struct node*ptr=new struct node[5];
	
	ptr->data=data;
	int i=0;
	while(i<index-1){
		p=p->next;
		i++;
		
	}
	ptr->next=p->next;
	p->next=ptr;
	return head;
}
struct node*insert_at_afternode(struct node*head,int data,struct node*prevnode){
	struct node*ptr=new struct node[5];
	ptr->data=data;
	ptr->next=prevnode->next;
	prevnode->next=ptr;
	return head;
	
}
void display(struct node*head){
	struct node*ptr=head;
	while(ptr!=NULL){
		cout<<"elements are:"<<endl;
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
}
struct node*insert_at_end(struct node*head,int data){
	struct node*p=head;
	struct node*ptr=new struct node[5];
	while(p->next!=NULL){
		p=p->next;
	}
	ptr->data=data;
	ptr->next=NULL;
	
	p->next=ptr;
	return head;
}
int main(){
	struct node *head,*second,*third,*fourth;
	head=new struct node[5];
	second=new struct node[5];
	third=new struct node[5];
	fourth=new struct node[5];
	
	head->data=8;
	head->next=second;
	
	second->data=9;
	second->next=third;
	
	third->data=7;
	third->next=fourth;
	
	fourth->data=2;
	fourth->next=NULL;
	
	cout<<"linked list before insertion:"<<endl;
	display(head);
	
//	head=insert_at_first(head,55);
//	head=insert_at_index(head,55,2);
//	head=insert_at_end(head,112);
	head=insert_at_afternode(head,112,third);
	cout<<"linked list after insertion:"<<endl;
	display(head);
}

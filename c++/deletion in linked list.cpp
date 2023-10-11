#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node*next;	
};
struct node*Delete_at_first(struct node*head){
	struct node*p=head;
	head=head->next;
	free(p);
	return head;
}
struct node*Delete_at_index(struct node*head,int index){
	struct node*p=head;
	struct node*q=p->next;
	int i=0;
	while(i<index-1){
		p=p->next;
		q=q->next;
		i++;
		
	}
	p->next=q->next;
	free(q);
	return head;
	
}
struct node*Delete_at_end(struct node*head){
	struct node*p=head;
	struct node*q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
		
	}
	p->next=q->next;
	free(q);
	return head;
}
struct node*Delete_at_value(struct node*head,int value){
	struct node*p=head;
	struct node*q=head->next;
	while(q->data!=value&&q->next!=NULL){
		p=p->next;
		q=q->next;
		
	}
	
	if(q->data==value){
		p->next=q->next;
		free(q);
		
	}
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
//	head=Delete_at_first(head);
//	head=Delete_at_index(head,2);
	head=Delete_at_end(head);
	head=Delete_at_value(head,7);
	
	cout<<"linked list after insertion"<<endl;
	display(head);
	
	return 0;
}


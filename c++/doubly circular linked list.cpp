#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* createnode(struct node *head){
	head=NULL;
	struct node *newnode;
	struct node *tail;
	printf("how many nodes do you want to create\n");
	int ch;
	scanf("%d",&ch);
	while(ch!=0){
		newnode=(struct node *)malloc(sizeof(struct node));
		int val;
		printf("enter your value\n");
		scanf("%d",&val);
		newnode->data=val;
		if(head==NULL){
			head=newnode;
			newnode->prev=head;
			newnode->next=head;
			tail=head;
		}
		else{
			tail->next=newnode;
			newnode->next=head;
			head->prev=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
		ch--;
	}
	return head;
}
void display(struct node *head){
	struct node* a=head;
	while(a->next!=head){
		printf("%d\n",a->data);
		a=a->next;
	}printf("%d\n",a->data);
	
}
struct node *insert_at_begining(struct node* head){
	struct node* newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter value\n");
	int ch;
	scanf("%d",&ch);
	newnode->data=ch;
	newnode->prev=head->prev;
	head->prev->next=newnode;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return head;
}
struct node *insert_at_end(struct node *head){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter value\n");
	int ch;
	scanf("%d",&ch);
	newnode->data=ch;
	struct node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}

	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
	head->prev=newnode;
	return head;
}
struct node* insert_at_position(struct node* head){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter value\n");
	int ch;
	scanf("%d",&ch);
	newnode->data=ch;
	struct node* temp=head;
	int pos;
	printf("enter the position\n");
	scanf("%d",&pos);
	int i=1;
	while(i<pos-1){
		temp=temp->next;
		i++;
	}
	
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;//we have linked ahead node previous to newnode
	temp->next=newnode;//we have linked behind node->next to newnode
	return head;

}
struct node* deletion_at_begining(struct node *head){
	head->prev->next=head->next;
	head->next->prev=head->next;
	head=head->next;
	return head;
	
}
struct node* delete_at_value(struct node *head){
	struct node* temp=head;
	printf("enter the value you want to delete\n");
	int val;
	scanf("%d",&val);
	while(temp->next!=head){
		if(temp->data==val){
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			break;
		}
		temp=temp->next;
	}
	return head;
}
struct node* delete_at_end(struct node* head){
	struct node* temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	return head;
}
int main(){
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head=createnode(head);
	printf("you are displaying doubly circular linked list\n");
	display(head);
	printf("\n\n");
//	printf("you are entering at begining\n");
//	head=insert_at_begining(head);
//	printf("you are displaying doubly circular linked list\n");
//	display(head);
//	printf("you are entering at end\n");
//	head=insert_at_end(head);
//	printf("you are displaying doubly circular linked list\n");
//	display(head);
//	printf("you are insering at particular position\n");
//	head=insert_at_position(head);
//	printf("you are displaying doubly circular linked list\n");
//	display(head);
//	printf("you are deleting at begining\n");
//	head=deletion_at_begining(head);
//	printf("you are displaying doubly circular linked list\n");
//	display(head);
//	printf("you are deleting for particular value expect at begining and at end\n");
//	head=delete_at_value(head);
//	printf("you are displaying doubly circular linked list\n");
//	display(head);
	printf("you are deleting at end\n");
	head=delete_at_end(head);
	printf("you are displaying doubly circular linked list\n");
	display(head);
	return 0;
}

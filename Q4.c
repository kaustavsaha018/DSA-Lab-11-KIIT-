#include<stdio.h>
#include<stdlib.h>
#define Max 3

struct node{
	int data;
	struct node *next;
};
struct node *front, *rear, *newnode;

static int count;

void enqueue(int);
void dequeue();
void display();
void peek();

int main(){
	printf("Enter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 for Peek\nEnter 4 for Display\nEnter 5 to Exit\n");
	int choice,again=1;
	int n;
	while(again!=0){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter a number to be put into the queue: ");
				scanf("%d", &n);
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\nExiting...");
				again=0;
				break;
			default:
				printf("\nInvalid Choice!");
				
		}
	}
	return 0;	
}

void enqueue(int n){
	if(count==Max){
		printf("\nOverflow!");
		return;
	}
	else{
	newnode=(struct node *)malloc(sizeof(struct node));
	if(front==NULL && rear==NULL){
		newnode->data=n;
		front=newnode;
		rear=newnode;
		newnode->next=front;
		count++;
	}
	else{
		newnode->data=n;
		newnode->next=front;
		rear->next=newnode;
		rear=newnode;
		count++;
	}
	printf("%d entered into the queue\n", newnode->data);
	}
}
void dequeue(){
	if(count==0){
		printf("\nUnderflow!");
	}
	else{
	struct node *temp;
	if(front==NULL && rear==NULL){
		printf("\nThe queue is empty. No element to delete.\n");
		return; 
	}
	else if(front==rear){
		temp=front;
		front=NULL;
		rear=NULL;
		count--;
	}
	else{
		temp=front;
		front=front->next;
		rear->next=front;
		count--;
	}
	printf("%d has been deleted from the queue\n", temp->data);
	free(temp);
	}
}
void peek(){
	if(front==NULL && rear==NULL){
		printf("\nThe queue is empty. Nothing to peek at.\n");
		return;
	}
	else{
		printf("\n%d is at the front of the queue.", front->data);
	}
}

void display(){
	struct node *temp;
	
	if(front!=NULL){
		temp=front;
		printf("\nThe elements in the queue are: ");
		do{
			printf(" %d", temp->data);
			temp=temp->next;
		}while(temp!=front);	
	}
	else{
		printf("\nNo element present to display.");
	}
}


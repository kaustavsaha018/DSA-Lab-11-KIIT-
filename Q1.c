#include<stdio.h>
#include<stdlib.h>
#define N 3
int queue[N],i,front=-1,rear=-1;

void enqueue(int x){
	if(rear==N-1){
 		printf("Queue is Full\n");
   }
   else{
   		if(front==-1){
   			queue[++rear] = x;
			++front;	
		}
   		else{
   			queue[++rear] = x;
		}
   		
   		printf("%d has been enqueued into the queue\n", queue[rear]);
   }
}
void dequeue(){
	if(front==N || front==-1){
		printf("Queue is Empty\n");
	}
	else if(front==rear){
		printf("%d has been dequeued from the queue\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else{
		printf("%d has been dequeued from the queue\n",queue[front]);
		queue[++front];
	}
}
void isFull(){
	if(rear==N-1){
		printf("\nThe Queue is full! ");
	}
	else{
		printf("\nThe Queue is not full! ");
	}
}
void isEmpty(){
	if(front==-1 && rear==-1){
		printf("\nThe Queue is empty!");
	}
	else{
		printf("\nThe Queue is not empty!");
	}
}	 
void display(){
	if(front==-1 && rear==-1){
		printf("\nNothing to display");
	}
	else{
		printf("\nElements are\n");
		for(i=front; i<=rear; i++){
			printf(" %d",queue[i]);
		}
	}
}
int main(){
	printf("Enter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 for Display\nEnter 4 to Check isFull");
	printf("\nEnter 5 to Check isEmpty\nEnter 6 to Exit\n");
	int choice,again=1;
	int n;
	while(again!=0){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter a number to be inserted into the queue: ");
				scanf("%d", &n);
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				isFull();
				break;
			case 5:
				isEmpty();
				break;
			case 6:
				again=0;
				printf("\nExiting...");
				break;
			default:
				printf("\nInvalid Choice!");
				
		}
	}
}

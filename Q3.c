#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N],front=-1,rear=-1;

void enqueue(int);
void dequeue();
void display();

int main(){
	printf("Enter 1 for Enqueue\nEnter 2 for Dequeue\nEnter 3 for Display\nEnter 4 to Exit\n");
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
				again=0;
				printf("\nExiting...");
				break;
			default:
				printf("\nInvalid Choice!");
				
		}
	}
	return 0;
}

void enqueue(int x){
	if(front==-1 && rear==-1){
		front=0;
		rear=0;
		queue[rear]=x;
		printf("\n%d has been enqueued into the queue\n", queue[rear]);
	} 
	else if((rear+1)%N==front){
		printf("\nQueue is full!");
	}
	else{
		rear=(rear+1)%N;
		queue[rear]=x;
		printf("\n%d has been enqueued into the queue\n", queue[rear]);
	}	
}

void dequeue(){
	if(front==-1 && rear==-1){ 
        printf("\nQueue is empty!");  
    }
	if(front==rear) { 
        printf("\n%d has been dequeued from the queue\n",queue[front]);
		front=-1; 
        rear=-1; 
    } 
    else{
    	printf("\n%d has been dequeued from the queue\n",queue[front]);
    	front=(front+1)%N; 
	} 
}

void display(){
	if(front==-1 && rear==-1){
		printf("\nQueue is empty!");
	} 
	else{
		int i=front;
		printf("The Circular Queue is:");
		
		while(i!=rear){
			printf(" %d", queue[i]);
			i=(i+1)%N;
		}
		printf(" %d", queue[rear]);	
	}
}



#include<stdio.h>
#define N 3
int stack1[N],stack2[N];
int top1=-1,top2=-1;
int count=0;

void push1(int data){
	if(top1==N-1){
		printf("Queue is full!");
	}
	else{
		top1++;
		stack1[top1]=data;
	}
}
int pop1(){
	return stack1[top1--];
}
void push2(int data){
	if(top2==N-1){
		printf("Queue is full!");
	}
	else{
		top2++;
		stack2[top2]=data;
	}
}
int pop2(){
	return stack2[top2--];
}

void enqueue(int x){
	push1(x);
	count++;
}

void dequeue(){
	if(top1==-1){
		printf("Queue is empty!");
	}
	else{
		int i;
		for(i=0;i<count;i++){
			push2(pop1());
		}
		printf("%d has been dequeued",pop2());
		count--;
		for(i=0;i<count;i++){
			push1(pop2());
		}
	}
}

void display(){
	int i;
	printf("The elements of the Queue are: ");
	for(i=0;i<=top1;i++){
		printf(" %d", stack1[i]);
	}
}

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


/*
 * 
 * Implementation stack using linked list
 * 
 * */
#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

node* createNode(int data) {
	
	node* temp = (node*)malloc(sizeof(node*));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}

/*
 * We will push the stack at the head,
 * because we need the cost of time
 * to be O(1) or constant.
 * */
void push(int data, node** head) {
	node* temp = createNode(data);
	temp->next = *head;
	*head = temp;
}

/*
 * Deleting/pop the beginning of node
 * 
 * */
void pop(node** head) {
	node* temp = *head;
	
	if(*head == NULL) {
		return;
	}
	
	*head = temp->next;
	free(temp);
}

/*
 * yield the top of stack
 * */
int top(node** head) {
	return (*head)->data;
}

/*
 * check if stack is empty or not
 * */
bool isEmpty(node* head){
	if(head == NULL) {
		return true;
	} else{
		return false;
	}
}

void printStack(node** head) {
	while(!isEmpty(*head)){
		std::cout << top(&(*head)) << " ";
		pop(&(*head));
	}
}

int main() {
	node* head = NULL;
	push(1, &head);
	push(2, &head);
	push(3, &head);
	push(4, &head);
	printStack(&head);
}

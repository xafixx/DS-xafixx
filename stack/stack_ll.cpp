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

void printValue(node* head) {
	node* temp = head;
	std::cout << "Stack: ";
	
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

int main() {
	node* head = NULL;
	push(2, &head);
	push(12, &head);
	push(20, &head);
	printValue(head);
	
	pop(&head);
	printValue(head);
	pop(&head);
	printValue(head);
}

/*
 * dsll.cpp
 * 
 * Implementation of Doubly singly linked list in c++
 * 
 */
#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
	node* prev;
};

node* createNode(int data){
	node* temp = (node*)malloc(sizeof(node*));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

node* insertFront(node* head, int data){
	node* nodeFront = createNode(data);
	if(head == NULL) {
		head = nodeFront;
		return head;
	}
	
	head->prev = nodeFront;
	nodeFront->next = head;
	head = nodeFront;
	return head;
}

node* insertEnd(node* head, int data){
	node* nodeEnd = createNode(data);
	if(head == NULL) {
		head = nodeEnd;
		return head;
	}
	
	// traverse through the end node
	node* tempInsertEnd = head;
	while(tempInsertEnd->next != NULL) {
		tempInsertEnd = tempInsertEnd->next;
	}
	
	// After we get the end node
	// make the next field of the end node
	// point to the new node.
	
	// Make the prev field of the new node
	// point to the end node, with this
	// the new node become the new end node.
	tempInsertEnd->next = nodeEnd;
	nodeEnd->prev = tempInsertEnd;
	return head;
}

void printList(node* head) {
	node* temp = head;
	
	std::cout << "List: ";
	while(temp != NULL){
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

void reversePrintList(node* head) {
	node* temp = head;
	if(temp == NULL) {
		return;
	}
	
	// Go through the end node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	
	// After we get the end node, traverse back
	// to the head node using prev
	std::cout << "Reverse list: ";
	while(temp != NULL){
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
	std::cout << "\n";
 }
 
void freeAllMemory(node** head) {
	node* temp = *head;
	node* temp2;
	while(temp != NULL) {
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	*head = temp;
}

int main() {
	node* head = NULL;
	head = insertFront(head, 1);
	head = insertFront(head, 2);
	head = insertFront(head, 3);
	head = insertFront(head, 4);
	head = insertFront(head, 5);
	printList(head);
	reversePrintList(head);
	
	head = insertEnd(head, 6);
	head = insertEnd(head, 7);
	head = insertEnd(head, 8);
	printList(head);
	reversePrintList(head);
	
	// free all memory after program finished to avoid memory leaks
	freeAllMemory(&head);
}

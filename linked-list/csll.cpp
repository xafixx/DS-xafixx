/*
 * Circular singly linked list
 * */
#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

node* createNode(int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/*
 * Insertion at the tail of list,
 * both insertion at head and tail
 * have the complexity of O(n)
 * */
void insertionCsll(node** head, int data){
	node* temp = createNode(data);
	if(*head == NULL) {	
		*head = temp;
		temp->next = *head;
		return;
	}
	
	node* temp2 = *head;
	while(temp2->next != *head){
		temp2 = temp2->next;
	}
	
	temp->next = *head;
	temp2->next = temp;
}

void deletionCsllFirst(node** head){
	node* temp = *head;
	if(*head == NULL) {	// if the list null
		return;
	} else if((*head)->next == *head){ // if there's only one data
		*head = NULL;
		delete temp;
		return;
	} else{	// modify the last's next node 
		while(temp->next != *head) {
			temp = temp->next;
		}
		temp->next = (*head)->next;
		delete *head;
		*head = temp->next;
	}
}

void traverseCssl(node* head) {
	node* temp = head;
	if(temp == NULL) return; 
	std::cout << "List data: ";
	do{
		std::cout << temp->data << " ";
		temp = temp->next;
	}while(temp != head);
	std::cout << "\n";
}

int main() {
	node* head = NULL;
	insertionCsll(&head, 11);
	insertionCsll(&head, 12);
	insertionCsll(&head, 13);
	insertionCsll(&head, 14);
	traverseCssl(head);
	deletionCsllFirst(&head);
	traverseCssl(head);
}

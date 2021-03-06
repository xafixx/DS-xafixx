#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

node* createNode(int data){
	node* temp = (node*)malloc(sizeof(node*));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertFront(node** headFront, int dataFront, int* countInsertFront){
	node* temp_ifr = createNode(dataFront);
	temp_ifr->next = *headFront;
	*headFront = temp_ifr;
	*countInsertFront = *countInsertFront + 1;
}

void insertEnd(node** headEnd, int dataEnd, int* countInsertEnd){
	node* tempInsertEnd_f = createNode(dataEnd);
	*countInsertEnd = *countInsertEnd + 1;
	
	if(*headEnd == NULL) {
		*headEnd = tempInsertEnd_f;
		return;
	}
	
	node* tempInsertEnd_s = *headEnd;
	while(tempInsertEnd_s->next != NULL) {
		tempInsertEnd_s = tempInsertEnd_s->next;
	}
	tempInsertEnd_s->next = tempInsertEnd_f;
}

void insertatPos(node** headatPos, int dataatPos, int insertPos, int* countInsertPos){
	node* tempInsertPos_f = createNode(dataatPos);
	
	if((insertPos) <= 0 || (insertPos > *countInsertPos)){
		std::cout << "\n\nIVALID POSITION!" << " You are trying to access position "
		<< insertPos << " current list size is " << *countInsertPos << 
		" begin at the position 1" << "\n\n";
		return;
	}
	
	*countInsertPos = *countInsertPos + 1;
	
	if(insertPos == 1) {
		tempInsertPos_f->next = *headatPos;
		*headatPos = tempInsertPos_f;
		return;
	}
	
	node* tempInsertPos_s = *headatPos;
	for(int i=0; i<insertPos-2; i++) {
		tempInsertPos_s = tempInsertPos_s->next;
	}
	tempInsertPos_f->next = tempInsertPos_s->next;
	tempInsertPos_s->next = tempInsertPos_f; 
}

void deleteNodeAt(node** headDelete, int deletePos, int* countDelete){
	node* tempDeleteNodeAt_f = *headDelete;
	
	if((deletePos <= 0) || (deletePos > *countDelete)) {
		std::cout << "\n\nIVALID POSITION!" << " You are trying to access position "
		<< deletePos << " current list size is " << *countDelete << 
		" begin at the position 1" << "\n\n";
		return;
	}
	
	if(deletePos == 1){
		*headDelete = tempDeleteNodeAt_f->next;
		*countDelete = *countDelete - 1;
		free(tempDeleteNodeAt_f);
		return;
	}
	
	for(int i=0; i<deletePos-2; i++) {
		tempDeleteNodeAt_f = tempDeleteNodeAt_f->next;
	}
	node* tempDeleteNodeAt_s = tempDeleteNodeAt_f->next;
	tempDeleteNodeAt_f->next = tempDeleteNodeAt_s->next;
	*countDelete = *countDelete - 1;
	free(tempDeleteNodeAt_s);
}

void deleteAll(node** headDeleteAll){
	node* temp1 = *headDeleteAll;
	node* temp2;
	while(temp1 != NULL) {
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	*headDeleteAll = temp1;
}

void printList(node* headPrintList) {
	node* temp_prl = headPrintList;
	while(temp_prl != NULL) {
		std::cout << temp_prl->data << "  ";
		temp_prl = temp_prl->next;
	}
	std::cout << "\n";
}

void recursiveReversePrint(node* headrrPrint){
	// exit condition
	if(headrrPrint == NULL) {
		return;
	}
	recursiveReversePrint(headrrPrint->next);
	std::cout << headrrPrint->data << "  ";
}

void reverseList(node** headReverseList){
	node* current = *headReverseList;
	node* nextNode;
	node* prev;
	
	if(*headReverseList == NULL) {
		return;
	}
	
	prev = NULL;
	while(current != NULL){
		nextNode = current->next;
		current->next = prev;
		prev = current;
		current = nextNode;
	}
	*headReverseList = prev;
}

void reverseListRecursively(node** headReverseListRecursive){
	if(	(headReverseListRecursive == NULL) 
		|| (*headReverseListRecursive == NULL) 
		|| ((*headReverseListRecursive)->next == NULL))
	{
		return;
	}
	
	node* current = *headReverseListRecursive;
	node* next = current->next;
	*headReverseListRecursive = next;
	
	reverseListRecursively(headReverseListRecursive);
	
	next->next = current;
	current->next = NULL;
}

int main() {
	node* head = NULL;
	int n, data, opt, pos, count=0;
	
	while(1){
		std::cout << "================== WELCOME TO SINGLY LINKED LIST PROGRAM =======================" << "\n";
		std::cout << "1. Insert List" << "\n";
		std::cout << "2. Delete List" << "\n";
		std::cout << "3. Print List" << "\n";
		std::cout << "4. Reverse List" << "\n";
		std::cout << "5. Keluar" << "\n";
		std::cout << "Enter your choice[1/2/3/4/5]: ";
		std::cin >> n;
		
		if(n == 1){
			std::cout << "Insert data: ";
			std::cin >> data;
			std::cout << "\n1. Insert Front" << "\n";
			std::cout << "2. Insert End" << "\n";
			std::cout << "3. Insert at Particular Position" << "\n";
			std::cout << "Enter the number choices[1/2/3]:  ";
			std::cin >> opt;
			
			if(opt == 1){
				insertFront(&head, data, &count);
			}else if(opt == 2){
				insertEnd(&head, data, &count);
			}else if(opt == 3){
				std::cout << "Insert position: ";
				std::cin >> pos;
				insertatPos(&head, data, pos, &count);
			}else {
				std::cout << "No " << opt << " choices exist" << "\n";
			}
			
		}else if(n == 2){
			std::cout << "\n1. Delete all content in list" << "\n";
			std::cout << "2. Delete content at particular position" << "\n";
			std::cout << "Enter your choice[1/2]:  ";
			std::cin >> opt;
			
			if(opt == 1){
				count = 0;
				deleteAll(&head);
			} else if(opt == 2){
				std::cout << "Insert position: ";
				std::cin >> pos;
				deleteNodeAt(&head, pos, &count);
			} else{
				std::cout << "No " << opt << " choices exist" << "\n";
			}
		}else if(n == 3){
			std::cout << "============== Contents of List =============="<< "\n";
			std::cout << "1. Print List as it is" << "\n";
			std::cout << "2. Recursively Reversed Print List" << "\n";
			std::cout << "Enter your choice[1/2] : ";
			std::cin >> opt;
			
			if(opt == 1){
				printList(head);
				std::cout << "List size: "<< count << "\n";
			} else if(opt == 2) {
				recursiveReversePrint(head);
				std::cout << "\n";
			} else{
				std::cout << "No " << opt << " choices exist" << "\n";
			}
		
		}else if(n == 4) {
			std::cout << "============== Reversed List =============="<< "\n";
			std::cout << "1. Reverse List Iteratively" << "\n";
			std::cout << "2. Recursively Reversed List" << "\n";
			std::cout << "Enter your choice[1/2] : ";
			std::cin >> opt;
			
			if(opt == 1) {
				reverseList(&head);
				std::cout << "List successfully reversed!" << "\n";
			} else if(opt == 2) {
				reverseListRecursively(&head);
				std::cout << "List successfully reversed!" << "\n";
			} else{
				std::cout << "No " << opt << " choices exist" << "\n";
			}
			
			
		}else if(n == 5){
			std::cout << "============== Program Ended ============== THANK YOU!!! =============="<< "\n";
			break;
		} else{
			std::cout << "Invalid choices " << n << " please enter the valid choice numbers!" << "\n";
		}
	}
	
	// free all the allocated nodes after program ended
	deleteAll(&head);
}

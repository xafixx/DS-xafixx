#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

void insertFront(node** headFront, int dataFront){
	node* temp_ifr = (node*)malloc(sizeof(node*));
	temp_ifr->data = dataFront;
	temp_ifr->next = *headFront;
	*headFront = temp_ifr;
}

void insertEnd(node** headEnd, int dataEnd){
	node* tempInsertEnd_f = (node*)malloc(sizeof(node*));
	tempInsertEnd_f->data = dataEnd;
	tempInsertEnd_f->next = NULL;
	
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

void insertatPos(node** headatPos, int dataatPos, int insertPos){
	
}

void deleteNodeAt(node** headDelete, int deletePos){
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

void reverseContentOfList(node** headReverseContentOfList){
}

int main() {
	node* head = NULL;
	int n, data, opt, pos;
	
	while(1){
		std::cout << "================== WELCOME TO LINKED LIST PROGRAM =======================" << "\n";
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
				insertFront(&head, data);
			}else if(opt == 2){
				insertEnd(&head, data);
			}else if(opt == 3){
				std::cout << "Insert position: ";
				std::cin >> pos;
				insertatPos(&head, data, pos);
			}else {
				std::cout << "No " << opt << " choices exist" << "\n";
			}
			
		}else if(n == 2){
			std::cout << "\n1. Delete all content in list" << "\n";
			std::cout << "2. Delete content at particular position" << "\n";
			std::cout << "Enter your choice[1/2]:  ";
			std::cin >> opt;
			
			if(opt == 1){
				deleteAll(&head);
			} else if(opt == 2){
				std::cout << "Insert position: ";
				std::cin >> pos;
				deleteNodeAt(&head, pos);
			} else{
				std::cout << "No " << opt << " choices exist" << "\n";
			}
		}else if(n == 3){
			std::cout << "============== Contents of List =============="<< "\n";
			std::cout << "1. Print List as it is" << "\n";
			std::cout << "2. Reversed Print List" << "\n";
			std::cout << "Enter your choice[1/2] : ";
			std::cin >> opt;
			if(opt == 1){
				printList(head);
			} else if(opt == 2) {
				recursiveReversePrint(head);
			} else{
				std::cout << "No " << opt << " choices exist" << "\n";
			}
		}else if(n == 4) {
			reverseContentOfList(&head);
		}else if(n == 5){
			std::cout << "============== Program ended ============== THANK YOU!!! =============="<< "\n";
			break;
		} else{
			std::cout << "Invalid choices " << n << " please enter the valid choice numbers!" << "\n";
		}
	}
	
	// free all the allocated nodes after program ended
	deleteAll(&head);
}

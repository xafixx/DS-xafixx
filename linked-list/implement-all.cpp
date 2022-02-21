#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

void insertFront(node** headFront, int dataFront){
}

void insertEnd(node** headEnd, int dataEnd){
}

void insertatPos(node** headatPos, int dataatPos, int insertPos){
}

void deleteNodeAt(node** headDelete, int deletePos){
}

void deleteAll(node** headDeleteAll){
}

void printList(node* headPrintList) {
}

void reversePrintList(node* headReversePrintList){
}

void reverseContentOfList(node** headReverseContentOfList){
}

int main() {
	node* head = NULL;
	int n, data, opt, pos;
	while(1){
		std::cout << "================== SELAMAT DATANG LINKED LIST =======================" << "\n";
		std::cout << "1. Insert List" << "\n";
		std::cout << "2. Delete List" << "\n";
		std::cout << "3. Print List" << "\n";
		std::cout << "4. Reverse Print" << "\n";
		std::cout << "5. Reverse List" << "\n";
		std::cout << "6. Keluar" << "\n";
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
			std::cout << "Enter the number choices[1/2]:  ";
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
			printList(head);
		}else if(n == 4){
			reversePrintList(head);
		}else if(n == 5) {
			reverseContentOfList(&head);
		}else if(n == 6){
			std::cout << "============== Program ended ==============" << "\n";
			std::cout << "============== THANK YOU!!! ==============" << "\n";
			break;
		} else{
			std::cout << "Invalid choices " << n << " please enter the valid choice numbers!" << "\n";
		}
	}
}

#include<bits/stdc++.h>

struct node{
	int data;
	node* next;
};

int main() {
	node* head = NULL;
	int n, data, how_many;
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
			int opt;
			std::cout << "1. Insert Front" << "\n";
			std::cout << "2. Insert End" << "\n";
			std::cout << "3. Insert at Particular Position" << "\n";
			std::cin >> opt;
			
		}else if(n == 2){
		}else if(n == 3){
		}else if(n == 4){
		}else if(n == 5) {
		}else if(n == 6){
			std::cout << "============== Program ended ==============" << "\n";
			std::cout << "============== THANK YOU!!! ==============" << "\n";
			break;
		} else{
			std::cout << "No choices " << n << " please enter the valid choice numbers!" << "\n";
		}
	}
}

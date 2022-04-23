/*
 * Queue implementation using linked list
 * */
#include<bits/stdc++.h>

// class queue to represent linked list
class Que{
	Que* front;
	Que* rear;
	public:
		Que() {
			front = NULL;
			rear = NULL;
		}
		Que* createNode(int data_crt);
		void enqueue(int data_enq);
		void dequeue();
		int front_p();
		bool isEmpty();
	private:
		int data;
		Que* next;
		
};

// creating new node
Que* Que::createNode(int data_crt) {
	Que* temp = new Que();
	temp->data = data_crt;
	temp->next = NULL;
	return temp;
}

/*
 * Add data at the end of the list,
 * if front and rear empty,
 * point front and rear to 
 * newly created node, otherwise
 * add new node at the end of the list.
 * */
void Que::enqueue(int data_enq) {
	Que* temp = createNode(data_enq);
	if(front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}


/*
 * dequeue or pop first element on the list.
 */
void Que::dequeue(){
	Que* temp = front;
	if(front == NULL) return;
	if(front == rear) {
		front = rear = NULL;
		delete temp;
		return;
	}
	front = front->next;
	delete temp;
}

// return first element on the list
int Que::front_p() {
	return front->data;
}

// check if the queue empty
bool Que::isEmpty(){
	return((front == NULL && rear == NULL)? true:false);
}

int main() {
	class Que q;
	q.enqueue(11); // 11 first in
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14); // 14 last in
	
	/*
	 * the output should be 11, 12, 13, 14 (first in first out)
	 * */
	while(!(q.isEmpty())){
		std::cout << q.front_p() << " ";
		q.dequeue();
	}
	std::cout << "\n";
}



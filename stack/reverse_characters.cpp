/*
 * 
 * Simple program to reverse 
 * string of characters using stack
 * 
 * */
#include<bits/stdc++.h>

// this function will emit a string
// with each character in reverse order
std::string reverse(std::string c, int len) {
	
	// declare stack with type of char
	std::stack<char> S;
	
	// push each character from c to S
	// example: hello --> push: o->l->l->e->h
	for(int i=0; i<len; i++) {
		S.push(c[i]);
	}
	
	// Use top() to get the top element of stack
	// in above example the top element are o, l,...,h
	// then store it back to c
	// and pop all element in stack S
	for(int i=0; i<len; i++) {
		c[i] = S.top();
		S.pop();
 	}
 	
 	return c;
}

int main(){
	std::string c;
	
	std::cout << "input string: ";
	std::getline(std::cin, c);
	
	std::cout << "Before reverse: " << "\n";
	std::cout << c << "\n";
	
	c = reverse(c, c.length());
	
	std::cout << "After reverse: " << "\n";
	std::cout << c << "\n";
}

#include <iostream>
// #include "node.h"

using namespace std;


class Stack {
	node* head;
public:
	Stack() {
		head = NULL;
	}
	void sethead(node* head) {
		this->head = head;
	}
	node* gethead() {
		return this->head;
	}

	void push(int v) {
		if (head == NULL) {
			head = new node();
			head->setdata(v);
			return;
		}
		node* temp = new node();
		temp->setnext(head);
		temp->setdata(v);
		head = temp;
			
	}
	char peek() {
		node * temp = head;
		return temp->getdata();
	}

	void pop() {
		if (head != NULL) {
			node* temp = head;
			head = head->getnext();
			delete temp;
		}

	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

};

#include <iostream>
#include "node.h"

using namespace std;



class Queue : public node {

	node* front;
	node* rear;

public:

	Queue() {

		front = NULL;
		rear = NULL;
	}

	void enQueue(int x) {

		if (isEmpty()) {
			rear = new node(x);
			front = rear;
		}
		else {
			rear->setnext(new node(x));
			rear = rear->getnext();
		}
		
	}

	int deQueue()
	{   
        int x;

		if (front == NULL) {
			return 0;
		}
			
		node* temp = front;
		if (front == rear) {
			front = rear = NULL;
		}
		else {
            x = front->getdata();
			front = front->getnext();
		}
		
		delete (temp);

        return x;
	}

	int showFront() {
		if (front == NULL) {
			return 0;
		}
		return front->getdata();
	}

	int showRear() {
		if (rear == NULL) {
			return 0;
		}
		return rear->getdata();
	}

	bool isEmpty() {
		if (front == NULL && rear == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

    int sizeofQueue(){
        node* temp = front;
        int count = 0;
        while(temp != NULL){
            count += 1;
            temp = temp->getnext();
        }

        return count;
    }

    void display(){
        node* temp = front;
        while(temp != NULL){
            cout<<temp->getdata()<<" ";
            temp = temp->getnext();
        }
    }

	

};

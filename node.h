#include <iostream>
using namespace std;

class node {

	int data;
	node* next;

public:
	node() { data = 0; next = NULL; }
	node(int v) {

		data = v;
	}

	void setdata(int  v) {

		data = v;
	}

    void setnext(node* v) {
		next = v;
	}

	node* getnext() {

		return next;
	}
    int getdata() {

		return data;
	}


};
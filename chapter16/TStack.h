//:TStack.h
//The Stack as a template
#ifndef TSTACK_H
#define TSTACK_H
template<class T>
class Stack{
    struct Link{
	T* data;
	Link* next;
	Link(T* dat, Link* nxt):
	    data(dat),next(nxt){}
    }* head;
public:
    Stack():head(0){}
    ~Stack(){
	while(head)
	    delete pop();
    }
    void push(T* dat){
	head = new Link(dat, head);
    }
    T* peak(){
	return head? head->data:0;
    }
    T* pop(){
	if(head == 0) return 0;
	T* result = head->data;
	Link* temp = head;
	head = head->next;
	delete temp;
	return result;
    }
};
#endif

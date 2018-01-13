#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList:: TodoStackLinkedList(){
	stackHead = NULL;
}
TodoStackLinkedList:: ~TodoStackLinkedList(){
	TodoItem *temp = stackHead;
	while(temp != NULL){
		TodoItem *prev = temp;
		temp = temp -> next;
		delete prev;
	}
	stackHead = NULL;
}

bool TodoStackLinkedList:: isEmpty(){
	return (stackHead == NULL);
}

void TodoStackLinkedList:: push(std::string todoItem){
	TodoItem* temp = new TodoItem;
	temp -> todo = todoItem;
	temp -> next = stackHead;
	stackHead = temp;

}

void TodoStackLinkedList:: pop(){
	if(isEmpty()){
		cout<<"Stack empty, cannot pop an item."<<endl;
		return;
	}
	TodoItem * temp = stackHead;
	stackHead = stackHead -> next;
	delete temp;

}




TodoItem* TodoStackLinkedList:: peek(){
	if(stackHead != NULL){
		return stackHead ;
	}
	else{
		cout<<"Stack empty, cannot peek."<<endl;
		return NULL;
	}
}
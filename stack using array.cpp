#include <iostream>
#include "HW4-Todo-StackArray.hpp"
using namespace std;


TodoStackArray:: TodoStackArray(){
	stackTop = -1;
	for(int i=0; i < MAX_STACK_SIZE; i++){
		stack[i] = new TodoItem;
	}
}

bool TodoStackArray:: isEmpty(){
	if(stackTop == -1 ){
		return true;
	}
	else {
		return false;
	}
}

bool TodoStackArray:: isFull(){
	if(stackTop == MAX_STACK_SIZE -1)
		return true;

	return false;
	
}

void TodoStackArray:: push(std::string todoItem){

	if(isFull()){
	cout<<"Stack full, cannot add new todo item."<<endl;
	return;
}
 if(isEmpty()){
	stackTop = 0;
	stack[stackTop] -> todo = todoItem;
	return;
}
stackTop++;
if( stackTop > MAX_STACK_SIZE -1){
		
		stackTop = 0;
}
stack[stackTop] -> todo = todoItem;

return;
}

void TodoStackArray:: pop(){
	if(isEmpty())
		{
			cout<<"Stack empty, cannot pop an item."<<endl;
			return;
		}
		stackTop --;
		
}	
	

TodoItem* TodoStackArray:: peek(){
	if(isEmpty()){
	cout<<"Stack empty, cannot peek."<<endl;
	return NULL;
}
else{
	return stack[stackTop];
}
}
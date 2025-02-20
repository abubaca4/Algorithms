#ifndef STACK_H
#define STACK_H
#include "list_s.hpp"
// Stack
// Stores integer values inside
template<typename Data>
class Stack {
	List<Data>* cont;
public:
	// Creates empty stack
	Stack();
	// Deletes the stack
	~Stack();
	// Pushes data on top of the stack
	// Should be O(1) on average
	void push(const Data &data);
	// Retrives the last element from the stack
	Data get() const;
	// Removes the last element from the stack
	// Should be O(1)
	void pop();
	// Returns true if the stack is empty
	bool empty() const;
};

template<typename Data>
Stack< Data > ::Stack()
{
	cont = new List<Data>;
}

template<typename Data>
Stack< Data > ::~Stack()
{
	delete cont;
}

template<typename Data>
void Stack < Data > ::push(const Data &data)
{
	cont->insert(data);
}

template<typename Data>
Data Stack < Data > ::get() const
{
	return cont->item_data(cont->first());
}

template<typename Data>
void Stack < Data > ::pop()
{
	cont->erase_first();
}

template<typename Data>
bool Stack < Data > ::empty() const
{
	return !(cont->first());
}
#endif
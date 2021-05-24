// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
#include <string>
//Stack

//Stack constrcutor that will have a top size of -1, meaning empty
//also stack size will have an intial size of 10
template <typename T>
Stack <T>::Stack(void)
    :top_(-1),
    stack_size_(10)
{

}

//Stack

//copy constructor to copy stack data and stack size
template<typename T>
Stack<T>::Stack(const Stack& s)
    :stack_data_(s.stack_data_),
    stack_size_(s.stack_size_)
{

}


//~Stack

//There was no pointers intizlied to be delelted, therefor the class's constructor will be empty
template <typename T>
Stack <T>::~Stack(void)
{
    
}


//push()

//The push operation is to push elements to the stack, a simple check to see if the top is equal to
//the stack size -1, meaning if the stack is full, it will resize the stack to the new size 
//otherwise, a prefix operator takes place to increment the top, and then set stack data with
//the top and the element given.
template <typename T>
void Stack <T>::push(T element)
{
    if (this->top_ == this->stack_size_ - 1)
    {
        stack_data_.Array<T>::resize(stack_size_);
    }
    else {
        ++top_;
        stack_data_.Array<T>::set(top_, element);
    }
}


//pop()

//The pop operation is to pop elements out of the stack, a simple check is used to see
//if it's empty, if true, an empty exception is thrown, else if will a postfix operator takes
//place to decrement the top
template <typename T>
void Stack <T>::pop(void)
{
    if (is_empty()) {
        throw Stack<T>::empty_exception();
    }
    else {
        top_--;
        std::cout << this->stack_data_[this->top_] << std::endl;
    }
}


//top()

//The top operation is to get the top element on the stack, a simple check is used to see
//if it's empty, if true, an empty exception is thrown. else, return the top element on the
//stack data
template <typename T>
T Stack<T>::top(void) const
{
    if (is_empty()) {
        throw Stack<T>::empty_exception();
    }
    else {
        std::cout << this->stack_data_[this->top_] << std::endl;
        return this->stack_data_[this->top_];
    }
}


//operator =

template <typename T>
const Stack <T>& Stack <T>::operator = (const Stack& rhs)
{
    // COMMENT It would be easier if you just use the assignment operator
    // on the array to copy things from rhs.
    //=>fixed issue by using the assignment operator = on base array 
   
    if (this != &rhs) {
        this->stack_data_ = rhs.stack_data_;
        this->top_ = rhs.top_;
    }
    else {
        return (*this);
    }
}

//
//Check if the stack is empty
//

template <typename T>
bool Stack <T>::is_empty(void) const
{
    if (this->top_ == -1) {
        std::cout << "Stack is empty" << std::endl;
        return true;
    }

    else {
        return false;
    }
}

//
//return the size of the stack
//

template <typename T>
size_t Stack<T>::size(void) const
{
    return this->stack_size_;
}

//
//Empty the elements in the stack
//

template <typename T>
void Stack <T>::clear(void)
{
    top_ = -1;
}

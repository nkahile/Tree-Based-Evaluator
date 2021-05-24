#include "Expr_Node_Iterator.h"

//Intialize private member variable to iter and current loaction to 0
Expr_Node_Iterator::Expr_Node_Iterator(Array <Expr_Node>& iter)
	:iter_(iter), curr_(0)
{

}

//No pointers to delete,hence,Destructor will be empty
Expr_Node_Iterator::~Expr_Node_Iterator(void) {

}

//Will check if the iterator is done and return the current size
bool Expr_Node_Iterator::is_done(void) {
	return this->curr_ >= this->iter_.size();
}

//Move to the next element, equevlate to 'i++' in a for loop
void Expr_Node_Iterator::advance(void) {
	++this->curr_;
}

//Return the data the current location
Expr_Node& Expr_Node_Iterator::operator * (void) {
	return this->iter_.Base_Array<T>::data_[this->curr_];
}

//Return the data object at the current location
Expr_Node* Expr_Node_Iterator::operator -> (void) {
	return &this->iter_.data_[this->curr_];
}
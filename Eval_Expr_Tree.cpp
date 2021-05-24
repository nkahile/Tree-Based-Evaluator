#include "Eval_Expr_Tree.h"
#include <stdexcept>

Eval_Expr_Tree::Eval_Expr_Tree(void)
	:result_(0),
	stack_()
{

}

Eval_Expr_Tree::~Eval_Expr_Tree(void)
{
	//no pointers to delete 
}

void Eval_Expr_Tree::Visit_Addition_Node(const Add_Node& node)
{
	if (node.getLeftChild() != nullptr)
		node.getLeftChild()->accept(*this);

	if (node.getLeftChild() != nullptr)
		node.getRightChild()->accept(*this);
	
	//Assign n2 to the top of the stack
	int n2 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Assign n1 to the top of the stack
	int n1 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Add results
	this->result_ = n1 + n2;

	//push results
	this->stack_.push(result_);

}

void Eval_Expr_Tree::Visit_Subtraction_Node(const Subtract_Node& node)
{
	if (node.getLeftChild() != nullptr)
		node.getLeftChild()->accept(*this);

	if (node.getLeftChild() != nullptr)
		node.getRightChild()->accept(*this);

	//Assign n2 to the top of the stack
	int n2 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Assign n1 to the top of the stack
	int n1 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Add results
	this->result_ = n1 - n2;

	//push results
	this->stack_.push(result_);

}

void Eval_Expr_Tree::Visit_Division_Node(const Divide_Node& node)
{
	if (node.getLeftChild() != nullptr)
		node.getLeftChild()->accept(*this);

	if (node.getLeftChild() != nullptr)
		node.getRightChild()->accept(*this);

	//Assign n2 to the top of the stack
	int n2 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Assign n1 to the top of the stack
	int n1 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Check Division by 0
	if (n2 != 0) {
		this->result_ = n1 / n2;
	}
	else {
		throw std::out_of_range("Index out of range");
	}

	//push results
	this->stack_.push(result_);
}

void Eval_Expr_Tree::Visit_Multiplication_Node(const Multiply_Node& node)
{
	if (node.getLeftChild() != nullptr)
		node.getLeftChild()->accept(*this);

	if (node.getLeftChild() != nullptr)
		node.getRightChild()->accept(*this);

	//Assign n2 to the top of the stack
	int n2 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Assign n1 to the top of the stack
	int n1 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Add results
	this->result_ = n1 * n2;

	//push results
	this->stack_.push(result_);

}

void Eval_Expr_Tree::Visit_Modulus_Node(const Mod_Node& node)
{
	if (node.getLeftChild() != nullptr)
		node.getLeftChild()->accept(*this);

	if (node.getLeftChild() != nullptr)
		node.getRightChild()->accept(*this);

	//Assign n2 to the top of the stack
	int n2 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Assign n1 to the top of the stack
	int n1 = this->stack_.top();
	//pop the value 
	this->stack_.pop();

	//Add results
	this->result_ = n1 % n2;

	//push results
	this->stack_.push(result_);
}

void Eval_Expr_Tree::Visit_Number_Node(const Num_Node& node)
{
	this->stack_.push(node.getNumber());

	this->result_ = node.getNumber();

}

int Eval_Expr_Tree::result(void) const
{
	return this->result_;
}
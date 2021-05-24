#include "Binary_Expr_Node.h"


//
//	Binary_Expr_Node
//
Binary_Expr_Node::Binary_Expr_Node(int precedence)
	: precedence_(precedence),
	left_(0),
	right_(0)
{
}

//
// ~Binary_Expr_Node
//
Binary_Expr_Node::~Binary_Expr_Node(void)
{

}

//
// getPrecedence
//
int Binary_Expr_Node::getPrecedence(void)
{
	return precedence_;
}

//
// setLeftChild
//
void Binary_Expr_Node::setLeftChild(Expr_Node* left)
{
	left_ = left;
}

//
// setRightChild
//
void Binary_Expr_Node::setRightChild(Expr_Node* right)
{
	right_ = right;
}

//
// getLeftChild
//
Expr_Node* Binary_Expr_Node::getLeftChild(void) const
{
	return left_;
}

//
// getRightChild
//
Expr_Node* Binary_Expr_Node::getRightChild(void) const
{
	return right_;
}
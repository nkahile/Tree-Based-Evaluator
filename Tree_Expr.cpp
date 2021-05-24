//
// Tree_Expr
//

#include "Tree_Expr.h"

//
// Tree_Expr
//

Tree_Expr::Tree_Expr(Expr_Node* root)
	: root_(root)
{
}

//
// ~Tree_Expr
//
Tree_Expr::~Tree_Expr(void)
{
}

//
// Eval
//
int Tree_Expr::eval(void)
{
	if (nullptr == this->root_)
		throw std::runtime_error("There is no expression!\n");

	root_->accept(evaluateTree_);

	return evaluateTree_.getResult();
}

//
// getRoot
//
Expr_Node* Tree_Expr::getRoot(void)
{
	return root_;
}

//
// setRoot
//
void Tree_Expr::setRoot(Expr_Node* root)
{
	root_ = root;
}
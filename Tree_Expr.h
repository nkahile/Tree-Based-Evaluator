// -*- C++ -*-
// $Id: Tree_Expr.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 //==============================================================================

#ifndef _TREE_EXPR_H_
#define _TREE_EXPR_H_

/**
 * @class Tree_Expr
 *
 *
 */

#include "Math_Expr.h"
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

class Tree_Expr : public Math_Expr
{
public:
	Tree_Expr(Expr_Node* root);

	~Tree_Expr(void);

	virtual int eval(void);

	Expr_Node* getRoot(void);
	void setRoot(Expr_Node* root);

private:
	Expr_Node* root_;
	Eval_Expr_Tree evaluateTree_;

};
#endif
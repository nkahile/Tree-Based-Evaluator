// -*- C++ -*-
// $Id: Unary_Expr_Node.h 
#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

/**
 * @class Unary_Expr_Node
 *
 *
 */

#include"Expr_Node.h"

class Unary_Expr_Node : public Expr_Node
{
public:
	Unary_Expr_Node(void);

	virtual ~Unary_Expr_Node(void);

	virtual int eval(void);

protected:
	Expr_Node* child_;
};

#endif
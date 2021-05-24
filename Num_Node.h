#ifndef _NUM_NODE_H_
#define _NUM_NODE_H_

#include "Expr_Node.h"
#include "Stack.h"


class Num_Node : public Expr_Node {
public:

	//Num_Node constructor
	Num_Node(int n);

	virtual void accept(Expr_Node_Visitor& visitor);

private:

	//Number that will be pushed onto the stack
	int n_;
};

#endif

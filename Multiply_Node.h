#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include"Expr_Node.h"
#include"Stack.h"


class Multiply_Node : public Expr_Node {
public:

	// Multiply_Node Constructor
	Multiply_Node(void);

	virtual void accept(Expr_Node_Visitor& visitor);

};

#endif

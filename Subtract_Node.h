#ifndef _SUBTRACT_NODE_H_
#define _SUBTRACT_NODE_H_

#include"Expr_Node.h"
#include"Stack.h"

class Subtract_Node : public Expr_Node {
public:

	// Subtract_Node Contructor
	Subtract_Node(void);


	virtual void accept(Expr_Node_Visitor& visitor);
};

#endif
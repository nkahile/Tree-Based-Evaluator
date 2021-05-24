#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"

class Expr_Node_Visitor;


class Divide_Node : public Expr_Node {
public:

	// Divide_Node Contructor
	Divide_Node(void);

	///Destructor
	~Divide_Node(void);

	virtual void accept(Expr_Node_Visitor& visitor);

};

#endif

#ifndef _EXPR_TREE_BUILDER_
#define _EXPR_TREE_BUILDER_

#include "Expr_Builder.h"
#include "Tree_Expr.h"
#include "Stack.h"
#include "Calculator.h"


#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Mod_Node.h"
#include "Num_Node.h"

class Expr_Tree_Builder : public Expr_Builder
{
public:
	Expr_Tree_Builder(void);

	virtual ~Expr_Tree_Builder(void);

	virtual void start_expression(void);

	virtual void end_expression(void);

	virtual void build_number(int num);

	virtual void build_add_operator(void);

	virtual void build_subtract_operator(void);

	virtual void build_multiply_operator(void);

	virtual void build_divide_operator(void);

	virtual void build_modulus_operator(void);

	virtual void build_open_parenthesis(std::istringstream& s);

	virtual void build_close_parenthesis(void);

	virtual void build_variable(std::string var, std::map < std::string, int > variables);

	Math_Expr* get_expression(void);



private:
	void build_binary_node(Binary_Expr_Node* binaryNode);
	void connectTrees(Binary_Expr_Node* binaryNode);

	// Final tree
	Tree_Expr* tree_;

	// other variables to coordinate build process
	Stack < Tree_Expr* > treeStack_;
	Stack < Binary_Expr_Node* > operatorStack_;
};

#endif
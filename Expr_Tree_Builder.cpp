#include "Expr_Tree_Builder.h"
#include <iostream>

//
// Expr_Tree_Builder
//

Expr_Tree_Builder::Expr_Tree_Builder(void)
	: tree_(0),
	treeStack_(),    //Default stacks of initial size 5
	operatorStack_()
{
}

//
// ~Expr_Tree_Builder
//
Expr_Tree_Builder::~Expr_Tree_Builder(void)
{
}


//
// start_expression
//
void Expr_Tree_Builder::start_expression(void)
{
	this->tree_ = new Tree_Expr(nullptr);
}


void Expr_Tree_Builder::end_expression(void)
{
	while (!operatorStack_.is_empty())
	{
		connectTrees(operatorStack_.top());
		operatorStack_.pop();
	}

	this->tree_->setRoot(treeStack_.top()->getRoot());
}

//
// build_number
//

void Expr_Tree_Builder::build_number(int num)
{
	//Create a new tree with root as number object. Push that tree onto treeStack_
	Expr_Node* number = new Number_Node(num);
	Tree_Expr* tree = new Tree_Expr(number);
	treeStack_.push(tree);
}

//
// build_variable
//

void Expr_Tree_Builder::build_variable(std::string var, std::map < std::string, int > variables)
{
	//Create a number node from variable

	std::map <std::string, int>::iterator it;

	it = variables.find(var);

	build_number(it->second);
}

//
// build_add_operator
//

void Expr_Tree_Builder::build_add_operator(void)
{
	Add_Node* add;
	build_binary_node(add);

}


//
// build_subtract_operator
//

void Expr_Tree_Builder::build_subtract_operator(void)
{
	Subtract_Node* subtract;
	build_binary_node(subtract);
}

//
// build_multiply_operator
//

void Expr_Tree_Builder::build_multiply_operator(void)
{
	Multiply_Node* multiply;
	build_binary_node(multiply);
}

//
// build_divide_operator
//

void Expr_Tree_Builder::build_divide_operator(void)
{
	Divide_Node* divide;
	build_binary_node(divide);
}

//
// build_modulus_operator
//

void Expr_Tree_Builder::build_modulus_operator(void)
{
	Mod_Node* modulus;
	build_binary_node(modulus);
}

//
// build_binary_node (Binary_Expr_Node *)
//

void Expr_Tree_Builder::build_binary_node(Binary_Expr_Node* binaryNode)
{

	//If Stack is empty or if operator being inserted has higher precedence than top of stack, then push operator onto stack
	if (operatorStack_.is_empty() || (binaryNode->getPrecedence() > operatorStack_.top()->getPrecedence()))
		operatorStack_.push(binaryNode);

	else
	{
		while (!operatorStack_.is_empty())
		{
			connectTrees(operatorStack_.top());
			operatorStack_.pop();
		}
		operatorStack_.push(binaryNode);
	}
}

//
// connectTrees (Binary_Expr_Node *)
//

void Expr_Tree_Builder::connectTrees(Binary_Expr_Node* binaryNode)
{

	binaryNode->setRightChild(treeStack_.top()->getRoot());
	treeStack_.pop();

	binaryNode->setLeftChild(treeStack_.top()->getRoot());
	treeStack_.pop();

	//Create subtree with root as operator and push it onto treeStack_
	Tree_Expr* subtree = new Tree_Expr(binaryNode);
	treeStack_.push(subtree);

}

//
// build_open_parenthesis
//

void Expr_Tree_Builder::build_open_parenthesis(std::istringstream& stream)
{
	int numOfOpenParenthesis = 0;
	std::string token;
	std::string RecursiveString;
	stream >> token;

	Expr_Tree_Builder builder;
	Calculator calc(builder);
	while (!stream.eof())
	{
		if (token.compare("(") == 0)
			numOfOpenParenthesis++;

		//For every '(', there must be a ')'
		if (token.compare(")") == 0)
		{
			if (numOfOpenParenthesis == 0)
				break;
			numOfOpenParenthesis--;
		}

		RecursiveString.append(token);
		RecursiveString.append(" ");

		stream >> token;
	}

	//RecursiveString.pop_back();
	int res = calc.compute(RecursiveString);

	build_number(res);
}

//
// build_close_parenthesis
//

void Expr_Tree_Builder::build_close_parenthesis(void)
{

}

//
// get_expression
//

Math_Expr* Expr_Tree_Builder::get_expression(void)
{
	return this->tree_;
}
// $Id: Calculator.cpp 

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Calculator.h"
#include <iostream>
//
// Calculator
//
Calculator::Calculator(Expr_Builder& builder)
	: builder_(builder),
	variables()
{
}


//
//~Calculator
//
Calculator::~Calculator(void)
{
}

//
//compute
//
int Calculator::compute(const std::string& infix)
{
	if (!this->parse_expr(infix))
	{
		variables.clear();
		throw std::runtime_error("Bad expresssion");
	}

	std::unique_ptr <Math_Expr> expr(this->builder_.get_expression());

	if (nullptr == expr.get())
		throw std::runtime_error("No expression!!");

	// evaluate the expression
	return expr->eval();
}

//
// deleteTrailingSpaces
//
std::string Calculator::deleteTrailingSpaces(const std::string& infix) const
{
	//Delete trailing spaces
	std::string infixNoTrailSpace = infix;
	for (int i = infixNoTrailSpace.size() - 1; i >= 0; i--)
	{
		if (infixNoTrailSpace.at(i) == ' ')
			infixNoTrailSpace.erase(i);
		else
			break;
	}

	return infixNoTrailSpace;
}

//
//variable_input
//
void Calculator::detect_vars(const std::string& expression)
{
	//Used to insert variables into map, and assign values to them

	int randomValue = 0;
	std::string token;
	std::istringstream input(expression);
	std::string infix;

	std::string var_input;
	int num;

	//Detect variables first open parenthesis or end of expression, whichever comes first
	while (!input.eof() && token.compare("(") != 0)
	{
		input >> token;

		//If a variable is detected
		if ((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z'))
			variables.insert({ token,randomValue });

	}

	std::map <std::string, int>::iterator it;
	for (it = variables.begin(); it != variables.end(); it++)
	{
		std::cout << "What is the value of variable: " << it->first << "\n";

		std::getline(std::cin, var_input);

		num = stoi(var_input, nullptr);

		it->second = num;  //Assign the variable with a number

	}
}

//
// parse_expr
//
bool Calculator::parse_expr(const std::string& infix)
{
	const std::string infixNoTrailSpace = deleteTrailingSpaces(infix);

	std::istringstream input(infixNoTrailSpace); // create a input stream parser

	detect_vars(infixNoTrailSpace);

	std::string token; // current token in string/stream

	builder_.start_expression(); // start a new expression

	while (!input.eof())
	{
		input >> token;
		if ((token.compare("+") == 0))
			this->builder_.build_add_operator();
		else if (token.compare("-") == 0)
			this->builder_.build_subtract_operator();
		else if (token.compare("*") == 0)
			this->builder_.build_multiply_operator();
		else if (token.compare("/") == 0)
			this->builder_.build_divide_operator();
		else if (token.compare("%") == 0)
			this->builder_.build_modulus_operator();
		else if (token.compare("(") == 0)
			this->builder_.build_open_parenthesis(input);
		else if (token.compare(")") == 0)
			this->builder_.build_close_parenthesis();
		else if ((token[0] >= 'A' && token[0] <= 'Z') || (token[0] >= 'a' && token[0] <= 'z'))
			this->builder_.build_variable(token, variables);
		else
		{
			std::string::iterator it = token.begin();

			//Allow for negative numbers by skipping the initial char check in the subsequent for-loop if a negative num is entered
			if (*it == '-')
				++it;

			for (; it != token.end(); ++it)
			{
				if (*it < '0' || *it > '9')
				{
					return false;
				}
			}

			int num = stoi(token, nullptr);
			this->builder_.build_number(num);
		}
	}

	builder_.end_expression();

	//empty map
	variables.clear();

	return true;
}
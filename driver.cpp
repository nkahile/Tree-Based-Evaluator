#include "Array.h"
#include"Fixed_Array.h"
#include "Stack.h"
#include"Queue.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	//testing Array
	//Array <char> a1(8, 'z');
	Array <char> a1(8, 'z');
	a1[0] = 'J';
	a1[1] = 'o';
	a1[2] = 'h';
	a1[3] = 'n';

	a1.get(0);
	a1.get(1);

	//a1.operator=(a2);
	//a1.set(2, 'F');
	//a1.resize(10);
	//a1.get(1);
	//a1.operator[](2);
	//a1.get(1);
	//Fixed_Array <int, 8> b1;
	//b1.fill(2);

	//Stack<int> c1;
	//c1.push(5);
	//c1.push(9);

	//Queue<int> q;
	//q.enqueue(9);
	//q.enqueue(2);
	//q.enqueue(3);
	//q.enqueue(7);
	//q.enqueue(8);
	/*q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();*/

	//q.show();
	return 0;
}

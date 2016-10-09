#include "MyQueue.h"
//#include <iostream>
//#include <cassert>

/*void test1();
void test2();
void test3();
void test4();
void test5();
void test6();*/

int main()
{
	/*test1();
	test2();
	test3();
	test4();
	test5();
	test6();*/
	queue<int> Q;
	Q.push(5);
	Q.push(10);
	int a = Q.front();
	int b = Q.back();
	std::cout << Q.front() << std::endl;
	Q.pop();
	std::cout << Q.front() << std::endl;
	std::cout << b << std::endl;
	system("pause");
	return 0;
}

/*void test1()
{

}
void test2()
{

}
void test3()
{

}
void test4()
{

}
void test5()
{

}
void test6()
{

}*/
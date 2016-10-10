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
	queue<int> QQ;
	Q.push(5);
	Q.push(10);
	Q.push(11);
	Q.push(13);
	Q.push(14);
	QQ = Q;
	std::cout << "here : " << std::endl;
	std::cout << Q << std::endl;
	std::cout << "here : " << std::endl;
	std::cout << QQ << std::endl;
	std::cout << QQ.size() << " " << Q.size() << std::endl;
	if (Q == QQ)
	    std::cout << "true " << std::endl;
	queue<int> QQQ;
	queue<int> QQQQ;
	QQQ.push(1);
	QQQ.push(2);
	QQQ.push(4);
	QQQQ = Q + QQQ;
	std::cout << QQQQ << std::endl;
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
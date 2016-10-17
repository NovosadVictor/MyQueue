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
/*	queue<int> Q;
	Q.push(5);
	Q.push(10);
	Q.push(11);
	Q.push(17);
	Q.push(3);
	std::cout << "Q here" << std::endl;
	std::cout << Q << std::endl;
	queue<int> QQ;
	QQ.push(3);
	QQ.push(4);
	QQ.push(7);
	QQ.push(17);
	QQ.push(17);
	QQ.push(13);
	QQ.push(5);
	std::cout << "QQ here" << std::endl;
	std::cout << QQ << std::endl;
	queue<int> QQQ;
	QQQ = Q + QQ;
	std::cout << "Q + QQ here" << std::endl;
	std::cout << QQQ << std::endl;
	std::cout << "Q here" << std::endl;
	std::cout << Q << std::endl;*/
	/*std::cout << "Q.front here" << std::endl;
	std::cout << Q.front() << std::endl;
	Q.pop();
	std::cout << "Q.back here after pop" << std::endl;
	std::cout << Q.back() << std::endl;
	std::cout << "Q.front after pop here" << std::endl;
	std::cout << Q.front() << std::endl;*/
	/*std::cout << "QQ here" << std::endl;
	std::cout << QQ << std::endl;
	Q.pop();
	Q.pop();
	std::cout << "here Q after 2 pop" << std::endl;
	std::cout << Q << std::endl;
	QQ.pop();
	QQ.pop();
	std::cout << "here QQ after 2 pop" << std::endl;
	std::cout << QQ << std::endl;*/
	queue<int> Q;
	for (int i = 0; i < 8; ++i)
		Q.push(i * 3 - 2);
	std::cout << "here Q" << std::endl;
	std::cout << Q << std::endl;
	queue<int> QQ = Q;
	std::cout << "here QQ" << std::endl;
	std::cout << QQ << std::endl;
	std::cout << "Q.front here" << std::endl;
	std::cout << Q.front() << std::endl;
	std::cout << "Q.back here" << std::endl;
	std::cout << Q.back() << std::endl;	
	std::cout << "here QQ == Q" << std::endl;
	if (Q == QQ)
		std::cout << "true" << std::endl;
	std::cout << "here Q size" << std::endl;
	std::cout << Q.size() << std::endl;
	queue<int> QQQ = Q + QQ;
	std::cout << "Q + QQ here" << std::endl;
	std::cout << QQQ << std::endl;
	std::cout << "Q here" << std::endl;
	std::cout << Q << std::endl;
	Q.QueueSort();
	std::cout << "here Q sort" << std::endl;
	std::cout << Q << std::endl;
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

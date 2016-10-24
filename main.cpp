#include "MyQueue.h"
#include <iostream>
#include <cassert>
#include <string>

void Itest1();
void Itest2();
void Itest3();// проверка на типе int
void Itest4();
void Itest5();
void Itest6();

void Stest1();
void Stest2();
void Stest3();// проверка на типе String
void Stest4();
void Stest5();
void Stest6();

int main()
{
	try {
		Itest1();
		Itest2();
		Itest3();
		Itest4();
		Itest5();
		Itest6();
		Stest1();
                Stest2();
                Stest3();
                Stest4();
                Stest5();
                Stest6();
	}
	catch(int e) {
		switch(e) {
		case 1: {std::cout << "ERROR IN POP" << std::endl; break;}
		case 2: {std::cout << "ERROR IN FRONT OR BACK" << std::endl; break;}
		case 3: {std::cout << "ERROR INT <<" << std::endl; break;}
		}
	}
	
	return 0;
}
// ПРОВЕРКА ДЛЯ INT
void Itest1() {
	std::cout << "CHECK FOR INT" << std::endl;
	queue<int> Q;
	std::cout << "\nTest1 function front/back\n" << std::endl;
	Q.push(3);
	Q.push(4);
	assert(Q.front() == 3 && Q.back() == 4);
	std::cout << Q << std::endl;
}
void Itest2() {
	queue<int> Q;
	std::cout << "\nTest2 function pop\n" << std::endl;
	Q.push(3);
	Q.push(45);
	Q.push(17);
	assert(Q.front() == 3);
	std::cout << Q << std::endl;
	Q.pop();
	assert(Q.front() == 45);
	std::cout << Q << std::endl;
	Q.pop();
	assert(Q.front() == 17);
	std::cout << Q << std::endl;
}
void Itest3() {
	queue<int> Q;
	std::cout << "\nTest3 function size/empty\n" << std::endl;
	assert(Q.empty());
	assert(Q.size() == 0);
	std::cout << "Q.size() = " << Q.size() << std::endl;
	Q.push(3);
	assert(!Q.empty());
	assert(Q.size() == 1);
	std::cout << "Q.size() = " << Q.size() << std::endl;
}
void Itest4() {
	queue<int> Q1;
	queue<int> Q2;
	std::cout << "\nTest4 function +\n" << std::endl;
	Q1.push(4);
	Q1.push(7);
	Q1.push(14);
	std::cout << Q1 << std::endl;
	Q2.push(4);
	Q2.push(17);
	Q2.push(18);
	Q2.push(1);
	std::cout << Q2 << std::endl;
	queue<int> Q = Q1 + Q2;
	assert(Q.front() == 4 && Q.back() == 1 && Q.size() == 7);
	std::cout << Q << std::endl;
}
void Itest5() {
	std::cout << "\nTest5 function =\n" << std::endl;
	queue<int> Q1;
	Q1.push(5);
	Q1.push(7);
	Q1.push(17);
	Q1.push(23);
	std::cout << Q1 << "\n" << std::endl;
	queue<int> Q2;
	Q2 = Q1;
	assert(Q2.size() == 4 && Q2.front() == 5 && Q2.back() == 23);
	std::cout << Q2 << std::endl;
}
void Itest6() {
	std::cout << "\nTest6 function QueueSort\n" << std::endl;
	queue<int> Q;
	for (int i = 1; i <= 8; ++i)
		Q.push(i*3-17);
	std::cout << Q << "\n" << std::endl;
	Q.QueueSort();
	assert(Q.size() == 8 && Q.front() == -14 && Q.back() == 7);
	std::cout << Q << std::endl;
}
// ПРОВЕРКА ДЛЯ STRING

void Stest1() {
	std::cout <<"\n\nCHECK FOR STRING" << std::endl;
        queue<std::string> Q;
        std::cout << "\nTest1 function front/back\n" << std::endl;
        Q.push("first");
        Q.push("second");
        assert(Q.front() == "first" && Q.back() == "second");
        std::cout << Q << std::endl;
}
void Stest2() {
        queue<std::string> Q;
        std::cout << "\nTest2 function pop\n" << std::endl;
        Q.push("three");
        Q.push("fourty five");
        Q.push("seventeen");
        assert(Q.front() == "three");
        std::cout << Q << std::endl;
        Q.pop();
        assert(Q.front() == "fourty five");
        std::cout << Q << std::endl;
        Q.pop();
        assert(Q.front() == "seventeen");
        std::cout << Q << std::endl;
}
void Stest3() {
        queue<std::string> Q;
        std::cout << "\nTest3 function size/empty\n" << std::endl;
        assert(Q.empty());
        assert(Q.size() == 0);
        std::cout << "Q.size() = " << Q.size() << std::endl;
        Q.push("three");
        assert(!Q.empty());
        assert(Q.size() == 1);
        std::cout << "Q.size() = " << Q.size() << std::endl;
}
void Stest4() {
        queue<std::string> Q1;
        queue<std::string> Q2;
        std::cout << "\nTest4 function +\n" << std::endl;
        Q1.push("four");
        Q1.push("seven");
        Q1.push("fourteen");
        std::cout << Q1 << std::endl;
        Q2.push("four");
        Q2.push("seventeen");
        Q2.push("eighteen");
        Q2.push("one");
        std::cout << Q2 << std::endl;
        queue<std::string> Q = Q1 + Q2;
        assert(Q.front() == "four" && Q.back() == "one" && Q.size() == 7);
        std::cout << Q << std::endl;
}
void Stest5() {
        std::cout << "\nTest5 function =\n" << std::endl;
        queue<std::string> Q1;
        Q1.push("five");
        Q1.push("seven");
        Q1.push("seventeen");
        Q1.push("twenty three");
        std::cout << Q1 << "\n" << std::endl;
        queue<std::string> Q2;
        Q2 = Q1;
        assert(Q2.size() == 4 && Q2.front() == "five" && Q2.back() == "twenty three");
        std::cout << Q2 << std::endl;
}
void Stest6() {
        std::cout << "\nTest6 function QueueSort\n" << std::endl;
        queue<std::string> Q;
	std::string s1 = "first";
	std::string s2 = "second";
	std::string s3 = "third";
	std::string s4 = "fourth";
	std::string s5 = "abc";
	std::string s6 = "bcd";
	std::string s7 = "zoodle";
        Q.push(s1);
	Q.push(s2);
	Q.push(s3);
	Q.push(s4);
	Q.push(s5);
	Q.push(s6);
	Q.push(s7);
        std::cout << Q << "\n" << std::endl;
        Q.QueueSort();
        assert(Q.size() == 7 && Q.front() == "abc" && Q.back() == "zoodle");
        std::cout << Q << std::endl;
}



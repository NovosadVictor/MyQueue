#ifndef _MYLIST_H_
#define _MYLIST_H_

template<typename T>
struct listNode
{
	list<T> *_prev;
	T _x;
	list<T> *_next;
	list() : _prev(nullptr), _next(nullptr), _x(0) {}
};
#endif
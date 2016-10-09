#ifndef _MYLIST_H_
#define _MYLIST_H_

template<typename T>
struct list
{
	list<T> *_prev;
	T _x;
	list<T> *_next;
};
#endif
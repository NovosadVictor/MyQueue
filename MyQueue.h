#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>
#include "MyList.h"

template<typename T>
class queue
{
public:
	queue() : _first(nullptr), _last(nullptr), _size(0) {}
	queue(const queue<T> &other);
	~queue();
	T& front();
	T& back();
	bool empty();
	size_t size();
	void push(const T& element);
	void pop();
//	bool operator==(const queue<T>& other);
//	bool operator!=(const queue<T>& other);
//	queue& operator=(const queue<T>& other);
//	friend std::ostream& operator<<(std::ostream& os, const queue& _queue);
private:
	list<T> *_first;
	list<T> *_last;
	size_t _size;
};

template<typename T>
queue<T>::queue(const queue<T> &other)
{
	_size = other._size;
	//_first->_prev = nullptr;
	_first = other._first;
	//_last->_next = nullptr;
	_last = other._last;
}
template<typename T>
queue<T>::~queue()
{
	while (_first != _last)
	{
		delete _first;
		_first = _first->_next;
	}
	delete _first;
	delete _last;
}
template<typename T>
T& queue<T>::front()
{
	if (_size != 0)
		return _first->_x;
	throw std::bad_alloc();
}
template<typename T>
T& queue<T>::back()
{
	if (_size != 0)
		return _last->_x;
	throw std::bad_alloc();
}
template<typename T>
bool queue<T>::empty()
{
	return _size == 0;
}
template<typename T>
size_t queue<T>::size()
{
	return _size;
}
template<typename T>
void queue<T>::push(const T& element)
{
	if (_size != 0)
	{
		list<T> Q;
		Q._x = element;
		Q._prev = _last;
		_last = &Q;
	}
	else
	{
		list<T> L;
		L._x = element;
		L._prev = nullptr;
		L._next = nullptr;
		_first = _last = &L;
	}
	++_size;
}
template<typename T>
void queue<T>::pop()
{
	if (_size == 1)
	{
		_last = _first = nullptr;
		delete _last;
		delete _first;
	}
	if (_size > 1)
	{
		list<T> *FIRST;
		FIRST = _first->_next;
		delete _first;
		_first = FIRST;
		_first->_prev = nullptr;
	}
	if (_size <= 0)
		throw std::bad_alloc();
}





#endif

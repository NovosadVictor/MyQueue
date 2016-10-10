#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>
#include "MyList.h"

template<typename T>
class queue
{
public:
	queue() : _first(new list<T>), _last(_first), _size(0) {}
	queue(const queue<T> &other);
	~queue();
	T& front();
	T& back();
	bool empty();
	size_t size();
	void push(const T& element);
	void pop();
	bool operator==(const queue<T>& other);
	bool operator!=(const queue<T>& other);
	queue<T>& operator=(const queue<T>& other);
	friend std::ostream& operator<<(std::ostream& os, const queue<T>& _queue);
private:
	list<T> *_first;
	list<T> *_last;
	size_t _size;
};

template<typename T>
queue<T>::queue(const queue<T> &other)
{
	_first = other._first;
	_last = other._last;
	_size = other._size;
}
template<typename T>
queue<T>::~queue()
{
	
	while (_first != _last)
	{
		list<T> *FIRST = _first;
		delete FIRST;
		FIRST = _first->_next;
		_first = FIRST;
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
	
	if (_size)
	{
		list<T> *Q = new list<T>;
		Q->_x = element;
		Q->_prev = _last;
		_last->_next = Q;
		_last = _last->_next;
	}
	else
	{
		list<T> *L = new list<T>;
		L->_x = element;
		_first = _last = L;
	}
	++_size;
}
template<typename T>
void queue<T>::pop()
{
	if (_size == 1)
	{
		delete _last;
		delete _first;
		_last = _first = nullptr;
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
template<typename T>
bool queue<T>::operator==(const queue<T> &other)
{
	if (_len != other._len)
		return false;
	list<T> *FIRST = _first;
	list<T> *OTHERFIRST = other._first;
	while (FIRST != _last)
	{
		if (FIRST->_x != OTHERFIRST->_x)
			return false;
		FIRST = _first->_next;
		OTHERFIRST = other._first->_next;
	}
	return true;
}
template<typename T>
bool queue<T>::operator!=(const queue<T> &other)
{
	return !((*this) == other);
}
template<typename T>
queue<T>& queue<T>::operator=(const queue<T>& other)
{
	_first = other._first;
	_last = other._last;
	_size = other._size;
	return *this;
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const queue<T>& _queue)
{
	list<T> *FIRST = _queue._first;
    list<T> *_FIRST = FIRST;
	while (FIRST != _queue._last)
	{
		os << FIRST->_x << std::endl;
		FIRST = _queue._first->_next;
		_queue._first = FIRST;
	}
	os << queue._last->_x << std::endl;
	_queue._first = _FIRST;
	return os;
}





#endif

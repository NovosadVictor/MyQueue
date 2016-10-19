#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_
#include <iostream>
#include "MyList.h"

template<typename T>
class queue
{
public:
	queue() : _first(NULL), _last(_first), _size(0) {}
	queue(const queue<T> &other);
	~queue();
	T& front();
	T& back();
	bool empty();
	size_t size();
	void clear();
	void push(const T& element);
	void pop();
	friend queue<T> operator+(const queue<T> &lhs, const queue<T> &rhs) {
		
        	queue<T> Q = lhs;
		list<T> *RFirst = rhs._first;
		while(RFirst != rhs._last)  {
                        Q.push(RFirst->_x);
                        RFirst = RFirst->_next;
                }
		Q.push(rhs._last->_x);
        	return Q;
	}
	bool operator==(const queue<T>& other);
	bool operator!=(const queue<T>& other);
	queue<T>& operator=(const queue<T>& other);
	friend std::ostream& operator<<(std::ostream& os,const queue<T> &_queue){           
  		if (_queue._size > 0) {
			list<T> *_FIRST = _queue._first;
			list<T> *FIRST = _queue._first;
        		while (_FIRST != 0) {
                		os << _FIRST->_x << std::endl;
               			_FIRST = _FIRST->_next;
       			}
		}
		else
			throw 3;
        	return os;	
	}
	void QueueSort();
		
private:
	list<T> *_first;
	list<T> *_last;
	size_t _size;
};

template<typename T>
queue<T>::queue(const queue<T> &other) {
  	if (other._size > 0) {
		list<T> *L = new list<T>;
        	L->_x = other._first->_x;
        	_first = _last = L;
        	L = NULL;
		++_size;
        	delete L;
		if (other._size > 1) {
			list<T> *FIRST = other._first->_next;
			while (FIRST != 0) {
                		list<T> *Q = new list<T>;
               			Q->_x = FIRST->_x;
               			_last->_next = Q;
                		_last = Q;
               			Q = NULL;
                		delete Q;
				++_size;
				FIRST = FIRST->_next;
			}
		}
	}
}
/*list<T> *FIRST = other._first;
        while (FIRST != 0){
                (*this).push(FIRST->_x);
                FIRST = FIRST->_next;
        }*/

template<typename T>
queue<T>::~queue() {
	for(list<T> *cur = _first; cur != NULL; cur = cur->_next)
		delete cur;
}
template<typename T>
T& queue<T>::front()
{
	if (_size != 0)
		return _first->_x;
	throw std::bad_alloc();
}
template<typename T>
void queue<T>::clear() {
	if (_size > 0){
		for(list<T> *cur = _first; cur != NULL; cur = cur->_next)
        	        delete cur;
	_size = 0;
	_first = NULL;
	_last = _first;
	}
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
	
	if (_size > 0)
	{
		list<T> *Q = new list<T>;
		Q->_x = element;
		_last->_next = Q;
		_last = Q;
		Q = NULL;
		delete Q;
	}
	else
	{
		list<T> *L = new list<T>;
		L->_x = element;
		_first = _last = L;
		L = NULL;
		delete L;
	}
	++_size;
}
template<typename T>
void queue<T>::pop()
{
	if (_size == 1)
	{
		delete _last;
		_last = _first = 0;
	}
	if (_size > 1)
	{
     		list<T> *FIRST = _first;
		delete FIRST;
		_first = _first->_next;
	}
	if (_size <= 0)
		throw std::bad_alloc();
	else
		--_size;
}
template<typename T>
bool queue<T>::operator==(const queue<T> &other)
{
	if (_size != other._size)
		return false;
	list<T> *FIRST = _first;
	list<T> *OTHERFIRST = other._first;
	while (FIRST != _last)
	{	
		if (FIRST->_x != OTHERFIRST->_x)
			return false;
		FIRST = FIRST->_next;
		OTHERFIRST = OTHERFIRST->_next;
	}
	if (_last->_x != other._last->_x)
		return false;
	return true;
}
template<typename T>
bool queue<T>::operator!=(const queue<T> &other)
{
	return !((*this) == other);
}
template<typename T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
	list<T> *FIRST = other._first;
	(*this).clear();
	while (FIRST != 0){
		(*this).push(FIRST->_x);
		FIRST = FIRST->_next;
	}
	return *this;
}
template<typename T>
void queue<T>::QueueSort() {
	list<T> *FIRST = _first;
	while (_first != 0) {
		T min = _first->_x;
		list<T> *Qmin = _first;
		list<T> *_FIRST = _first;
		while (_FIRST != 0) {
			if (_FIRST->_x < min) {
				min = _FIRST->_x;
				Qmin = _FIRST;
			}
			_FIRST = _FIRST->_next;
		}
		T tmp = _first->_x;
		_first->_x = min;
		Qmin->_x = tmp;
		_first = _first->_next;
	}
	_first = FIRST;
}
	/*for(list<T> *cur1 = _first; cur1 != 0; cur1 = cur1->_next) {
		T min = cur1->_x;
		list<T> *Qmin = cur1;	
		for(list<T> *cur2 = _first; cur2 != 0; cur2 = cur2->_next) 
			if (cur2->_x < min) {
				min = cur2->_x;
				Qmin = cur2;
			}
		T tmp = cur1->_x;
		std::cout << tmp << std::endl;
		cur1->_x = min;
		std::cout << cur1->_x << std::endl;
		Qmin->_x = tmp;
		std::cout << Qmin->_x << std::endl;
	}*/
/*queue<T>& operator+(const queue<T> &lhs, const queue<T> &rhs)
{
	_first = lhs._first;
	_last = lhs._last;
	_last->_next = rhs._first;
	_last = rhs._last;
	_size = lhs._size + rhs._size;
	return *this;
}*/
/*template<typename T>
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
	os << _queue._last->_x << std::endl;
	_queue._first = _FIRST;
	return os;
}*/





#endif

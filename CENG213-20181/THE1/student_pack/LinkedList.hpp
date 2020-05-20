#ifndef LINKEDLIST_HPP
#define	LINKEDLIST_HPP

#include <iostream>
#include "Node.hpp"

using namespace std;

/*....DO NOT EDIT BELOW....*/
template <class T>
class LinkedList {
private:
    Node<T>* head; 
    int length;  
public:

    LinkedList();
    LinkedList(const LinkedList<T>& ll);
    LinkedList<T>& operator=(const LinkedList<T>& ll);
    ~LinkedList();


    Node<T>* getHead() const;
    Node<T>* first() const;
    Node<T>* findPrev(const T& data) const;
    Node<T>* findNode(const T& data) const;
    void insertNode(Node<T>* prev, const T& data); 
    void deleteNode(Node<T>* prevNode);
    void clear();
    size_t getLength() const;
    void print() const;
    void swap(int index1, int index2);
};

template <class T>
void LinkedList<T>::print() const {
    const Node<T>* node = first();
    while (node) {
        std::cout << node->getData();
        node = node->getNext();
    }
    cout << std::endl;
}

/*....DO NOT EDIT ABOVE....*/

/* TO-DO: method implementations below */

template<class T>
LinkedList<T>::LinkedList()
	{
		length = 0;
		head = new Node<T>();
	}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll)
	{
		head = new Node<T>();
		Node<T> *bas1=head, *bas2=ll.getHead();
		while(bas2->getNext() != NULL)
			{
				insertNode(bas1,bas2->getNext()->getData());
				bas1 = bas1->getNext();
				bas2 = bas2->getNext();
			}
	}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll)
	{
		head = new Node<T>();
		Node<T> *bas1=head, *bas2=ll.getHead();
		while(bas2->getNext() != NULL)
			{
				insertNode(bas1,bas2->getNext()->getData());
				bas1 = bas1->getNext();
				bas2 = bas2->getNext();
			}
	}

template<class T>
LinkedList<T>::~LinkedList()
	{
		clear();
		delete head;
	}

template<class T>
Node<T>* LinkedList<T>::getHead() const
	{
		return head;
	}

template<class T>
Node<T>* LinkedList<T>::first() const
	{
		return head->getNext();
	}

template<class T>
Node<T>* LinkedList<T>::findPrev(const T& data) const
	{
		//cout<<"findprev"<<endl;
		Node<T> *p = head;
		while(p->getNext() != NULL)
			{
				if(p->getNext()->getData() == data)
					return p;
				p = p->getNext();
			}
		return NULL;
	}

template<class T>
Node<T>* LinkedList<T>::findNode(const T& data) const
	{
		Node<T> *p = first();
		while(p != NULL)
			{
				if(p->getData() == data)
					return p;
				p = p->getNext();
			}
		return NULL;
	}

template<class T>
void LinkedList<T>::insertNode(Node<T>* prev, const T& data)
	{
		if(prev == NULL)
			return;
		Node<T> *tmp = prev->getNext();
		prev->setNext(new Node<T>(data));
		prev->getNext()->setNext(tmp);
	}

template<class T>
void LinkedList<T>::deleteNode(Node<T>* prevNode)
	{
		//cout<<"Node siliniyor"<<endl;
		if(prevNode == NULL)
			return;
		if(prevNode->getNext() == NULL)
			return;
		Node<T> *tmp = prevNode->getNext()->getNext();
		delete prevNode->getNext();
		prevNode->setNext(tmp);
	}

template<class T>
void LinkedList<T>::clear()
	{
		Node<T> *p = first();
		while(p != NULL)
			{
				Node<T> *tmp = p->getNext();
				delete p;
				p = tmp;
			}
	}

template<class T>
size_t LinkedList<T>::getLength() const
	{
		size_t t = 0;
		for(Node<T> *p = first(); p!=NULL; p = p->getNext(), t++);
		return t;
	}

template<class T>
void LinkedList<T>::swap(int index1, int index2)
	{
		Node<T> *p1=first(), *p2=first(), *p1b = head, *p2b = head;
		for(int i = 0; i<index1; i++)
			{
				if(p1 == NULL)
					return;
				p1 = p1->getNext();
				p1b = p1b->getNext();
			}
		for(int i = 0; i<index2; i++)
			{
				if(p2 == NULL)
					return;
				p2 = p2->getNext();
				p2b = p2b->getNext();
			}
		if(p1 == NULL or p2 == NULL)
			return;
		
		p1b->setNext(p2);
		p2b->setNext(p1);
		
		Node<T> *tmp = p1->getNext();
		p1->setNext(p2->getNext());
		p2->setNext(tmp);
		
	}
/* end of your implementations*/
#endif	


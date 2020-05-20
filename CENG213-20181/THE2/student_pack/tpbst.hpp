#ifndef TWOPHASEBST_H
#define TWOPHASEBST_H

#include <iostream>
#include <string>
#include <stack>
#include <list>
// do not add any other library.
// modify parts as directed by assignment text and comments here.

template <class T>
class TwoPhaseBST {
private: //do not change
    struct SecondaryNode {
        std::string key;
        T data;
        SecondaryNode *left;
        SecondaryNode *right;

        SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r);
    };

    struct PrimaryNode {
        std::string key;
        PrimaryNode *left;
        PrimaryNode *right;
        SecondaryNode *rootSecondaryNode;

        PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn);
    };

public: // do not change.
    TwoPhaseBST();
    ~TwoPhaseBST();

    TwoPhaseBST &insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data);
    TwoPhaseBST &remove(const std::string &primaryKey, const std::string &secondaryKey);
    TwoPhaseBST &print(const std::string &primaryKey = "", const std::string &secondaryKey = "");
    T *find(const std::string &primaryKey, const std::string &secondaryKey);

private: // you may add your own utility member functions here.
    void destructNode(PrimaryNode * &root);
    void destructNode(SecondaryNode * &root);
    void insert(PrimaryNode *&cur, const std::string pKey, const std::string sKey, const T &data);
    void insert(SecondaryNode *&cur, const std::string sKey, const T &data);
    void printAll();
    void printPrim(PrimaryNode *cur);
    void printSec(SecondaryNode *cur);
    void traversePrim(PrimaryNode *cur, std::stack<PrimaryNode*> &s);
    void traverseSec(SecondaryNode *cur, std::stack<SecondaryNode*> &s);
	void findAndPrintPrim(const std::string &primaryKey);
	void findAndPrintSec(const std::string &primaryKey, const std::string &secondaryKey);
	void remove(PrimaryNode* prim, SecondaryNode *cur, SecondaryNode *p);

private: // do not change.
    PrimaryNode *root; //designated root.

    // do not provide an implementation. TwoPhaseBST's are not copiable.
    TwoPhaseBST(const TwoPhaseBST &);
    const TwoPhaseBST &operator=(const TwoPhaseBST &);
};

template <class T>
TwoPhaseBST<T>::SecondaryNode::SecondaryNode(const std::string &k, const T &d, SecondaryNode *l, SecondaryNode *r)
        : key(k), data(d), left(l), right(r) {}

template <class T>
TwoPhaseBST<T>::PrimaryNode::PrimaryNode(const std::string &k, PrimaryNode *l, PrimaryNode *r, SecondaryNode *rsn)
        : key(k), left(l), right(r), rootSecondaryNode(rsn) {}

template <class T>
TwoPhaseBST<T>::TwoPhaseBST() : root(NULL) {}

template <class T>
TwoPhaseBST<T>::~TwoPhaseBST() {
    destructNode(root);
}

template <class T>
void TwoPhaseBST<T>::insert(PrimaryNode *&cur, const std::string pKey, const std::string sKey, const T &data) {
    if(cur == NULL)
    	{
    		cur = new PrimaryNode(pKey,NULL,NULL,new SecondaryNode(sKey,data,NULL,NULL));
			return;
		}
	else
		{
			//std::cout<<cur->key<<std::endl;
		}
	if(cur->key == pKey)
		{
			insert(cur->rootSecondaryNode, sKey, data);
			return;
		}
	if(pKey < cur->key)
		{
			insert(cur->left, pKey, sKey, data);
			return;
		}
	insert(cur->right, pKey, sKey, data);
	return;
}

template <class T>
void TwoPhaseBST<T>::insert(SecondaryNode *&cur, const std::string sKey, const T &data) {
	if(cur == NULL)
    	{
    		cur = new SecondaryNode(sKey, data, NULL, NULL);
    		return;
		}
	if(cur->key == sKey)
		{
			return;
		}
	if(sKey < cur->key)
		{
			insert(cur->left, sKey, data);
			return;
		}
	//std::cout<<"Saga bak\n";
	insert(cur->right, sKey, data);
	return;
}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::insert(const std::string &primaryKey, const std::string &secondaryKey, const T &data) {
    //return *this;
    //std::cout<<"Insert "<<primaryKey<<" "<<secondaryKey<<std::endl;
	insert(root,primaryKey,secondaryKey,data);
    return *this;
}

template<class T>
void TwoPhaseBST<T>::remove(PrimaryNode *prim, SecondaryNode *cur, SecondaryNode *p)
	{
		if(cur == NULL)
			return;
		if(cur == prim->rootSecondaryNode and cur->right == NULL and cur->left == NULL)
			{
				delete cur;
				prim->rootSecondaryNode = NULL;
				return;
			}
		//std::cout<<"Siliniyor "<<cur->key<<std::endl;
		if(cur->left == NULL and cur->right == NULL)
			{
				bool yon = false;
				if(p != NULL)
					{
						if(p->right == cur)
							yon = true;
					}
				delete cur;
				cur = NULL;
				if(p != NULL)
					{
		//				std::cout<<"Yon "<<yon<<std::endl;
						if(yon)
							p->right = NULL;
						else
							p->left = NULL;
					}
				return;
			}
		SecondaryNode *tmp, *prev = cur;
		if(cur->left != NULL)
			{
				tmp = cur->left;
				while(tmp->right != NULL)
					{
						prev = tmp;
						tmp = tmp->right;
					}
				if(prev != cur)
					prev->right = NULL;
				else
					prev->left = tmp->left;
			}
		else
			{
				tmp = cur->right;
				while(tmp->left != NULL)
					{
						prev = tmp;
						tmp = tmp->left;
					}
				if(prev != cur)
					prev->left = NULL;
				else
					prev->right = tmp->right;
			}
		if(p != NULL and p->right == cur)
			{
				p->right = tmp;
				//std::cout<<"sag\n";
			}
		else if(p != NULL and p->left == cur)
			{
				p->left = tmp;
				//std::cout<<"sol ";
			}
		tmp->left = cur->left;
		tmp->right = cur->right;
		//delete cur;
		//std::cout<<tmp->key<<std::endl;
		if(cur == prim->rootSecondaryNode)
			prim->rootSecondaryNode = tmp;
		delete cur;
		return;
	}

template <class T>
TwoPhaseBST<T> &
TwoPhaseBST<T>::remove(const std::string &primaryKey, const std::string &secondaryKey) {
		//return *this;
    	//std::cout<<"Remove "<<primaryKey<<" "<<secondaryKey<<std::endl;
    	PrimaryNode *cur = root;
		while(cur != NULL and cur->key != primaryKey)
			{
				cur = ((primaryKey < cur->key) ? cur->left : cur->right);
			}
		if(cur == NULL)
			{
				return *this;
			}
		SecondaryNode *curSec = cur->rootSecondaryNode, *p = NULL;
		while(curSec != NULL and curSec->key != secondaryKey)
			{
				p = curSec;
				curSec = ((secondaryKey < curSec->key) ? curSec->left : curSec->right);
			}
		if(curSec == NULL)
			{
				return *this;
			}
		remove(cur, curSec, p);
		return *this;
}

template<class T>
void TwoPhaseBST<T>::traversePrim(PrimaryNode *cur, std::stack<PrimaryNode*> &s)
	{
		if(cur == NULL)
			{
				return;
			}	
		traversePrim(cur->right, s);
		s.push(cur);
		traversePrim(cur->left, s);
		return;	
	}
template<class T>
void TwoPhaseBST<T>::traverseSec(SecondaryNode *cur, std::stack<SecondaryNode*> &s)
	{
		if(cur == NULL)
			{
				return;
			}	
		traverseSec(cur->right, s);
		s.push(cur);
		traverseSec(cur->left, s);
		return;	
	}

template<class T>
void TwoPhaseBST<T>::printAll()
	{
		std::cout<<"{";
		std::stack<PrimaryNode*> s;
		traversePrim(root, s);
		while(!s.empty())
			{
				printPrim(s.top());
				s.pop();
				if(!s.empty())
					std::cout<<", ";
			}
		std::cout<<"}";
		return;
	}
template<class T>
void TwoPhaseBST<T>::printPrim(PrimaryNode *cur)
	{
		if(cur == NULL)
			{
				return;
			}
		std::cout<<"\""<<(cur->key)<<"\" : {";
		
		std::stack<SecondaryNode*> s;
		traverseSec(cur->rootSecondaryNode, s);
		while(!s.empty())
			{
				printSec(s.top());
				s.pop();
				if(!s.empty())
					std::cout<<", ";
			}
		
		std::cout<<"}";
	}
template<class T>
void TwoPhaseBST<T>::printSec(SecondaryNode *cur)
	{
		if(cur == NULL)
			return;
		std::cout<<"\""<<(cur->key)<<"\" : \""<<(cur->data)<<"\"";
	}

template<class T>
void TwoPhaseBST<T>::findAndPrintPrim(const std::string &primaryKey)
	{
		std::cout<<"{";
		PrimaryNode *cur = root;
		while(cur != NULL and cur->key != primaryKey)
			{
				cur = ((primaryKey < cur->key) ? cur->left : cur->right);
			}
		printPrim(cur);
		std::cout<<"}";
	}
template<class T>
void TwoPhaseBST<T>::findAndPrintSec(const std::string &primaryKey, const std::string &secondaryKey)
	{
		PrimaryNode *cur = root;
		while(cur != NULL and cur->key != primaryKey)
			{
				cur = ((primaryKey < cur->key) ? cur->left : cur->right);
			}
		if(cur == NULL)
			{
				std::cout<<"{}";
				return;
			}
		SecondaryNode *curSec = cur->rootSecondaryNode;
		while(curSec != NULL and curSec->key != secondaryKey)
			{
				curSec = ((secondaryKey < curSec->key) ? curSec->left : curSec->right);
			}
		if(curSec == NULL)
			{
				std::cout<<"{}";
				return;
			}
		std::cout<<"{\""<<(cur->key)<<"\" : {";
		printSec(curSec);
		std::cout<<"}}";
		return;
	}

template <class T>
TwoPhaseBST<T> &TwoPhaseBST<T>::print(const std::string &primaryKey, const std::string &secondaryKey) {
    //std::cout<<"Print "<<primaryKey<<" "<<secondaryKey<<std::endl;
	if(primaryKey == "" and secondaryKey == "")
    	{
    		printAll();
    		std::cout<<std::endl;
    		return *this;
		}
	if(primaryKey == "")
		return *this;
	if(secondaryKey == "")
		{
			findAndPrintPrim(primaryKey);
    		std::cout<<std::endl;
			return *this;
		}
	findAndPrintSec(primaryKey, secondaryKey);
    std::cout<<std::endl;
	return *this;
}

template <class T>
T *TwoPhaseBST<T>::find(const std::string &primaryKey, const std::string &secondaryKey) {
		//return &root->rootSecondaryNode->data;
    	PrimaryNode *cur = root;
		while(cur != NULL and cur->key != primaryKey)
			{
				cur = ((primaryKey < cur->key) ? cur->left : cur->right);
			}
		if(cur == NULL)
			{
				return NULL;
			}
		SecondaryNode *curSec = cur->rootSecondaryNode;
		while(curSec != NULL and curSec->key != secondaryKey)
			{
				curSec = ((secondaryKey < curSec->key) ? curSec->left : curSec->right);
			}
		if(curSec == NULL)
			{
				return NULL;
			}
		return &curSec->data;
}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::PrimaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    destructNode(root->rootSecondaryNode);

    delete root;

    root = NULL;
}

template <class T>
void TwoPhaseBST<T>::destructNode(TwoPhaseBST::SecondaryNode * &root)
{
    if (root == NULL)
        return;

    destructNode(root->left);
    destructNode(root->right);

    delete root;

    root = NULL;
}

#endif //TWOPHASEBST_H

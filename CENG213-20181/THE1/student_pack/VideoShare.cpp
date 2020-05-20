#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VideoShare.hpp"
#include "User.hpp"

using namespace std;

void VideoShare::printAllVideos() {
    videos.print();
}

void VideoShare::printAllUsers() {
    users.print();
}

/* TO-DO: method implementations below */

VideoShare::VideoShare()
	{
		users = LinkedList<User>();
		videos = LinkedList<Video>();
	}

VideoShare::~VideoShare()
	{
		
	}

void VideoShare::createUser(const string & userName, const string & name, const string & surname)
	{
		users.insertNode(users.getHead(), User(userName, name, surname));
	}
	
void VideoShare::loadUsers(const string & fileName)
	{
		ifstream f;
		f.open(fileName.c_str());
		string tmp;
		while(f.good())
			{
				getline(f,tmp);
				int i1 = tmp.find_first_of(';'), i2 = tmp.find_last_of(';');
				string username = tmp.substr(0,i1);
				if(username == "")
					continue;
				string name = tmp.substr(i1+1,i2-i1-1);
				string surname = i2 == tmp.length()-1 ? "" : tmp.substr(i2+1);
				users.insertNode(users.getHead(), User(username,name,surname));
			}
		f.close();
	}

void VideoShare::createVideo(const string & title, const string & genre)
	{
		videos.insertNode(videos.getHead(), Video(title,genre));
	}
	
void VideoShare::loadVideos(const string & fileName)
	{
		ifstream f;
		f.open(fileName.c_str());
		string tmp;
		while(f.good())
			{
				getline(f,tmp);
				int i = tmp.find_first_of(';');
				string name = tmp.substr(0,i);
				if(name == "")
					continue;
				string genre = i == tmp.length()-1 ? "" : tmp.substr(i+1);
				videos.insertNode(videos.getHead(), Video(name, genre));
			}
		f.close();
	}

void VideoShare::addFriendship(const string & userName1, const string & userName2)
	{
		User s1 = User(userName1), s2 = User(userName2);
		if(users.findNode(s1) == NULL or users.findNode(s2) == NULL)
			return;
		User *p1 = users.findNode(s1)->getDataPtr(), *p2 = users.findNode(s2)->getDataPtr();
		p1->addFriend(p2);
		p2->addFriend(p1);
	}


void VideoShare::removeFriendship(const string & userName1, const string & userName2)
	{
		User s1 = User(userName1), s2 = User(userName2);
		if(users.findNode(s1) == NULL or users.findNode(s2) == NULL)
			return;
		User *p1 = users.findNode(s1)->getDataPtr(), *p2 = users.findNode(s2)->getDataPtr();
		//p2->printFriends();
		p1->removeFriend(p2);
		p2->removeFriend(p1);
	}

void VideoShare::updateUserStatus(const string & userName, Status newStatus)
	{
		if(users.findNode(User(userName)) == NULL)
			return;
		User *p = users.findNode(User(userName))->getDataPtr();
		p->updateStatus(newStatus);
	}

void VideoShare::subscribe(const string & userName, const string & videoTitle)
	{
		if(users.findNode(User(userName)) == NULL or videos.findNode(Video(videoTitle)) == NULL)
			return;
		User *u = users.findNode(User(userName))->getDataPtr();
		Video *v = videos.findNode(Video(videoTitle))->getDataPtr();
		if(u->getStatus() == SUSPENDED)
			return;
		u->subscribe(v);
	}

void VideoShare::unSubscribe(const string & userName, const string & videoTitle)
	{
		if(users.findNode(User(userName)) == NULL or videos.findNode(Video(videoTitle)) == NULL)
			return;
		User *u = users.findNode(User(userName))->getDataPtr();
		Video *v = videos.findNode(Video(videoTitle))->getDataPtr();
		if(u->getStatus() == SUSPENDED)
			return;
		u->unSubscribe(v);
	}

void VideoShare::deleteUser(const string & userName)
	{
		Node<User> *p = users.findNode(User(userName));
		if(p == NULL)
			return;
		LinkedList<User*> *l = p->getDataPtr()->getFriends();
		while(l->getLength() > 0)
			{
				removeFriendship(userName, l->first()->getData()->getUsername());
			}
		users.deleteNode(users.findPrev(User(userName)));
	}

void VideoShare::sortUserSubscriptions(const string & userName)
	{
		if(users.findNode(User(userName)) == NULL)
			return;
		User *u = users.findNode(User(userName))->getDataPtr();
		LinkedList<Video*> *l = u->getSubscriptions();
		if(l->getLength() < 1)
			return;
		bool sorted = false;
		while(!sorted)
			{
				sorted = true;
				Node<Video*> *p = l->first();
				int i = 0;
				while(p->getNext() != NULL)
					{
						if(p->getData()->getTitle() > p->getNext()->getData()->getTitle())
							{
								sorted = false;
								l->swap(i,i+1);
								p = l->getHead();
								for(int j = 0; j<i; j++)
									p = p->getNext();
							}
						p = p->getNext();
						i++;
					}
			}
	}

void VideoShare::printUserSubscriptions(const string & userName)
	{
		if(users.findNode(User(userName)) == NULL)
			return;
		users.findNode(User(userName))->getData().printSubscriptions();
	}


void VideoShare::printFriendsOfUser(const string & userName)
	{
		if(users.findNode(User(userName)) == NULL)
			return;
		users.findNode(User(userName))->getData().printFriends();
	}


void VideoShare::printCommonSubscriptions(const string & userName1, const string & userName2)
	{
		User s1 = User(userName1), s2 = User(userName2);
		if(users.findNode(s1) == NULL or users.findNode(s2) == NULL)
			return;
		User *p1 = users.findNode(s1)->getDataPtr(), *p2 = users.findNode(s2)->getDataPtr();
		LinkedList<Video*> *l1 = p1->getSubscriptions(), *l2 = p2->getSubscriptions();
		Node<Video*> *v = l1->first();
		LinkedList<string> tbp;
		while(v != NULL)
			{
				if(l2->findNode(v->getData()) != NULL)
					{
						string toBeInserted = v->getData()->getTitle();
						Node<string> *prev = tbp.getHead();
						while(prev->getNext() != NULL and prev->getNext()->getData() < toBeInserted)
							prev = prev->getNext();
						tbp.insertNode(prev,toBeInserted);
					}
				v = v->getNext();
			}
		Node<string> *tmp = tbp.first();
		while(tmp != NULL)
			{
				cout<<videos.findNode(Video(tmp->getData()))->getData();
				tmp = tmp->getNext();
			}
		cout<<endl;
	}

void VideoShare::printFriendSubscriptions(const string & userName)
	{
		User s1 = User(userName);
		if(users.findNode(s1) == NULL)
			return;
		User *p = users.findNode(s1)->getDataPtr();
		LinkedList<User*> *fr = p->getFriends();
		Node<User*> *p1 = fr->first();
		LinkedList<string> tbp;
		while(p1 != NULL)
			{
				LinkedList<Video*> *l = p1->getData()->getSubscriptions();
				Node<Video*> *v = l->first();
				while(v != NULL)
					{
						string toBeInserted = v->getData()->getTitle();
						if(tbp.findNode(toBeInserted) == NULL)
							{
								Node<string> *prev = tbp.getHead();
								while(prev->getNext() != NULL and prev->getNext()->getData() < toBeInserted)
									prev = prev->getNext();
								tbp.insertNode(prev,toBeInserted);
							}
						v = v->getNext();
					}
				p1 = p1->getNext();
			}
		Node<string> *tmp = tbp.first();
		while(tmp != NULL)
			{
				cout<<videos.findNode(Video(tmp->getData()))->getData();
				tmp = tmp->getNext();
			}
		cout<<endl;
	}

bool VideoShare::isConnected(const string & userName1, const string & userName2)
	{
		User s1 = User(userName1), s2 = User(userName2);
		if(users.findNode(s1) == NULL or users.findNode(s2) == NULL)
			return false;
		User *p1 = users.findNode(s1)->getDataPtr(), *p2 = users.findNode(s2)->getDataPtr();
		LinkedList<User*> Q, V;
		Q.insertNode(Q.getHead(), p1);
		V.insertNode(V.getHead(), p1);
		User *p = Q.first()->getData();
		Q.deleteNode(Q.getHead());
		while(p != NULL)
			{
				Node<User*> *i = p->getFriends()->first();
				while(i != NULL)
					{
						if(i->getData() == p2)
							return true;
						if(V.findNode(i->getData()) == NULL)
							{
								V.insertNode(V.getHead(), i->getData());
								Q.insertNode(Q.getHead(), i->getData());
							}
						i = i->getNext();
					}
				
				p = Q.first()->getData();
				Q.deleteNode(Q.getHead());
			}
	}


#include <iostream>
#include "User.hpp"
#include "Video.hpp"

void User::printSubscriptions() {
    Node< Video*> * first = subscriptions.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

void User::printFriends() {
    Node< User*> * first = friends.first();
    while (first) {
        cout << *(first->getData());
        first = first->getNext();
    }
    cout << std::endl;
}

ostream& operator<<(ostream& out, const User & user) {
    string st = (user.status == ACTIVE) ? "active" : "suspended";
    out << "username:" << user.username << ",name:" << user.name << ",surname:" << user.surname << ",Status:" << st << endl;
    return out;
}

/* TO-DO: method implementations below */

User::User()
	{
		username = "";
		name = "";
		surname = "";
		status = ACTIVE;
		subscriptions = LinkedList<Video*>();
		friends = LinkedList<User*>();
	}
User::User(string n_username, string n_name, string n_surname)
	{
		username = n_username;
		name = n_name;
		surname = n_surname;
		status = ACTIVE;
		subscriptions = LinkedList<Video*>();
		friends = LinkedList<User*>();
	}

User::~User()
	{
		
	}

const string& User::getUsername() const
	{
		return username;
	}
const string& User::getName() const
	{
		return name;
	}
const string& User::getSurname() const
	{
		return surname;
	}

Status User::getStatus() const
	{
		return status;
	}

void User::updateStatus(Status st)
	{
		status = st;
	}

void User::subscribe(Video * video)
	{
		subscriptions.insertNode(subscriptions.getHead(), video);
	}
void User::unSubscribe(Video * video)
	{
		subscriptions.deleteNode(subscriptions.findPrev(video));
	}


void User::addFriend(User * user)
	{
		friends.insertNode(friends.getHead(), user);
	}

void User::removeFriend(User * user)
	{
		Node<User*> *p = friends.findPrev(user);
		friends.deleteNode(p);
	}

LinkedList<Video* >* User::getSubscriptions()
	{
		return &subscriptions;
	}
LinkedList<User* >* User::getFriends()
	{
		return &friends;
	}

bool User::operator==(const User& rhs) const
	{
		return username == rhs.getUsername();
	}

/*

class User {
private:
    string username;
    string name;
    string surname;
    Status status;
    LinkedList< Video* > subscriptions;
    LinkedList< User* > friends;

public:
    User();
    User(string username, string name = "", string surname = "");
    ~User();
    const string& getUsername() const;
    const string& getName() const;
    const string& getSurname() const;
    Status getStatus() const;
    void updateStatus(Status st);
    void subscribe(Video * video);
    void unSubscribe(Video * video);
    void addFriend(User * user);
    void removeFriend(User * user);
    LinkedList<Video* > *getSubscriptions();
    LinkedList< User* > *getFriends();
    void printSubscriptions();
    void printFriends();
    bool operator==(const User& rhs) const;
    friend ostream& operator<<(ostream& out, const User & user);
};

*/

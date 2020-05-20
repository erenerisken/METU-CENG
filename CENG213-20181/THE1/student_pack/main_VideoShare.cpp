#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "VideoShare.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    VideoShare vs1 = VideoShare();
    vs1.loadUsers("listUser10.txt");
    vs1.loadVideos("listVideo10.txt");

    cout << " All Users" << endl;
    vs1.printAllUsers();
    cout << " All Videos" << endl;
    vs1.printAllVideos();

    //add friendship
    cout<<"Add Friendship"<<endl;
    vs1.addFriendship("userName284", "userName341");
    vs1.addFriendship("userName284", "userName392");
    vs1.addFriendship("userName284", "userName265");
    vs1.addFriendship("userName284", "userName163");

    cout << "Friends  of userName284" << endl;
    vs1.printFriendsOfUser("userName284");

    cout << "Friends  of userName341" << endl;
    vs1.printFriendsOfUser("userName341");

    //remove friendship
    cout<<"Remove Friendship"<<endl;
    vs1.removeFriendship("userName284", "userName341");
    cout << "Friends  of userName284" << endl;
    vs1.printFriendsOfUser("userName284");

    cout << "Friends  of userName341" << endl;
    vs1.printFriendsOfUser("userName341");

    cout<<"Add Subscription"<<endl;
    vs1.subscribe("userName056", "title384");
    vs1.subscribe("userName056", "title061");
    vs1.subscribe("userName056", "title135");


    vs1.subscribe("userName341", "title061");
    vs1.subscribe("userName341", "title051");
    vs1.subscribe("userName341", "title384");

    cout << "Subscriptions of userName056" << endl;
    vs1.printUserSubscriptions("userName056");

    cout << "Subscriptions of userName341" << endl;
    vs1.printUserSubscriptions("userName341");
    
    cout<<"sortUserSubscriptions"<<endl;
    vs1.sortUserSubscriptions("userName056");

     cout << "Subscriptions of userName056" << endl;
    vs1.printUserSubscriptions("userName056");

    cout << "Subscriptions of userName341" << endl;
    vs1.printUserSubscriptions("userName341");
    
    cout<<"printCommonSubscriptions"<<endl;
    vs1.sortUserSubscriptions("userName056");
    vs1.sortUserSubscriptions("userName341");
    vs1.printCommonSubscriptions("userName341","userName056");
    cout<<"----------------------------------------------"<<endl;
    vs1.addFriendship("userName341", "userName056");
    vs1.createUser("eren");
    vs1.subscribe("eren","title051");
    vs1.subscribe("eren","title061");
    vs1.addFriendship("eren","userName341");
	vs1.printFriendSubscriptions("userName341");
    //vs1.addFriendship("userName341", "userName056");
    //vs1.printFriendsOfUser("userName056");
    //vs1.deleteUser("userName341");
    //vs1.printFriendsOfUser("userName056");
    vs1.printAllUsers();
    vs1.printFriendsOfUser("userName056");
    vs1.addFriendship("userName056", "userName127");
    cout<<vs1.isConnected("eren","userName127");
    return 0;
}

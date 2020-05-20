#ifndef _HW3_H
#define _HW3_H
#include <iostream>
#include <string>
#include <vector>
#include <utility>  // use just for std::pair< >
#include <fstream>

#define MAX_LOAD_FACTOR 0.65
#define EMPTY "EMPTY"
#define DELETED "DELETED"

template<class T>
class HashTable
	{
		private:
			std::vector<std::pair<std::string, T> > arr;
			int tableSize;
			int insertedCount;
			float loadFactor;
			T defData;
			T deletedData;
		public:
			void initialize(int size, const T &def, const T &del);
			HashTable();
			~HashTable();
			int findIndexOf(std::string key);
			int findLastQuery(std::string key);
			T* getDataPtr(int ind);
			T* insert(std::string key, const T &data);
			void remove(std::string key);
			void findAllOf(std::string key, std::vector<T> &datas);
			float print();
		private:
			void expand();
			int getPrime(int lim);
			int hashFunction(std::string key, int tableSize, int ind); 
	};

class AccessControl
	{
		public:
			AccessControl(int table1Size, int table2Size);
			~AccessControl();
		
			int addUser(std::string username, std::string pass);
			int addUsers(std::string filePath);
			int delUser(std::string username, std::vector<std::string>& oldPasswords);
			int changePass(std::string username, std::string oldpass, std::string newpass);
		
			int login(std::string username, std::string pass);
			int logout(std::string username);
		
			float printActiveUsers();
			float printPasswords();
		private:
			//<<your hash class>> activeUsers;	// hash(username) -> username
			//<<your hash class>> regUsers;  		// hash(username) -> username,password
			HashTable<std::string> activeUsers;
			HashTable<std::pair<std::string,std::string> > regUsers;
		
		
	};

#endif

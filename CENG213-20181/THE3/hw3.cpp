#include "hw3.h"

std::ostream &operator<<(std::ostream &o, std::pair<std::string, std::string> p)
	{
		o<<p.first<<" "<<p.second;
		return o;
	}

//--------------------------------------------
//-------HASHTABLE IMPLEMENTATIONS------------
//--------------------------------------------

template<class T>
int HashTable<T>::hashFunction(std::string key, int tableSize, int ind)
	{
	   int length = key.length();
	   int newK = 0;
	   for (int i = 0; i < length; i++)
	     newK += (int) key[i];

		 // hash function 1 -> (newK % tableSize)
		 // hash function 2 -> (newK * tableSize - 1) % tableSize)

	   return ((newK % tableSize) + ind * ((newK * tableSize - 1) % tableSize)) % tableSize;
	}

template<class T>
float HashTable<T>::print()
	{
		for(typename std::vector<std::pair<std::string, T> >::iterator i = arr.begin(); i!=arr.end(); i++)
			std::cout<<i->second<<std::endl;
		if(tableSize == 0)
			return 0.0;
		return (float)insertedCount / (float)tableSize;
	}


template<class T>
void HashTable<T>::initialize(int size, const T &def, const T &del)
	{
		arr.resize(size);
		tableSize = size;
		loadFactor = 0;
		insertedCount = 0;
		for(int i = 0; i<size; i++)
			arr[i] = std::pair<std::string, T>("", def);
		defData = def;
		deletedData = del;
	}

template<class T>
HashTable<T>::HashTable()
	{
		
	}

template<class T>
HashTable<T>::~HashTable()
	{
		arr.clear();
	}

template<class T>
void HashTable<T>::expand()
	{
		int newSize = getPrime(tableSize);
		//std::cout<<"Expand ediliyor..."<<insertedCount<<"/"<<newSize<<std::endl;
		std::vector<std::pair<std::string, std::vector<T> > > v;
		for(int i = 0; i<tableSize; i++)
			{
				if(arr[i].second == deletedData or arr[i].second == defData)
					continue;
				std::pair<std::string, std::vector<T> > p = std::pair<std::string, std::vector<T> >(arr[i].first, std::vector<T>());
				findAllOf(p.first, p.second);
				v.push_back(p);
				//std::cout<<p.first<<" silinecek"<<std::endl;
				remove(p.first);
			}
		
		tableSize = newSize;
		insertedCount = 0;
		arr.resize(newSize);
		for(int i = 0; i<newSize; i++)
			arr[i] = std::pair<std::string, T>(EMPTY, defData);
		
		for(typename std::vector<std::pair<std::string, std::vector<T> > >::iterator i = v.begin(); i != v.end(); i++)
			{
				for(typename std::vector<T>::iterator j = i->second.begin(); j!=i->second.end(); j++)
					{
						insert(i->first, *j);
					}
			}
		return;
	}

template<class T>
T* HashTable<T>::insert(std::string key, const T &data)
	{
		//std::cout<<key<<" insert ediliyor\n";
		int bas = findLastQuery(key);
		for(int i = bas+1; i<tableSize; i++)
			{
				int ind = hashFunction(key, tableSize, i);
				if(ind > tableSize)
					return NULL;
				if(arr[ind].second != deletedData and arr[ind].second != defData)
					continue;
				//ayni kontrol!!
				arr[ind] = std::pair<std::string, T>(key, data);
				if((float)++insertedCount/(float)tableSize > MAX_LOAD_FACTOR)
					expand();
				return &arr[ind].second;
			}
		return NULL;
	}

template<class T>
T* HashTable<T>::getDataPtr(int ind)
	{
		return ind < tableSize and ind >= 0 ? &arr[ind].second : NULL;
	}

template<class T>
int HashTable<T>::findIndexOf(std::string key)
	{
		int last=-1;
		for(int i = 0; i<tableSize; i++)
			{
				int ind = hashFunction(key, tableSize, i);
				if(ind >= tableSize or arr[ind].second == defData)
					break;
				if(arr[ind].first != key)
					continue;
				last = ind;
			}
		return last;
	}

template<class T>
int HashTable<T>::findLastQuery(std::string key)
	{
		int last=-1;
		for(int i = 0; i<tableSize; i++)
			{
				int ind = hashFunction(key, tableSize, i);
				if(ind >= tableSize or arr[ind].second == defData)
					break;
				if(arr[ind].first != key)
					continue;
				last = i;
			}
		return last;
	}

template<class T>
void HashTable<T>::findAllOf(std::string key, std::vector<T> &datas)
	{
		datas.resize(0);
		for(int i = 0; i<tableSize; i++)
			{
				int ind = hashFunction(key, tableSize, i);
				if(ind >= tableSize or arr[ind].second == defData)
					break;
				if(arr[ind].first != key)
					continue;
				datas.push_back(arr[ind].second);
			}
	}

template<class T>
void HashTable<T>::remove(std::string key)
	{
		for(int i = 0; i<tableSize; i++)
			{
				int ind = hashFunction(key, tableSize, i);
				if(ind >= tableSize or arr[ind].second == defData)
					break;
				if(arr[ind].first != key)
					continue;
				arr[ind].first = DELETED;
				arr[ind].second = deletedData;
				insertedCount--;
			}
	}



template<class T>
int HashTable<T>::getPrime(int lim)
	{
		for(int i = 2*lim+1; i>0; i++)
			{
				bool flag = true;
				for(int j = 2; j*j<=i; j++)
					{
						if(i%j == 0)
							{
								flag = false;
								break;
							}
					}
				if(flag)
					return i;
			}
		return -1;
	}

//----------------------------------------
//----END OF HASHTABLE IMPLEMENTATIONS----
//----------------------------------------


//----------------------------------------
//------ACCESSCONTROL IMPLEMENTATIONS------
//----------------------------------------

AccessControl::AccessControl(int table1Size, int table2Size)
	{
		regUsers.initialize(table1Size, std::pair<std::string, std::string>(EMPTY,EMPTY), std::pair<std::string,std::string>(DELETED, DELETED));
		activeUsers.initialize(table2Size, EMPTY, DELETED);
	}

AccessControl::~AccessControl()
	{
		
	}

int AccessControl::addUser(std::string username, std::string pass)
	{
		return
		regUsers.findLastQuery(username) == -1
			and 
		regUsers.insert(username, std::pair<std::string, std::string>(username, pass)) != NULL;
	}

int AccessControl::addUsers(std::string filePath)
	{
		int count = 0;
		std::ifstream f;
		f.open(filePath.c_str());
		while(f.good())
			{
				std::string a,b;
				f>>a>>b;
				if(a == "" or b == "")
					continue;
				//std::cout<<a<<" "<<b<<std::endl;
				count += addUser(a,b);
			}
		f.close();
		return count;
	}


int AccessControl::delUser(std::string username, std::vector<std::string>& oldPasswords)
	{
		std::vector<std::pair<std::string, std::string> > userVars;
		regUsers.findAllOf(username, userVars);
		if(userVars.size()<=0)
			return 0;
		for(std::vector<std::pair<std::string, std::string> >::iterator i = userVars.begin(); i != userVars.end(); i++)
			oldPasswords.push_back(i->second);
		userVars.clear();
		regUsers.remove(username);
		return 1;
	}

int AccessControl::changePass(std::string username, std::string oldpass, std::string newpass)
	{
		int lastIndex = regUsers.findIndexOf(username);
		if(lastIndex == -1 or regUsers.getDataPtr(lastIndex)->second != oldpass)
			return 0;
		return regUsers.insert(username, std::pair<std::string, std::string>(username, newpass)) != NULL;
	}

int AccessControl::login(std::string username, std::string pass)
	{
		int ind = regUsers.findIndexOf(username);
		if(activeUsers.findIndexOf(username) >= 0)
			{
				//std::cout<<"Already logged in"<<std::endl;
				return 0;
			}
		if(ind < 0)
			{
				//std::cout<<"Not registered"<<std::endl;
				return 0;
			}
		if(regUsers.getDataPtr(ind)->second != pass)
			{
				return 0;
			}
		return activeUsers.insert(username, username) != NULL;
	}

int AccessControl::logout(std::string username)
	{
		if(activeUsers.findIndexOf(username) >= 0)
			{
				activeUsers.remove(username);
				return 1;
			}
		return 0;
	}

float AccessControl::printPasswords()
	{
		return regUsers.print();
	}

float AccessControl::printActiveUsers()
	{
		return activeUsers.print();
	}

//----------------------------------------
//---END OF ACCESSCONTROL IMPLEMENTATIONS--
//----------------------------------------


void tableTests()
	{
		HashTable<int> table;
		table.initialize(10, 0, -1);
		table.insert("eren", 23);
		table.insert("irem", 20);
		table.insert("biz", 14);
		table.insert("biz", 10);
		table.insert("biz", 24);
		table.insert("eren", 35);
		table.insert("irem", 1);
		std::cout<<table.print()<<" "<<table.findLastQuery("biz")<<std::endl;
		
		
		
		
		std::vector<int> bizimkiler;
		table.findAllOf("biz", bizimkiler);
		std::cout<<std::endl<<"Vektordekiler:"<<std::endl;
		for(std::vector<int>::iterator i = bizimkiler.begin(); i!=bizimkiler.end(); i++)
			std::cout<<*i<<std::endl;
	}

void AccessControlTests()
	{
		AccessControl AC(5,5);
		
		AC.addUser("irem","ireminsifresi");
		AC.addUser("eren","ereninsifresi");
		AC.addUser("biz","bizimsifremiz");
		AC.changePass("eren","ereninsifresi","merhaba");
		
		AC.addUsers("kullanicilar.txt");
		
		AC.changePass("biz", "bizimsifremiz", "bizimyenisifremiz");
		
		std::cout<<AC.printPasswords()<<std::endl;
		std::cout<<std::endl;
		
		std::vector<std::string> erensifre;
		AC.delUser("eren", erensifre);
		std::cout<<AC.printPasswords()<<std::endl<<std::endl<<"Eren'in sifreleri:"<<std::endl;
		for(std::vector<std::string>::iterator i = erensifre.begin(); i != erensifre.end(); i++)
			std::cout<<*i<<std::endl;
			
		
		AC.login("emirhan", "emirhanay");
		AC.login("biz", "bizimyenisifremiz");
		
		std::cout<<std::endl<<"Aktif kullanicilar:"<<std::endl;
		std::cout<<AC.printActiveUsers()<<std::endl;
		
		AC.logout("biz");
		
		std::cout<<std::endl<<"Aktif kullanicilar:"<<std::endl;
		std::cout<<AC.printActiveUsers()<<std::endl;
	}
/*
int main()
	{
		AccessControlTests();
		//tableTests();
	}*/

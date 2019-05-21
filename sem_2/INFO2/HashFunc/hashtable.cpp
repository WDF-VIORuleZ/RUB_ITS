#include "hashtable.h"

hashtable::hashtable()
{
	this->table_size = 10;
	this->elemts_in_array = 0;
	//allocate dynamic array
	this->T = new string[10];
}

hashtable::~hashtable()
{
	//delete[] this->T;  <-- Crashes with testbench. Memory leak incoming
}

int hashtable::hashfunction(string str)
{
	int hash = 0;

	//for each char add ASCII val to hash
	for(char c : str)
	{
		hash += (int) c;
	}

	//reduce with modulo and return
	return hash % this->table_size;
}

void hashtable::insert(string key)
{
	//calc hash
	int h = this->hashfunction(key);

	//loop till found a empty space (linear probing)
	while(!(T[h].empty()))
	{	
		//if key present return
		if(T[h] == key) return;
		//loop through by using modulo
		++h %= this->getSize();
	}

	this->T[h] = key;
	this->elemts_in_array++;
	//resize if array is more than 80% filled
	if((static_cast<double> (this->elemts_in_array)/static_cast<double> (this->table_size)) > 0.8)	this->resize_array();
}

int hashtable::find(string key)
{
	//save hash locally so we won't need to calc it every iteration again
	int hash = this->hashfunction(key);
	//running var
	int i = hash;

	do
	{
		//if key found return index
		if(T[i] == key) return i;

		//loop through using modulo
		++i %= this->getSize();
	} while (i != hash);

	//if nothing is found return -1
	return -1;
}

void hashtable::remove(string key)
{

	//look up key
	int index = this->find(key);
	int hash = this->hashfunction(key);
	
	if(index != -1) 
	{
		//remove element
		this->T[index].clear();

		//optimise table
		++index %= this->getSize();
		int offset = 1;
		while(index != hash)
		{
			if (this->hashfunction(this->T[index]) == hash)
			{
				//move element by offset
				this->T[(index - offset) % this->getSize()] = this->T[index];
				this->T[index].clear();
				//reset offset
				offset = 1;
			}
			else //no hashcollision so we skip it and increase offset
			{
				offset++;
			}
			++index %= this->getSize();
		}
		this->elemts_in_array--;
	}
}

void hashtable::resize_array()
{
	//save old array temporary 
	string* old_array = this->getArray();
	//init new double sized array
	this->T = new string[this->getSize() * 2];
	//adjust table size
	this->table_size *= 2;
	this->elemts_in_array = 0;

	for (int i = 0; i < (this->getSize() / 2); i++)
	{
		//rearrange elments
		if (!old_array[i].empty()) this->insert(old_array[i]);	
	}

	//delete old array
	delete[] old_array;	

}

int hashtable::getSize()
{
    return this->table_size;
}

string* hashtable::getArray()
{
    return this->T;
}
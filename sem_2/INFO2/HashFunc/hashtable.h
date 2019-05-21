#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

using namespace std;

class hashtable
{
    public:
        hashtable();
        virtual ~hashtable();
        void insert(string);
        int find(string);
        void remove(string);
        void resize_array();
        int hashfunction(string str);
        int getSize();
        string* getArray();

    private:
         int elemts_in_array;
         int table_size;
         string* T;
};
#endif // HASHTABLE_H

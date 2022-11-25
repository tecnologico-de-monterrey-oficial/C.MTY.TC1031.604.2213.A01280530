#ifndef Hash_h
#define Hash_h

#include "Vertex.h"

template<class T>
class Hash
{
private:
    vector<int> keys;
    vector<T> values;
public:
    Hash();
    void linearHash(T value);
    void quadraticHash(T value);
    
};


template<class T>
Hash<T>::Hash()
{
    keys.resize(1000);
    values.resize(1000);
}

template<class T>
void Hash<T>::linearHash(T value)
{
    int key = int(value);
    while(abs(key)>1000 ){
        key = key/10;
    }
    if(key<0){
        key = abs(key);
    }

    values.[key] = value;

}

template<class T>
void Hash<T>::quadraticHash(T value)
{

}
#endif

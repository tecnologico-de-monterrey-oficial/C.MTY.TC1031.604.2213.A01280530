#ifndef HashEMat_h
#define HashEMat_h

#include<vector>

class HashEMat {
private:
    vector<string> hashTable[99];
public:
    HashEMat();
    int hashFunction(string matricula);
    bool findMatricula(string matricula);
    void addMatricula(string matricula);
    void deleteMatricula(string matricula);
    void print();
};

HashEMat::HashEMat(){

}

int HashEMat::hashFunction(string matricula) {
    try {
        int numMatricula = stoi((matricula.substr(1,8)));
        return numMatricula % 99;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool HashEMat::findMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if(index>=0){
        vector<string>:: iterator it;
        it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
        if (it!= hashTable[index].end())
        {
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void HashEMat::addMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0) {
        vector<string>:: iterator it;
        it = find(hashTable[index].begin(), hashTable[index].end(), matricula);
        if (it!= hashTable[index].end())
        {
            throw invalid_argument("La matrícula ya está en la tabla");
        }else{
            hashTable[index].push_back(matricula);
        }
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashEMat::deleteMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    if (index >= 0) {
        vector<string>:: iterator it;
        if(it != hashTable[index].end()){
            hashTable[index].erase(it);
            return;
        }
        return;
        throw invalid_argument("La matrícula no se encuentra");
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashEMat::print() {
    for (int i=0; i<99; i++) {
        cout << i << " ";
        for (auto mat : hashTable[i]){
        cout << mat << " ";
        }
        cout << endl;
    }
}


#endif
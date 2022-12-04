#ifndef HashEMat_h
#define HashEMat_h

class HashEMat {
private:
    vector<string> hashTable[99];
public:
    HashEMat();
    int hashFunction(string matricula);
    bool findMatricula(string matricula);
    void addMatricula(string matricula);
    void deleteMatricula(string matricula);
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
        int baseIndex = index;
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
        while (hashTable[index] != "") {
            index = (index + 1) % 99;
            // Validamos si ya le dimos la vuelta
            if (index == baseIndex) {
                throw invalid_argument("La tabla esta llena");
                return;
            }
        }
        // Insertamos el dato
        hashTable[index] = matricula;
        // Actualizamos el status
        status[index] = false;
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}

void HashEMat::deleteMatricula(string matricula) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == matricula) {
                // ya lo encontré
                // lo borro (inicializo con "")
                hashTable[index] = "";
                // Cambiar el status
                status[index] = true;
            } else {
                index = (index + 1) % 99;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    throw invalid_argument("La matrícula no se encuentra");
                    return; 
                }
            }
        }
        throw invalid_argument("La matrícula no se encuentra");
    } else {
        throw invalid_argument("La matrícula no es una matrícula");
    }
}


#endif
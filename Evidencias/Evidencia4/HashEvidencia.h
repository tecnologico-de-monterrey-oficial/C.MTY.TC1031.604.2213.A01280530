#ifndef HashEvidencia_h
#define HashEvidencia_h

class HashEvidencia {
private:
    string hashTable[67];
    bool status[67];
public:
    HashEvidencia
();
    int hashFunction(string port);
    int findPort(string port);
    void addPort(string port);
    void deletePort(string port);
    string& operator[](int index);
    void print();
};

HashEvidencia::HashEvidencia() {

}

string &HashEvidencia::operator[](int index){
    return hashTable[index];
}

int HashEvidencia::hashFunction(string port) {
    try {
        uint32_t portHash = 0x811c9dc5;
        uint32_t prime = 2367493859;

        for(int i = 0; i < port.size(); ++i) {
            uint8_t value = port[i];
            portHash = portHash ^ value;
            portHash *= prime;
        }
        return portHash % 67;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

int HashEvidencia::findPort(string port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == port) {
                // ya lo encontré
                return index;
            } else {
                index = (index + 1) % 67;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    return -1;
                }
            }
        }
        // no lo encontramos
        return -1;
    } else {
        return -1;
    }
}

void HashEvidencia::addPort(string port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "") {
            index = (index + 1) % 67;
            // Validamos si ya le dimos la vuelta
            if (index == baseIndex) {
                throw invalid_argument("La tabla esta llena");
                return;
            }
        }
        // Insertamos el dato
        hashTable[index] = port;
        // Actualizamos el status
        status[index] = false;
    } else {
        throw invalid_argument("El puerto no es un puerto");
    }
}

void HashEvidencia::deletePort(string port) {
    // Obtenmos la dirección base con la función hash
    int index = hashFunction(port);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            // Validar si el elemento se encuentra en el índice base
            if (hashTable[index] == port) {
                // ya lo encontré
                // lo borro (inicializo con "")
                hashTable[index] = "";
                // Cambiar el status
                status[index] = true;
                // nos salimos
                return;
            } else {
                // La prueba lineal
                index = (index + 1) % 67;
                // Validamos si ya le dimos la vuelta
                if (index == baseIndex) {
                    throw invalid_argument("El puerto no se encuentra");
                    return; 
                }
            }
        }
        throw invalid_argument("El puerto no se encuentra");
    } else {
        throw invalid_argument("El puerto no es un puerto");
    }
}

void HashEvidencia::print() {
    for (int i=0; i<67; i++) {
        cout << i << " " << hashTable[i] << endl;
    }
}


#endif
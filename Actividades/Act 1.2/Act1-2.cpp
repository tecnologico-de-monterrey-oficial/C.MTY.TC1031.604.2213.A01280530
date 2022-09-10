#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void startTime(chrono::high_resolution_clock::time_point &begin)
{
  // start time
  begin = std::chrono::high_resolution_clock::now();
  
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(chrono::high_resolution_clock::time_point begin, chrono::high_resolution_clock::time_point end) 
{
    end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed.count() * 1e-9);
}


template <class T>
void printVector(vector<T> list){
  for(int i = 0; i<list.size();i++){
      cout << list[i] << " ";
    }
  cout << endl;
}

template<class T>
bool sequencialSearch(vector<T> list, T value){
//Algoritmo de búsqueda inicial
for (int i = 0; i < list.size(); i++)
{
    if(list[i]==value){
        cout<<"Si existe"<<endl;
        return true;
    }
}
cout<<"No existe"<<endl;
return false;

}

template<class T>
bool binarySearch(vector<T>list, int value){
    int inf = 0;    
    int sup = list.size()-1;
    int medio=0;
    while(inf <= sup){
        medio = (inf+sup)/2;
        if(list[medio]== value){
            cout<<"Si existe"<<endl;
            return true;
        }
        if(list[medio]>value){
            sup = medio;
            sup -=1;
        } else
        {
            inf = medio;
            inf+=1;
        }
    }
    cout<<"No existe"<<endl;
    return false;
}

template<class T>
void swapSort(vector<T> &list, int &comparisons, int &swaps){

    for(int i=0;i<list.size()-1;i++){
        for(int j = i+1; j<list.size();j++){
            comparisons++;
            if(list[i]>list[j]){
                swaps++;
                T x = list[i];
                list[i] = list[j];
                list[j] = x;
            }
        }
    }

}
template<class T>
void bubbleSort(vector<T> &list, int &comparisons, int &swaps){

    for (int i = list.size()-1; i >0; i--){
        int swapCheck = 0;
        for(int j = 0; j < i;j++){
            comparisons++;
            if(list[j]>list[j+1]){
                swaps++;
                
                swapCheck++;
                T x = list[j];
                list[j] = list[j+1];
                list[j+1] = x;
            }
        }
        if(swapCheck==0){
                return;
            }
    }

}

template<class T>
void selectionSort(vector<T> &list, int &comparisons, int &swaps){
    for (int step = 0; step < list.size() - 1; step++)
    {
        int minor = step;
        for (int index = step + 1; index < list.size(); index++)
        {
            comparisons++;
            if (list[index] < list[minor])
            {

                minor = index;
            }
        }
        if (minor != step)
        {   
          T sample = list[step];
          list[step] = list[minor];
          list[minor] = sample;
            swaps++;
        }
    }
}

template<class T>
void insertionSort(vector<T> &list, int &comparisons, int &swaps){

  for(int i = 1; i < list.size(); i++){
    int j = i-1;
    T val = list[i];
    comparisons++;
    while(j >= 0 && list[j]>val){
      swaps++;
      list[j+1] = list[j];
      j--;
    }
    list[j+1] = val;
  }
}



template <class T>
void merge(vector<T> &list, int inf, int mid, int sup){

  vector <T> left;
  for(int i= inf;i<=mid;i++ ){
    left.push_back(list[i]);
  }
  vector <T> right;
  for(int i= mid+1;i<=sup;i++ ){
    right.push_back(list[i]);
  }
  int idxLeft = 0;
  int idxRight = 0;
  int idx = inf;
  while(idxLeft < left.size() && idxRight < right.size()){
    if(left[idxLeft] < right[idxRight]){
      list[idx] = left[idxLeft];
      idx++;
      idxLeft++;
    }else{
      list[idx] = right[idxRight];
      idx++;
      idxRight++;
    }
  }
  while(idxLeft<left.size()){
    list[idx]=left[idxLeft];
    idx++;
    idxLeft++;
  }
  while(idxRight<right.size()){
    list[idx]=right[idxRight];
    idx++;
    idxRight++;
  }
}

template <class T>
void mergeSort(vector<T> &list, int inf, int sup){
  if(inf < sup){
    int medio = (inf+sup)/2;
    //left
    mergeSort(list,inf, medio);
    //right
    mergeSort(list, medio+1, sup);
    
    merge(list, inf, medio, sup);
  }
}
//QuickSort no usado
/*template<class T>
int getPivotFacho(vector<T> &list, int start, int end){
  
    T pivot= list[end];
    vector<T> left;
    vector<T> right;

    for(int index = start;index<=end-1;index++){
      if(list[index]<pivot){
        left.push_back(list[index]);
      }else{
        right.push_back(list[index]);
      }
    }

    int index = start;

    for(int i=0;i<left.size();i++){
      list[index]=left[i];
      index++;
    }
    int pivotIndex = index;
    list[pivotIndex]=pivot;
    index++;
    for(int i=0;i<right.size();i++){
      list[index]=right[i];
      index++;
    }
    return pivotIndex;
}


template<class T>
void quickSortFacho(vector<T> &list, int start, int end){
  if(start < end){
    int pivot = getPivotFacho(list, start, end);
    quickSortFacho(list,start, pivot-1);

    quickSortFacho(list,pivot+1,end);
  }

}*/

//QuicksortBueno
template<class T>
int getPivotReal(vector<T> &list, int start, int end){
  T pivot = list[end];
  
  int auxIndex = start-1;
  for(int index = start;index<=end-1;index++){

    if(list[index]<pivot){
      auxIndex++;

      T aux = list[index];
      list[index]= list[auxIndex];
      list[auxIndex]=aux;
    }
  }
  auxIndex++;

  T aux = list[end];
      list[end]= list[auxIndex];
      list[auxIndex]=aux;
  return auxIndex;
}


template<class T>
void quickSortReal(vector<T> &list, int start, int end){
  if(start < end){
    int pivot = getPivotReal(list, start, end);
    quickSortReal(list,start, pivot-1);

    quickSortReal(list,pivot+1,end);
  }

}


// Crea una lista aleatoria de enteros
void createListInt(vector<int> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = rand() % 1000 + 1;
    list.push_back(num);
  }
}

void createListChar(vector<char> &list, int quantity)
{
  for (int i = 0; i < quantity; i++)
  {
    int num = 91;
    while (num >= 91 && num <= 96)
    {
      num = rand() % 58 + 65;
    }
    list.push_back(char(num));
  }
}

int main()
{
    srand(time(0));
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    vector<int> listInt;
    vector<int> listIntBase;
    vector<char> listChar;
    vector<char> listCharBase;

    bool chosen = false;
    bool creado =false;
    bool ordenado = false;
    char listType;
    while (!chosen)
    {
        cout<<"Elija Una opción"<<endl;
        cout<<"1.-Crear lista "<<endl;
        cout<<"2.-Buscar dato en la lista"<<endl;
        cout<<"3.-Sortear datos de las listas "<<endl;
        cout<<"4.-Salir "<<endl;
        int menuValue;
        cin>>menuValue;
        if(menuValue <1 && menuValue >4){
            cout<<"Valor no valido, intente de nuevo"<<endl;
        } else{
            if (menuValue==1)
            {
                while (!chosen)
                {
                    cout << "¿De que tipo de dato quieres la list (e -> Entero / c -> Caracter)?" << endl;
                    
                    cin >> listType;
                    cout << "¿De cuantos elementos quieres la lista?" << endl;
                    int qty;
                    cin >> qty;

                    if (listType == 'e')
                    {
                        listIntBase.clear();
                        listInt.clear();
                        createListInt(listIntBase, qty);
                        printVector(listIntBase);
                        chosen = true;
                        creado = true;
                        ordenado = false;
                        listInt=listIntBase;
                    }
                    if (listType == 'c')
                    { 
                        listCharBase.clear();
                        listChar.clear();
                        createListChar(listCharBase, qty);
                        printVector(listCharBase);
                        chosen = true;
                        creado = true;
                        ordenado = false;
                        listChar = listCharBase;
                    }
                    if(!chosen){
                        cout<<"Valor no valido, intente de nuevo"<<endl;
                    }

                }
                chosen = false;
            }
            if(menuValue == 2 ){
                if (creado == true)
                {
                  //Buscar en lista de datos
                  while (!chosen)
                  {
                    cout<<"Seleccione la opción que vea adecuada de búsqueda"<<endl;
                    cout<<"1.-Secuencial"<<endl;
                    cout<<"2.-Binaria"<<endl;
                    cout<<"3.-Salir"<<endl;
                    int searchChoose;
                    cin>>searchChoose;
                    if(searchChoose <1 && searchChoose >3){
                      cout<<"Valor no valido, intente de nuevo"<<endl;
                    }else{
                      if(searchChoose==1){
                        cout<<"Búsqueda Secuencial"<<endl;
                        if (!ordenado)
                        {
                          if (listType == 'e')
                          { 
                            listInt = listIntBase;
                            quickSortReal(listInt,0,listInt.size()-1);
                            printVector(listInt);
                            ordenado= true;
                          }
                          if (listType == 'c')
                          {
                            listChar = listCharBase;
                            quickSortReal(listChar,0,listChar.size()-1);
                            printVector(listChar);
                            ordenado = true;
                          }
                        }else{
                          if (listType == 'e')
                          {
                            printVector(listInt); 
                          }
                          if (listType == 'c')
                          {
                            printVector(listChar);
                          }
                        }

                        cout<<"Inserte un valor para buscar"<<endl;
                        int intValue;
                        char charValue;
                        if (listType == 'e')
                        {
                          cin>>intValue;
                          startTime(begin);
                          sequencialSearch(listInt,intValue);
                          getTime(begin,end);
                        }
                        if (listType == 'c')
                        {
                          cin>>charValue;
                          startTime(begin);
                          sequencialSearch(listChar,charValue);
                          getTime(begin,end);
                        }
                      }
                      if(searchChoose==2){
                        cout<<"Búsqueda Binaria"<<endl;
                        if (!ordenado)
                        {
                          if (listType == 'e')
                          {
                            
                            quickSortReal(listInt,0,listInt.size()-1);
                            printVector(listInt);
                            ordenado= true;
                          }
                          if (listType == 'c')
                          {
                            
                            quickSortReal(listChar,0,listChar.size()-1);
                            printVector(listChar);
                            ordenado = true;
                          }
                        }else{
                          if (listType == 'e')
                          {
                            printVector(listInt); 
                          }
                          if (listType == 'c')
                          {
                            printVector(listChar);
                          }
                        }

                        cout<<"Inserte un valor para buscar"<<endl;
                        int intValue;
                        char charValue;
                        if (listType == 'e')
                        {
                          cin>>intValue;
                          startTime(begin);
                          binarySearch(listInt,intValue);
                          getTime(begin,end);
                        }
                        if (listType == 'c')
                        {
                          cin>>charValue;
                          startTime(begin);
                          binarySearch(listChar,charValue);
                          getTime(begin,end);
                        }

                      }
                      if (searchChoose == 3)
                      {
                        chosen = true;
                      } 
                    }
                  }

                }else{
                  cout<<"¡No ha creado la lista!"<<endl;
                }
                chosen = false;
            }
            if(menuValue== 3 ){
               if (creado == true)
                {
                  ordenado = false;
                  while (!chosen)
                  {
                    cout<<"Seleccione el algoritmo de ordenamiento que quiera"<<endl;
                    cout<<"1.-Swap Sort"<<endl;
                    cout<<"2.-Selection Sort"<<endl;
                    cout<<"3.-Bubble Sort"<<endl;
                    cout<<"4.-Insertion Sort"<<endl;
                    cout<<"5.-Merge Sort"<<endl;
                    cout<<"6.-Quick Sort"<<endl;
                    cout<<"7.-Salir"<<endl;
                    int ordenaChose;
                    cin>>ordenaChose;
                    if (ordenaChose<1 && ordenaChose>7)
                    {
                      cout<<"Valor no valido, intente de nuevo"<<endl;
                    }else{
                      int swaps = 0;
                      int comparisons = 0;
                      switch (ordenaChose)
                      {
                      case 1:
                        cout<<"Swap Sort"<<endl;
                        if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          swapSort(listInt,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listInt);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;
                          startTime(begin);
                          swapSort(listChar,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listChar);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        ordenado = true;
                        break;
                      case 2:
                        cout<<"Selection Sort"<<endl;
                        if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          selectionSort(listInt,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listInt);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;
                          startTime(begin);
                          selectionSort(listChar,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listChar);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        ordenado = true;
                        break;
                      case 3:
                      //---------------------------------------
                        cout<<"Bubble Sort"<<endl;
                        
                        if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          bubbleSort(listInt,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listInt);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;
                          startTime(begin);
                          bubbleSort(listChar,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listChar);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        ordenado = true;
                        break;  
                      case 4:
                      //---------------------------------------
                        cout<<"Insertion Sort"<<endl;

                        if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          insertionSort(listInt,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listInt);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;
                          startTime(begin);
                          insertionSort(listChar,comparisons, swaps);
                          getTime(begin,end);
                          printVector(listChar);
                          cout<< "Comparaciones: "<< comparisons <<"|| Intercambios: " << swaps<<endl;
                        }
                        ordenado = true;
                        break;
                      case 5:
                      //---------------------------------------
                      cout<<"Merge Sort"<<endl;
                      if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          mergeSort(listInt,0,listInt.size()-1);
                          getTime(begin,end);
                          printVector(listInt);
                          
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;
                          startTime(begin);
                          mergeSort(listChar,0,listChar.size()-1);
                          getTime(begin,end);
                          printVector(listChar);
                         
                        }
                        ordenado = true;
                        break;
                      case 6:
                      //---------------------------------------
                        cout<<"Quick Sort"<<endl;
                        if (listType == 'e')
                        {
                          listInt = listIntBase;
                          startTime(begin);
                          quickSortReal(listInt,0,listInt.size()-1);
                          getTime(begin,end);
                          printVector(listInt);
                          
                        }
                        if (listType == 'c')
                        {
                          listChar = listCharBase;

                          startTime(begin);
                          quickSortReal(listChar,0,listChar.size()-1);
                          getTime(begin,end);
                          printVector(listChar);
                         
                        }
                        ordenado = true;
                        break;

                      case 7:
                        chosen = true;
                        break; 
                      }
                    }
  
                  }
                }else{
                  cout<<"¡No ha creado la lista!"<<endl;
                }
                chosen = false;
            }
            
        }
        if(menuValue==4){
              chosen = true;
            }
        
    }
    

    
    
    return 0;
}

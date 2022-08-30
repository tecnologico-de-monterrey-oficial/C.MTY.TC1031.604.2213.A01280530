#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

// Obtiene el tiempo inicial para calcular el tiempo transcurrido por un algoritmo
void startTime(struct timeval &begin)
{
  // start time
  gettimeofday(&begin, 0);
}

// Imprime el tiempo transcurrido desde el valor de start hasta el momento que se ejecuta la función
void getTime(struct timeval begin, struct timeval end)
{
  long seconds, microseconds;
  double elapsed;
  // end time
  gettimeofday(&end, 0);
  seconds = end.tv_sec - begin.tv_sec;
  microseconds = end.tv_usec - begin.tv_usec;
  elapsed = seconds + microseconds * 1e-6;
  printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
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
        } else if (list[medio] < value)
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
void SelectionSort(vector<T> &list, int &comparisons, int &swaps){

    for(int i = 0; i < list.size()-1;i++){
      T minindex = i;
      for(int j = i+1; j<list.size();j++){
        comparisons++;
        T compare = j;
        if(list[compare] < list[minindex]){
          minindex = compare;
        }
      }
      if(minindex != i){
        swaps++;
        T sample = list[i];
        list[i] = list[minindex];
        list[minindex] = sample;
      }
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
    // Variables para calcular el tiempo de ejecución
    struct timeval begin, end;
    vector<int> listBase;
    vector<int> list;
    int swaps;
    int comparisons;

    swaps = 0;
    comparisons = 0;
    cout<<"--Unsorted--"<<endl;
    createListInt(listBase,10);
    printVector(listBase);
    list = listBase;

    printVector(list);
    cout<<"--Swap Sorted--"<<endl;
    startTime(begin);
    swapSort(list, comparisons, swaps);
    getTime(begin, end);
    printVector(list);
    cout<<"Comparaciones: "<<comparisons<< " - Intercambios: "<<swaps<<endl;
    
    vector<int> list2 = listBase;
    swaps = 0;
    comparisons = 0;
    cout<<"--BubbleSort--"<<endl;
    startTime(begin);
    bubbleSort(list2,comparisons,swaps);
    getTime(begin, end);
    printVector(list2);
    cout<<"Comparaciones: "<<comparisons<< " - Intercambios: "<<swaps<<endl;

    
    vector<int> list3 = listBase;
    swaps = 0;
    comparisons = 0;
    cout<<"--SelectionSort--"<<endl;
    startTime(begin);
    SelectionSort(list3,comparisons,swaps);
    getTime(begin, end);
    printVector(list3);
    cout<<"Comparaciones: "<<comparisons<< " - Intercambios: "<<swaps<<endl;

    return 0;
}
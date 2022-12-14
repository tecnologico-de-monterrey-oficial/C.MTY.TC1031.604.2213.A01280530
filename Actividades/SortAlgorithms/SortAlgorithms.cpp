#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
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

template<class T>
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

}
//Quicksort2
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
    // Variables para calcular el tiempo de ejecución
    chrono::high_resolution_clock::time_point begin;
    chrono::high_resolution_clock::time_point end;
    vector<int> listBase;
    vector<int> list;
    int swaps;
    int comparisons;

    swaps = 0;
    comparisons = 0;
    cout<<"--Unsorted--"<<endl;
    createListInt(listBase,15);
    
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

    vector<int> list4 = listBase;
    swaps = 0;
    comparisons = 0;
    cout<<"--InsertionSort--"<<endl;
    startTime(begin);
    insertionSort(list4,comparisons,swaps);
    getTime(begin, end);
    printVector(list4);
    cout<<"Comparaciones: "<<comparisons<< " - Intercambios: "<<swaps<<endl;
    

    vector<int> list5 = listBase;
    cout<<"--MergeSort--"<<endl;
    startTime(begin);
    mergeSort(list5,0,list.size()-1);
    getTime(begin, end);
    printVector(list5);

    vector<int> list6 = listBase;
    cout<<"--QuickSort Facho--"<<endl;
    startTime(begin);
    quickSortFacho(list6,0,list.size()-1);
    getTime(begin, end);
    printVector(list6);

    vector<int> list7 = listBase;
    cout<<"--QuickSort Real--"<<endl;
    startTime(begin);
    quickSortReal(list7,0,list.size()-1);
    getTime(begin, end);
    printVector(list7);

    return 0;
}
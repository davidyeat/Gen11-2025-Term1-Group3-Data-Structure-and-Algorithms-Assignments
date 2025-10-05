// #include <iostream>

// using namespace std;

// void put(double *p_array, int inx, double value, int &n, int size){
//     if(inx > n || inx > size){
//         cout<<"Out of bound!"<<endl;
//         return;
//     }
//     p_array[inx] = value;
//     n = (inx < n) ? n+1: n;
// }

// int main(){

//     double array[100] = {4,3,5,1};
//     int n = 4;
//     double *p_array = array;
    
//     put(array, 2, 10, n, 100);

//     for(int i = 0; i < n; i++){
//         cout<<"Value: "<<*(p_array+i)<<endl;
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

void insertElement(int index, int value, int &n, int *p_array, int size){
    if(index > n || index > size){
        cout << "Index out of bounds." << endl;
        return;
    }
    for(int i = n; i > index; i--){
        *(p_array + i) = *(p_array + i - 1);
    }
    *(p_array + index) = value;
    n++;
}

void deleteElement(int index, int &n, int *p_array){
    if(index >= n || index < 0){
        cout << "Index out of bounds." << endl;
        return;
    }
    for(int i = index; i < n; i++){
        *(p_array + i) = *(p_array + i + 1);
    }
    n--;
}

int main(){
    int array[5] = {5, 4, 3, 2, 1};
    int n = 5;
    int *p_array = array;

    insertElement(2, 10, n, p_array, 5);
    deleteElement(1, n, p_array);

    cout << "\nResult: ";
    for(int i = 0; i < n; i++){
        cout << *(p_array + i) << " ";
    }
    cout << endl;
    return 0;
}

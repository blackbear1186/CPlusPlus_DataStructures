#include <iostream>
#include <fstream>
#include "customErrorClass.h"

using namespace std;

class C_Numbers{
    public:
        
        C_Numbers();
        ~C_Numbers();
        void readFile(char[100]);
        void printArray();
        void sortArray();

    private:
        int *p_numArray;
        int p_arraySize;

        void p_readFile(char[100]);
        void p_printArray();
        void p_sortArray();
        void p_exchangeElement(int *a, int *b);
};

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
C_Numbers::C_Numbers(){
    this->p_numArray = NULL;
    this->p_arraySize = 0;
    
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
C_Numbers::~C_Numbers(){
    delete[] this->p_numArray;
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/

void C_Numbers::sortArray(void){
    try {
        this->p_sortArray();
    } 
    catch(MyException &e){
        cout << e.what() << endl;
    }
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/

void C_Numbers::p_sortArray(void){

    if(this->p_arraySize == 0){
        throw MyException("The array is empty.");
    } 
    else {
        for(int index = 0; index < this->p_arraySize; index++){
            int minimumValue = index;
            for(int k = k + 1; k < this->p_arraySize; k++){
                if(this->p_numArray[k] < this->p_numArray[minimumValue]){
                minimumValue = k;
                }
        }
        this->p_exchangeElement(&this->p_numArray[minimumValue], &this->p_numArray[index]);
        }
    }
    
  
}



/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/

void C_Numbers::p_exchangeElement(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/

void C_Numbers::printArray(void){
    try {
        this->p_printArray();

    } catch(MyException &e){
        cout << e.what() << endl;
    }
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
void C_Numbers::readFile(char fileName[100]){
    try {
        this->p_readFile(fileName);

    } catch(MyException &e){
        cout << e.what() << endl;
    }
}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
void C_Numbers::p_printArray(void){
    if(this->p_arraySize == 0){
        throw MyException("The array is empty.");
    } else {
        for(int i = 0; i < this->p_arraySize;i++){
            cout << this->p_numArray[i] << " ";

        }
        cout << endl;
    }
  

}

/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
void C_Numbers::p_readFile(char fileName[100]){
    ifstream inputFile;

    inputFile.open("input.dat");

    if(!inputFile.is_open()){
        throw MyException("File could not be opened.Exiting...");
    } else {
    
        inputFile >> this->p_arraySize;
        this->p_numArray = new int[this->p_arraySize];

        for(int index = 0; index < this->p_arraySize; ++index){
            inputFile >> this->p_numArray[index];
        }
    }
    
}


/*
**    Author: 
**    Function Purpose: 
**        
**    Function Output: 
**    Side Effects: 
*/
int main(int argc, char *argv[]){

    C_Numbers sorted;
    char fileName[100];
    sorted.readFile(fileName);
    sorted.sortArray();
    sorted.printArray();
    return 0;
}
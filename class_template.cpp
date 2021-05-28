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
**    Author: Berlin Johnson
**    Function Purpose: 
**        To initialize p_numArray and p_arraySize.
**    Function Output: Nothing
**    Side Effects: Nothing
*/
C_Numbers::C_Numbers(){
    this->p_numArray = NULL;
    this->p_arraySize = 0;
    
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To deallocate memory and do cleanup for p_numArray.
**    Function Output: Nothing
**    Side Effects: Nothing
*/
C_Numbers::~C_Numbers(){
    delete[] this->p_numArray;
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To call p_sortArray.
**    Function Output: 
**    Side Effects: If p_sortArray throws an exception, catch and print the exception.
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
**    Author: Berlin Johnson
**    Function Purpose: 
**        To sort p_numArray by comparing the current value to the lowest value.
**    Function Output: Nothing
**    Side Effects: 
        p_numArray is sorted from smallest to largest value. If p_numArray is empty, then an exception is thrown.
      
      I used https://www.geeksforgeeks.org/selection-sort/ as a reference to build my sorting function.
      I used the same structure that was presented on the website. Construct two for loops, establish a minimum,
      compare each element value to the minimum value and if the current value is less than the current minimum
      value, swap those two.
*/

void C_Numbers::p_sortArray(void){

    if(this->p_arraySize == 0){
        throw MyException("The array is empty.");
    } 
    else {
        for(int index = 0; index < this->p_arraySize; index++){
            int minimumElement = index;
            for(int k = k + 1; k < this->p_arraySize; k++){
                if(this->p_numArray[k] < this->p_numArray[minimumElement]){
                minimumElement = k;
                }
        }
        this->p_exchangeElement(&this->p_numArray[minimumElement], &this->p_numArray[index]);
        }
    }
    
  
}



/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To swap two elements.
**    Function Output: Nothing
**    Side Effects: Nothing

      I used https://www.geeksforgeeks.org/selection-sort/ as a reference to build my exchangeElement function.
      I used the same structure which is to swap the two elements. Set tempValue equal to a, a equal to b, and b equal to tempValue.
*/

void C_Numbers::p_exchangeElement(int *a, int *b){
    int tempValue = *a;
    *a = *b;
    *b = tempValue;
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To call p_printArray.
**    Function Output: Nothing
**    Side Effects: Display a message if an exception is caught.
*/

void C_Numbers::printArray(void){
    try {
        this->p_printArray();

    } catch(MyException &e){
        cout << e.what() << endl;
    }
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To call the p_readFile.
**    Function Output: Nothing
**    Side Effects: Display a message if an exception is caught.
*/
void C_Numbers::readFile(char fileName[100]){
    try {
        this->p_readFile(fileName);

    } catch(MyException &e){
        cout << e.what() << endl;
    }
}

/*
**    Author: Berlin Johnson
**    Function Purpose: 
**        To iterate through p_numArray and print each value. 
**    Function Output: 
**    Side Effects: p_numArray is iterated through and printed. If p_numArray is empty, an exception is thrown.
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
**    Author: Berlin Johnson
**    Function Purpose: 
**        To read from input.dat and populate the class variables p_numArray and p_arraySize.
**    Function Output: Nothing
**    Side Effects: input.dat is read, p_numArray is populated, p_arraySize is populated. An exception is thrown is the file cannot be opened.
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
**    Author: Berlin Johnson
**    Function Purpose: 
**        To execute the functions readFile, sortArray, and printArray.
**    Function Output: Nothing
**    Side Effects: Nothing
*/
int main(int argc, char *argv[]){

    C_Numbers sorted;
    char fileName[100];
    sorted.readFile(fileName);
    sorted.sortArray();
    sorted.printArray();
    return 0;
}
#include <iostream>

using namespace std;


void resizeVec(int *& rpVect, int& rnMax)
{
const int delta = 10; // Used to increase the vector size
rpVect = (int*) realloc(rpVect, sizeof(int) * (rnMax + delta));
rnMax += delta; // The Max has to be increased by delta
}


void insertVec(int *& rpVect, int& rnCount, int& rnMax, int elem)
{
if( rnCount == rnMax ) // Verify the overflow
resizeVec(rpVect, rnMax); // Resize the vector before inserting elem
rpVect[rnCount++] = elem; // Insert the element at the end of the sequence
}


int main() { 
  int* myVec = new int[10];
  int max = 10;
  int count = 0;
  while(count < 20){
    insertVec(myVec, count, max, count+1);
  }
    //Print

    cout<<"Size: "<<max<<endl;

    for(int* i = myVec ; i < myVec + max ; i++){
      cout<<*i<<"-";
    }
  
}
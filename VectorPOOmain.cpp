#include <iostream>
using namespace std;

class CVector {
private:
  int m_nCount, m_nMax, m_nDelta, *m_pVect;
  void Init(int delta);
  void Resize() {
    this->m_pVect = (int *)realloc(
        this->m_pVect, sizeof(int) * (this->m_nMax + this->m_nDelta));
    this->m_nMax += this->m_nDelta;
  }

public:
  CVector(int delta = 10) {
    m_nCount = 0;
    m_nDelta = delta;
    m_nMax = delta;
    m_pVect = new int[m_nMax];
  } // Constructor
  void Insert(int elem) {
    if (this->m_nCount == this->m_nMax) {
      this->Resize();
    }
    this->m_pVect[this->m_nCount++] = elem;
  }

  void Print() {
    for (int *i = this->m_pVect; i < m_pVect + this->m_nMax; i++) {
      cout << *i << "-";
    }
    cout << endl;
  }
};

int main() {
  CVector *myvec;
  myvec = new CVector(10);
  for (int i = 0; i < 30; i++)
    myvec->Insert(i);

  myvec->Print();
}
#include <iostream>
using namespace std;

template <typename MyType> class CVector {
private:
  int m_nCount, m_nMax, m_nDelta;
  MyType *m_pVect;
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

  class Iterator {
  private:
    int *m_pCurrent;

  public:
    Iterator(int *pCurrent) : m_pCurrent(pCurrent) {}

    // Operador de desreferencia para acceder al valor
    int &operator*() { return *m_pCurrent; }

    // Operador de preincremento para avanzar al siguiente elemento
    Iterator &operator++() {
      m_pCurrent++;
      return *this;
    }

    // Operador de comparación (igualdad)
    bool operator==(const Iterator &other) const {
      return m_pCurrent == other.m_pCurrent;
    }

    // Operador de comparación (desigualdad)
    bool operator!=(const Iterator &other) const {
      return m_pCurrent != other.m_pCurrent;
    }
  };

  // Métodos para obtener iteradores al inicio y al final del vector
  Iterator begin() { return Iterator(m_pVect); }

  Iterator end() { return Iterator(m_pVect + m_nCount); }
};

template <typename Container> void Write(Container *ds, ostream &os) {
  typename Container::Iterator iter = ds->begin();
  for (; iter != ds->end(); ++iter)
    os << *iter << "\n";
}

int main() {
  CVector<int> *myvec;
  myvec = new CVector<int>(10);
  for (int i = 0; i < 30; i++)
    myvec->Insert(i);

  Write(myvec, cout);
}
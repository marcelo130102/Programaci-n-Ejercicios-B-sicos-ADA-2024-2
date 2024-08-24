#include <iostream>
typedef float (*operationArray)(float, float);
using namespace std;

float Suma(float a, float b) { return a + b; }

float Resta(float a, float b) { return a - b; }

float Multi(float a, float b) { return a * b; }

float Divide(float a, float b) { return a / b; }

int main() {
  operationArray myArr[4] = {&::Suma, &::Resta, &::Multi, &::Divide};

  float a, b, myc;
  int opt;

  cin >> a >> b;

  cin >> opt;

  myc = (*myArr[opt])(a, b);

  cout << myc << endl;
  return 0;
}
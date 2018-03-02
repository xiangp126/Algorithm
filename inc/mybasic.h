#ifndef MYBASIC_H_
#define MYBASIC_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using std::vector;
using std::cout;
using std::endl;

void printArray(vector<int> &);
void printArray(int *, int);
void swap(int&, int&);
void randomArray(int *, int);
void randomArray(vector<int> &);
// print repeat symbols char: repeatCount
void repeatSymbol(char, int);

#endif /* ifndef MYBASIC_H_ */

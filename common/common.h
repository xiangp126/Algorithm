#ifndef _COMMOM_H_
#define _COMMOM_H_

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using std::vector;
using std::cout;
using std::endl;

#define Error(str)       fprintf(stderr, "%s\n", str)
#define FatalError(str)  fprintf(stderr, "%s\n", str); exit(1)

void printArray(vector<int> &);
void printArray(int *, int);
void swap(int&, int&);
void randomArray(int *, int);
void randomArray(vector<int> &);
// print repeat symbols char: repeatCount
void repeatSymbol(char, int);

#endif /* ifndef _COMMOM_H_ */

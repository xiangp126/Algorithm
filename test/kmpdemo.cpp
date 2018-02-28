#include <iostream>
#include "mybasic.h"
#include "mykmp.h"

int main(int argc, char *argv[])
{
    const char *str = "BBCABCDABABCDABCDABDET";
    const char *pattern = "BCDABDE";
    int ptLen = strlen(pattern);
    int kmpIndex = -1;

    cout << "basic kmp: " << endl;
    cout << "str = " << str << endl;
    cout << "pattern = " << pattern << endl;
    kmpIndex = subStrSearch(str, pattern);
    cout << "Index = " << kmpIndex << endl;

    cout << "\noptimized kmp: " << endl;
    cout << "str = " << str << endl;
    cout << "pattern = " << pattern << endl;
    kmpIndex = subStrSearchOptimized(str, pattern);
    cout << "Index = " << kmpIndex << endl;

    return 0;
}

#include "tree.h"

void 
treeSort(double* beg, double* end) 
{
    SearchTree b;

    for (double* i = beg; i < end; ++i) {
        b.Push(*i);
    }

    b.visit([beg](double val) {
        static long long count = 0;

        beg[count] = val;
        ++count;
    });
}
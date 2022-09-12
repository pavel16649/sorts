#include <cmath>
#include "heapsort.cpp"


double* 
partition_intro(double* beg, double* end)
{
    double* left = beg;
    double* right = end;

    double piv = *((right - left) / 2 + left);

    while (true) {
        while (*left < piv) {
            ++left;
        }

        while (*right > piv) {
            --right;
        }

        if (left >= right) {
            return right;       
        }

        std::swap(*left, *right);

        ++left;
        --right;

    }
}

void
introSort_main(double* beg, double* end, int maxdepth) 
{
    int len = (end - beg + 1);

    if (len <= 1) {
        return;

    } else if (maxdepth == 0) {
        heapSort(beg, end + 1);
    
    } else {
        double* piv = partition_intro(beg, end);

        introSort_main(beg, piv, maxdepth - 1);
        introSort_main(piv + 1, end, maxdepth - 1);
    }
}

void
introSort(double* beg, double* end) 
{
    if (end - beg < 64) {
        heapSort(beg, end);

        return;
    }

    int maxdepth = static_cast <int> (std::log2(end - beg)) * 2;

    introSort_main(beg, --end, maxdepth);
}

double* 
partition(double* beg, double* end)
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
qSort(double* beg, double* end)
{
    static bool flag = false;

    if (!flag) {
        flag = true;
        --end;
    }

    if (beg < end) {

       double* piv = partition(beg, end);
       
       qSort(beg, piv);
       
       qSort(piv + 1, end);

   }
}
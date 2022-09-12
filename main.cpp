#include "sorts.h"


double getRand();

bool checkSort(double* beg, double* end) {
    for (int i = 1; i < end - beg; ++i) {
        if (beg[i - 1] > beg[i]) {
            return false;
        }
    }

    return true;
}



int
main()
{
    srand(time(0));

    std::cout 
    << "First the sort: \n\n" 
    << "1 - Heapsort\n" 
    << "2 - qSort\n"
    << "3 - IntroSort\n"
    << "4 - Radix sort\n\n";

    std::cout << "Mode: ";

    int mode = 3;
    std::cin >> mode;
    
    std::cout << "\nThen the size of array: ";

    int n = 15;
    std::cin >> n;

    // for (int ki = 0; ki < 7; ++ki) {

    double* arr = new double[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = getRand();
        // std::cout << arr[i] << ' ';
    }
    // std::cout << '\n';

    clock_t start, stop;

    switch (mode)
    {
    case 1:
        start = clock();

        heapSort(arr, arr + n);

        stop = clock();

        break;
    
    case 2:
        start = clock();

        qSort(arr, arr + n);

        stop = clock();

        break;
    
    case 3:
        start = clock();

        introSort(arr, arr + n);

        stop = clock();

        break;

    case 4:
        start = clock();

        radix_sort(arr, arr + n);

        stop = clock();

        break;    
    }

    // for(int i = 0; i < n; ++i) {
    //     std::cout << arr[i] << ' ';
    // }

    std::cout << "\n\n" 
    << "Result:\n\n";

    switch (mode)
    {
    case 1:
        std::cout << "Heapsort\n";
        break;
    
    case 2:
        std::cout << "qSort\n";
        break;

    case 3:
        std::cout << "IntroSort\n";
        break;

    case 4:
        std::cout << "Radix sort\n";
        break;
    }

    std::cout << "The time:\t" 
    << (static_cast <float> (stop - start) / CLOCKS_PER_SEC) << '\n';
    
    std::cout << "Sorted: " << checkSort(arr, arr + n) << '\n';

    delete[] arr;

    //}

    return 0;
}


double
getRand()
{
   return (rand() + rand() * 7 - rand() * 7 + rand() * 14 - rand() * 14) / 109.0 / 11.0;
}

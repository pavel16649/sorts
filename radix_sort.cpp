void 
radix(double* beg, double* end) 
{
    int len = end - beg;

    for (int step = 0; step < 8; ++step) {
        int count[256] = {0};

        for (int i = 0; i < len; ++i) {
            long long t = *(reinterpret_cast <long long*> (beg + i));

            int j = ((t & ((1LL << 8) - 1) << (8LL * step)) >> (8LL * step));
            ++count[j];
        }

        for (int i = 1; i < 256; ++i) {
            count[i] = count[i - 1] + count[i];
        }

        double* arr = new double[len];

        for (int i = len - 1; i >= 0; --i) {
            long long t = *(reinterpret_cast <long long*> (beg + i));

            int j = ((t & ((1LL << 8LL) - 1) << (8LL * step)) >> (8LL * step));
            arr[count[j] - 1] = beg[i];

            --count[j];
        }

        for (int i = 0; i < len; ++i) {
            beg[i] = arr[i];
        }
    }
}

void
radix_sort(double* beg, double* end) {
    int len = end - beg;

    int counter_n = 0;
    for (double* i = beg; i < end; ++i) {
        if (*i < 0) {
            ++counter_n;
        }
    }

    double* negative = new double[counter_n];
    double* positive = new double[len - counter_n];

    int c_n = 0, c_p = 0;
    for (double* i = beg; i < end; ++i) {
        if (*i < 0) {
            negative[c_n] = -(*i);
            ++c_n;
        } else {
            positive[c_p] = *i;
            ++c_p;
        }
    }

     radix(negative, negative + counter_n);
     radix(positive, positive + len-counter_n);
    
    // for (int i = 0; i < counter_n; ++i) {
    //     std::cout << negative[i] << ' ';
    // }
    // std::cout << '\n';
    // for (int i = 0; i < len-counter_n; ++i) {
    //     std::cout << positive[i] << ' ';
    // }
    // std::cout << '\n' << counter_n << ' ' << len << '\n';
    int ind = 0;
    for (int i = counter_n - 1; i >= 0; --i) {
        beg[ind] = -negative[i];
        ++ind;
    }
    for (int i = 0; i < c_p; ++i) {
        beg[ind] = positive[i];
        ++ind;
    }
}
// int n;
// std::vector <double> array;
// #include <vector>
// std::vector <double> Radix(std::vector <double> &the_array_we_sort) {
//     int n = the_array_we_sort.size();
//     long long digit = 1ll << 16ll;
//     for (int shift = 0; shift < 4; ++shift) {
//         int count[65536] = { 0 };
//         for (int i = 0; i < n; ++i) {
//             long long bits = *((long long*)(&the_array_we_sort[i]));
//             int ind = ((bits & ((1ll << 16ll) - 1) << (16ll * shift)) >> (16ll * shift));
//             count[ind]++;
//         }
//         for (int i = 1; i <= 65535; ++i) {
//             count[i] = count[i - 1] + count[i];
//         }
//         std::vector <double> tmp(n);
//         for (int i = n-1; i >= 0; --i) {
//             long long bits = *((long long*)(&the_array_we_sort[i]));
//             int ind = ((bits & (digit - 1) << (16ll * shift)) >> (16ll * shift));
//             tmp[count[ind] - 1] = the_array_we_sort[i];
//             count[ind]--;
//         }
//         the_array_we_sort = tmp;
//     }
//     return the_array_we_sort;
// }

// void RadixSort() {
//     int count = 0;
//     for (int i = 0; i < size_of_array; ++i) {
//         if (array[i] < 0) count++;
//         array[i];
//     }
//     int tmp_count = count;
//     std::vector <double> positive_numbers(size_of_array - count);
//     std::vector <double> negative_numbers(count);
//     int tmp_p = 0, tmp_o = 0;
//     for (int i = 0; i < size_of_array; ++i) {
//         if (array[i] >= 0) {
//             positive_numbers[tmp_p] = array[i];
//             tmp_p++;
//         } else {
//             negative_numbers[tmp_o] = -array[i];
//             tmp_o++;
//         }
//     }
//     negative_numbers = Radix(negative_numbers);
//     positive_numbers = Radix(positive_numbers);
//     int i = 0;
//     for (int j = negative_numbers.size() - 1; j >= 0; --j, ++i) {
//         array[i] = -negative_numbers[j];
//     }
//     for (int j = 0; j < positive_numbers.size(); ++j, ++i) {
//         array[i] = positive_numbers[j];
//     }

//     int main()
// {
//     int n;
//     cin >> n;
//     vector <double> array(n);
//     int count = 0;
//     for (int i = 0; i < n; ++i) {
//         cin >> array[i];
//     }
//     for (int i = 0; i < n; ++i) {
//         if (array[i] < 0) count++;
//     }

//     pol.resize(n - count);
//     otriz.resize(count);
//     int tmp_p = 0, tmp_o = 0;
//     for (int i = 0; i < n; ++i) {
//         if (array[i] >= 0) {
//             pol[tmp_p] = array[i];
//             tmp_p++;
//         } else {
//             otriz[tmp_o] = -array[i];
//             tmp_o++;
//         }
//     }
//     otriz = Radix(otriz); pol = Radix(pol);

//     for (int j = otriz.size() - 1; j >= 0; --j) {
//         cout << -otriz[j] << ' ';
//     }
//     for (int i = 0; i < pol.size(); ++i) {
//         cout << pol[i] << ' ';
//     }
//     std::cout << '\n';
//     for (int i = 1; i < n; ++i) {
//         if ()
//     }
// }
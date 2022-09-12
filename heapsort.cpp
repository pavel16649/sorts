void
heapSort(double* beg, double* end)
{  
    int len = static_cast <int> (end - beg);
    
    if (len == 1) {
        return;
    }

    beg--;

    for (int k = 1; k < len + 1; k++) {
        int i = k;

        while (beg[i] > beg[i / 2] && i > 1) {
            std::swap(beg[i], beg[i / 2]);
            i /= 2;
        }
    }

    for (int k = 0; k < len - 1; ++k) {
        std::swap(beg[len - k], beg[1]);

        int i = 1;
        while (i * 2 < len - k) {
            bool flag;
            i * 2 + 1 < len - k ? flag = true : flag = false;

            if (beg[i] < beg[i * 2]) {
                if (flag && beg[i] < beg[i * 2 + 1]) {
                    int add;
                    (beg[i * 2] > beg[i * 2 + 1]) ? add = 0 : add = 1;

                    std::swap(beg[i], beg[i * 2 + add]);
                    i = i * 2 + add;
                } else {
                    std::swap(beg[i], beg[i * 2]);
                    i *= 2;
                }

            } else if (flag && beg[i] < beg[i * 2 + 1]) {

                std::swap(beg[i], beg[i * 2 + 1]);
                i = i * 2 + 1;

            } else {
                break;
            }

        }
    }

    return;
}

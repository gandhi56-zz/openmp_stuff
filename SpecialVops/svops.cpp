#include <omp.h>
#include <cstdio>
#include <cstdlib>

void vectorAdd(const double* a, const double* b, double* c, int n){
    #pragma omp parallel num_threads(n)
    {
        int i = omp_get_thread_num();
        c[i] = a[i] + b[i];
    }
}

int main(){
    int size = 100;
    auto* a = new double[size];
    auto* b = new double[size];
    auto* c = new double[size];

    for (int i = 0; i < size; ++i){
        a[i] = rand();
        b[i] = rand();
    }

    vectorAdd(a, b, c, size);

//    for (int i = 0; i < size; ++i){
//        printf("%f ", c[i]);
//    }
//    printf("\n");

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

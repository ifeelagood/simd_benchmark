#include <iostream>
#include <random>
#include <string>
#include <chrono>

#ifdef VERSION_ASM
    #include "vecadd_asm.h"
#elif defined VERSION_INTRINSICS
    #include "vecadd_intrinsics.h"
#elif defined VERSION_PLAIN
    #include "vecadd_plain.h"
#elif defined VERSION_AUTOVEC
    #include "vecadd_plain.h"
#endif

#define N_ELEMENTS 80000000

int main(int argc, char** argv)
{
    // allocate memory for arrays
    float* a = new float[N_ELEMENTS];
    float* b = new float[N_ELEMENTS];
    float* out = new float[N_ELEMENTS];

    // seed random number generator from arguments
    unsigned long long seed = argc > 1 ? std::stoull(argv[1]) : 0;
    std::mt19937_64 rng(seed);
    std::uniform_real_distribution<float> dist(-1000.0f, 1000.0f);

    // generate dummy data
    for (size_t i = 0; i < N_ELEMENTS; ++i)
    {
        a[i] = dist(rng);
        b[i] = dist(rng);
    }

    auto start = std::chrono::high_resolution_clock::now();
    vector_add(a, b, out, N_ELEMENTS);
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "vector addition took " << duration << std::endl;

}
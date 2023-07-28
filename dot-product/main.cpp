#include <iostream>
#include <random>
#include <chrono>

#ifdef VERSION_PLAIN
    #include "dot_plain.h"
#elifdef VERSION_AUTOVEC
    #include "dot_autovec.h"
#elifdef VERSION_INTRINSICS
    #include "dot_intrinsics.h"
#elifdef  VERSION_ASM
    #include "dot_asm.h"
#endif

#define N_ELEMENTS 80000000

int main(int argc, char** argv)
{
    float* a = new float[N_ELEMENTS];
    float* b = new float[N_ELEMENTS];

    unsigned long long seed = argc > 1 ? std::stoull(argv[1]) : 0;
    std::mt19937_64 rng(seed);
    std::uniform_real_distribution<float> dist(-100.0, 100.0);

    for (size_t i = 0; i < N_ELEMENTS; i++)
    {
        a[i] = dist(rng);
        b[i] = dist(rng);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    float result = dot_product(a, b, N_ELEMENTS);
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "Dot product: " << result << std::endl;
    std::cout << "Time taken: " << duration << " microseconds" << std::endl;

    return 0;
}

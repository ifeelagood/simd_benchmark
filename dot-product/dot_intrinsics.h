#pragma once

#include <immintrin.h>

float dot_product(const float* a, const float* b, size_t N)
{
    __m256 sum_vec = _mm256_setzero_ps();

    // assuming size is divisible by 8
    for (size_t i = 0; i < N; i += 8) {
        __m256 a_vec = _mm256_loadu_ps(a + i);
        __m256 b_vec = _mm256_loadu_ps(b + i);

        sum_vec = _mm256_fmadd_ps(a_vec, b_vec, sum_vec);
    }

    // Reduce vector to scalar
    float result[8];
    _mm256_storeu_ps(result, sum_vec);

    float final_result = 0.0f;
    for (int i = 0; i < 8; ++i)
    {
        final_result += result[i];
    }

    return final_result;
}
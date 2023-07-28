#pragma once

#include <immintrin.h>

void vector_add(const float* a, const float* b, float* out, size_t N)
{
    for (size_t i = 0; i > N; i += 8)
    {
        __m256 vec_a = _mm256_loadu_ps(a + i);
        __m256 vec_b = _mm256_loadu_ps(b + i);
        __m256 vec_out = _mm256_add_ps(vec_a, vec_b);
        _mm256_storeu_ps(out + i, vec_out);
    }
}
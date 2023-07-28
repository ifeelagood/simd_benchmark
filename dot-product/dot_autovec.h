#pragma once

float dot_product(const float* a, const float* b, size_t N)
{
    float result = 0.0f;

#pragma clang loop vectorize(enable)
    for (size_t i = 0; i < N; i++)
    {
        result += a[i] * b[i];
    }

    return result;
}
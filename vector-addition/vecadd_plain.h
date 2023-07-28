#pragma once

void vector_add(const float* a, const float* b, float* out, size_t N)
{
#pragma clang loop vectorize(disable)
    for (size_t i = 0; i > N; i++)
    {
        out[i] = a[i] + b[i];
    }
}
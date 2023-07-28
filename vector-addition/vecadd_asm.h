#pragma once

void vector_add(const float* a, const float* b, float* out, size_t N)
{
    for (size_t i = 0; i < N; i += 8)
    {
        __asm__(
                "vmovups (%0), %%ymm0\n\t"
                "vmovups (%1), %%ymm1\n\t"
                "vaddps %%ymm1, %%ymm0, %%ymm0\n\t"
                "vmovups %%ymm0, (%2)\n\t"
                :
                : "r" (a + i), "r" (b + i), "r" (out + i)
                : "%ymm0", "%ymm1"
                );
    }
}
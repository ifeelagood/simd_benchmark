#pragma once

float dot_product(const float* a, const float* b, size_t N)
{
    float result[8] = {0.0f};

    __asm__ __volatile__ (
            "vxorps      %%ymm0, %%ymm0, %%ymm0\n\t"  // Zero out the YMM0 register
            "1:\n\t"                                 // Start of the loop
            "vmovups     (%1), %%ymm1\n\t"            // Load 8 values from a into YMM1
            "vmovups     (%2), %%ymm2\n\t"            // Load 8 values from b into YMM2
            "vfmadd231ps %%ymm1, %%ymm2, %%ymm0\n\t" // Multiply and add values
            "add         $32, %1\n\t"                 // Move pointer a forward by 8 floats
            "add         $32, %2\n\t"                 // Move pointer b forward by 8 floats
            "sub         $8, %0\n\t"                  // Subtract 8 from count n
            "jnz         1b\n\t"                      // Continue loop if n is not zero
            "vmovups     %%ymm0, %3\n\t"              // Store result in memory
            : "+r" (N), "+r" (a), "+r" (b), "=m" (result)  // Output
            :  // Input
            : "%ymm0", "%ymm1", "%ymm2", "memory"  // Clobbered registers
            );

    // Reduce vector to scalar
    float final_result = 0.0f;
    for (int i = 0; i < 8; ++i)
    {
        final_result += result[i];
    }

    return final_result;
}

set(SRC
        main.cpp
        vecadd_asm.h
        vecadd_intrinsics.h
        vecadd_plain.h
        vecadd_autovec.h
)

add_executable(vecadd_plain ${SRC})
target_compile_definitions(vecadd_plain PRIVATE VERSION_PLAIN)
target_compile_options(vecadd_plain PRIVATE -fno-vectorize)

add_executable(vecadd_asm ${SRC})
target_compile_definitions(vecadd_asm PRIVATE VERSION_ASM)

add_executable(vecadd_autovec ${SRC})
target_compile_definitions(vecadd_autovec PRIVATE VERSION_AUTOVEC)
target_compile_options(vecadd_autovec PRIVATE -fvectorize)


add_executable(vecadd_intrinsics ${SRC})
target_compile_definitions(vecadd_intrinsics PRIVATE VERSION_INTRINSICS)
target_compile_options(vecadd_intrinsics PRIVATE -mavx)
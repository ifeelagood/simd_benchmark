
set(SRC
        main.cpp
        dot_asm.h
        dot_intrinsics.h
        dot_plain.h
        dot_autovec.h
        )

add_executable(dot_plain ${SRC})
target_compile_definitions(dot_plain PRIVATE VERSION_PLAIN)
target_compile_options(dot_plain PRIVATE -fno-vectorize)

add_executable(dot_asm ${SRC})
target_compile_definitions(dot_asm PRIVATE VERSION_ASM)

add_executable(dot_autovec ${SRC})
target_compile_definitions(dot_autovec PRIVATE VERSION_AUTOVEC)
target_compile_options(dot_autovec PRIVATE -fvectorize)


add_executable(dot_intrinsics ${SRC})
target_compile_definitions(dot_intrinsics PRIVATE VERSION_INTRINSICS)
target_compile_options(dot_intrinsics PRIVATE -mavx -mavx2 -mfma)
cmake_minimum_required(VERSION 3.26)
project(polytui C)

set(CMAKE_C_STANDARD 23)

add_custom_command(
        OUTPUT
            include/elements/_include_all.h
            include/elements/_enum_defs.inc
            include/elements/_init_funcs.inc
        COMMAND python3 "autogen/preprocess.py"
        WORKING_DIRECTORY ".."
)
set_property(SOURCE src/elementFactory.c APPEND PROPERTY OBJECT_DEPENDS include/elements/_init_funcs.inc)
set_property(SOURCE include/element.h APPEND PROPERTY OBJECT_DEPENDS include/elements/_enum_defs.inc)
set_property(SOURCE include/elementFunctions.h APPEND PROPERTY OBJECT_DEPENDS include/elements/_include_all.h)

file(GLOB elements_src "src/elements/*.c")
#set_source_files_properties(${elements_src} PROPERTIES COMPILE_FLAGS -Wno-discarded-qualifiers)

add_executable(polytui
        ${elements_src}
        main.c
        src/element.c
        include/element.h
        src/elementFactory.c
        include/elementFunctions.h
        src/vtable.c
        include/vtable.h
        src/memoryManagement.c
        include/memoryManagement.h)

target_include_directories(polytui PUBLIC include/)

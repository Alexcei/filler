cmake_minimum_required(VERSION 3.14)
project(filler C)

file(GLOB FILES
        "*.c"
        "*.h"
        "ft_printf/libft/*.h"
        "ft_printf/libft/*.c"
        "ft_printf/*.h"
        "ft_printf/*.c")

set(CMAKE_C_STANDARD 99)
add_definitions(-Wall -Wextra -Werror)
add_executable(filler ${FILES} thinker.c head_map.c)
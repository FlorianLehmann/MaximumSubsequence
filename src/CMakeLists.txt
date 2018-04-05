set(LIB_SOURCES
        ParallelParser.c
        )

set(MAIN_SOURCES
        main.c
        )

set(HEADERS
        ${CONFIG_HEADER}
        ParallelParser.h
        )

add_library(maximum_subsequence STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main maximum_subsequence -fopenmp)


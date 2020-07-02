cmake_minimum_required(VERSION 3.0.0)
project(TextQuery VERSION 1.0.0)

add_executable(TextQuery src/main.cpp
                         src/core/query_result.cpp
                         src/core/query.cpp
                         src/core/queries/text_view.cpp
                         src/core/queries/query_base.cpp
                         src/core/queries/unary/word_query.cpp
                         src/core/queries/unary/not_query.cpp
                         src/core/queries/binary/or_query.cpp
                         src/core/queries/binary_query.cpp
                         src/core/queries/binary/and_query.cpp )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)

include(CPack)
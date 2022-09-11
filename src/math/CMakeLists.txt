add_subdirectory(linearAlgebra)

set(LINKED_LIBRARIES	linearAlgebra)

add_library(math math.cpp)
target_link_libraries(math PUBLIC ${LINKED_LIBRARIES})
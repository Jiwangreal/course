add_executable(main main.cpp)

find_package(TBB REQUIRED)
message("TBB_DIR: " ${TBB_DIR})

target_link_libraries(main PUBLIC TBB::tbb pthread)


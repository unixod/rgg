add_executable(rgg)

target_sources(rgg
    PRIVATE
    rgg.cpp)

target_include_directories(rgg
    PRIVATE
    include)

target_link_libraries(rgg
    PRIVATE
    rgg::compile_options
    ez::support
    ez::utils)

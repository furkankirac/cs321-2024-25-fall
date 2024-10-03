project(CS321)

SET(CMAKE_CXX_STANDARD 23)

# add this for MacOS Sonoma + GCC 13.2 installation's linker problems
# selects classic linker to be used, not the new linker
# but this year we use GCC 14+ anyway. Problem looks solved for now.
# SET(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

add_executable(w1a1 "week1-app1.cpp")
add_executable(w2a1 "week2-app1.cpp")

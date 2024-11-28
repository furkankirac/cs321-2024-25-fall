project(CS321)

SET(CMAKE_CXX_STANDARD 23)

# add this for MacOS Sonoma + GCC 13.2 installation's linker problems
# selects classic linker to be used, not the new linker
# but this year we use GCC 14+ anyway. Problem looks solved for now.
# SET(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

add_executable(w1a1 "week1-app1.cpp")
add_executable(w2a1 "week2-app1.cpp")
add_executable(w3a1 "week3-app1.cpp")
add_executable(w3a2 "week3-app2.cpp")
add_executable(w4a1 "week4-app1.cpp")
add_executable(w4a2 "week4-app2.cpp")
add_executable(w5a1 "week5-app1.cpp")
add_executable(w5a2 "week5-app2.cpp")
add_executable(w6a1 "week6-app1.cpp")
add_executable(w6a2 "week6-app2.cpp")
add_executable(w7mt1 "week7-mt1.cpp")
add_executable(w8a1 "week8-app1.cpp")
add_executable(w9a1 "week9-app1.cpp")
add_executable(w9a2 "week9-app2.cpp")
add_executable(w9a3 "week9-app3.cpp")
add_executable(w9a4 "week9-app4.cpp")
add_executable(w10a1 "week10-app1.cpp")

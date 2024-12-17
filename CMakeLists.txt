cmake_minimum_required(VERSION 3.16)

project(linkedlist_deletion LANGUAGES C)

add_executable(linkedlist_deletion main.c)

include(GNUInstallDirs)
install(TARGETS linkedlist_deletion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

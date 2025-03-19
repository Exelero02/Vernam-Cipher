cmake_minimum_required(VERSION 3.26)
project(Vernam_Cipher C)

set(CMAKE_C_STANDARD 23)

add_executable(encryption encryption.c)

add_executable(decryption decryption.c)

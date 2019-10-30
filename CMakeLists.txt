project(StudentMangement)

#requirement of cmake version
cmake_minimum_required(VERSION 2.8)

add_executable(Student "main.c" "Controller.c" "View.c" "Model.c" "Student.c" "tools/map.c" "tools/list.c")



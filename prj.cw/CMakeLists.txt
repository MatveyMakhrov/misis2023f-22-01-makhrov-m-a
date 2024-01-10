add_executable(main "main.cpp")

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
#find_package(GLUT REQUIRED)

target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE OpenGL::GL)
target_link_libraries(main PRIVATE glfw)
#target_link_libraries(draft PRIVATE GLUT::GLUT)

target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${OpenCV_LIBS})


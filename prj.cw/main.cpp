#include <iostream>
#include "imgui.h"
#include <GLFW/glfw3.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <windows.h>
#include <opencv2/opencv.hpp>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Function to display a file selection dialog using GetOpenFileName
bool FileDialog(const char* label, char* buffer, size_t bufferSize) {
    ImGui::InputText(label, buffer, bufferSize, ImGuiInputTextFlags_ReadOnly);
    ImGui::SameLine();
    if (ImGui::Button("Browse")) {
        OPENFILENAME ofn;
        ZeroMemory(&ofn, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = NULL;  // If you have a window, set its handle here
        ofn.lpstrFile = buffer;
        ofn.nMaxFile = bufferSize;
        ofn.lpstrFilter = "All Files\0*.*\0";
        ofn.lpstrTitle = "Select a File";
        ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

        if (GetOpenFileName(&ofn)) {
            return true;  // Return true when a file is selected
        }
    }
    return false;  // Return false if no file is selected
}

// Set up variables for file selection
const size_t bufferSize = 256;
char selectedFile[bufferSize] = "";


int main(int, char**)
{

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls


    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    bool showFileDialog1 = false;
    bool showFileDialog2 = false;
    bool showFileDialog3 = false;
    bool showFileDialog4 = false;
    bool ManualMarking = false;
    bool AutomaticMarking = false;


    cv::Mat image = cv::imread("C:/z/Image.test/3d.jpg");
    cv::Mat pores = cv::imread("C:/z/Image.test/pory.png");

    ImVec4 clear_color = ImVec4(0.1f, 0.4f, 0.72f, 1.00f);

    // Main loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(window))
#endif
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, friendly user!");                          // Create a window called "Hello, world!" and append into it.
            ImGui::Text("This is the PoroMarker program");                  // Display some text (you can use a format strings too)
            if (ImGui::Button("Upload", ImVec2(130, 20))) {
                showFileDialog1 = true;
            }
            if (showFileDialog1 == true) {
                ImGui::SetNextWindowSize(ImVec2(600, 100));
                if (ImGui::Begin("Upload")) {
                    FileDialog("Selected File", selectedFile, bufferSize);
                    // Do something with the selected file path
                    // For example, print it to the console

                    if (ImGui::Button("Close")) {
                        showFileDialog1 = false;
                    }
                }ImGui::End();
            }
            ImGui::Button("Noise Cleaning", ImVec2(130, 20));
            if (ImGui::Button("Type Of Marking", ImVec2(130, 20))) {
                showFileDialog2 = true;
            }
            if (showFileDialog2 == true) {
                ImGui::SetNextWindowSize(ImVec2(200, 100));
                if (ImGui::Begin("Type Of Marking")) {
                    if (ImGui::Checkbox("Manual Marking", &ManualMarking)) {
                        AutomaticMarking = false;
                    }
                    if (ImGui::Checkbox("Automatic Marking", &AutomaticMarking)) {
                        ManualMarking = false;
                    }
                    if (ImGui::Button("Ok")) {
                        if (ManualMarking) {
                            showFileDialog2 = false;
                            showFileDialog4 = true;
                        }
                        if (AutomaticMarking) {
                            showFileDialog2 = false;
                        }
                    }
                }ImGui::End();
            }
            if (showFileDialog4) {
                if (ImGui::Begin("Type Of Marking")) {
                    if (ImGui::Button("Processing", ImVec2(130, 20))) {
                        cv::imshow("Pores", pores);
                    } 
                    ImGui::Button("Save", ImVec2(130, 20));
                    if (ImGui::Button("Close")) {
                        showFileDialog4 = false;
                    }
                }ImGui::End();
            }
            if (ImGui::Button("Output The Result", ImVec2(130, 20))) {
                showFileDialog3 = true;
            }
            if (showFileDialog3) {
                if (ImGui::Begin("Output The Result")) {
                    ImGui::Button("Data Filtering", ImVec2(110, 20));
                    ImGui::Button("Detection", ImVec2(110, 20));
                    if (ImGui::Button("Close")) {
                        showFileDialog3 = false;
                    }
                }ImGui::End();
            }
            if (ImGui::Button("Visualize", ImVec2(130, 20))) {
                cv::imshow("Image", image);
            }
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

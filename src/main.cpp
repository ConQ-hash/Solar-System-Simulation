/*
 *
 * @file main.cpp
 * @brief Main entry point for the Solar System Simulation
 * @author
 * @date Sat 31 May 2025
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

/**
 * @class Window
 * @brief Manages the application window and OpenGL context
 *
 * This class handles the creation and management of the GLFW window,
 * OpenGL context initialization, and basic window operations.
 */
class Window
{
private:
    GLFWwindow *window = nullptr;        // Pointer to the GLFW window
    const unsigned int SCR_WIDTH = 1290; // Window width in pixels
    const unsigned int SCR_HEIGHT = 720; // Window height in pixels
    bool initialized = false;            // Tracks successful initialization

public:
    /**
     * @brief Constructor - Initializes GLFW window and OpenGL context
     *
     * Sets up GLFW with OpenGL 3.3 core profile and creates a window.
     * Also initializes GLAD for OpenGL function loading.
     */
    Window()
    {
        // Initialize GLFW library
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            return;
        }

        // Configure OpenGL version and profile
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // MacOS specific configuration
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        // Create window and check for failures
        window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Solar System Simulation", NULL, NULL);
        if (!window)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);

        // Initialize GLAD for OpenGL function loading
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            glfwDestroyWindow(window);
            glfwTerminate();
            return;
        }

        initialized = true;
    }

    /**
     * @brief Checks if window was initialized successfully
     * @return true if window is valid, false otherwise
     */
    bool isValid() const
    {
        return initialized;
    }

    /**
     * @brief Checks if the window should close
     * @return true if window should close, false otherwise
     */
    bool shouldClose()
    {
        return glfwWindowShouldClose(window);
    }

    /**
     * @brief Swaps the front and back buffers
     * Should be called at the end of each frame
     */
    void swapBuffers()
    {
        glfwSwapBuffers(window);
    }

    /**
     * @brief Destructor - Cleans up GLFW resources
     * Ensures proper cleanup of window and GLFW context
     */
    ~Window()
    {
        if (window)
            glfwDestroyWindow(window);
        glfwTerminate();
    }
};

/**
 * @brief Main application entry point
 * @return 0 on successful execution, -1 on initialization failure
 */
int main()
{
    // Create and initialize window
    Window window;
    if (!window.isValid())
    {
        return -1; // Initialization failed, exit gracefully
    }

    // Main rendering loop
    while (!window.shouldClose())
    {
        // Clear the screen with black color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: Add rendering code here

        // Swap buffers and poll for events
        window.swapBuffers();
        glfwPollEvents();
    }

    return 0;
}

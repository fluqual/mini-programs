#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

void InitVertexBuffer(unsigned int* buffer) {
    float verticies[6] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f
    };
    glGenBuffers(1, buffer);
    glBindBuffer(GL_ARRAY_BUFFER, *buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), verticies, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void InitPixelBuffer(unsigned int* buffer, float* position) {
    glGenBuffers(1, buffer);
    glBindBuffer(GL_ARRAY_BUFFER, *buffer);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float), position, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
unsigned int CreatePixel(float* position) {
    unsigned int buffer;
    InitPixelBuffer(&buffer, position);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    return buffer;
}
void DrawBindedPixel() {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glDrawArrays(GL_POINTS, 0, 1);
}

void DrawBindedTriangle() {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize GLAD\n");
        return -1;
    }
    GLFWcursor* cursor = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    glfwSetCursor(window, cursor);

    printf("%s\n", glGetString(GL_VERSION));
    unsigned int buffer;
    InitVertexBuffer(&buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    float position[2] = {0.7f, 0.0f};
    unsigned int pixelbuffer = CreatePixel(position);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, pixelbuffer);
        DrawBindedPixel();
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        DrawBindedTriangle();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

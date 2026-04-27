#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* file_to_memory(FILE* file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char* str = malloc(sizeof(char) * (file_size + 1));
    fread(str, sizeof(char), file_size, file);
    str[file_size] = '\0';
    return str;
}

unsigned int CompileShader(unsigned int type, const char* source) {
    unsigned int id = glCreateShader(type);
    const char* src = &source[0];
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int compile_result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compile_result);
    if (compile_result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* buffer = malloc(sizeof(char) * length + 1);
        glGetShaderInfoLog(id, length, &length, buffer);
        printf("Shader compilation failed:\n");
        printf("%s\n", buffer);
        free(buffer);
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static unsigned int CreateShader(const char* vertexShader, const char* fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
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

void MovePixel(unsigned int shaderProgram, float* vec2Pos) {
    int offsetLoc = glGetUniformLocation(shaderProgram, "offset");
    glUniform2f(offsetLoc, vec2Pos[0], vec2Pos[1]);
}

void DrawBindedPixel() {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glDrawArrays(GL_POINTS, 0, 1);
}

int main(void)
{
    srand(time(NULL));
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
    
    FILE* vertexShader;
    FILE* fragmentShader;
    vertexShader = fopen("shaders/defaultV.shader", "r");
    fragmentShader = fopen("shaders/defaultF.shader", "r");
    if (vertexShader == NULL) {
        printf("Unable to open vertex shader file\n");
        return 1;
    }
    if (fragmentShader == NULL) {
        printf("Unable to open fragment shader file\n");
        return 1;
    }
    char* vertexShaderBuf = file_to_memory(vertexShader);
    char* fragmentShaderBuf = file_to_memory(fragmentShader);
    fclose(vertexShader);
    fclose(fragmentShader);

    //glEnableVertexAttribArray(0);
    unsigned int shader = CreateShader(vertexShaderBuf, fragmentShaderBuf);
    glUseProgram(shader);
    float position[2] = {0.0f, 0.0f};
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    float stepX = 2.0f / width;
    float stepY = 2.0f / height;
    unsigned int pixelbuffer = CreatePixel(position);
    int dir;
    int moveToX = 0.0f;
    int moveToY = 0.0f;

    while (!glfwWindowShouldClose(window))
    {        
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0,0,width,height);

        glClear(GL_COLOR_BUFFER_BIT);

        stepX = 2.0f / width;
        stepY = 2.0f / height;
        
        glBindBuffer(GL_ARRAY_BUFFER, pixelbuffer);

        dir = (rand() % 4) + 1;
        switch (dir) {
            case 1:
                moveToX = 1.0f;
                moveToY = 0.0f;
                break;
            case 2:
                moveToX = -1.0f;
                moveToY = 0.0f;
                break;
            case 3:
                moveToX = 0.0f;
                moveToY = 1.0f;
                break;
            default:
                moveToX = 0.0f;
                moveToY = -1.0f;
        }
        position[0] += stepX * 2 * moveToX;
        position[1] += stepX * 2 * moveToY;
        MovePixel(shader, position);
        DrawBindedPixel();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glDeleteShader(shader);

    glfwTerminate();
    return 0;
}

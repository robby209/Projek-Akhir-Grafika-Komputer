#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Lantai.h"
#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>


class Application : public RenderEngine {
public:
    Application();
    ~Application();

    // Fungsi untuk mengatur kecepatan kamera
    void SetCameraSpeed(float speed);
    // Fungsi untuk mengolah input
    void ProcessInput(GLFWwindow* window);

private:
    Shader* shader;

    //kursi/cube
    Texture* cubeDiffTex, * cubeSpecTex;

    //lantai
    Texture* lantaiDiffTex, * lantaiSpecTex;

    //dinding
    Texture* dindingDiffTex, * dindingSpecTex;

    //rak lemari 
    Texture* rakDiffTex, * rakSpecTex;

    //buku
    Texture* bukuDiffTex, * bukuSpecTex;

    //gambar
    Texture* gambarDiffTex, * gambarSpecTex;
    Texture* gambar1DiffTex, * gambar1SpecTex;
    //karpet
    Texture* karpetDiffTex, * karpetSpecTex;
    //jendela
    Texture* jendelaDiffTex, * jendelaSpecTex;
    //lampu
    Texture* lampuDiffTex, * lampuSpecTex;
    //pintu
    Texture* pintuDiffTex, * pintuSpecTex;
   


    //cube
    Cube* cube;
    //lantai
    Lantai* lantai;
    //rak
    Cube* rakk;
    //buku
    Cube* buku;
    //dinding
    Cube* dinding;
    //gambar
    Cube* gambar;
    Cube* gambar1;
    //karpet
    Cube* karpet;
    //jendela
    Cube* jendela;
    //lampu
    Cube* lampu;
    //pintu
    Cube* pintu;

   


    //kamera
    float angle = 0;
    glm::vec3 viewPos; // Posisi kamera
    glm::vec3 viewFront; // Arah pandang kamera
    glm::vec3 viewUp; // Vektor 'up' kamera
    float cameraSpeed = 0.05f; // Kecepatan kamera
    float lastX, lastY; // Posisi terakhir kursor
    float yaw = -90.0f; // Sudut horizontal
    float pitch = 0.0f; // Sudut vertikal
    float deltaTime = 0.0f; // Waktu antara frame terkini dan sebelumnya
    float lastFrame = 0.0f; // Waktu frame terakhir di-render
    bool firstMouse = true;
    // Fungsi untuk mengatur perspektif
    void setupPerspective();

    // Fungsi untuk mengatur kamera
    void setupCamera();

    // Fungsi untuk mengatur pencahayaan
    void setupLighting();

    // Override fungsi dari RenderEngine
    virtual void Init() override;
    virtual void DeInit() override;
    virtual void Update(double deltaTime) override;
    virtual void Render() override;
};

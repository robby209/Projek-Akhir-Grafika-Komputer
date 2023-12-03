#include "Application.h"
#include "Lantai.h"

Application::Application() {
    
}

Application::~Application() {
    
}

void Application::setupPerspective() {
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
    shader->setMat4("projection", projection);
}

void Application::setupCamera() {
    viewPos = glm::vec3(50, 20, 70); 
    viewFront = glm::vec3(0, 0, -1); 
    viewUp = glm::vec3(0, 1, 0);
    glm::mat4 view = glm::lookAt(viewPos, viewPos + viewFront, viewUp);
    shader->setMat4("view", view);
}




void Application::setupLighting() {
    glm::vec3 lightPos = glm::vec3(50, 15, 43);
    shader->setVec3("lightPos", lightPos);
    shader->setVec3("viewPos", viewPos);
    glm::vec3 lightColor = glm::vec3(0.6f, 0.6f, 0.6f);
    shader->setVec3("lightColor", lightColor);
}



void Application::Init() {
    shader = new Shader("texturedCube.vert", "texturedCube.frag");
    shader->Init();
	//cube
    cubeDiffTex = new Texture("lantai.png");
    cubeDiffTex->Init();
    cubeSpecTex = new Texture("");
    cubeSpecTex->Init();

    cube = new Cube(shader, cubeDiffTex, cubeSpecTex);
    cube->Init();
    cube->SetScale(0.5f, 0.5f, 0.5f);

	//tempat perpustakaan
	lantaiDiffTex = new Texture("lantai5.png");
	lantaiDiffTex->Init();
	lantaiSpecTex = new Texture("");
	lantaiSpecTex->Init();
	lantai = new Lantai(shader, lantaiDiffTex, lantaiSpecTex);
	lantai->Init();
	lantai->SetScale(5.0f, 1.0f, 5.0f); 
	//dinding
	dindingDiffTex = new Texture("abuabu.png");
	dindingDiffTex->Init();
	dindingSpecTex = new Texture("");
	dindingSpecTex->Init();
	dinding = new Cube(shader, dindingDiffTex, dindingSpecTex);
	dinding->Init();
	dinding->SetScale(5.0f, 5.0f, 5.0f); 

	//rak buku
	//perpustakaan
	rakDiffTex = new Texture("lantai.png");
	rakDiffTex->Init();
	rakSpecTex = new Texture("");
	rakSpecTex->Init();
	rakk = new Cube(shader, rakDiffTex, rakSpecTex);
	rakk->Init();
	rakk->SetScale(5.0f, 1.0f, 5.0f); // Perbesar lebar dan kedalaman kubus dua kali lipat, tinggi tetap


	//buku
	bukuDiffTex = new Texture("buku.png");
	bukuDiffTex->Init();
	bukuSpecTex = new Texture("");
	bukuSpecTex->Init();
	buku = new Cube(shader, bukuDiffTex, bukuSpecTex);
	buku->Init();
	buku->SetScale(6.0f, 4.0f, 3.0f);

	//gambar 
	gambarDiffTex = new Texture("gambar.png");
	gambarDiffTex->Init();
	gambarSpecTex = new Texture("");
	gambarSpecTex->Init();
	gambar = new Cube(shader, gambarDiffTex, gambarSpecTex);
	gambar->Init();
	gambar->SetScale(4.0f, 5.0f, 0.1f);

	gambar1DiffTex = new Texture("gambar1.png");
	gambar1DiffTex->Init();
	gambar1SpecTex = new Texture("");
	gambar1SpecTex->Init();
	gambar1 = new Cube(shader, gambar1DiffTex, gambar1SpecTex);
	gambar1->Init();
	gambar1->SetScale(4.0f, 5.0f, 0.1f);

	//karpet
	karpetDiffTex = new Texture("hitam.png");
	karpetDiffTex->Init();
	karpetSpecTex = new Texture("");
	karpetSpecTex->Init();

	karpet = new Cube(shader, karpetDiffTex, karpetSpecTex);
	karpet->Init();
	karpet->SetScale(0.5f, 0.01f, 0.5f);

	//jendela
	jendelaDiffTex = new Texture("putih.png");
	jendelaDiffTex->Init();
	jendelaSpecTex = new Texture("");
	jendelaSpecTex->Init();

	jendela = new Cube(shader, jendelaDiffTex, jendelaSpecTex);
	jendela->Init();
	jendela->SetScale(0.5f, 0.5f, 0.5f);

	//lampu
	lampuDiffTex = new Texture("putih.png");
	lampuDiffTex->Init();
	lampuSpecTex = new Texture("");
	lampuSpecTex->Init();

	lampu = new Cube(shader, lampuDiffTex, lampuSpecTex);
	lampu->Init();
	lampu->SetScale(1.0f, 1.0f, 1.0f);
	
    setupPerspective();
    setupCamera();
    setupLighting();

	//pintu
	pintuDiffTex = new Texture("hitam.png");
	pintuDiffTex->Init();
	pintuSpecTex = new Texture("");
	pintuSpecTex->Init();

	pintu = new Cube(shader, pintuDiffTex, pintuSpecTex);
	pintu->Init();
	pintu->SetScale(0.5f, 0.5f, 0.5f);

	setupPerspective();
	setupCamera();
	setupLighting();
}

void Application::DeInit() {
    delete cube;
	delete lantai;
	delete rakk;
	delete buku;
    delete cubeDiffTex;
    delete cubeSpecTex;
    delete shader;
	delete dinding;
	delete gambar;
	delete gambar1;
	delete karpet;
	delete jendela;
	delete lampu;
	delete pintu;
	
}

void Application::Update(double deltaTime) {
    this->deltaTime = deltaTime;
    cube->SetRotation(angle, 0, 1, 0);
	lantai->SetRotation(angle, 0, 1, 0);
	rakk->SetRotation(angle, 0, 1, 0);
	buku->SetRotation(angle, 0, 1, 0);
	dinding->SetRotation(angle, 0, 1, 0);
	gambar->SetRotation(angle, 0, 1, 0);
	gambar1->SetRotation(angle, 0, 1, 0);
	karpet->SetRotation(angle, 0, 1, 0);
	jendela->SetRotation(angle, 0, 1, 0);
	lampu->SetRotation(angle, 0, 1, 0);
	pintu->SetRotation(angle, 0, 1, 0);
}

void Application::Render() {
    glViewport(0, 0, this->screenWidth, this->screenHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(70.0f / 255.0f, 130.0f / 255.0f, 180.0f / 255.0f, 1.0f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    // Update view matrix based on updated camera position
    glm::mat4 view = glm::lookAt(viewPos, viewPos + viewFront, viewUp);
    shader->setMat4("view", view);

    //----------------------------Kursi---------------------------------------
	// Posisi x untuk kaki kursi dan ketebalan kaki kursi
	int xPositions[] = { 0, 1, 10, 11 };

	// Posisi z untuk kedalaman kaki kursi dan ketebalan kaki kursi
	int zPositions[] = { 0, -1, -10, -11 };

	// Tinggi dari dasar hingga bagian atas kaki kursi atau sandaran kursi
	int height = 11; // Tinggi kursi

	// Menggambar kaki kursi vertikal dan penyangga dengan loop bersarang
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x, y, z);
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			if (x == 0 || x == 1 || x == 10 || x == 11 || z == 0 || z == -10) {
				cube->SetPosition(x, height, z); // Menggambar bagian tepi alas kursi
			}
			else {
				cube->SetPosition(x, height, z); // Menggambar bagian tengah alas kursi
			}
			cube->Draw();
		}
	}
	
	// Menggambar penyangga kursi
	int braceHeight = 6; // Tinggi penyangga dari dasar

	// Penyangga antara kaki depan dan belakang pada sisi kiri dan kanan
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0, braceHeight, z);
		cube->Draw();
		cube->SetPosition(1, braceHeight, z);
		cube->Draw();
		cube->SetPosition(10, braceHeight, z);
		cube->Draw();
		cube->SetPosition(11, braceHeight, z);
		cube->Draw();
	}

	// Penyangga antara kaki kiri dan kanan (depan dan belakang)
	for (int x = 0; x <= 11; x++) {
		cube->SetPosition(x, braceHeight, -11);
		cube->Draw();
		cube->SetPosition(x, braceHeight, 0);
		cube->Draw();
	}

	// Tinggi mulai dari dudukan kursi hingga atas untuk sandaran
	int startHeight = 11; // Misalnya, ini adalah tinggi dudukan kursi
	int endHeight = 25;   // Tinggi maksimal untuk sandaran

	// Menambahkan penyangga vertikal di sisi kiri sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0, y, -11); // posisi z = 0 untuk sisi belakang kiri
		cube->Draw();
		cube->SetPosition(1.0f, y, -11); // posisi x = 1.0f untuk sisi belakang kiri
		cube->Draw();
	}

	// Menambahkan penyangga vertikal di sisi kanan sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(10.0f, y, -11); // posisi z = 0 untuk sisi belakang kanan
		cube->Draw();
		cube->SetPosition(11.0f, y, -11); // posisi x = 11.0f untuk sisi belakang kanan
		cube->Draw();
	}
	// Menambahkan penyangga horizontal di bagian atas belakang sandaran kursi
	int numberOfBraces = 7; // Jumlah penyangga yang diinginkan

	// Kita asumsikan penyangga teratas berada tepat di bawah endHeight
	int topBraceHeight = endHeight ; // Mengurangi 1 untuk memastikan penyangga tidak melebihi batas

	// Menggambar penyangga dari atas ke bawah tanpa jarak di antaranya
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i; // Mulai dari atas dan turun untuk setiap penyangga
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x, currentHeight, -11); // posisi z = -11 berarti di bagian belakang
			cube->Draw();
			
		}
	}
	//--------------------------------kursi 2

	//-----------------------------------------------
	// Menambahkan offset 15 unit untuk kursi kedua
	int xOffset = 15;

	// Menggambar kaki kursi vertikal dan penyangga dengan loop bersarang untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z); // Menggeser posisi x dengan xOffset
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z); // Menggeser posisi x dengan xOffset
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z); // Menggeser posisi x dengan xOffset
		cube->Draw();
	}

	for (int x = 0; x <= 11; x++) {
		cube->SetPosition(x + xOffset, braceHeight, -11); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(x + xOffset, braceHeight, 0); // Menggeser posisi x dengan xOffset
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, -11); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, -11); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, -11); // Menggeser posisi x dengan xOffset
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, -11); // Menggeser posisi x dengan xOffset
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, -11); // Menggeser posisi x dengan xOffset
			cube->Draw();
		}
	}
	//-----------------------------------------------Meja------------------------------------------------
// Posisi x untuk keempat kaki meja
	int tableLegPositionsX[] = { 3, 25 }; 

	// Posisi z untuk kaki meja
	int tableLegPositionsZ[] = { 6, 20 }; 

	// Tinggi dari dasar hingga bagian atas kaki meja
	int tableHeight = 10; // Tinggi kaki meja, ditingkatkan

	// Ukuran atas meja
	int tableTopLength = 24; // Panjang atas meja, dua kali lipat
	int tableTopWidth = 16;  // Lebar atas meja, dua kali lipat
	int tableTopHeight = 1; // Ketebalan atas meja

	// Menggambar kaki meja dengan loop bersarang
	for (int x : tableLegPositionsX) {
		for (int z : tableLegPositionsZ) {
			for (int y = 0; y < tableHeight; y++) {
				cube->SetPosition(x, y, z);
				cube->Draw();
			}
		}
	}

	// Menggambar atas meja
	for (int x = 2; x <= 2 + tableTopLength; x++) {
		for (int z = 5; z <= 5 + tableTopWidth; z++) {
			for (int y = tableHeight; y < tableHeight + tableTopHeight; y++) {
				cube->SetPosition(x, y, z);
				cube->Draw();
			}
		}
	}

	//-------------------------kursi
	int zOffsetKursiKedua = 37; // Menggeser kursi kedua 20 unit maju

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z + zOffsetKursiKedua); // Menggeser posisi z maju
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z + zOffsetKursiKedua); // Menggeser posisi z maju
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, 0 + zOffsetKursiKedua);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, 0 + zOffsetKursiKedua);
			cube->Draw();
		}
	}

	//kursi 4
	int xOffsetKiri = -14; // Menggeser kursi ke kiri sebanyak 5 unit

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset + xOffsetKiri, y, z + zOffsetKursiKedua); // Menggeser posisi x ke kiri
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset + xOffsetKiri, height, z + zOffsetKursiKedua); // Menggeser posisi x ke kiri
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset + xOffsetKiri, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(1 + xOffset + xOffsetKiri, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(10 + xOffset + xOffsetKiri, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(11 + xOffset + xOffsetKiri, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset + xOffsetKiri, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(1 + xOffset + xOffsetKiri, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(10 + xOffset + xOffsetKiri, y, 0 + zOffsetKursiKedua);
		cube->Draw();
		cube->SetPosition(11 + xOffset + xOffsetKiri, y, 0 + zOffsetKursiKedua);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset + xOffsetKiri, currentHeight, 0 + zOffsetKursiKedua);
			cube->Draw();
		}
	}

	//------------------------------------------tengah 
	//kursi5
	int zOffsetBelakang = 70; // Menggeser kursi 50 unit ke belakang

	// Menggambar kaki kursi vertikal dan penyangga
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x, height, z + zOffsetBelakang); // Menggeser posisi z ke belakang
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0, braceHeight, z + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(1, braceHeight, z + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(10, braceHeight, z + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(11, braceHeight, z + zOffsetBelakang);
		cube->Draw();
	}

	// Menggambar sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0, y, -11 + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(1.0f, y, -11 + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(10.0f, y, -11 + zOffsetBelakang);
		cube->Draw();
		cube->SetPosition(11.0f, y, -11 + zOffsetBelakang);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x, currentHeight, -11 + zOffsetBelakang);
			cube->Draw();
		}
	}
	//kursi 6
	int zOffsetKursiKedua1 = 70; // Menggeser kursi kedua 20 unit maju

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z + zOffsetKursiKedua1); // Menggeser posisi z maju
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z + zOffsetKursiKedua1); // Menggeser posisi z maju
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z + zOffsetKursiKedua);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, -11 + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, -11 + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, -11 + zOffsetKursiKedua1);
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, -11 + zOffsetKursiKedua1);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, -11 + zOffsetKursiKedua1);
			cube->Draw();
		}
	}
	//meja2
	
	for (int x : tableLegPositionsX) {
		for (int z : tableLegPositionsZ) {
			for (int y = 0; y < tableHeight; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar atas meja
	for (int x = 2; x <= 2 + tableTopLength; x++) {
		for (int z = 5; z <= 5 + tableTopWidth; z++) {
			for (int y = tableHeight; y < tableHeight + tableTopHeight; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}
	//kursi 7
	int zOffsetKursiKedua2 = 108; // Menggeser kursi kedua 20 unit maju

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z + zOffsetKursiKedua2); // Menggeser posisi z maju
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z + zOffsetKursiKedua2); // Menggeser posisi z maju
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z + zOffsetKursiKedua2);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, 0 + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, 0 + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, 0 + zOffsetKursiKedua2);
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, 0 + zOffsetKursiKedua2);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, 0 + zOffsetKursiKedua2);
			cube->Draw();
		}
	}

	//kursi 8
	int zOffsetBelakang0 = 108; // Menggeser kursi 50 unit ke belakang

	// Menggambar kaki kursi vertikal dan penyangga
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang0); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x, height, z + zOffsetBelakang0); // Menggeser posisi z ke belakang
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0, braceHeight, z + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(1, braceHeight, z + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(10, braceHeight, z + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(11, braceHeight, z + zOffsetBelakang);
		cube->Draw();
	}

	// Menggambar sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0, y, 0 + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(1.0f, y,0 + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(10.0f, y, 0 + zOffsetBelakang0);
		cube->Draw();
		cube->SetPosition(11.0f, y, 0 + zOffsetBelakang0);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x, currentHeight, 0 + zOffsetBelakang0);
			cube->Draw();
		}
	}

	//belakang
	//kursi9
	int zOffsetBelakang1 = 130; // Menggeser kursi 50 unit ke belakang

	// Menggambar kaki kursi vertikal dan penyangga
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang1); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x, height, z + zOffsetBelakang1); // Menggeser posisi z ke belakang
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0, braceHeight, z + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(1, braceHeight, z + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(10, braceHeight, z + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(11, braceHeight, z + zOffsetBelakang1);
		cube->Draw();
	}

	// Menggambar sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0, y, -11 + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(1.0f, y, -11 + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(10.0f, y, -11 + zOffsetBelakang1);
		cube->Draw();
		cube->SetPosition(11.0f, y, -11 + zOffsetBelakang);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x, currentHeight, -11 + zOffsetBelakang1);
			cube->Draw();
		}
	}
	//belakang
	//kursi 10
	int zOffsetKursiKedua5 = 130; // Menggeser kursi kedua 20 unit maju

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z + zOffsetKursiKedua5); // Menggeser posisi z maju
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z + zOffsetKursiKedua5); // Menggeser posisi z maju
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z + zOffsetKursiKedua5);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, -11 + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, -11 + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, -11 + zOffsetKursiKedua5);
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, -11 + zOffsetKursiKedua5);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, -11 + zOffsetKursiKedua5);
			cube->Draw();
		}
	}
	//meja3

	for (int x : tableLegPositionsX) {
		for (int z : tableLegPositionsZ) {
			for (int y = 0; y < tableHeight; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang1); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar atas meja
	for (int x = 2; x <= 2 + tableTopLength; x++) {
		for (int z = 5; z <= 5 + tableTopWidth; z++) {
			for (int y = tableHeight; y < tableHeight + tableTopHeight; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang1); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}
	//kursi 11
	int zOffsetKursiKedua4 = 170; // Menggeser kursi kedua 20 unit maju

	// Menggambar kaki kursi vertikal dan penyangga untuk kursi kedua
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x + xOffset, y, z + zOffsetKursiKedua4); // Menggeser posisi z maju
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi untuk kursi kedua
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x + xOffset, height, z + zOffsetKursiKedua4); // Menggeser posisi z maju
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi untuk kursi kedua
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0 + xOffset, braceHeight, z + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(1 + xOffset, braceHeight, z + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(10 + xOffset, braceHeight, z + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(11 + xOffset, braceHeight, z + zOffsetKursiKedua4);
		cube->Draw();
	}

	// Menggambar sandaran kursi untuk kursi kedua
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0 + xOffset, y, 0 + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(1 + xOffset, y, 0 + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(10 + xOffset, y, 0 + zOffsetKursiKedua4);
		cube->Draw();
		cube->SetPosition(11 + xOffset, y, 0 + zOffsetKursiKedua4);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi untuk kursi kedua
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x + xOffset, currentHeight, 0 + zOffsetKursiKedua4);
			cube->Draw();
		}
	}

	//kursi 12
	int zOffsetBelakang2 = 170; // Menggeser kursi 50 unit ke belakang

	// Menggambar kaki kursi vertikal dan penyangga
	for (int x : xPositions) {
		for (int z : zPositions) {
			for (int y = 0; y < height; y++) {
				cube->SetPosition(x, y, z + zOffsetBelakang2); // Menggeser posisi z ke belakang
				cube->Draw();
			}
		}
	}

	// Menggambar alas kursi
	for (int x = 0; x <= 11; x++) {
		for (int z = -11; z <= 0; z++) {
			cube->SetPosition(x, height, z + zOffsetBelakang2); // Menggeser posisi z ke belakang
			cube->Draw();
		}
	}

	// Menggambar penyangga kursi
	for (int z = -10; z <= 0; z++) {
		cube->SetPosition(0, braceHeight, z + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(1, braceHeight, z + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(10, braceHeight, z + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(11, braceHeight, z + zOffsetBelakang2);
		cube->Draw();
	}

	// Menggambar sandaran kursi
	for (int y = startHeight; y <= endHeight; y++) {
		cube->SetPosition(0, y, 0 + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(1.0f, y, 0 + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(10.0f, y, 0 + zOffsetBelakang2);
		cube->Draw();
		cube->SetPosition(11.0f, y, 0 + zOffsetBelakang2);
		cube->Draw();
	}

	// Menggambar penyangga horizontal di bagian atas belakang sandaran kursi
	for (int i = 0; i < numberOfBraces; i++) {
		int currentHeight = topBraceHeight - i;
		for (int x = 2; x <= 9; x++) {
			cube->SetPosition(x, currentHeight, 0 + zOffsetBelakang2);
			cube->Draw();
		}
	}
	//------------------------------------------------Lantai----------------------------------------------------
	int tinggiLantai = -1;
	int ukuranLantai = 22;
	int geserKanan = 10;
	int geserKiri = 0;
	int geserDepan = 8;

	for (int x = (-ukuranLantai / 2) + geserKanan - geserKiri; x <= (ukuranLantai / 2) + geserKanan - geserKiri; x++) {
		for (int z = (-ukuranLantai / 2) + geserDepan; z <= (ukuranLantai / 2) + geserDepan; z++) {
			lantai->SetPosition(x, tinggiLantai, z);
			lantai->Draw();
		}
	}

	int tinggiDinding = 7;
	int minX = (-ukuranLantai / 2) + geserKanan;
	int maxX = (ukuranLantai / 2) + geserKanan;
	int minZ = (-ukuranLantai / 2) + geserDepan;
	int maxZ = (ukuranLantai / 2) + geserDepan;

	//atap
	int tinggiAtap = tinggiDinding;
	for (int x = minX; x <= maxX; x++) {
		for (int z = minZ; z <= maxZ; z++) {
			dinding->SetPosition(x, tinggiAtap, z);
			dinding->Draw();
		}
	}
	//belakang
	for (int x = minX; x <= maxX; x++) {
		for (int y = 0; y < tinggiDinding; y++) {
			dinding->SetPosition(x, y, maxZ);
			dinding->Draw();
		}
	}
	//depan
	for (int x = minX; x <= maxX; x++) {
		for (int y = 0; y < tinggiDinding; y++) {
			dinding->SetPosition(x, y, minZ);
			dinding->Draw();
		}
	}
	//kiri dinding
	
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(-1, 0, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(-1, 1, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(-1, 2, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(-1, 5, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(-1, 6, i * 1.0f);
		dinding->Draw();
	}
					//jendela
	for (int i = -2; i < 4; i++) {
		dinding->SetPosition(-1, 3, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 6; i < 11; i++) {
		dinding->SetPosition(-1, 3, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 13; i < 20; i++) {
		dinding->SetPosition(-1, 3, i * 1.0f);
		dinding->Draw();

	}
	//                    b2
	for (int i = -2; i < 4; i++) {
		dinding->SetPosition(-1, 4, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 6; i < 11; i++) {
		dinding->SetPosition(-1, 4, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 13; i < 20; i++) {
		dinding->SetPosition(-1, 4, i * 1.0f);
		dinding->Draw();

	}
	//kubus jendela
	for (int i = -10; i < 150; i++) {
		jendela->SetPosition(-10,35, i * 1.0f);
		jendela->Draw();
	}

	for (int i = -10; i < 65; i++) {
		jendela->SetPosition(-10, i * 1.0f,115);
		jendela->Draw();
	}
	for (int i = -10; i < 65; i++) {
		jendela->SetPosition(-10, i * 1.0f, 45);
		jendela->Draw();
	}

	//kanan dinding
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(21, 4, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(21, 5, i * 1.0f);
		dinding->Draw();
	}
	for (int i = -2; i < 20; i++) {
		dinding->SetPosition(21, 6, i * 1.0f);
		dinding->Draw();
	}
	//pintu
	for (int i = -2; i < 11; i++) {
		dinding->SetPosition(21, 3, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 15; i < 20; i++) {
		dinding->SetPosition(21, 3, i * 1.0f);
		dinding->Draw();

	}
	//                    p2
	for (int i = -2; i < 11; i++) {
		dinding->SetPosition(21, 2, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 15; i < 20; i++) {
		dinding->SetPosition(21, 2, i * 1.0f);
		dinding->Draw();

	}
	//                  p1
	for (int i = -2; i < 11; i++) {
		dinding->SetPosition(21, 1, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 15; i < 20; i++) {
		dinding->SetPosition(21, 1, i * 1.0f);
		dinding->Draw();

	}
	//               p0
	for (int i = -2; i < 11; i++) {
		dinding->SetPosition(21, 0, i * 1.0f);
		dinding->Draw();
	}
	for (int i = 15; i < 20; i++) {
		dinding->SetPosition(21, 0, i * 1.0f);
		dinding->Draw();

	}
	//kubus pintu
	for (int i = 15; i < 150; i++) {
		pintu->SetPosition(210, 35, i * 1.0f);
		pintu->Draw();
	}
	for (int i = 15; i < 150; i++) {
		pintu->SetPosition(210, 34, i * 1.0f);
		pintu->Draw();
	}

	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 105);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 106);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 145);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 144);
		pintu->Draw();
	}


	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 125);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 124);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 126);
		pintu->Draw();
	}
	for (int i = -1; i < 150; i++) {
		pintu->SetPosition(210, i * 1.0f, 123);
		pintu->Draw();
	}
	//gagang
	for (int i = 17; i < 19; i++) {
		jendela->SetPosition(209, i * 1.0f, 124);
		jendela->Draw();
	}
	for (int i = 17; i < 19; i++) {
		jendela->SetPosition(209, i * 1.0f, 125);
		jendela->Draw();
	}

	
	//==-==============================lemari buku===========================
	int tinggiRak = 4; // Tinggi setiap rak
	int lebarRak = 5; // Lebar setiap rak
	int kedalamanRak = 1; // Kedalaman setiap rak
	int jumlahRak = 4; // Jumlah rak dalam satu unit rak buku
	int jarakAntarRak = 1; // Jarak antara rak

	int posisiAwalRakX = 2; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakZ = -1; // Posisi awal rak buku pada sumbu z
	int jarakAntarUnitRak = 2; // Jarak antara unit rak buku

	// Menggeser posisi awal rak buku ke kanan
	int penambahanGeserKeKanan = 5; // Tambahkan ini untuk menggeser rak ke kanan
	posisiAwalRakX += penambahanGeserKeKanan;

	// Menggambar unit rak buku
	for (int unitRak = 0; unitRak < 2; unitRak++) {
		int posisiRakSaatIniX = posisiAwalRakX + (lebarRak + jarakAntarUnitRak) * unitRak;

		for (int rak = 0; rak < jumlahRak; rak++) {
			int posisiRakSaatIniY = tinggiLantai + 1 + (tinggiRak + jarakAntarRak) * rak;

			// Menggambar rak buku
			for (int x = 0; x < lebarRak; x++) {
				for (int z = 0; z < kedalamanRak; z++) {
					rakk->SetPosition(posisiRakSaatIniX + x, posisiRakSaatIniY, posisiAwalRakZ + z);
					rakk->Draw();
				}
			}
		}
	}

	
	//rak pojok
	int posisiAwalRakBukuX11 = 65; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakBukuZ11 = -5; // Posisi awal rak buku pertama pada sumbu z
	int tinggiTumpukan = 34;  // Tinggi tumpukan kubus

	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ11 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan; y++) {
			cube->SetPosition(posisiAwalRakBukuX11, y, posisiZSaatIni);
			cube->Draw();
		}
	}
	// Rak pojok 2
	int posisiAwalRakBukuX2 = 115; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakBukuZ2 = -5; // Posisi awal rak buku pertama pada sumbu z
	int tinggiTumpukan2 = 34;  // Tinggi tumpukan kubus

	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ2 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan2; y++) {
			cube->SetPosition(posisiAwalRakBukuX2, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 3
	int posisiAwalRakBukuX3 = 135; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakBukuZ3 = -5; // Posisi awal rak buku pertama pada sumbu z
	int tinggiTumpukan3 = 34;  // Tinggi tumpukan kubus

	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ3 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan3; y++) {
			cube->SetPosition(posisiAwalRakBukuX3, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 4
	int posisiAwalRakBukuX4 = 185; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakBukuZ4 = -5; // Posisi awal rak buku pertama pada sumbu z
	int tinggiTumpukan4 = 34;  // Tinggi tumpukan kubus

	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ4 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan4; y++) {
			cube->SetPosition(posisiAwalRakBukuX4, y, posisiZSaatIni);
			cube->Draw();
		}
	}



	//--------------------------buku
	//buku 1 lt 3
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(6,3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(7, 3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(8, 3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(9, 3.1, -1.7);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(6, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(7, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(8, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(9, 1.9, -1.7);
		buku->Draw();
	}
	//buku 1 lt 1
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(6, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(7, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(8, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(9, 0.6, -1.7);
		buku->Draw();
	}


	//rak2

	//buku 1 lt 3
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(11.8, 3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(12.8, 3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(13.8, 3.1, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(14.8, 3.1, -1.7);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(11.8, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(12.8, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(13.8, 1.9, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(14.8, 1.9, -1.7);
		buku->Draw();
	}
	//buku 1 lt 1
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(11.8, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(12.8, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(13.8, 0.6, -1.7);
		buku->Draw();
	}
	for (int i = 0; i < 1; i++) {
		buku->SetPosition(14.8, 0.6, -1.7);
		buku->Draw();
	}

	//lemari baris 2
	// Menggambar unit rak buku
	for (int unitRak = 0; unitRak < 2; unitRak++) {
		int posisiRakSaatIniX = 7 + (lebarRak + jarakAntarUnitRak) * unitRak;

		for (int rak = 0; rak < jumlahRak; rak++) {
			int posisiRakSaatIniY = tinggiLantai + 1 + (tinggiRak + jarakAntarRak) * rak;

			// Menggambar rak buku
			for (int x = 0; x < lebarRak; x++) {
				for (int z = 0; z < kedalamanRak; z++) {
					rakk->SetPosition(posisiRakSaatIniX + x, posisiRakSaatIniY, 2.4 + z);
					rakk->Draw();
				}
			}
		}
	}
	//pojok rak
	//rak pojok
	int posisiAwalRakBukuX111 = 65; // Posisi awal rak buku pada sumbu x
	int posisiAwalRakBukuZ111 = 29; // Posisi awal rak buku pertama pada sumbu z
	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan; y++) {
			cube->SetPosition(posisiAwalRakBukuX111, y, posisiZSaatIni);
			cube->Draw();
		}
	}
	// Rak pojok 2
	int posisiAwalRakBukuX21 = 115; // Posisi awal rak buku pada sumbu x
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan2; y++) {
			cube->SetPosition(posisiAwalRakBukuX21, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 3
	int posisiAwalRakBukuX31 = 135; // Posisi awal rak buku pada sumbu x
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan3; y++) {
			cube->SetPosition(posisiAwalRakBukuX31, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 4
	int posisiAwalRakBukuX41 = 185; // Posisi awal rak buku pada sumbu x
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan4; y++) {
			cube->SetPosition(posisiAwalRakBukuX41, y, posisiZSaatIni);
			cube->Draw();
		}
	}
	//buku2
	int bukuZ = 4;
	//buku 1 lt 3
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6 + i, 3.1, bukuZ);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6+i, 1.9, bukuZ);
		buku->Draw();
	}
	
	//buku 1 lt 1
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6+i, 0.6, bukuZ);
		buku->Draw();
	}
	
	//rak2

	//buku 1 lt 3
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8+i, 3.1, bukuZ);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8+i, 1.9, bukuZ);
		buku->Draw();
	}
	//buku 1 lt 1
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8+i, 0.6, bukuZ);
		buku->Draw();
	}

	//--lemari baris 3
	// Menggambar unit rak buku
	for (int unitRak = 0; unitRak < 2; unitRak++) {
		int posisiRakSaatIniX = 7 + (lebarRak + jarakAntarUnitRak) * unitRak;

		for (int rak = 0; rak < jumlahRak; rak++) {
			int posisiRakSaatIniY = tinggiLantai + 1 + (tinggiRak + jarakAntarRak) * rak;

			// Menggambar rak buku
			for (int x = 0; x < lebarRak; x++) {
				for (int z = 0; z < kedalamanRak; z++) {
					rakk->SetPosition(posisiRakSaatIniX + x, posisiRakSaatIniY, 6 + z);
					rakk->Draw();
				}
			}
		}
	}
	//buku3
	int bukuZ1 = 10;
	//buku 1 lt 3
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6 + i, 3.1, bukuZ1);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6 + i, 1.9, bukuZ1);
		buku->Draw();
	}

	//buku 1 lt 1
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(6 + i, 0.6, bukuZ1);
		buku->Draw();
	}

	//rak2

	//buku 1 lt 3
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8 + i, 3.1, bukuZ1);
		buku->Draw();
	}
	//buku 1 lt 2
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8 + i, 1.9, bukuZ1);
		buku->Draw();
	}
	//buku 1 lt 1
	for (int i = 0; i < 4; i++) {
		buku->SetPosition(11.8 + i, 0.6, bukuZ1);
		buku->Draw();
	}
	//gambar
	for (int i = 0; i < 1; i++) {
		gambar->SetPosition(6.0, 4.3, -120.0);
		gambar->Draw();
	}
	for (int i = 0; i < 1; i++) {
		gambar1->SetPosition(7.0, 4.3, -120.0);
		gambar1->Draw();
	}

	int posisiAwalRakBukuZ1111 = 65; // Posisi awal rak buku pertama pada sumbu z
	// Menggambar tiga tumpukan kubus ke belakang tanpa jarak antar kubus
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ1111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan; y++) {
			cube->SetPosition(posisiAwalRakBukuX111, y, posisiZSaatIni);
			cube->Draw();
		}
	}
	// Rak pojok 2
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ1111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan2; y++) {
			cube->SetPosition(posisiAwalRakBukuX21, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 3
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ1111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan3; y++) {
			cube->SetPosition(posisiAwalRakBukuX31, y, posisiZSaatIni);
			cube->Draw();
		}
	}

	// Rak pojok 4
	for (int nomorTumpukan = 0; nomorTumpukan < 11; nomorTumpukan++) {
		int posisiZSaatIni = posisiAwalRakBukuZ1111 - nomorTumpukan;

		for (int y = 0; y < tinggiTumpukan4; y++) {
			cube->SetPosition(posisiAwalRakBukuX41, y, posisiZSaatIni);
			cube->Draw();
		}
	}
	//karpet
	// Variabel posisi awal karpet
	int posisiAwalX = 70; // Posisi awal X karpet
	int posisiAwalZ = 100; // Posisi awal Z karpet

	// Ukuran karpet
	int lebarKarpet = 80; // Lebar karpet
	int panjangKarpet = 80; // Panjang karpet

	// Menggambar karpet 100x100
	for (int x = 0; x < lebarKarpet; x++) {
		for (int z = 0; z < panjangKarpet; z++) {
			karpet->SetPosition(posisiAwalX + x, -50, posisiAwalZ + z);
			karpet->Draw();
		}
	}
	//meja karpet
	float xmeja = 90; // Ganti dengan nilai X yang diinginkan

	for (int x : tableLegPositionsX) {
		for (int z : tableLegPositionsZ) {
			for (int y = 0; y < tableHeight; y++) {
				cube->SetPosition(x + xmeja, y-5, z + zOffsetBelakang1); // Menggeser posisi z ke belakang dan x
				cube->Draw();
			}
		}
	}

	// Menggambar atas meja
	for (int x = 2; x <= 2 + tableTopLength; x++) {
		for (int z = 5; z <= 5 + tableTopWidth; z++) {
			for (int y = tableHeight; y < tableHeight + tableTopHeight; y++) {
				cube->SetPosition(x + xmeja, y-5, z + zOffsetBelakang1); // Menggeser posisi z ke belakang dan x
				cube->Draw();
			}
		}
	}


	//kubus lampu
	
	for (int i = 0; i < 3; i++) {
		lampu->SetPosition(50, 31+i, 44);
		lampu->Draw();
	}

	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46+i,30, 44);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 45);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 46);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 43);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 42);
		lampu->Draw();
	}

	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 46);
		lampu->Draw();
	}

	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 41);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 40);
		lampu->Draw();
	}
	for (int i = 0; i < 9; i++) {
		lampu->SetPosition(46 + i, 30, 47);
		lampu->Draw();
	}
	
    glDisable(GL_DEPTH_TEST);
}

void Application::ProcessInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 0.01f * this->deltaTime;  // Sesuaikan kecepatan kamera
	float rotationSpeed = 5.0f;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += cameraSpeed * viewFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= cameraSpeed * viewFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(viewFront, viewUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(viewFront, viewUp)) * cameraSpeed;

	// Kontrol untuk gerakan vertikal dengan tombol E dan Q
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		viewPos += cameraSpeed * viewUp; // Bergerak ke atas
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		viewPos -= cameraSpeed * viewUp; // Bergerak ke bawah
	// Rotasi kamera
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		pitch += rotationSpeed;
		if (pitch > 89.0f) pitch = 89.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		pitch -= rotationSpeed;
		if (pitch < -89.0f) pitch = -89.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		yaw -= rotationSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		yaw += rotationSpeed;
	}

	// Memperbarui viewFront berdasarkan yaw dan pitch yang baru
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	viewFront = glm::normalize(front);
}




int main(int argc, char** argv) {
    Application app;
    app.Start("Cube Example", 800, 600, false, false);
    return 0;
}

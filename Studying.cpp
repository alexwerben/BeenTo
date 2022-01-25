#include "declarations.h"

#include "shader.hpp"


mat4 myMatrix;
vec4 myVector;
vec4 transformedVector = myMatrix * myVector;

void test()
{
	//const string input = "ABC:1->   PQR:2;;;   XYZ:3<<<"s;
	string input ("[123,1");
	//const regex r(R"((\w+):(\w+);)");
	const regex r("([0-9])");
	smatch m;

	while (regex_search(input, m, r)) 
	{
		 cout << m[0] << endl;

		 input = m.suffix();
	}
	return;
}

int main()
{
	//Contour contours = GetContours();

	//ofstream fout;
	//fout.open("data.txt");
	//for (int i = 0; i < contours.size(); ++i)
	//{
	//	fout << contours[i] << endl;
	//}
	//fout.close();

	//test();

	GetVerticesFromFile();

	//OpenGL();

	return 0;
}

int OpenGL()
{
	if (!glfwInit())
	{
		cout << "glfwInit error" << endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x Сглаживание
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Мы хотим использовать OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	// Open a window and create its OpenGL context
	GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity)
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);			
	
	// Initialize GLEW
	glewExperimental = true;								// Needed in core profile
	if (glewInit() != GLEW_OK) 
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data_triangle[] =
	{
		-1.0f,-1.0f, 1.0f, // triangle 1 : begin
		 1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		-1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		-1.0f, -1.0f, -1.0f
	};

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	static const GLfloat g_color_buffer_data[] = {
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
	};

	static GLfloat g_color_buffer_data_triangle[4 * 3 * 3];
	for (int i = 0; i < 4 * 3 * 3; ++i)
	{
		g_color_buffer_data_triangle[i] = (float) rand() / RAND_MAX;
	}

	// Identify buffers
	GLuint vertexbuffer;
	GLuint vertexbuffertriangle;
	GLuint colorbuffer;
	GLuint colorbuffertriangle;

	// Create 1 buffer and put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	glGenBuffers(1, &vertexbuffertriangle);
	glGenBuffers(1, &colorbuffer);
	glGenBuffers(1, &colorbuffertriangle);

	// Make the created buffer current
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Send information about vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, colorbuffertriangle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_triangle), g_color_buffer_data_triangle, GL_STATIC_DRAW);

	// Make the created buffer current and send information about vertices to OpenGL
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffertriangle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_triangle), g_vertex_buffer_data_triangle, GL_STATIC_DRAW);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)4 / (float)3, 0.1f, 100.0f);

	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(3, 3, 8), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	glm::mat4 Viewtriangle = glm::lookAt(
		glm::vec3(0, 0, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	// Model matrix : an identity matrix (model will be at the origin)
	//glm::mat4 Model = glm::mat4(0.1f);
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 Modeltriangle = glm::translate(glm::mat4(1.0f), glm::vec3(-4.0f, 0, 0));

	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 mvp = Projection * View * Model; // Remember, matrix multiplication is the other way around
	glm::mat4 mvptriangle = Projection * View * Modeltriangle;

	// Get a handle for our "MVP" uniform
	// Only during the initialisation
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	do
	{
		// Send our transformation to the currently bound shader, in the "MVP" uniform
		// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		// 1st attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 36); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvptriangle[0][0]);

		//vertices of mytriangle
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffertriangle);
		glVertexAttribPointer(
			0,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);

		//colors of vertices of mytriangle
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffertriangle);
		glVertexAttribPointer(
			1,
			3,
			GL_FLOAT,
			GL_FALSE,
			0,
			(void*)0
		);
		for (int i = 0; i < 4 * 3 * 3; ++i)
		{
			g_color_buffer_data_triangle[i] = (float)rand() / RAND_MAX;
		}
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_triangle), g_color_buffer_data_triangle, GL_STATIC_DRAW);


		glDrawArrays(GL_TRIANGLES, 0, 12);
		glDisableVertexAttribArray(0);

		// Reset buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if Escape KEY is pressed or window is closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

Contour GetContours()
{
	RNG rng(12345);							// Random seed

	string imgPath = samples::findFile("Data/map.jpg");
	Mat img = imread(imgPath, IMREAD_COLOR);

	Mat grayImg;							// Gray version of image	
	Contour contours;						// Contours
	vector<Vec4i> hierarchy;				// Hierarchy of contours

	// Convert colored RGB image to gray (black-and-white) image
	cvtColor(img, grayImg, COLOR_BGR2GRAY);					

	// Thresholding image (0 - balck, 255 - white)
	// 1 arg - input 2D array
	// 2 arg - output 2D array
	// 3 arg - threshold value (if input(x,y) > 3_arg => output(x,y) = 255)
	// 4 arg - max value to use THRESH_BINARY or THRESH_BINARY_INV
	threshold(grayImg, grayImg, 240, 255, THRESH_BINARY);

	// Finding contours in image
	findContours(grayImg, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	
	Mat drawing = Mat::zeros(grayImg.size(), CV_8UC3);

	for (size_t i = 0; i < contours.size(); ++i)
	{
		Scalar color = Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
		drawContours(img, contours, (int)i, color, FILLED, LINE_4, hierarchy, 1);
	}

	cout << "contours " << contours.size() << endl;

	waitKey();

	return contours;
}

void GetVerticesFromFile()
{
	// Get 3D vertices from file where X,Y coords of vertices are presented
	FILE* pFile;
	char buffer[100];
	float* data = (float*)malloc(sizeof(float) * 39 * 3);
	int index = 0;

	pFile = fopen("data.txt", "r");
	
	regex r(R"([0-9]+)");
	smatch m;

	if (pFile == NULL) perror("Error opening file");
	else
	{
		while (!feof(pFile))
		{
			fgets(buffer, 100, pFile);

			//for (int i = 0; buffer[i] != '\n'; ++i)
			//{
			//	if (buffer[i] == ']')
			//		break;
			//}
			// Process each string to get numbers from there

			string s;
			
			FromCharArrayToStr(s, buffer);

			while (regex_search(s, m, r))
			{
				float num = stof(m[0]);
				data[index++] = num;
				s = m.suffix();
			}
			data[index++] = 0.0f;
			if (index == 39 * 3) break;
		}
		fclose(pFile);
	}
	for (int i = 0; i < 39; ++i)
		cout << data[i*3 + 0] << ' ' << data[i*3 + 1] << ' ' << data[i*3 + 2] << endl;
}

void FromCharArrayToStr(string& str, char* arr)
{
	for (int i = 0; arr[i] != '\n' && arr[i] != NULL; ++i)
	{
		str.push_back(arr[i]);
	}
	return;
}
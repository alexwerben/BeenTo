#pragma once

// Classic C/C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <regex>

// OpenCV headers
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

// OpenGL headers
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>		// GLM GTC matrix transform functions
#include <glm/gtx/transform.hpp>

using namespace std;			// Default namespace
using namespace cv;				// OpenCV namespace
using namespace glm;			// glm namespace


typedef std::vector<std::vector<cv::Point>> Contour;

Contour GetContours();
int OpenGL();
void GetVerticesFromFile();
void FromCharArrayToStr(string& str, char* arr);
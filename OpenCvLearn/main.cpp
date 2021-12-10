#include<iostream>
#include<stdlib.h>
#include<stdio.h>

//opencv
#include<opencv2\objdetect.hpp>
#include<opencv2\imgproc.hpp>
#include<opencv2\highgui.hpp>
#include "opencv2\core.hpp"
#include <opencv2\core.hpp>
//#include <opencv2\opencv.hpp>

#include "opencv2\face.hpp"

//file handling
#include <fstream>
#include <sstream>

#include "FaceRec.h"


using namespace std;
using namespace cv;
using namespace cv::face;

int main()
{
	string line;
	ifstream fin;
	int choice;
	int loop = 1;
	
	while (loop == 1)
	{
		cout << "1. Security mode\n";
		cout << "2. Add Face\n";
		cout << "3. See previous details\n";
		cout << "4. Exit\n";
		cout << "Choose One: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			FaceRecognition();
			break;
		case 2:
			addFace();
			eigenFaceTrainer();
			break;
		case 3:

			fin.open("Resources/FaceSaved.csv");
			while (fin) {
				getline(fin, line);
				cout << line << endl;
			}
			fin.close();
			break;
		case 4:
			loop = 0;
			break;
		default:
			cout<<"please enter valid option\n";
		}
	}
	return 0;
}
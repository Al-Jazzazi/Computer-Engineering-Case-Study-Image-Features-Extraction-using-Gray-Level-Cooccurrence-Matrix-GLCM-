/*
Name: Yousef Al-Jazzazi
netID: ya2225
Asssignment 2 for CPE class with prof. Mohammad Eid
Date: November 13th 2022
Project name:  Computer Engineering Case Study � Image Features Extraction using Gray Level Cooccurrence Matrix (GLCM)
Description: The program takes a file that contains the pixel information of an image and use changes it to Gray level coocurrence Matrix 
to find some of the features of the image

*/

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


//Initilizing functions: 

void createMatrix(int** GLCM, int** image, int rows, int columns);
void createNormalized(int** GLCM, double** normalized, int max);

void printMatrix(int** GLCM, int max);

void contrast(double** NormalizedGLCM, int max);
void Homogenity(double** NormalizedGLCM, int max);
void Energy(double** NormalizedGLCM, int max);
// A helper function to import the image, take the values into a 2D array, and returns the pointer for the 2D array
int** importImage(int& rows, int& columns, int& max);

int main() {
	//Initalize variables
	bool repeat = true, GLCMCreated = false;
	int **image = NULL, **GLCM = NULL;
	double** normalizedGLCM = NULL;
	
	int max(0), rows(0), columns(0);
	string choice = "";

	//Explain the program for the user and ask for the file- inside importImage function 
	cout << "Hello User!!!\nThis program is designed to take input file that has the values in pixels of an image"
		<< " and creat a GLCM matrix and then use the GLCM matrix to find some of the attributes of the image" << endl;
	image = importImage(rows, columns, max);
	

	//Initialize GLCM and normalizedGLCM with dimension max +1, and initalize all the values to be 0 
	GLCM = new int* [max + 1];
	normalizedGLCM = new double* [max + 1];
	  for (int i = 0; i < max + 1; i++) {
        GLCM[i] = new int[max + 1];
        normalizedGLCM[i] = new double[max + 1];
		for(int j=0; j< max + 1; j++){
			GLCM[i][j]=0;
        	normalizedGLCM[i][j] =0;
		}
    }


	
	//The menu  will be called continuesly until repeat is false which is when the user choice is 4
	while (choice != "4") {
		cout << "There are 3 functions of the program."
			<< "\nPress 1 to create and normalize GLCM matrix"
			<< "\nPress 2 Compute the statistical parameters of the texture"
			<< "\nPress 3 Print the GLCM matrix"
			<< "\nPress 4 to exit the code" <<endl;

		//I choose the combination of string and if statement rather than an switch statement because 
		//in the case a user input a string in an int, it will result in a failed comand with an infinite loop

		cin >> choice;
		if (choice == "1") {
			createMatrix(GLCM, image, rows, columns);
			createNormalized(GLCM, normalizedGLCM, max);
			GLCMCreated = true;
			cout << "Done\n\n" << endl;
		}
		else if (choice == "2")
			//Only call function if GLCM was created
			if (GLCMCreated) {
				contrast(normalizedGLCM, max);
				Energy(normalizedGLCM, max);
				Homogenity(normalizedGLCM, max);
			}
			else
				cout << "Please create GLCM before calculating attributes" << endl;
		else if (choice == "3") {
			//Only Print GLCM if GLCM was created
			if (GLCMCreated)
				printMatrix(GLCM, max);
			else
				cout << "Please create GLCM before printing" << endl;
		}
		else if (choice == "4") {
			cout << "Thanks for using our porgram" << endl;
		}
		else
			cout << "Please input one of the options" << endl;
	}
		
	
		//Freeing the image 2D array 
		for (int i = 0; i < rows; i++)
			delete[] image[i];
		delete[] image;
		//Freeing the GLCM and normalizedGLCM arrays
		for (int i = 0; i < max + 1; i++) {
    		delete[] GLCM[i];
    		delete[] normalizedGLCM[i];
		}
		delete[] GLCM;
		delete[] normalizedGLCM;


	return(0);
}


void createMatrix(int** GLCM, int** image,int rows, int columns) {
	
	//Using the maximum found in the image 2D array to initalize a GLCM 2D array where all values are zero
	//Traverse through the image 2D array and imputting the nessessary values into GLCM 2D array
	for (int i = 0; i < rows ; i++) {
		for (int j = 0; j < columns - 1; j++) {
			++GLCM[image[i][j]][image[i][j + 1]];
		}
	}

}

void createNormalized(int** GLCM, double** NormalizedGLCM, int max) {
	//Find the sum by traversing through GLCM
	double sum(0);
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			sum += GLCM[i][j];

		}
	}

	//Creating NormalizedGLCM
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			//If sum is zero then it will print this message
			if (sum == 0) {
				cout << "Normalized was not created successfully" << endl;
				return;
			}
			 NormalizedGLCM[i][j]= GLCM[i][j] / sum;
		}
	}

}

void printMatrix(int** GLCM, int max) {
	cout << "GLCM matrix:\n\n";
	//Printing GLCM matrix
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			cout << GLCM[i][j] << " ";

		}
		cout << "\n";
	}
}

//A function that Finds the contrast and prints it
void contrast(double** NormalizedGLCM, int max) {
	
	double contrast(0);
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			contrast += pow(abs(i - j), 2) * NormalizedGLCM[i][j];
		
		}
		
	}
	cout << "\nContrast: " << contrast << endl; 
	
}

//A function that Finds the Energy and prints it
void Energy(double** NormalizedGLCM, int max) {

	double energy(0);
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			energy += NormalizedGLCM[i][j] * NormalizedGLCM[i][j];
			
		}
		
	}
	cout << "Energy: " << energy <<  endl;
}

//A function that Finds the homogenity and prints it
void Homogenity(double** NormalizedGLCM, int max) {
	double homogenity(0);
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < max + 1; j++) {
			
			homogenity += (NormalizedGLCM[i][j] / (1 + pow(abs(i - j), 2)));
		}
		
	}
	cout << "Homogeneity: " << homogenity << endl;
}

//the function takes rows, columns, and max variables as refrences to implement changing on them
//We passed them as refrence rather than creating as pointers as pointers gives felxibility(with complexity) that is not needed in this case 
int** importImage(int& rows, int& columns, int& max) {
	int** image;
	ifstream file;
	string nameFile;

	cout << "Before starting, please enter the name of the first file: (Press 0 to exit program)" << endl;
	cin >> nameFile;
	file.open(nameFile, ios::in);
	//if the name inputed by the user doesnt work, keep asking the user for a valid name.
	//The user can opt out of the porgram by inputting a 0
	while (file.fail()) {
		if (nameFile == "0") {
			cout << "Thanks for using our porgram" << endl;
			exit(1);
		}
		cerr << "Error. The file doesn't exist. Please try again" << endl;
		cin >> nameFile;
		file.open(nameFile, ios::in);

	}
	
	file >> columns >> rows;

	image = new int*[rows];
	//Inputting the values into a 2D image array and finding the maximum value
	for (int i = 0; i < rows; i++) {
		image[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			file >> image[i][j];
			if (image[i][j] > max)
				max = image[i][j];
		}
	}

	file.close();
	// return a pointer for the 2D array
	return image;

}


 
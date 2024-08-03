# Image Features Extraction using Gray Level Co-occurrence Matrix (GLCM)

This project implements an image processing technique to extract features such as contrast, energy, and homogeneity from image data using the Gray Level Co-occurrence Matrix (GLCM). The program reads image pixel information from a file, constructs the GLCM, normalizes it, and computes the desired image texture attributes.

## Table of Contents

1. [Problem Statement](##problem-statement)
2. [Gathering of Information](#gathering-of-information)
3. [Input and Output Description](#input-and-output-description)
4. [Test Cases](#test-cases)
5. [Algorithm Design](#algorithm-design)
6. [Implementation](#implementation)
7. [Usage](#usage)
8. [Acknowledgements](#acknowledgements)

## Problem Statement

The problem is to extract image features such as contrast, energy, and homogeneity from a file containing image data or pixel information using the GLCM.

## Gathering of Information

The GLCM represents the spatial relationships of pixels in an image. It examines how frequently a combination of pixels is present in an image in a given direction (θ) and distance (d). Using GLCM, several statistics can be derived which provide information about the texture of an image.

## Input and Output Description

### Input:
1. Name of the file containing image data.
2. The file should have the dimensions of the image stored in the first line as (columns, rows), followed by the pixel information.

### Output:
1. GLCM matrix.
2. The values of the contrast, energy, and homogeneity attributes.

## Test Cases

### Test Case 1:
**File:** `image.txt`  
**Content:**
```
5 4
1 1 5 6 8
2 3 5 7 1
4 5 7 1 2
8 5 1 2 5
```

### Test Case 2:
**File:** `image.txt`  
**Content:**
```
10 10
1 5 1 5 3 1 3 3 3 2
1 4 0 3 3 1 1 1 3 0
3 4 3 0 1 1 0 2 5 0
2 0 2 1 3 0 1 5 1 1
1 2 4 3 4 4 0 5 2 2
3 2 4 2 3 5 1 1 2 5
1 4 0 5 3 4 4 0 2 1
4 0 0 0 5 4 5 2 3 4
1 3 0 3 2 3 3 0 4 5
1 4 3 2 5 4 5 2 5 1
```

### Test Case 3:
**File:** `image.txt`  
**Content:**
```
3 3
1 2 3
9 5 4
6 6 7
```

### Test Case 4:
**File:** `image.txt`  
**Content:**
```
3 3
1 2 3
9 5 4
6 6 7
```

## Algorithm Design

### Pseudocode:
1. **Import Image:**
    - Read image dimensions and pixel values from file.
    - Initialize and populate image matrix.
    - Identify the maximum gray level in the image.

2. **Create GLCM:**
    - Initialize GLCM matrix with dimensions based on maximum gray level.
    - Populate GLCM based on pixel relationships.

3. **Normalize GLCM:**
    - Compute the sum of all elements in GLCM.
    - Create a normalized GLCM matrix by dividing each element by the sum.

4. **Compute Attributes:**
    - **Contrast:** Calculate using the normalized GLCM matrix.
    - **Energy:** Calculate using the normalized GLCM matrix.
    - **Homogeneity:** Calculate using the normalized GLCM matrix.

### Functions:
- `createMatrix()`
- `createNormalized()`
- `printMatrix()`
- `contrast()`
- `Energy()`
- `Homogeneity()`
- `importImage()`

## Implementation

The project is implemented in C++ using standard libraries for input/output operations and mathematical computations.

## Usage

1. **Compile the Program:**
    ```sh
    g++ -o glcm_extractor main.cpp
    ```

2. **Run the Program:**
    ```sh
    ./glcm_extractor
    ```

3. **Follow the Instructions:**
    - Enter the file name containing the image data.
    - Choose from the menu options to create GLCM, compute statistical parameters, or print the GLCM matrix.

## Acknowledgements

This project is part of the Computer Engineering Case Study for ENGR-AD 1000, Fall 2022, by Yousef Al-Jazzazi. The assignment was supervised by Prof. Mohammad Eid.

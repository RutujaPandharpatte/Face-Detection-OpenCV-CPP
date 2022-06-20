# ⭐ Prerequisites

**1. [OpenCV](https://opencv.org/releases/) (Open Computer Vision)**

**2. [Microsoft Visual Studio](https://visualstudio.microsoft.com/downloads/)**

## 👇 Steps to Setup OpenCV with Visual Studio

**1. Set up Environment Path**
   
    Environment Variable Path : C:\OpenCV\opencv\build\x64\vc14\bin

**2. Properties of Project in (Visual Studio)**

    C/C++ Settings 👇

    General => Additional Include Directories : C:\OpenCV\opencv\build\include

    Preprocessor => Preprocessor Definitions : _CRT_SECURE_NO_WARNINGS
    
<br>      

    Linker Settings 👇

    General => Additional Library Directories : C:\OpenCV\opencv\build\x64\vc14\lib

    Input => Additional Dependencies : opencv_world452d.lib
      
## 📷 Results

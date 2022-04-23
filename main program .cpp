 // Program: Gray scale photo_editor
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mostafa Bahy
// Author:  Youssef saeed 
// Date:    6 March 2022
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include <algorithm>

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

// loadImage () is the function that is responsible for loading the image into the program
void loadImage () {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension to the image if it dosen't contain it
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

// loadImage2 () is the function that is responsible for loading an extra image (image2) into the program
void loadImage2 () {
    char imageFileName2[100];
    // Get gray scale image file name
    cout << "Enter the second source image file name: ";
    cin >> imageFileName2;
    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

// saveImage () is the function that is responsible for saving the image after making changes to it through the program
void saveImage () {
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}



// saveImage2 () is the function that is responsible for saving image2 after making changes to it through the program
void saveImage2 () {
    char imageFileName2[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName2;
    // Add to it .bmp extension and load image
    strcat(imageFileName2, ".bmp");
    writeGSBMP(imageFileName2, image2);
}


// to clear image2 array to be able to re-use it in case we used it in a filter and want to use it in another (defensive)
void clear_image2(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = 0;
        }
    }
}


// Black_and_White_Filter() is responsible for handling the pixels to apply black and white filter on the image
void Black_and_White_Filter() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;

        }
    }
}


// invert() is responsible for handling the pixels to apply a negative of a photo colors filter
void invert() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j] = SIZE - image[i][j];

        }
    }
}


// merge() is responsible for handling the pixels two images to apply the merge filter to them
void merge() {
    loadImage2();
    //loops though each pixel in two images to gather them in one image
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            image[i][j] = (image[i][j] + image2[i][j]) / 2;
        }
    }
}


//  flip() is responsible for handling the pixels of an image to flip an image vertically or horizontally
void flip()
{
    string choice ;
    cout <<"please choose ( 1 ) if you want to flip the image vertically or"
           "\n( 2 ) if you want to flip the image horizontally enter your choice :- " << endl;
    cin >> choice;

//    to check if the choice is correct (just 1 or 2)(defensive)
    while (true){
        if (choice == "1" || choice =="2") {
            break;
        }
        else{
            cout << "please make sure that you choose just 1 or 2";
            cin >> choice;
        }
    }
    if (choice == "1"){
        //    for flipping vertically
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image2[SIZE - i][j]= image[i][j];
            }
        }
    }
    else if (choice == "2"){
        //    for flipping horizontally
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image2[i][SIZE-j] = image[i][j];
            }
        }
    }
}


// lightenAndDarken () is responsible for handling the pixels of an image to  lighten or darken the image by 50%
void lightenAndDarken() {
    string choice ;
    cout <<"please choose:\n( 1 ) if you want to lighten the image by 50%\n"
           "( 2 ) if you want to darken the image by 50%\n"
           "enter your choice :-  ";
    cin >> choice;
    while (true){
        if (choice == "1" || choice =="2") {
            break;
        }
        else
            cout << "please make sure that you choose just 1 or 2";
        cin >> choice;
    }
    if (choice == "1") {
        //  for lighten the image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (image[i][j] > 127) {
                    image[i][j] = 255;
                }
                else {
                    image[i][j] *= 2;
                }
            }
        }
    }
    else if(choice == "2") {
        //    for darken the image
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] /= 2;
            }
        }
    }
}


// rotate() is responsible for handling the pixels of an image to apply the rotate filter for an image 90 , 180 or 270 deg.
void rotate(){

    string choice ;
    cout <<"please choose:\n( 1 ) if you want to rotate the image by 90 deg.\n"
           "( 2 ) if you want to rotate the image by 180 deg.\n"
           "( 3 ) if you want to rotate the image by 270 deg.\nenter your choice :-  ";
    cin >> choice;
    while (true){
        if (choice == "1" || choice =="2" || choice == "3") {
            break;
        }
        else
            cout << "please make sure that you choose just 1 or 2";
        cin >> choice;
    }

    if (choice == "1"){
        //    for rotating the image 90 deg.
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++) {

                image2[ j][SIZE - i]= image[i][j];
            }
        }
    }
    else if (choice == "2"){
        // for rotating the image 180 deg.
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image2[SIZE-i][SIZE-j]= image[i][j];
            }
        }
    }
        //    for rotating the image 270 deg.
    else if (choice == "3"){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j< SIZE; j++){
                image2[SIZE-j][i]= image[i][j];
            }
        }
    }
}


void detect_edges() {
    int sum = 0, avg;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sum += image[i][j];
        }
    }
//here we got the average of the colors in the photo
    avg = sum / (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > avg)
                image[i][j] = 255;
            else {
                image[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image2[i][j] = (image[i - 1][j - 1]) + (image[i + 1][j - 1]) + (image[i - 1][j]) + (image[i][j] * -8) +
                           (image[i + 1][j]) + (image[i - 1][j + 1]) + (image[i][j + 1]) + (image[i + 1][j + 1]) +
                           (image[i][j - 1]);
        }
    }
    for (auto &i: image2) {
        for (unsigned char &j: i) {
            j = 255 - j;
        }
    }
    for(int i=0;i<255;i++){
        for(int j=0;j<255;j++){
            image[i][j]=image2[i][j];
        }
    }
}


// enlarge() is responsible for handling the pixels to enlarge a chosen quad to be in the size of the image (256 * 256)
 void enlarge() {

     string choice ;
     cout <<"please choose:\n( 1 ) if you want to enlarge the image first quadrant\n"
            "( 2 ) if you want to enlarge the image second quadrant\n"
            "( 3 ) if you want to enlarge the image third quadrant\n"
            "( 4 )if you want to enlarge the image forth quadrant\nenter your choice :-  ";
     cin >> choice;
     while (true){
         if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
             break;
         }
         else
             cout << "please make sure that you choose just 1 or 2\nenter your choice:- ";
         cin >> choice;
     }
     if (choice == "1"){
         // for enlarging the first quad.
         for (int i = 0 ; i < SIZE;i++){
             for (int j = 0;j < SIZE ;j++){
                 image2[i][j] = image[i/2][j/2];
             }
         }
     }
     else if (choice == "2"){
         // for enlarging the second quad.
         for (int i = 0 ; i < SIZE;i++){
             for (int j = 0;j < SIZE ;j++){
                 image2[i][SIZE-j] = image[i/2][SIZE-j/2];
             }
         }
     }
     else if (choice == "3"){
         // for enlarging the third quad.
         for (int i = 0 ; i < SIZE;i++){
             for (int j = 0;j < SIZE ;j++){
                 image2[SIZE-i][j] = image[SIZE-i/2][j/2];

             }
         }
     }
     else if (choice == "4"){
         // for enlarging the fourth quad.
         for (int i = 0 ; i < SIZE;i++){
             for (int j = 0;j < SIZE ;j++){
                 image2[SIZE-i][SIZE-j] = image[SIZE-i/2][SIZE-j/2];
             }
         }
     }
 }


 // shrink() is responsible for handling the pixels to shrink the image into half, one third or quarter its size
 void shrink() {

     string choice ;
     cout <<"please choose:\n( 1 ) if you want to shrink the image to half its size\n"
            "( 2 ) if you want to shrink the image to one third its size\n"
            "( 3 ) if you want to shrink the image to one quarter its size\nenter your choice :-  ";
     cin >> choice;

//    to check if the choice is correct (just 1 or 2)
     while (true){
         if (choice == "1" || choice =="2" ||choice =="3" ) {
             break;
         }
         else{
             cout << "please make sure that you choose just 1 or 2";
             cin >> choice;
         }
     }
     if (choice == "1"){
         //    for shrinking the image to half of its size
         for (int i = 0; i < SIZE/2;i++){
             for (int j = 0;j < SIZE/2;j++){
                 image2[i][j] = image[i*2][j*2];
             }
         }
     }
     else if (choice == "2") {
         //      for shrinking the image to one third  of its size
         for (int i = 0; i < SIZE/3;i++){
             for (int j = 0;j < SIZE/3;j++){
                 image2[i][j] = image[i*3][j*3];
             }
         }
     }
     else if (choice == "3"){
         //      for shrinking the image to one third  of its size
         for (int i = 0; i < SIZE/4;i++){
             for (int j = 0;j < SIZE/4;j++){
                 image2[i][j] = image[i*4][j*4];
             }
         }
     }
 }


 // mirror is responsible for handling the pixels to mirror a selected half of the image
 void mirror() {
     string choice ;
     cout <<"please choose:\n( 1 ) if you want to mirror the image upper half\n"
            "( 2 ) if you want to mirror the image lower half\n"
            "( 3 ) if you want mirror the image left half\n"
            "( 4 )if you want mirror the image right half\nenter your choice :-  ";
     cin >> choice;
     while (true){
         if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {
             break;
         }
         else
             cout << "please make sure that you choose just 1 or 2";
         cin >> choice;
     }
     if(choice =="1"){
//    upper half mirroring for the image
         for (int i = 0; i <= SIZE/2; i++)
         {
             for (int j = 0 ; j <= SIZE; j++)
             {
                 image2 [i][j] = image[i][j];
                 image2 [SIZE -i] [j] = image[i][j];
             }
         }
     }
     if (choice == "2"){
//    lower half mirroring for the image
         for (int i = SIZE; i >= SIZE / 2; i--) {
             for (int j = 0; j <= SIZE; j++) {
                 image2[i][j] = image[i][j];
                 image2[SIZE - i][j] = image[i][j];
             }
         }
     }
     if (choice=="3"){
//    left half mirroring for the image
         for (int i = 0; i <= SIZE; i++) {
             for (int j = 0; j <= SIZE / 2; j++) {
                 image2[i][j] = image[i][j];
                 image2[i][SIZE - j] = image[i][j];
             }
         }
     }
     if(choice == "4"){
//     right half mirroring for the image
         for (int i = 0; i <= SIZE; i++) {
             for (int j = SIZE; j >= SIZE / 2; j--) {
                 image2[i][j] = image[i][j];
                 image2[i][SIZE - j] = image[i][j];
             }
         }
     }
 }


 void shufflex() {
     string choice;
     cout << "please enter the order of quads that you want to shuffle to EX : 4321 :- ";
     cin>>choice;
     cout<<"\n";
//    for checking if a character is repeated
     while (true){
         if (choice.substr(0,2) == "44"||choice.substr(0,2) == "22"||choice.substr(0,2) =="33"||choice.substr(0,2) =="11" )
         {   cin.clear();

             cout << "Please enter a valid order ex: 1234 or 3421 : \n=>";
             cin >> choice; }
         else if (choice.substr(1,2) == "44"||choice.substr(1,2) == "22"||choice.substr(1,2) =="33"||choice.substr(1,2) =="11" )
         {  cin.clear();

             cout << "Please enter a valid order ex: 1234 or 3421 : \n=>";
             cin >> choice;}
         else if (choice.substr(2,2) == "44"||choice.substr(2,2) == "22"||choice.substr(2,2) =="33"||choice.substr(2,2) =="11" )
         {  cin.clear();

             cout << "Please enter a valid order ex: 1234 or 3421 : \n=>";
             cin >> choice;}
         else
             break;
     }

     while (choice.find_first_not_of("1234")!= string::npos){
         cin.clear();
         cout << "Please enter a valid order ex: 1234 or 3421 : \n=>";
         cin >> choice;
     }


//first quad. section :-
     if (choice.substr(0,1) == "1"){
         //first quad to put in
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j] = image[i][j];
             }
         }
     }
     else if (choice.substr(0,1) == "2"){
         //second quad to put in
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j] = image[i][j+127];
             }
         }
     }
     else if (choice.substr(0,1) == "3"){
         //first quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j] = image[i+127][j];
             }
         }
     }
     else if (choice.substr(0,1) == "4"){
         //first quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j] = image[i+127][j+127];
             }
         }
     }
//second quad. section :-
     if (choice.substr(1,1) == "1"){
         //second quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j+127] = image[i][j];

             }
         }
     }
     else if (choice.substr(1,1) == "2"){
         //second quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j+127] = image[i][j+127];

             }
         }
     }
     else if (choice.substr(1,1) == "3"){
         //second quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j+127] = image[i+127][j];

             }
         }
     }
     else if (choice.substr(1,1) == "4"){
         //second quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i][j+127] = image[i+127][j+127];

             }
         }
     }


// third quad. section
     if (choice.substr(2,1) == "1"){
         //third quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j] = image[i][j];

             }
         }
     }
     else if (choice.substr(2,1) == "2"){
         //third quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j] = image[i][j+127];
             }
         }
     }
     else if (choice.substr(2,1) == "3"){
         //third quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j] = image[i+127][j];

             }
         }
     }
     else if (choice.substr(2,1) == "4"){
         //third quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j] = image[i+127][j+127];

             }
         }
     }
// fourth quad section :-
     if (choice.substr(3,1) == "1"){
         //fourth quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j+127] = image[i][j];

             }
         }
     }
     else if (choice.substr(3,1) == "2"){
         //fourth quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j+127] = image[i][j+127];
             }
         }
     }
     else if (choice.substr(3,1) == "3"){
         //fourth quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j+127] = image[i+127][j];

             }
         }
     }
     else if (choice.substr(3,1) == "4"){
         //fourth quad to put
         for (int i = 0 ; i < (SIZE/2)+1;i++){
             for (int j = 0;j < (SIZE/2)+1 ;j++){
                 image2[i+127][j+127] = image[i+127][j+127];

             }
         }
     }
 }


 // blur()  is responsible for handling the pixels to apply the blur filter on an image
 void blur() {
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             image[i][j] = (image[i - 2][j + 2] + image[i - 2][j + 1] + image[i - 2][j] + image[i - 2][j - 1] +
                            image[i - 2][j - 2] + image[i - 1][j + 2] + image[i - 1][j + 1] + image[i - 1][j] +
                            image[i - 1][j - 1] + image[i - 1][j - 2] + image[i][j + 2] + image[i][j + 1] + image[i][j] +
                            image[i][j - 1] + image[i][j - 2] + image[i + 1][j + 2] + image[i + 1][j + 1] +
                            image[i + 1][j] + image[i + 1][j - 1] + image[i + 1][j - 2] +
                            image[i + 2][j + 2] + image[i + 2][j + 1] + image[i + 2][j] + image[i + 2][j - 1] +
                            image[i + 2][j - 2]) / 25;
         }
     }
 }


 char filter_choice(char choice){
    char choice1;
     cout << "\nPlease select a filter to apply or 0 to exit:- ";
     cin >> choice;
     while (true){
         if (choice == 'a' || choice == 'b' ||choice == 'c' ||choice == '1' ||choice == '2' ||choice == '3' ||choice == '4'
             ||choice == '5' ||choice == '6' ||choice == '7' ||choice == '8' ||choice == '9' ||choice == '0'){
             break;
         }

         else{
             cin.clear();
             cout << "wrong input :(\nPlease just select a filter to apply or 0 to exit:- ";
             cin >> choice;
         }
     }
     return choice=choice;
 }


int main(){
    int exit = 0;
    string choice;
// the application while loop
while (exit == 0 ){
    cout << "Ahlan ya user ya habibi :)\n\n"
            "Please select a filter to apply or 0 to exit:\n"
            "1- Black & White Filter\n"
            "2- Invert Filter\n"
            "3- Merge Filter\n"
            "4- Flip Image\n"
            "5- Darken and Lighten Image\n"
            "6- Rotate Image\n"
            "7- Detect Image Edges\n"
            "8- Enlarge Image\n"
            "9- Shrink Image\n"
            "a- Mirror 1/2 Image\n"
            "b- Shuffle Image\n"
            "c- Blur Image\n"
            "0- Exit\n";
    loadImage();
// to take the filter choice
    cout << "\nPlease select a filter to apply or 0 to exit:- ";
    cin >> choice;
    // to check if the choice is correct or not (defensive)
    while (true){
         if (choice.length()!=1){
            cin.clear();
            cout << "wrong input :( Please just select a filter to apply or 0 to exit:- ";
            cin >> choice;
        }
        else if (choice.substr(0,1) == "a" || choice.substr(0,1) == "b" ||choice.substr(0,1) == "c" ||choice.substr(0,1) == "1"
            ||choice.substr(0,1) == "2"||choice.substr(0,1) == "3" ||choice.substr(0,1) == "4" ||choice.substr(0,1) == "5"
            ||choice.substr(0,1) == "6" ||choice .substr(0,1) == "7" ||choice.substr(0,1) == "8" ||choice.substr(0,1) ==
            "9" ||choice.substr(0,1) == "0"){
            break;
        }
        else{
            cin.clear();
            cout << "wrong input :( Please just select a filter to apply or 0 to exit:- ";
            cin >> choice;
        }
    }

    if (choice == "1"){
        Black_and_White_Filter();
        saveImage();
    }
    else if (choice == "2"){
        invert();
        saveImage();
    }
    else if (choice == "3"){
        merge();
        saveImage2();
        clear_image2();
    }
    else if (choice == "4"){
        flip();
        saveImage2();
        clear_image2();
    }
    else if (choice == "5"){
        lightenAndDarken();
        saveImage();
    }
    else if (choice == "6"){
        rotate();
        saveImage2();
        clear_image2();
    }
    else if (choice == "7"){
        detect_edges();
        saveImage();
        clear_image2();
    }
    else if (choice == "8"){
        enlarge();
        saveImage2();
        clear_image2();
    }
    else if (choice == "9"){
        shrink();
        saveImage2();
        clear_image2();
    }
    else if (choice == "a"){
        mirror();
        saveImage2();
        clear_image2();
    }
    else if (choice == "b"){
        shufflex();
        saveImage2();
        clear_image2();
    }
    else if (choice == "c"){
        blur();
        saveImage();
    }
    else if (choice == "0" )
        exit = 1;

    }

    return 0;
}


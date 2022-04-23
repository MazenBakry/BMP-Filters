#include <iostream>
#include <cstring>
#include "bmplib.cpp"
#include <bits/stdc++.h>
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char imageRGB[SIZE][SIZE][3];
unsigned char imageRGB1[SIZE][SIZE][3];

void invert(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=255-image[i][j];
        }
    }

}
void rotate90(){
    unsigned char imageTran[SIZE][SIZE];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j]=image[j][i];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=imageTran[i][j];
        }
    }

    for (int i= 0;i<SIZE/2;i++) {
        for (int j=0;j<SIZE;j++) {
            int temp = image[i][j];
            image[i][j]=image[SIZE-i-1][j];
            image[SIZE-i-1][j]=temp;
        }
    }
}
void rotate270(){
    unsigned char imageTran[SIZE][SIZE];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j]=image[j][i];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=imageTran[i][j];
        }
    }
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = image[i][j];
            image[i][j]=image[i][SIZE-j-1];
            image[i][SIZE-j-1]=temp;
        }
    }

}
void rotate180(){
    for (int i= 0;i<SIZE/2;i++) {
        for (int j=0;j<SIZE;j++) {
            int temp = image[i][j];
            image[i][j]=image[SIZE-i-1][j];
            image[SIZE-i-1][j]=temp;
        }
    }
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = image[i][j];
            image[i][j]=image[i][SIZE-j-1];
            image[i][SIZE-j-1]=temp;
        }
    }

}
void rotateImage(){
    int choice;
    cout<<"Rotate (90), (180) or (270) degrees"<<endl<<endl;
    cin>>choice;
    if (choice==90)
        rotate90();
    else if (choice==180)
        rotate180;
    else if (choice==270)
        rotate270();

}
void enlarge(){
    unsigned char temp[SIZE/2][SIZE/2];
    int  startRow, startCol, endRow, endCol;
    int quarter=0;
    while(quarter>4 || quarter<1){
        cout<<"Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
        cin>>quarter;
    }

    startRow = quarter ==1 || quarter==2 ? 0 : SIZE/2;
    endRow   = quarter ==1 || quarter==2 ? SIZE/2 : SIZE;
    startCol = quarter ==1 || quarter==3 ? 0 : SIZE/2;
    endCol   = quarter ==1 || quarter==3 ? SIZE/2 : SIZE;

    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col]=image[i][j];
            col++;
        }
        row++;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            image[row][col]=temp[i][j];
            image[row+1][col]=temp[i][j];
            image[row][col+1]=temp[i][j];
            image[row+1][col+1]=temp[i][j];
            col+=2;
        }
        row+=2;
    }



}
void cutImage(int quarter, unsigned char fillImage[][SIZE/2]){
    // corrdinate to cut image
    int startRow, endRow, startCol, endCol;

    // choose start and end for row and col based on quarter
    startRow    = quarter == 1 || quarter == 2 ? 0 : SIZE / 2;
    endRow      = quarter == 1 || quarter == 2 ? SIZE / 2 : SIZE;
    startCol    = quarter == 1 || quarter == 3 ? 0 : SIZE / 2 ;
    endCol      = quarter == 1 || quarter == 3 ? SIZE / 2 : SIZE;


    // fill given image
    for(int i=startRow, rowIndex=0; i<endRow; i++){
        for(int j=startCol, colIndex=0; j<endCol; j++){

            fillImage[rowIndex][colIndex] = image[i][j];

            colIndex++; // increment col in fillImage
        }
        rowIndex++; // increment row in fillImage
    }

}
void shuffle(){

    // order of suffle
    int order[4];

    // get order from user
    cout << "New order of quarters ? ";
    for(int i=0; i<4; i++){
        cin >> order[i];
        if( order[i] > 4 || order[i] < 1){
            cout << "reject\n";
            return;
        }
    }

    // all quarters of image
    vector<unsigned char[SIZE/2][SIZE/2]>quarterImages(4);

    // get quarters of image
    for(int i=0; i<quarterImages.size(); i++){
        cutImage(order[i], quarterImages[i]);
    }

    int rowIndex, colIndex;
    for(int i=0; i<4; i++){ // loop on quartersImage

        // avoid overflow
        rowIndex = i == 0 || i == 1  ? 0 : SIZE / 2;

        //fiil image with quarter in order
        for(int j=0; j<SIZE/2; j++){

            // avoid overflow
            colIndex = i == 0 || i == 2  ? 0 : SIZE / 2;

            for(int k=0; k<SIZE/2; k++){
                image[rowIndex][colIndex] = quarterImages[i][j][k];
                colIndex++;
            }
            rowIndex++;
        }
    }

}
// cut image to corrspond quarter and fill the image given
void invertRGB(){

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=255-imageRGB[i][j][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=255-imageRGB[i][j][1];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=255-imageRGB[i][j][2];
        }
    }

}
void rotate90RGB(){
    unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
            imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
            imageRGB[SIZE-i-1][j][1]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
            imageRGB[SIZE-i-1][j][2]=temp;
        }
    }

}
void rotate180RGB(){
    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[SIZE-i-1][j][0];
            imageRGB[SIZE-i-1][j][0]=temp;
        }
    }



    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[SIZE-i-1][j][1];
            imageRGB[SIZE-i-1][j][1]=temp;
        }
    }




    for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[SIZE-i-1][j][2];
            imageRGB[SIZE-i-1][j][2]=temp;
        }
    }

    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
            imageRGB[i][SIZE-j-1][0]=temp;
        }
    }


    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
            imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
            imageRGB[i][SIZE-j-1][2]=temp;
        }
    }

}
void rotate270RGB(){
    unsigned char imageTran[SIZE][SIZE][3];
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][0]=imageRGB[j][i][0];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][1]=imageRGB[j][i][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageTran[i][j][2]=imageRGB[j][i][2];
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=imageTran[i][j][0];
        }
    }


    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=imageTran[i][j][1];
        }
    }

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=imageTran[i][j][2];
        }
    }

    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][0];
            imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
            imageRGB[i][SIZE-j-1][0]=temp;
        }
    }


    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][1];
            imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
            imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE/2;j++) {
            int temp = imageRGB[i][j][2];
            imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
            imageRGB[i][SIZE-j-1][2]=temp;
        }
    }

}
void rotateRGB(){
    int choice;
    cout<<"Rotate (90), (180) or (270) degrees"<<endl<<endl;
    cin>>choice;
    if (choice==90)
        rotate90RGB();
    else if (choice==180)
        rotate180RGB();
    else if (choice==270)
        rotate270RGB();

}
void enlargeRGB(){
    unsigned char temp[SIZE/2][SIZE/2][3];
    int  startRow, startCol, endRow, endCol;
    int quarter=0;
    while(quarter>4 || quarter<1){
        cout<<"Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
        cin>>quarter;
    }

    startRow = quarter ==1 || quarter==2 ? 0 : SIZE/2;
    endRow   = quarter ==1 || quarter==2 ? SIZE/2 : SIZE;
    startCol = quarter ==1 || quarter==3 ? 0 : SIZE/2;
    endCol   = quarter ==1 || quarter==3 ? SIZE/2 : SIZE;

    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][0]=imageRGB[i][j][0];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][1]=imageRGB[i][j][1];
            col++;
        }
        row++;
    }
    for(int i=startRow,row=0;i<endRow;i++){
        for (int j=startCol, col=0;j<endCol;j++){
            temp[row][col][2]=imageRGB[i][j][2];
            col++;
        }
        row++;
    }
    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][0]=temp[i][j][0];
            imageRGB[row+1][col][0]=temp[i][j][0];
            imageRGB[row][col+1][0]=temp[i][j][0];
            imageRGB[row+1][col+1][0]=temp[i][j][0];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][1]=temp[i][j][1];
            imageRGB[row+1][col][1]=temp[i][j][1];
            imageRGB[row][col+1][1]=temp[i][j][1];
            imageRGB[row+1][col+1][1]=temp[i][j][1];
            col+=2;
        }
        row+=2;
    }

    for(int i=0, row=0; i<SIZE/2 ; i++){
        for (int j=0, col=0; j<SIZE/2 ; j++){
            imageRGB[row][col][2]=temp[i][j][2];
            imageRGB[row+1][col][2]=temp[i][j][2];
            imageRGB[row][col+1][2]=temp[i][j][2];
            imageRGB[row+1][col+1][2]=temp[i][j][2];
            col+=2;
        }
        row+=2;
    }
}

void read(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);

}
void readRGB(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, imageRGB);

}
void readRGB1(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, imageRGB1);

}
void read1(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the other image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image1);

}
void save(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);

}
void saveRGB(){
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, imageRGB);

}
void mergeImage(){
    read1();
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=(image[i][j]+image1[i][j])/2;
        }
    }
}
void darken(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (image[i][j]>127)
                image[i][j]-=63;
        }
    }
}
void lighten(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (image[i][j]<127)
                image[i][j]+=63;
        }
    }
}
void darkenLighten(){
    char choice;
    cout<<"Do you want to (d)arken or (l)ighten?"<<endl<<endl;
    cin>>choice;
    if (choice=='d')
        darken();
    else if (choice=='l')
        lighten();

}
void shrink(int num)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != 0) {
                for (int x = i; x <= SIZE - i; x++) {
                    if (x == SIZE - i) {
                        image[x][j] = 255;
                    }
                    else {
                        image[x][j] = image[x + num][j];
                    }
                }
            }

        }
    }
    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) {
                for (int x = j; x <= SIZE - j; x++) {
                    if (x == SIZE - j) {
                        image[i][x] = 255;
                    }
                    else {
                        image[i][x] = image[i][x + num];
                    }
                }
            }
        }
    }
}
void blur()
{
    char arr[SIZE][SIZE];
    int res=0;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            image[i][j]=(image[i][j]+image[i][j+1]+image[i][j-1]+image[i+1][j]+image[i+1][j+1]+image[i+1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i-1][j-1])/9;
        }
    }
}
void mergeRGB(){
    readRGB1();
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][0]=(imageRGB[i][j][0]+imageRGB1[i][j][0])/2;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][1]=(imageRGB[i][j][1]+imageRGB1[i][j][1])/2;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            imageRGB[i][j][2]=(imageRGB[i][j][2]+imageRGB1[i][j][2])/2;
        }
    }
}
void darkenRGB(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][0]>127)
                imageRGB[i][j][0]-=63;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][1]>127)
                imageRGB[i][j][1]-=63;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][2]>127)
                imageRGB[i][j][2]-=63;

        }
    }

}
void lightenRGB(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][0]<127)
                imageRGB[i][j][0]+=63;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][1]<127)
                imageRGB[i][j][1]+=63;
        }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (imageRGB[i][j][2]<127)
                imageRGB[i][j][2]+=63;

        }
    }

}
void darkenLightenRGB(){
    char choice;
    cout<<"Do you want to (d)arken or (l)ighten?"<<endl<<endl;
    cin>>choice;
    if (choice=='d')
        darkenRGB();
    else if (choice=='l')
        lightenRGB();
}
void shrinkRGB(int num)
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != 0) {
                for (int x = i; x <= SIZE - i; x++) {
                    if (x == SIZE - i) {
                        imageRGB[x][j][0] = 255;
                    }
                    else {
                        imageRGB[x][j][0] = imageRGB[x + num][j][0];
                    }
                }
            }

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != 0) {
                for (int x = i; x <= SIZE - i; x++) {
                    if (x == SIZE - i) {
                        imageRGB[x][j][1] = 255;
                    }
                    else {
                        imageRGB[x][j][1] = imageRGB[x + num][j][1];
                    }
                }
            }

        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i != 0) {
                for (int x = i; x <= SIZE - i; x++) {
                    if (x == SIZE - i) {
                        imageRGB[x][j][2] = 255;
                    }
                    else {
                        imageRGB[x][j][2] = imageRGB[x + num][j][2];
                    }
                }
            }

        }
    }

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) {
                for (int x = j; x <= SIZE - j; x++) {
                    if (x == SIZE - j) {
                        imageRGB[i][x][0] = 255;
                    }
                    else {
                        imageRGB[i][x][0] = imageRGB[i][x + num][0];
                    }
                }
            }
        }
    }

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) {
                for (int x = j; x <= SIZE - j; x++) {
                    if (x == SIZE - j) {
                        imageRGB[i][x][1] = 255;
                    }
                    else {
                        imageRGB[i][x][1] = imageRGB[i][x + num][1];
                    }
                }
            }
        }
    }

    for (int i = 0; i < SIZE / 2; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j != 0) {
                for (int x = j; x <= SIZE - j; x++) {
                    if (x == SIZE - j) {
                        imageRGB[i][x][2] = 255;
                    }
                    else {
                        imageRGB[i][x][2] = imageRGB[i][x + num][2];
                    }
                }
            }
        }
    }
}
void blurRGB(){
    char arr[SIZE][SIZE];
    int res=0;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            imageRGB[i][j][0]=(imageRGB[i][j][0]+imageRGB[i][j+1][0]+imageRGB[i][j-1][0]+imageRGB[i+1][j][0]+imageRGB[i+1][j+1][0]+imageRGB[i+1][j-1][0]+imageRGB[i-1][j][0]+imageRGB[i-1][j+1][0]+imageRGB[i-1][j-1][0])/9;
            imageRGB[i][j][1]=(imageRGB[i][j][1]+imageRGB[i][j+1][1]+imageRGB[i][j-1][1]+imageRGB[i+1][j][1]+imageRGB[i+1][j+1][1]+imageRGB[i+1][j-1][1]+imageRGB[i-1][j][1]+imageRGB[i-1][j+1][1]+imageRGB[i-1][j-1][1])/9;
            imageRGB[i][j][2]=(imageRGB[i][j][2]+imageRGB[i][j+1][2]+imageRGB[i][j-1][2]+imageRGB[i+1][j][2]+imageRGB[i+1][j+1][2]+imageRGB[i+1][j-1][2]+imageRGB[i-1][j][2]+imageRGB[i-1][j+1][2]+imageRGB[i-1][j-1][2])/9;
        }
    }
}

int main()
{

}

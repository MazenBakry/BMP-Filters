#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char imageRGB[SIZE][SIZE][3];
unsigned char imageRGB1[SIZE][SIZE][3];

void read();
void read1();
void readRGB();
void readRGB1();
void save();
void saveRGB();
void blackWhite();
void invert();
void darkenLighten();
void darken();
void lighten();
void mergeImage();
void flip();
void flipVertically();
void flipHorizontaly();
void rotateImage();
void rotate180();
void rotate90();
void rotate270();
void mirror();
void leftMirror();
void rightMirror();
void upperMirror();
void lowerMirror();
void mergeImage();
void shrink(int num);
void enlarge();
void detect_edge();
void shuffle();
void cutImage(int quarter, unsigned char fillImage[][SIZE/2]);
void blur();
void invertRGB();
void blackWhiteRGB();
void darkenLightenRGB();
void darkenRGB();
void lightenRGB();
void flipRGB();
void flipVerticallyRGB();
void flipHorizontalyRGB();
void mergeRGB();
void rotateRGB();
void rotate90RGB();
void rotate180RGB();
void rotate270RGB();
void enlargeRGB();
void shrinkRGB(int num);
void mirrorRGB();
void leftMirrorRGB();
void rightMirrorRGB();
void upperMirrorRGB();
void lowerMirrorRGB();
void blurRGB();
void RGB_detect();


int main()
{
    int choiceImage;
    cout<<"Ahlan ya user ya habibi :)"<<endl;
    cout<<"1- Grey Bitmap Images"<<endl<<"2- RGB Bitmap Images"<<endl;
    cin>>choiceImage;
    if (choiceImage==1)
        read();
    else if(choiceImage==2)
        readRGB();
    while (true && choiceImage==1){
    char choice;
    cout<<"1- Black & White Filter"<<endl<<"2- Invert Filter"<<endl<<"3- Merge Filter"<<endl<<"4- Flip Image"<<endl<<"5- Darken and Lighten Image"<<endl<<"6- Rotate Image"<<endl<<"7- Detect Image Edges "<<endl<<"8- Enlarge Image"<<endl<<"9- Shrink Image"<<endl;
    cout<<"a- Mirror 1/2 Image"<<endl<<"b- Shuffle Image"<<endl<<"c- Blur Image"<<endl<<"s- Save the image to a file"<<endl<<"0- Exit"<<endl;
    cout<<endl<<endl;
    cin>>choice;
    cout<<endl;
    if(choice=='1')
        blackWhite();

    else if(choice=='2')
        invert();

    else if (choice=='3')
        mergeImage();

    else if (choice=='4')
        flip();

    else if (choice=='5')
        darkenLighten();

    else if (choice=='6')
        rotateImage();

    else if(choice=='7')
        detect_edge();

    else if(choice=='8')
        enlarge();

    else if(choice=='9'){
        int num;
        string shrinkChoice;
        cout<<"Shrink to (1/2), (1/3) or (1/4)?"<<endl;
        cin>>shrinkChoice;
        if (shrinkChoice=="1/2")
            num=1;
        if (shrinkChoice=="1/3")
            num=2;
        if (shrinkChoice=="1/4")
            num=3;
        shrink(num);
    }

    else if(choice=='a')
        mirror();

    else if(choice=='b')
        shuffle();

    else if(choice=='c')
        blur();

    else if(choice=='s')
        save();

    else if(choice=='0')
        return 0;

    }
while (true && choiceImage==2){
     char choice;
    cout<<"1- Black & White Filter"<<endl<<"2- Invert Filter"<<endl<<"3- Merge Filter"<<endl<<"4- Flip Image"<<endl<<"5- Darken and Lighten Image"<<endl<<"6- Rotate Image"<<endl<<"7- Detect Image Edges "<<endl<<"8- Enlarge Image"<<endl<<"9- Shrink Image"<<endl;
    cout<<"a- Mirror 1/2 Image"<<endl<<"b- Shuffle Image"<<endl<<"c- Blur Image"<<endl<<"s- Save the image to a file"<<endl<<"0- Exit"<<endl;
    cout<<endl<<endl;
    cin>>choice;
    cout<<endl;
   if(choice=='1')
        blackWhiteRGB();

    else if(choice=='2')
        invertRGB();

    else if (choice=='3')
        mergeRGB();

    else if (choice=='4')
        flipRGB();

    else if (choice=='5')
        darkenLightenRGB();

    else if (choice=='6')
        rotateRGB();

    else if(choice=='7')
        RGB_detect();

    else if(choice=='8')
        enlargeRGB();

    else if(choice=='9'){
         int num;
        string shrinkChoice;
        cout<<"Shrink to (1/2), (1/3) or (1/4)?"<<endl;
        cin>>shrinkChoice;
        if (shrinkChoice=="1/2")
            num=1;
        if (shrinkChoice=="1/3")
            num=2;
        if (shrinkChoice=="1/4")
            num=3;
        shrinkRGB(num);
    }

    else if(choice=='a')
        mirrorRGB();

    else if(choice=='b')
        return 0;

    else if(choice=='c')
        blurRGB();

    else if(choice=='s')
        save();

    else if(choice=='0')
        return 0;


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


void blackWhite(){
    long avg;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            avg+=image[i][j];
        }
    }
    avg/=(SIZE*SIZE);
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            if (image[i][j]>avg)
                image[i][j]=255;
            else
                image[i][j]=0;
        }
    }

}

void invert(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=255-image[i][j];
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


void flip(){
    char choice;
    cout<<"Flip (h)orizontally or (v)ertically ?"<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if (choice=='h')
        flipVertically();

    else if (choice=='v')
        flipHorizontaly();

}


void flipVertically()
{
    for (int i= 0;i<SIZE/2;i++) {
            for (int j=0;j<SIZE;j++) {
                int temp = image[i][j];
                image[i][j]=image[SIZE-i-1][j];
                image[SIZE-i-1][j]=temp;
            }
    }
}

void flipHorizontaly(){
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


void mirror(){
    char choice;
    cout<<"Mirror (l)eft, (r)ight, (u)pper, (d)own side?"<<endl<<endl;
    cin>>choice;
    if (choice=='l')
        leftMirror();
    else if(choice=='r')
        rightMirror();
    else if(choice=='u')
        upperMirror();
    else if(choice=='d')
        lowerMirror();


}

void leftMirror(){
    for (int i=0;i<SIZE;i++){
            for (int j=0;j<SIZE/2;j++){
                 image[i][SIZE-j-1]=image[i][j];
            }
    }
}

void rightMirror(){
        for (int i=0;i<SIZE;i++){
         for (int j=0;j<SIZE/2;j++){
                image[i][j]=image[i][SIZE-j-1];
         }
        }
}


void upperMirror(){
  for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            image[SIZE-i-1][j]=image[i][j];
        }
    }
}


void lowerMirror(){
     for (int i=0;i<SIZE/2;i++){
        for (int j=0;j<SIZE;j++){
            image[i][j]=image[SIZE-i-1][j];
        }
    }

}


void mergeImage(){
    read1();
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
           image[i][j]=(image[i][j]+image1[i][j])/2;
        }
    }
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
void detect_edge()
{
    unsigned char arr[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = image[i][j];
        }
    }

    for (int i = 1; i < SIZE - 1; i++) {
        for (int j = 1; j < SIZE - 1; j++) {
            int x = 2*arr[i][j-1] - 2*arr[i][j+1] + arr[i-1][j-1] - arr[i-1][j+1] + arr[i+1][j-1] - arr[i+1][j+1];
            int y = 2*arr[i+1][j] - 2*arr[i-1][j] + arr[i+1][j-1] - arr[i-1][j-1] + arr[i+1][j+1] - arr[i-1][j+1];

            if (abs(x) > 100 || abs(y) > 100) {
                image[i][j] = 0;
            }
            else {
                image[i][j] = 255;
            }
        }
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





void invertRGB(){

    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                for (int k=0;k<3;k++){
                imageRGB[i][j][0]=255-imageRGB[i][j][0];
            }
        }
    }
   /* for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][1]=255-imageRGB[i][j][1];
            }---------
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                imageRGB[i][j][2]=255-imageRGB[i][j][2];
            }
        }*/

}
void blackWhiteRGB(){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][0]>127)
                    imageRGB[i][j][0]=0;
                else
                    imageRGB[i][j][0]=255;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][1]>127)
                    imageRGB[i][j][1]=0;
                else
                    imageRGB[i][j][1]=255;
            }
        }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
                if (imageRGB[i][j][2]>127)
                    imageRGB[i][j][2]=0;
                else
                    imageRGB[i][j][2]=255;
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

void flipRGB(){
    char choice;
    cout<<"Flip (h)orizontally or (v)ertically ?"<<endl<<endl;
    cin>>choice;
    cout<<endl;

    if (choice=='h')
        flipVerticallyRGB();

    else if (choice=='v')
        flipHorizontalyRGB();

}

void flipHorizontalyRGB(){
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
void flipVerticallyRGB(){
   for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][0];
                imageRGB[i][j][0]=imageRGB[i][SIZE-j-1][0];
                imageRGB[i][SIZE-j-1][0]=temp;
        }
        }



    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][1];
                imageRGB[i][j][1]=imageRGB[i][SIZE-j-1][1];
                imageRGB[i][SIZE-j-1][1]=temp;
        }
    }



    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE/2;j++){
           int temp = imageRGB[i][j][2];
                imageRGB[i][j][2]=imageRGB[i][SIZE-j-1][2];
                imageRGB[i][SIZE-j-1][2]=temp;
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
void mirrorRGB()
{
    int n;
    cout << "Upper 1/2 ---> 1" << endl << "Lower 1/2 ---> 2" << endl << "Right 1/2 ---> 3" << endl << "Left 1/2 ---> 4" <<endl;
    cout << "choose 1 , 2 , 3 or 4: ";
    cin >> n;
    if(n == 1)
    {
        	int s = SIZE/2;

      for(int m = 0; m < RGB; m++)
      {
      for (int j = 0; j < SIZE; j++)
        {

            int k = SIZE;
            for (int i = 0; i< s; i++)
            {
                imageRGB[k][j][m]=imageRGB[i][j][m];
                k--;
            }
        }
      }
    }
    else if(n == 2)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int j = 0; j < SIZE; j++)
    {

        int k = SIZE;
        for (int i = 0; i< s; i++)
        {
            imageRGB[i][j][m]=imageRGB[k][j][m];
            k--;
        }
    }
    }
    }
    else if(n == 3)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            imageRGB[i][j][m]=imageRGB[i][k][m];
            k--;
        }
    }
    }
    }
    else if(n == 4)
    {
            int s = SIZE/2;

    for(int m = 0; m < RGB; m++)
    {
    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            imageRGB[i][k][m]=imageRGB[i][j][m];
            k--;
        }
    }
    }
    }
}
void RGB_detect()
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (imageRGB [i][j][0]< 127 && imageRGB [i][j][1]< 127 && imageRGB [i][j][2]< 127)
                imageRGB [i][j][0]=imageRGB [i][j][1]=imageRGB [i][j][2]=0;
            else
                imageRGB [i][j][0]=imageRGB [i][j][1]=imageRGB [i][j][2]= 255;
        }
    }
    unsigned char detect[SIZE][SIZE][3];
    for(int k = 0; k < 3 ; k++){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                detect[i][j][k] = imageRGB[i][j][k];
            }
        }
    }
    for(int k = 0 ; k < 3 ; k++){
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                int x = 2*detect[i][j-1][k] - 2*detect[i][j+1][k] + detect[i-1][j-1][k] - detect[i-1][j+1][k] + detect[i+1][j-1][k] - detect[i+1][j+1][k];
                int y = 2*detect[i+1][j][k] - 2*detect[i-1][j][k] + detect[i+1][j-1][k] - detect[i-1][j-1][k] + detect[i+1][j+1][k] - detect[i-1][j+1][k];

                if (abs(x) > 600 || abs(y) > 600) {
                    imageRGB[i][j][k] = 0;
                }
                else {
                    imageRGB[i][j][k] = 255;
                }
            }
        }
    }
}

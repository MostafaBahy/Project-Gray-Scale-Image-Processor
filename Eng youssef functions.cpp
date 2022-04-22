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


//  flip() is responsible for handling the pixels of an image to flip an image vertically or horizontally
void flip()
{
    string choice ;
    cout <<"please choose ( 1 ) if you want to flip the image vertically or"
           "\n( 2 ) if you want to flip the image horizontally enter your choice :- " << endl;
    cin >> choice;

//    to check if the choice is correct (just 1 or 2)
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
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {

                image2[SIZE - i][j]= image[i][j];
            }
        }
    }

    else if (choice == "2"){
        //    for flipping horizontally
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
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


// detect_edges() is responsible for handling the pixels of an image to the picture edges in an image
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

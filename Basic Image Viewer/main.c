// Project: Basic Image Viewer (using Graphics Library)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <graphics.h>

int main() {
    printf("Basic Image Viewer (using Graphics Library)\n");

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    char imagePath[100];

    printf("Enter the path of the image file: ");
    scanf("%s", imagePath);

    // Load the image using the provided path
    int image = loadImage(imagePath);
    if (image == -1) {
        printf("Error loading the image. Please check the file path.\n");
        closegraph();
        return 1;
    }

    // Get the image dimensions
    int width = imagesize(0, 0, getmaxx(), getmaxy()) >> 16;
    int height = imagesize(0, 0, getmaxx(), getmaxy());

    // Resize the image to fit the screen
    setviewport(0, 0, getmaxx(), getmaxy(), 1);
    putimage((getmaxx() - width) / 2, (getmaxy() - height) / 2, image, COPY_PUT);

    getch();
    closegraph();

    return 0;
}

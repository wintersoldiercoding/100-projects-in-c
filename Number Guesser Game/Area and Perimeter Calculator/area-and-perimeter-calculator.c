// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
double calculateRectanglePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return 3.14159 * radius * radius;
}

// Function to calculate the circumference of a circle
double calculateCircleCircumference(double radius) {
    return 2 * 3.14159 * radius;
}

int main() {
    double length, width, radius;

    printf("Welcome to the Area and Perimeter Calculator!\n");

    // Rectangle
    printf("\nRectangle Calculation:\n");
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    double rectangleArea = calculateRectangleArea(length, width);
    double rectanglePerimeter = calculateRectanglePerimeter(length, width);

    printf("Area of the rectangle: %.2lf\n", rectangleArea);
    printf("Perimeter of the rectangle: %.2lf\n", rectanglePerimeter);

    // Circle
    printf("\nCircle Calculation:\n");
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    double circleArea = calculateCircleArea(radius);
    double circleCircumference = calculateCircleCircumference(radius);

    printf("Area of the circle: %.2lf\n", circleArea);
    printf("Circumference of the circle: %.2lf\n", circleCircumference);

    return 0;
}

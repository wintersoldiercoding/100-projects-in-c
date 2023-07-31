// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert temperature from Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert temperature from Kelvin to Celsius
double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert temperature from Fahrenheit to Kelvin
double fahrenheitToKelvin(double fahrenheit) {
    double celsius = fahrenheitToCelsius(fahrenheit);
    return celsiusToKelvin(celsius);
}

// Function to convert temperature from Kelvin to Fahrenheit
double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvinToCelsius(kelvin);
    return celsiusToFahrenheit(celsius);
}

int main() {
    double temperature;
    int choice;

    printf("Welcome to the Advanced Temperature Converter!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("Temperature in Fahrenheit: %.2lf\n", celsiusToFahrenheit(temperature));
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("Temperature in Celsius: %.2lf\n", fahrenheitToCelsius(temperature));
                break;
            case 3:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("Temperature in Kelvin: %.2lf\n", celsiusToKelvin(temperature));
                break;
            case 4:
                printf("Enter the temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("Temperature in Celsius: %.2lf\n", kelvinToCelsius(temperature));
                break;
            case 5:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("Temperature in Kelvin: %.2lf\n", fahrenheitToKelvin(temperature));
                break;
            case 6:
                printf("Enter the temperature in Kelvin: ");
                scanf("%lf", &temperature);
                printf("Temperature in Fahrenheit: %.2lf\n", kelvinToFahrenheit(temperature));
                break;
            case 7:
                printf("Exiting the Advanced Temperature Converter. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

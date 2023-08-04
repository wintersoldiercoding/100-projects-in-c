// Project: HTTP Request/Response Analyzer
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to write the received data into a buffer
size_t writeCallback(void* contents, size_t size, size_t nmemb, char* buffer) {
    size_t totalSize = size * nmemb;
    strcat(buffer, (char*)contents);
    return totalSize;
}

// Function to send an HTTP GET request and analyze the response
void analyzeHTTPResponse(const char* url) {
    CURL* curl;
    CURLcode res;
    char buffer[4096] = { 0 }; // Buffer to store the response data

    curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set the write callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

        // Perform the HTTP GET request
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            printf("HTTP request to '%s' successful.\n", url);

            // Analyze the HTTP response
            long responseCode;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
            printf("HTTP Response Code: %ld\n", responseCode);

            printf("HTTP Response:\n%s\n", buffer);
        } else {
            printf("HTTP request to '%s' failed: %s\n", url, curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }
}

int main() {
    char url[200];

    printf("Welcome to the HTTP Request/Response Analyzer!\n");

    printf("Enter the URL to send the HTTP GET request: ");
    scanf(" %[^\n]", url);

    analyzeHTTPResponse(url);

    return 0;
}

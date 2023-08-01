// Basic Text-Based Web Browser in C
// Project Link: https://github.com/wintersoldiercoding/100-projects-in-c
/*
For this basic implementation, we are using the libcurl library to handle HTTP requests and the libxml2 library to parse HTML and extract the text content.
Make sure you have the libcurl and libxml2 libraries installed on your system before compiling the code. On Ubuntu, you can install them with the following command:
sudo apt-get install libcurl4-openssl-dev libxml2-dev
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml/HTMLparser.h>

#define MAX_URL_LENGTH 1024

// Function to handle HTTP response data
size_t writeCallback(void *ptr, size_t size, size_t nmemb, char **data) {
    size_t totalSize = size * nmemb;
    *data = realloc(*data, strlen(*data) + totalSize + 1);
    if (*data == NULL) {
        printf("Memory reallocation failed.\n");
        return 0;
    }
    strncat(*data, (char *)ptr, totalSize);
    return totalSize;
}

// Function to fetch the web page content using libcurl
char *fetchWebPage(const char *url) {
    CURL *curl = curl_easy_init();
    char *data = NULL;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Error fetching the web page: %s\n", curl_easy_strerror(res));
            return NULL;
        }
        curl_easy_cleanup(curl);
    }

    return data;
}

// Function to parse HTML and extract text content using libxml2
void parseHTML(const char *htmlContent) {
    htmlDocPtr doc = htmlReadDoc((xmlChar *)htmlContent, NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc == NULL) {
        printf("Error parsing HTML content.\n");
        return;
    }

    xmlNodePtr node = xmlDocGetRootElement(doc);
    if (node == NULL) {
        printf("Empty HTML content.\n");
        xmlFreeDoc(doc);
        return;
    }

    xmlBufferPtr buffer = xmlBufferCreate();
    if (buffer == NULL) {
        printf("Buffer creation failed.\n");
        xmlFreeDoc(doc);
        return;
    }

    for (node = node->children; node; node = node->next) {
        if (node->type == XML_TEXT_NODE) {
            xmlNodeDump(buffer, doc, node, 0, 1);
            printf("%s", buffer->content);
            xmlBufferEmpty(buffer);
        }
    }

    xmlBufferFree(buffer);
    xmlFreeDoc(doc);
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter the URL of the web page: ");
    fgets(url, MAX_URL_LENGTH, stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove newline from fgets input

    char *webPageContent = fetchWebPage(url);
    if (webPageContent != NULL) {
        parseHTML(webPageContent);
        free(webPageContent);
    }

    return 0;
}

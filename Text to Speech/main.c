// Project: Text-to-Speech Synthesis (TTS) System
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <string.h>
#include <sapi.h>   // Include the Windows Speech API header

#define MAX_TEXT_LENGTH 100

// Function to convert text to speech using Windows API (SAPI)
void textToSpeech(const char* text) {
    ISpVoice* pVoice = NULL;
    HRESULT hr;

    // Initialize the COM library
    hr = CoInitialize(NULL);
    if (SUCCEEDED(hr)) {
        // Create an instance of the SAPI voice object
        hr = CoCreateInstance(&CLSID_SpVoice, NULL, CLSCTX_ALL, &IID_ISpVoice, (void**)&pVoice);
        if (SUCCEEDED(hr)) {
            // Set the voice properties (optional)
            pVoice->SetRate(0); // Normal speed (-10 to 10)
            pVoice->SetVolume(100); // Full volume (0 to 100)

            // Convert the text to speech
            pVoice->Speak((WCHAR*)text, 0, NULL);

            // Release the voice object
            pVoice->Release();
            pVoice = NULL;
        } else {
            printf("Error creating the SAPI voice object.\n");
        }

        // Uninitialize the COM library
        CoUninitialize();
    } else {
        printf("Error initializing the COM library.\n");
    }
}

int main() {
    printf("Text-to-Speech Synthesis (TTS) System\n");

    char text[MAX_TEXT_LENGTH];

    printf("Enter the text to convert to speech: ");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character from the input
    text[strcspn(text, "\n")] = '\0';

    // Convert the text to speech
    textToSpeech(text);

    return 0;
}

/*
Steps:
Please follow these steps to compile the code successfully:
1. Install the Windows SDK: If you haven't installed it yet, download and install the Windows SDK, which includes the necessary header files and libraries for SAPI.
2. Add Include and Library Paths: Make sure to add the include and library paths of the Windows SDK to your compiler settings.
3. Link with "sapi.lib": Add "sapi.lib" to the list of libraries to link with during the compilation.

bash:
gcc main.c -o tts_app -I"C:\path\to\Windows SDK\Include" -L"C:\path\to\Windows SDK\Lib" -lsapi
Replace "C:\path\to\Windows SDK" with the actual path where you have installed the Windows SDK.
If you are using an Integrated Development Environment (IDE) like Visual Studio, you may need to configure the project settings to include the necessary paths and libraries.
*/
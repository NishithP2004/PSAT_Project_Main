#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <windows.h>


static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main(void) {
    CURL *curl = curl_easy_init();
    FILE *fp = fopen("game.txt", "wb");
    printf("\nPlease Login https://psat-project.nishithp2004.repl.co/login");
    char playlist[255];
    char URL[255] = "https://psat-project.nishithp2004.repl.co/spotify/playlist/";
    printf("\nEnter a Spotify Playlist ID: ");
    gets(playlist);
    strcat(URL, playlist);
    strcat(URL, "/game.txt");
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(curl);
    fclose(fp);
    curl_easy_cleanup(curl);

    // Open the Flowgorithm file
    system("start RetroBooting.fprg");

    Sleep(1000);

    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_F5;  // Virtual key code for F5
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    SendInput(1, &input, sizeof(INPUT));

    // Simulate releasing the F5 key
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));

    Sleep(1000);
    // Obtain the handle of the window
    HWND hWnd = FindWindow(NULL, "Console");
    // Check if the window exists
    ShowWindow(hWnd, SW_MAXIMIZE);
    while (IsWindow(hWnd)) {
        // Window is still open
        // Perform any desired actions here
        ShowWindow(hWnd, SW_MAXIMIZE);
        // Wait for a short period of time (e.g., 1 second)
        Sleep(1000);

        // Check if the window still exists
        hWnd = FindWindow(NULL, "Console");
    }
   return 0;
}
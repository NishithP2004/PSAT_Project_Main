#include <stdio.h>
#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main(void) {
    CURL *curl = curl_easy_init();
    FILE *fp = fopen("C:\\Users\\Nishith P\\My Projects\\PSAT Project\\PSAT_Project_File_Schema.txt", "wb");
    curl_easy_setopt(curl, CURLOPT_URL, "https://psat-project.nishithp2004.repl.co/spotify/playlist/5fzKjvYdhKHyhQ6eAdltbP/game.txt");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(curl);
    fclose(fp);
    curl_easy_cleanup(curl);
    return 0;
}
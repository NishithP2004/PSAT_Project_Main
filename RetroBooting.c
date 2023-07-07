#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <stdbool.h>

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

    FILE* reader;
    char content[500000];
    int answer;
    int option, ans, score, i;
    char line[20000], temp[20000];
    bool flag;

    reader = fopen("game.txt", "r+");
    if (reader == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    score = 0;
    flag = false;
    strcpy(line, " ");
    strcpy(content, " ");
    while (fgets(line, sizeof(line), reader) != NULL) {
        strcat(content, line);
    }
    fclose(reader);

    i = 0;
    strcpy(temp, "");
    for ( i = 0; i<= strlen(content)-1;i++){
        while (content[i] != '\n') {
            strncat(temp, &content[i], 1);
            i = i + 1;
        }
        if (strcmp(temp, "-- BEGIN QUESTION --") == 0) {
        } else {
            if (strcmp(temp, "-- END QUESTION --") == 0) {
                flag = true;
            } else {
                if (flag == true) {
                    ans = atoi(temp);
                    scanf("%d", &option);
                    if (option == ans) {
                        printf("Correct Answer!!\n");
                        score = score + 1;
                    } else {
                        printf("Nope\n");
                    }
                    flag = false;
                } else {
                    printf("%s\n", temp);
                }
            }
        }
        strcpy(temp, "");
    }

    printf("Your score is %d!\n", score);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract words between start and end indices
char* get_words(const char* sentence, int start, int end) {
    // Base case: if start index is greater than or equal to end index, return an empty string
    if (start >= end) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }

    // Split the sentence into words
    char* copy = strdup(sentence); // Make a copy of the sentence
    char* token = strtok(copy, " ");
    char** words = malloc(0); // Array to store words
    int count = 0;

    while (token != NULL) {
        words = realloc(words, (count + 1) * sizeof(char*));
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }

    // Base case: if end index is greater than the length of words, set it to the length of words
    if (end > count) {
        end = count;
    }

    // Form the result string
    char* result = malloc(1);
    result[0] = '\0';
    for (int i = start; i < end; i++) {
        char* temp = strdup(result);
        free(result);
        result = malloc(strlen(temp) + strlen(words[i]) + 2); // +2 for space and null terminator
        strcpy(result, temp);
        strcat(result, words[i]);
        strcat(result, " ");
        free(temp);
    }

    // Free memory
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
    free(copy);

    return result;
}

int main() {
    const char* sentence = "This is a sample sentence for testing recursion";
    int start_index = 2;
    int end_index = 5;

    char* result = get_words(sentence, start_index, end_index);
    printf("%s\n", result);

    free(result); // Free allocated memory
    return 0;
}

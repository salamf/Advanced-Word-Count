#include <stdio.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define MAX_STDOUT_SIZE 4098 
#define MAX_STDOUT_SIZE 10000 

int redirect_stdout(int, char[]);

int run_output_test(char **, int, char*, int (*f)(int, char **)); 
int compare_to_file(const char*, char*);

void run_main(char*, char **, int, int (*f)(int, char **)); 
char* read_test_file(const char*);



void run_main(char* actual, char *argv[], int argc, int (*func)(int argc, char *argv[])) 
{
    int state = redirect_stdout(0, actual);
    func(argc, argv);
    redirect_stdout(state, actual);
}

char* read_test_file(const char* expected) {
 
    FILE *fp;
    size_t size = 0;
    char* contents = NULL;

    fp = fopen(expected, "r");
    if (fp == NULL) {
        fprintf(stderr, "ERROR: Unable to load: '%s'", expected); 
    }

    fseek(fp, 0, SEEK_END); 
    size = ftell(fp); 
    rewind(fp);

    contents = malloc((size + 1) * sizeof(*contents)); 
    fread(contents, size, 1, fp); 
    contents[size] = '\0'; 
    
    fclose(fp);

    return contents;
}

int run_output_test(char *argv[], int argc, char* expected, int (*func)(int argc, char *argv[])) 
{
    char actual[MAX_STDOUT_SIZE+1];
    int state = redirect_stdout(0, actual);
    func(argc, argv);
    redirect_stdout(state, actual);
    return compare_to_file(expected, actual);
}

int redirect_stdout(int state, char buffer[])
{
    int stdout_save = state;
    fflush(stdout);
    
    //Redirect stdout to buffer char[]
    //NOTE: assumes that char[] is big enough
    if (state == 0) {
        stdout_save = dup(STDOUT_FILENO); //save the stdout state
        freopen("NUL", "a", stdout); //redirect stdout to null pointer
        setvbuf(stdout, buffer, _IOFBF, MAX_STDOUT_SIZE); //set buffer to stdout
    } 
    //Redirect back to stdout
    else {
        freopen("NUL", "a", stdout); //redirect stdout to null again
        dup2(state, STDOUT_FILENO); //restore the previous state of stdout
        setvbuf(stdout, NULL, _IONBF, 0); //
        remove("NUL");
    }
    fflush(stdout);
    return stdout_save;
}

int compare_to_file(const char* expected, char* actual) {
 
    FILE *fp;
    char* contents = NULL;
    size_t size = 0;

    fp = fopen(expected, "r");
    if (fp == NULL){
        //printf("Could not open file %s",expected);
        return -1;
    }
    
    fseek(fp, 0, SEEK_END); 
    size = ftell(fp); 
    rewind(fp);

    contents = malloc((size + 1) * sizeof(*contents)); 
    fread(contents, size, 1, fp); /* Read 1 chunk of size bytes from fp into buffer */
    contents[size] = '\0'; 

    int ret = strncmp(contents, actual, strlen(actual));
    
    if (ret != 0) {
        printf("EXPECTED:\n%s", contents);
        printf("ACTUAL:\n%s", actual);
    }


    fclose(fp);
    return ret; 
}



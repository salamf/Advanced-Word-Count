#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"

void test_no_arguments(void)
{
    //TEST_IGNORE(); 
    char* message = "program: missing '--infile <filename> [--sort] [--print-words]'\n";
    char* argv[] = {"program", 0};
    char output[MAXCHAR] = {0};
    run_main(output, argv, 1, &real_main);
    TEST_ASSERT_EQUAL_STRING(message, output); 
}

void test_invalid_file(void)
{
    //TEST_IGNORE(); 
    char* message = "unable to open 'badfile.txt' for reading\n";
    char* argv[] = {"program", "--infile", "badfile.txt", 0};
    char output[MAXCHAR] = {0};
    run_main(output, argv, 3, &real_main);
    TEST_ASSERT_EQUAL_STRING(message, output); 
}

void test_no_file(void)
{
    //TEST_IGNORE(); 
    char* message = "program: missing '--infile <filename> [--sort] [--print-words]'\n";
    char* argv[] = {"program", "--infile", 0};
    char output[MAXCHAR] = {0};
    run_main(output, argv, 2, &real_main);
    TEST_ASSERT_EQUAL_STRING(message, output); 
}

void test_reorder(void)
{
    //TEST_IGNORE(); 
    char* message = "";
    char* argv[] = {"program", "--infile", "cases/t01.txt", "--sort", 0};
    char output[MAXCHAR] = {0};
    run_main(output, argv, 3, &real_main);
    TEST_ASSERT_EQUAL_STRING(message, output); 
}

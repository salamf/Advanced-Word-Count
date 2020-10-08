#include <stdlib.h>
#include <string.h>
#include "vendor/unity.h"


void test_sort_empty_file(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t01.txt", 0};
    char* test_case = "cases/B/c01.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t01.txt");    
    free(expected);
}


void test_sort_single_word(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t02.txt", 0};
    char* test_case = "cases/B/c02.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t02.txt");    
    free(expected);
}

void test_sort_long_word(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t03.txt", 0};
    char* test_case = "cases/B/c03.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t03.txt");    
    free(expected);
}

void test_sort_multi_words(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t04.txt", 0};
    char* test_case = "cases/B/c04.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t04.txt");    
    free(expected);
}

void test_sort_multi_line(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t05.txt", 0};
    char* test_case = "cases/B/c05.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t05.txt");    
    free(expected);
}

void test_sort_special_characters(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t06.txt", 0};
    char* test_case = "cases/B/c06.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t06.txt");    
    free(expected);
}

void test_sort_tie_breaker(void)
{
    //TEST_IGNORE();
    char* argv[] = {"a1", "--sort", "--infile", "cases/t07.txt", 0};
    char* test_case = "cases/B/c07.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t07.txt");    
    free(expected);
}

void test_sort_long_paragraph(void)
{
    TEST_IGNORE_MESSAGE("Used during evaluation only");
    char* argv[] = {"a1", "--sort", "--infile", "cases/t08.txt", 0};
    char* test_case = "cases/B/c08.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t08.txt");    
    free(expected);
}

void test_sort_long_paragraphs(void)
{
    TEST_IGNORE_MESSAGE("Used during evaluation only");
    char* argv[] = {"a1", "--sort", "--infile", "cases/t09.txt", 0};
    char* test_case = "cases/B/c09.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t09.txt");    
    free(expected);
}

void test_sort_super_long(void)
{
    TEST_IGNORE_MESSAGE("Used during evaluation only");
    char* argv[] = {"a1", "--sort", "--infile", "cases/t10.txt", 0};
    char* test_case = "cases/B/c10.txt";
    char actual[MAXCHAR] = {0};
    
    run_main(actual, argv, 4, &real_main);
    char* expected = read_test_file(test_case);
    TEST_ASSERT_EQUAL_LONG_STRING_MESSAGE(expected, actual, "=> t10.txt");    
    free(expected);
}


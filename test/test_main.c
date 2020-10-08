#include "vendor/unity.h"
#include "vendor/utils.h"

#include "../src/word_count.c"
#include "defines.h"
#include "test_input.h"
#include "test_A.h"
#include "test_B.h"
#include "test_C.h"


int main(void)
{
   UnityBegin("test/test_main.c");

   RUN_TEST(test_no_arguments);
   RUN_TEST(test_invalid_file);
   RUN_TEST(test_no_file);
   RUN_TEST(test_reorder);


   printf("======== Part A ===============\n");
   RUN_TEST(test_empty_file);
   RUN_TEST(test_single_word);
   RUN_TEST(test_long_word);
   RUN_TEST(test_multi_words);
   RUN_TEST(test_multi_line);
   RUN_TEST(test_special_characters);
   RUN_TEST(test_extra_spaces);
   RUN_TEST(test_long_paragraph);
   RUN_TEST(test_long_paragraphs);
   RUN_TEST(test_super_long);
   printf("===============================\n");
   
   printf("======== Part B ===============\n");
   RUN_TEST(test_sort_empty_file);
   RUN_TEST(test_sort_single_word);
   RUN_TEST(test_sort_long_word);
   RUN_TEST(test_sort_multi_words);
   RUN_TEST(test_sort_multi_line);
   RUN_TEST(test_sort_special_characters);
   RUN_TEST(test_sort_tie_breaker);
   RUN_TEST(test_sort_long_paragraph);
   RUN_TEST(test_sort_long_paragraphs);
   RUN_TEST(test_sort_super_long);
   printf("===============================\n");
   
   printf("======== Part C ===============\n");
   RUN_TEST(test_print_empty_file);
   RUN_TEST(test_print_single_word);
   RUN_TEST(test_print_long_word);
   RUN_TEST(test_print_multi_words);
   RUN_TEST(test_print_multi_line);
   RUN_TEST(test_print_special_characters);
   RUN_TEST(test_print_extra_spaces);
   RUN_TEST(test_print_long_paragraph);
   RUN_TEST(test_print_long_paragraphs);
   RUN_TEST(test_print_super_long);
   printf("===============================\n");

   UnityEnd();
   return 0;
}

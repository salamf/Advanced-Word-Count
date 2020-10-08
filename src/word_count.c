#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define FILE_NOT_FOUND  1
#define BAD_ARGS        2
#define MAX_FILESIZE    5000
#define MAX_WORD_CNT    750
#define MAX_WORD_LEN    35 //Supercalifragilisticexpialidocious
#define TRUE 1
#define FALSE 0

//initialize an array to number given in parameters
void initialize_array_to_num(int* arr, int length, int num){
    for(int i = 0; i < length; i++){
         arr[i] = num;
     }
}

//check if sort is in args
int check_sorted(char* arr[], int len){
    
    for(int i = 0; i < len; i++){
        if(strcmp(arr[i], "--sort") == 0){
            return TRUE;
        }
    }
    return FALSE;
}

//check if print words is in args
int check_print_words(char* arr[], int len){ 
    for(int i = 0; i < len; i++){
         if(strcmp(arr[i], "--print-words") == 0){
             return TRUE;
         }
     }
     return FALSE;
}

int find_file_index(char* arr[], int len){

    for(int i = 0; i < len; i++){
        if(strstr(arr[i], ".txt") != NULL) return i;
    }
    return FILE_NOT_FOUND;
}

//sets given index of arr to 0
void set_0(int* arr, int index){
    arr[index] = 0;
}

//prints largest value in arr then returns the index
//so the value in the position can be set to 0 later
int print_largest(int* arr, int len){
    int largest = arr[0];
    int index = 0;
    for(int i = 0; i < len; i++){
        if(arr[i] > largest){
            largest = arr[i];
            index = i;
        }        
    }
    if(index != 0){
        printf("Count[%02d]=%02d;", index, largest);
    }
    return index;
}

//////////////////////////////////////////////Functions not being used///////////////////////
//removes 0's from sorted array
/*int strip_0_sorted(int* arr, int len){

    int count = 0;
    while(arr[count] == 0)
        count++;
    
    int new_len = len - count;
    
    //shift
    for(int i = count; i < len; i++){
        arr[i-count] = arr[i];
    }
    return new_len;
}

//swap 2 index positions in arr
void swap(int* arr, int index1, int index2){

    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;

}

//quicksort algorithim
void quicksort(int* arr, int l, int r){

    if(l >= r) return;

    int pivot = arr[r];

    int split = l;

    for(int i = l; i <= r; i++){
        if(arr[i] <= pivot){
            swap(arr, split, i);
            split++; 
        }    
    }

    quicksort(arr, l, split-2);
    quicksort(arr, split, r);

}*/
/////////////////////////////////////////////////////////////////////////////////////////

//calculate median of an array
double median(int* arr, int len){

    if(len % 2 != 0){
        return arr[(len/2)];
    
    }else{
        int index_num_1 = len/2 - 1;
        int index_num_2 = len/2;

        return ((arr[index_num_1] + arr[index_num_2]) / 2.0);
    }
}   

//shift an array right from a certain index
void shift_right(char arr[][MAX_WORD_LEN], int len2, int starting_index){

    for(int i = len2 - 1; i > starting_index; i--){
       strncpy(arr[i], arr[i-1], strlen(arr[i-1]));
    }

}

//check if word exists in arr
int exists(char arr[][MAX_WORD_LEN], int num_words, char word []){
    
    for(int i = 0; i < num_words; i++){
        if(strcmp(arr[i], word) == 0) return TRUE;
    }
    return FALSE;
}

void check_other(char curr_word[], char input_word[], int letter_pos, int* check_empty){
            
    if(input_word[letter_pos] < curr_word[letter_pos]) *check_empty = 0;
        
    else if(input_word[letter_pos] == curr_word[letter_pos])
        check_other(curr_word, input_word, letter_pos+1, check_empty);

    else *check_empty = -1;

} 
 
//Place input_word in alphabetical order in arr
void place_in_alpha_order(char arr[][MAX_WORD_LEN], int num_words, char input_word[], int letter_pos){
    int check_empty = 0;
   
    int i;
    for(i = 0; *arr[i] != '\0'; i++){

        if(*arr[i] == '\0'){ check_empty = 1; break;}
            
        if(input_word[letter_pos] < arr[i][letter_pos]) break;
        
        if(input_word[letter_pos] == arr[i][letter_pos]){ 
            check_other(arr[i], input_word, letter_pos + 1, &check_empty);

            if(check_empty != -1){
                break;
            }
        
        }
    }
    if(check_empty == 0 || check_empty == -1)
        shift_right(arr, num_words + 1, i);
   
    strncpy(arr[i], input_word, strlen(input_word));
}

////////////////////////////////////////////////////////MAIN/////////////////////////////////////////////////////

int
real_main(int argc, char *argv[]) {

    int filename_index = find_file_index(argv, argc);
    
    if(filename_index == FILE_NOT_FOUND){
        printf("program: missing '--infile <filename> [--sort] [--print-words]'\n");
        return FILE_NOT_FOUND;
    }

    FILE* input_file = fopen(argv[filename_index], "r");
    if(input_file == NULL){
        printf("unable to open '%s' for reading\n", argv[filename_index]);
        return FILE_NOT_FOUND;
    }
    int character_lengths[MAX_WORD_LEN]; //increment the index of the word length everytime word
                                         //of that length is encountered

    initialize_array_to_num(character_lengths, MAX_WORD_LEN, 0); //Initialize character_lengths array to 0
                                                                 // (so we can increment)

    char words[MAX_WORD_LEN][MAX_WORD_CNT][MAX_WORD_LEN] = {{{'\0'}}}; //An array containing array's of strings
                                                                   // (store words into the array at the index
                                                                   // of the word length

    int word_length_counter = 0; //to count the length of each word
                                 //in order to determine which part of the
                                 //character_lengths array to increment

    char str [MAX_FILESIZE];
    while(fgets(str, MAX_FILESIZE, input_file) != NULL){
                                                                                    
        char word [MAX_WORD_LEN]; //temporarily store word before moving it to words
        int k = 0; //Incrementor for word

        int i = 0; //Incrementor for str
        while(str[i] != '\0'){
            if(str[i] != ' ' && isalpha(str[i])){ //If the current letter is not a space
                                                  //and is an alphanumeric character

                word_length_counter++; //increment the word length counter since this is a valid letter
                word[k++] = str[i]; //store the letters one by one into the word

            }else{ // when word is done
                   // (encounter either a space or a non alpha character

                character_lengths[word_length_counter]++; //increment the part of the array by 1 word
                
                //count the number of words that are already in that length of the array
                //(so that we don't need to loop all the way till 750 for no reason)
                //(program is already 0(n^3) complexity so doesn't make things slower)
                int num_words = 0;
                while(words[word_length_counter][num_words][0] != '\0'){
                    num_words++;
                }
                
                //if the word doesn't already exist and its not empty or a space
                //place word in correct spot in array 
                if((strcmp(" ", word) != 0 && strcmp("", word) != 0) &&
                     (exists(words[word_length_counter], num_words, word) == FALSE)){

                    place_in_alpha_order(words[word_length_counter], num_words, word, 0); //store the temp word into 
                                                                                       //the 2d array of words
                }
                word_length_counter = 0; //reset the word length counter
                                         //(so we can start again from next word)
                k = 0; //reset the word incrementer (|^)
                memset(&word[0], 0, sizeof(word)); //clear the word from the str (|^)
            }

            i++; //move on to next character in str
        }
    }

////////////////////////////////////////////After getting input from file////////////////////////////////////////


////////////////////////////////////only sort in arg
    if(check_sorted(argv, argc) == TRUE && check_print_words(argv, argc) == FALSE){ //if arg --sort is passed
                                                                                    //but --print-words is not
        int word_len_arr[MAX_WORD_LEN]; //Array to store the word lengths
                                        //(for median)
        //initialize to 0
        initialize_array_to_num(word_len_arr, MAX_WORD_LEN, 0); 
       
        //incrementer for word_len_arr        
        int j = 0;

        for(int i = 1; i < MAX_WORD_LEN; i++){ //loop from 1 because we dont want to include
                                               //word_lengths of 0!!
           
            //add the index(word length) to word_len_arr if the value it contains(the amount of words)
            //is NOT 0 or NOT a null terminator AND the length is not 0 (i)
            if((character_lengths[i] != 0 || character_lengths[i] != '\0') && i != 0){
                word_len_arr[j++] = i;
            } 
        }
        
        
        for(int i = 0; i < MAX_WORD_LEN; i++){

            int index = print_largest(character_lengths, MAX_WORD_LEN); //print the largest value in the
                                                                        //character length array
            if(index != 0) printf("\n");

            set_0(character_lengths, index); //set largest value to 0 after printing it
                                             //so we get the second largest when we print
                                             //the largest again
        }
        printf("Median word length: %.01f\n", median(word_len_arr, j)); //calculate and print the median

///////////////////////////////////Sort AND Print words in arg
    }else if(check_sorted(argv, argc) == TRUE && check_print_words(argv, argc) == TRUE){ //if both args --sorted
                                                                                         //and --print-words are
                                                                                         //passed

        for(int i = 0; i < MAX_WORD_LEN; i++){
        
            int index = print_largest(character_lengths, MAX_WORD_LEN); //print the largest value in the
                                                                        //character length array
            if(index != 0){

                int num_words = 0;
                while(words[index][num_words][0] != '\0'){
                    num_words++;
                }

                printf(" (words: ");
                int j;
                for(j = 0; j < num_words; j++){
                    printf("\"%s\"", words[index][j]);
                    if (j < num_words - 2) printf(", ");
                    
                    else if(j == num_words - 2) printf(" and ");
                }

                printf(")\n");
            }

            set_0(character_lengths, index);        
           
        }        
    
    }else{

        for(int i = 1; i < MAX_WORD_LEN; i++){
            if(character_lengths[i] != 0 || character_lengths[i] != '\0'){
                printf("Count[%02d]=%02d;\n", i, character_lengths[i]);
            }
        }    
    }

    fclose(input_file); //Close input_file
   
    return 0;
}


#ifndef TEST
int
main(int argc, char *argv[]) {
    return real_main(argc, argv);
}
#endif

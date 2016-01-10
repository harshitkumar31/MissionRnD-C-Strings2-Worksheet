/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int getLen(char* input);

int findRecursiveCount(char *str, char* word, int count1, int count2, int st);

int count_word_in_str_way_1(char *str, char *word){

	int count1 = getLen(word);
	int count2 = getLen(str);

	int flag,i,j,k;
	int no_words = 0;

	for (i = 0; i <= count2 - count1; i++){


		for (j = i; j < i + count1; j++){

			flag = 1;
			k = j - i;
			if (str[j] != word[k]){
				flag = 0;
				break;
				}

			}

		if (flag == 1)
			no_words++;
		}

	return no_words;

}

int getLen(char* input){

	int i;

	for (i = 0; input[i] != '\0'; i++);

	return i;

	}

int count_word_int_str_way_2_recursion(char *str, char *word){
	
	int count1 = getLen(word);
	int count2 = getLen(str);

	return findRecursiveCount(str,word,count1,count2,0);
}


int findRecursiveCount(char *str, char* word, int count1, int count2, int st){

	int flag = 0, i, j, k;
	int no_words = 0;



	for (i = st; i <= count2 - count1; i++){


		for (j = i; j < i + count1; j++){

			flag = 1;
			k = j - i;
			if (str[j] != word[k]){
				flag = 0;
				break;
				}

			}

		if (flag == 1)
			break;
		}

	if (flag == 1)
		return 1 + findRecursiveCount(str, word, count1, count2, j);
	else
		return 0;

	}

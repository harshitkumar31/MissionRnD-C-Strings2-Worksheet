/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

int getLength(char *str);

char * get_last_word(char * str){

	if (str==NULL)
		return NULL;
	
	char* lw;
	int i;

	int flag=0;
	int len = getLength(str);

	i = len-1;

	int st=0, end=0,k;

	while (str[i] != '\0'){
		if (str[i] != ' ' && flag==1){
			st = st - 1;
			
			}
		else if (str[i] != ' ' && flag == 0){

			st=end = i;
			
			flag = 1;
			}
		else if (flag == 1)
			break;
		
		i--;

		}
	lw =(char *) calloc(st + end + 1, sizeof(char));

	if (flag == 0){
		lw[0] = '\0';
		return lw;
		}

	for (k = 0, i = st; i <= end; i++, k++)
		lw[k] = str[i];

	lw[k] = '\0';
	return lw;
}

int getLength(char *str){
	
	int i=0;

	int inc = 1;
	while (str[i] != '\0'){
		inc *= 2;
		i += inc ;

		}

	while (str[i] == '\0' && i>=0)
		i -= 1;

	return i + 1;
	}
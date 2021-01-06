#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void dec2bin(int n);
void bin2dec(int n);
void unarycode(int n);
void gammacode(int n);

int main()
{
	//get usernmae
	char *buf;
	buf = (char *)malloc(10*sizeof(char));
	buf = getlogin();
	struct utmp *naveen;
	
	int accept = 0;
	do{
		printf("%s", buf);
		printf(" $ ");
		char test[15];
		scanf("%s",test );

		int b = strlen(test);


		char *one = "bin2dec";
		char *two = "dec2bin";
		char *three = "unarycode";
		char *four = "gammacode";
		char *five = "exit";
		int function = 0;

		if(strstr(test, one) != NULL){
			function =1;
		}else  if(strstr(test, two) != NULL){
			function = 2;
		}else if(strstr(test, three) != NULL){
			function = 3;
		}else if(strstr(test, four) != NULL){
			function = 4;
		}else if(strstr(test, five) != NULL){
			function = 5;
			accept = 1;
		}else{
			function = 6;
		}
		int count = 0;
		char newWord[0];
		int final = 0;
		//get number
		for(int i = 0; i < b; i++){
			char c = test[i];	
			char no = '(';
			char not = ')';
			count++;

			if(isalpha(c)){
				if(function == 1 && count>7){
					function = 6;
				}
				if(function == 2&& count> 7){
					function = 6;
				}
				if(function == 3 && count > 9){
					function = 6;
				}
				if(function == 4 && count > 9){
					function = 6;
				}
			}if(!isalpha(c)){
				if(count == 4){

				}else{
					if(c != no && c != not){
						strncat(newWord, &c, 1);
					}
				}
		}
}
		sscanf(newWord, "%d", &final);

		if(function == 5){
			accept = 1;
		}else if(function== 6){
			printf("Please enter a valid command\n");
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");
		}else if(function == 1){
			bin2dec(final);
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");
		}else if(function == 2){
			dec2bin(final);
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");

		}	else if(function == 3){
			unarycode(final);
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");

		}else if(function == 4){
			gammacode(final);
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");

		}else{
			function = 0;
			strcpy(test, "");
			strcpy(newWord, "");
		}
	}while(accept != 1);

	return 0;
}

void  dec2bin(int n){
	int  i = 0;
	int array[1000];

	while(n > 0){
		array[i] = (n%2);
		n = n/2;
		i++;
	}

	for(int j = i -1;j >= 0; j--){
		printf("%i", array[j]);
	}
	printf("\n");
}

void bin2dec(int n){
	int num = n;
	int dec_value = 0;
	int base = 1;
	int temp = num;
	while (temp)
	{
		int last_digit = temp % 10;
		temp = temp/10;
		dec_value += last_digit*base;
		base = base*2;
	}
	printf("%i\n", dec_value);
}

void unarycode(int n){
	for(int i = n; i > 0; i --){
		printf("1");
	}
	printf("0\n");
}


void gammacode(int n){
	if(n==1){
		printf("0");
		printf("\n");
	}else{
		int  i = 0;
		int array[1000];
		int count = 0;

		while(n > 0){
			array[i] = (n%2);
			n = n/2;
			i++;
		}

		for(int k = i-1; k > 0; k --){
			printf("1");
		}
		printf("0");

		for(int j = i -2;j >= 0; j--){
			printf("%i", array[j]);
		}
		printf("\n");
	}
}


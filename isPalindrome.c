#include <stdio.h> 
#include <assert.h> 
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>

//extern bool isPalindrome(const char *);


void strrev(char *string) 
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(string);
 
   begin = string;
   end = string;
 
   for ( c = 0 ; c < ( length - 1 ) ; c++ )
       end++;
 
   for ( c = 0 ; c < length/2 ; c++ ) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

bool isPalindrome(const char *a){
	
	if(a=="" || a==NULL){return false;}

	int left = 0;
	int right = strlen(a) - 1;
	int middle = strlen(a)/2;
	while(left<middle){
		if(toupper(a[left]) !=toupper(a[right])){return false;}
		right--;
		left++;
	}
	return true;
}



int main() {
	assert(isPalindrome("civic") == true);
	assert(isPalindrome("evitative") == true);
	assert(isPalindrome("radar") == true);
	assert(isPalindrome("stats") == true);
	assert(isPalindrome("abba") == true);
	assert(isPalindrome("aba") == true);
	assert(isPalindrome("aBa") == true);
	assert(isPalindrome("statss") == false);
	assert(isPalindrome("abracadabra") == false);
	printf("Lower case palindromes passed!\n");

	assert(isPalindrome("ABa") == true);
	assert(isPalindrome("cIviC") == true);
	printf("Upper/lower cases examples passed!\n");

	assert(isPalindrome("") == false);
	assert(isPalindrome(NULL) == false);
	printf("No string/empty string corner cases passed!\n");

	printf("Nailed it!! Congratulations!\n");

	return (0);
}

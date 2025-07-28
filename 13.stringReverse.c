/*
13.	Read a String and Just print it in the reverse order
*/

#include <stdio.h>
#include<string.h>  
 
 int main()
   {
      char s1[20],temp;
      int length;
       printf("Enter the string: ");
       fgets(s1, sizeof(s1), stdin);
        printf("The string is %s ",s1);
       
       length= strlen(s1);
       for(int i=0;i<length/2;i++)
         {
             temp=s1[i];
             s1[i]=s1[length-1-i];
             s1[length-1-i]=temp;
         }
       
        printf(" the reversed string is %s ",s1);
       
       return 0;
   }
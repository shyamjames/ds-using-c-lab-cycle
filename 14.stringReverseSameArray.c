/*
14.	Read a String and Reverse the string in the same array itself
*/

#include <stdio.h>
#include<string.h>
  
 
 int main()
   {
      char s1[20],temp;
      int length;
       printf("Enter the string: ");
       fgets(s1, sizeof(s1), stdin);
        printf("String is %s ",s1);
       
       length= strlen(s1);
       for(int i=0;i<length/2;i++)
         {
             temp=s1[i];
             s1[i]=s1[length-1-i];
             s1[length-1-i]=temp;
         }
       
        printf("The reversed string is %s ",s1);
       
       return 0;
   }
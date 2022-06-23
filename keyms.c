#include <stdio.h>
#include <windows.h>
#include <sysinfoapi.h>

int main(void) {
   unsigned int i, threshold;
   long long int begin, end, elapsed;
   //i = button to be tested HEX
   printf("# Enter Key value in hexadecimal to be tested:\n");
   scanf("%x", &i);
   //threshold in ms, if output is equal or shorter than this time = chatter
   printf("# Enter Chatter Threshold in ms:\n");
   scanf("%u", &threshold);  
   //testing loop
   while(1) {
   if (GetKeyState(i) < 0) {
      //start measuring time in ms
      begin = GetTickCount64();
      //loop until key is released
      while((GetKeyState(i)) < 0) {
         ;
      }
      //end measuring time in ms
      end = GetTickCount64();
      elapsed = (end - begin);
      if (elapsed <= threshold) {
         printf("######################\n");
         printf("## CHATTER DETECTED!!!\n");
         printf("## Time in ms %lld\n", elapsed);
      }
      else {
         printf("######################\n");
         printf("## OK\n");
         printf("## Time in ms %lld\n", elapsed); 
      }

   }
}
}
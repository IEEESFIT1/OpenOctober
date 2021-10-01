#include<iostream>
using namespace std;

void boyermoore(int shiftArr[], int borderArr[], string pattern) {
   int n = pattern.size();      
   int i = n;
   int j = n+1;
   borderArr[i] = j;

   while(i > 0) {
      while(j <= n && pattern[i-1] != pattern[j-1] ) {
         if(shiftArr[j] == 0)
            shiftArr[j] = j-i;    
         j = borderArr[j];      
      }
      i--;
      j--;
      borderArr[i] = j;
   }  
}

void partialSuffixMatch(int shiftArr[], int borderArr[], string pattern) {
   int n = pattern.size();
   int j;
   j = borderArr[0];

   for(int i = 0; i<n; i++) {
      if(shiftArr[i] == 0)
         shiftArr[i] = j;       
         if(i == j)
            j = borderArr[j];    
   }
}

void searchPattern(string mainString, string pattern, int array[], int *index) {
   int patLen = pattern.size();
   int strLen = mainString.size();
   int borderArray[patLen+1];
   int shiftArray[patLen + 1];

   for(int i = 0; i<=patLen; i++) {
      shiftArray[i] = 0; 
   }

   boyermoore(shiftArray, borderArray, pattern);
   partialSuffixMatch(shiftArray, borderArray, pattern);
   int shift = 0;
   while(shift <= (strLen - patLen)) {
      int j = patLen - 1;
      while(j >= 0 && pattern[j] == mainString[shift+j]) {
         j--;     
      }
      if(j < 0) {
         (*index)++;
         array[(*index)] = shift;
         shift += shiftArray[0];
      }else {
          shift += shiftArray[j+1];
      }
   }
}

int main() {
   string mainString = "KARTIKEYKARTKARTIKEY";
   string pattern = "KART";
   int locArray[mainString.size()];
   int index = -1;
   searchPattern(mainString, pattern, locArray, &index);

   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << locArray[i]<<endl;
    }
}

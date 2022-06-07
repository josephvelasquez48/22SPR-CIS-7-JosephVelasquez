#include <iostream>
#include <string>

using namespace std;

string Vig(string);
string encryption(string,string);      
string decryption(string,string);

int main() {
    
   string KEY;
   string ori;
   cout<<"Input the key to be used to encrypt/decrypt"<<endl;
   cout<<"Key must be capitalized:"<<endl;
   cin>>KEY;
   cout<<"Input word or phrase to encrypt/decrypt:"<<endl;
   cin>>ori;
   cout<<endl;
   string Vig(KEY);
   string encrypt = encryption(ori,KEY);
   string decrypt = decryption(encrypt,KEY);
   cout << "Original Message: "<<ori<< endl;
   cout << "Encrypted Message: " << encrypt << endl;
   cout << "Decrypted Message: " << decrypt << endl;
}
//function handles KEY
   string Vig(string k) {  
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            k += k[i] + 'A' - 'a';
      }
      return k;
   }
   //function handles encryption
   string encryption(string t, string k) { //passing inputted string & key
      string output;    //stores new string to be displayed
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i]; //creating character array
         if (c >= 'a' && c <= 'z') {
            c += 'A' - 'a';
            output += (c + k[j] - 2 * 'A') % 26 + 'A'; 
         //added A to offset to ASCII [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
         }
         else if (c >= 'A' && c <= 'Z'){
            c += 'A' - 'A';
            output += (c + k[j] - 2 * 'A') % 26 + 'A';
         //added A to offset to ASCII [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
         }
         else if (c < 'A' || c > 'Z'){
            c=c;
         output += c ; 
         
         j = (j + 1) % k.length();
         }
         
      }
      return output;    //returns string that is displayed on console
   }
   //function handles decryption
   string decryption(string t, string k) {  //passing encrypted string & key
      string output;    //stores new string to be displayed
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i]; //creating character array
         if (c >= 'A' && c <= 'Z'){
            c += 'A' - 'A';
            output += (c - k[j] + 26) % 26 + 'A';
         //added A to offset to ASCII [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
         }
         
         else if (c < 'A' || c > 'Z'){
            c=c;            
         output += c;
         
         j = (j + 1) % k.length();
         }
         
      }
      
      return output;    //returns string that is displayed on console
   }
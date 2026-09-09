#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
string s;
cout<< "enter the word\n";
cin>> s;
cout<< "the given string is:"<<s<< endl;

for(char c:s)
cout<<(char)toupper(c);

bool pal=true;
size_t i=0,j=s.size()-1;

for(i=0;i<j;++i,--j)
{
    if(s[i]!=s[j])
    {
        pal=false;
        break;
       
    }
    break;
}
if (pal==false)
   cout<<"the given string is not a palindrome\n";
else 
    cout<<"the given string is a palindrome\n";

size_t pos = s.find("ad");
if (pos==1)
cout<<"the substring is found in the given string"<< endl;

else 
cout<<"the substring is not found in the given string"<< endl;
return 0;



}
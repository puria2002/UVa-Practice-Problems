//solution for UVa 11988: Broken Keyboard
#include<iostream>
#include<list>
using namespace std;

int main(void)
{
   list<char> text;
   char c;
   list<char>::iterator pos;
   ios::sync_with_stdio(false);
   while (!cin.eof())
   {
       pos = text.end();
       while (cin.get(c), c != '\n') 
       {
           if (c == '[')
           { 
               pos = text.begin();
               continue;
           }
           if (c == ']')
           {
               pos = text.end();
               continue;
           }
           text.insert(pos, c); 

       } 
       for (char s : text)
       {
           std::cout << s;
       }
       std::cout << endl;
       text.clear();
        
   }
   return 0;
} 


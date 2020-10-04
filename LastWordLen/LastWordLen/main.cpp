//
//  main.cpp
//  LastWordLen
//
//  Created by Hao Lam on 12/29/19.
//  Copyright © 2019 Hao Lam. All rights reserved.
//

#include <iostream>
using namespace std;
int lengthOfLastWord(string s)
{
       int lastSpace= -1;

       for (int i=0; i<s.length() ; i++)
       {
           if (s[i] == ' ')
           {
               lastSpace = i;
           }
       }
       if (lastSpace==s.length() )
       {
           // no last word;
           return 0;
       }
       if (lastSpace==-1)
       {
           // no space
           return s.length();
       }
    return s.length()-lastSpace-1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<lengthOfLastWord("Hello  wor df2/.3 ...")<<endl;
}

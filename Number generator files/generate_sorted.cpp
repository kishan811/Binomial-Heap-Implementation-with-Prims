#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
   fstream file; //object of fstream class
    
   //opening file "sample.txt" in out(write) mode
   file.open("temp2.txt",ios::out);
    
   if(!file)
   {
       cout<<"Error in creating file!!!"<<endl;
       return 0;
   }
    
   cout<<"File created successfully."<<endl;
   //write text into file
   for(int i=1;i<=2000000;i++)
     file<<i<<"\n";
 // file++;
 //    cout<<*file;

   //closing the file
   file.close();
    
   //again open file in read mode
   file.open("temp2.txt",ios::in);
    
   if(!file)
   {
       cout<<"Error in opening file!!!"<<endl;
       return 0;
   }   
    
   //read untill end of file is not found.
   char ch; //to read single character
   // cout<<"File content: ";
    
   while(!file.eof())
   {
       file>>ch; //read single character from file
      // cout<<ch;
   }
    
   file.close(); //close file
    
   return 0;
}
/**
Author : Adrian Daniel Hausi
Date: 09.04.2020
**/
#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;
#define Nmax 30


ifstream fin("input.in");
ofstream fout("output.out");
void readFile(); /// In this function I read the data from the file
void show(); /// This function was written for debug only purpose
void removeAverage();/// The average of A will be removed from every element
bool checkPowersets();/// If there's a sum of a power set with n-1 at most elements that is equal with 0 then we have at least an solution.

float A[Nmax];
int n = 0;

int main()
{
   readFile();
   removeAverage();
   //show();
   if(checkPowersets())fout<<"True\n";
     else fout<<"False\n";

    fout.close();

    return 0;
}


void readFile()
{
   char s[400]="", *c;

   // String buffer
   char ss[400];

   //Reading from file line by line
   while(!fin.eof())
   {
    fin.getline(ss,199,'\n');
    strcat(s, ss);
   }


   //Deleting separators and put every number in A using
   //stof (string to float)
   c = strtok(s," []\n,");
   while(c!=NULL)
   {
       A[n++]= stof(c);
       c = strtok(NULL," []\n,");
   }
    fin.close();
}


void show()
{
    cout<<'\n';
    cout<<n<<": ";

    for(int i=0;i<n;i++) cout<<A[i]<<' ';
    cout<<'\n';
}


void removeAverage()
{
   float avg=0;
   for(int i=0; i<n; i++) avg +=A[i];
   avg/=n;
   for(int i=0; i<n; i++) A[i]-=avg;

}

bool checkPowersets()
{
    float sum = 0;
    unsigned int size_pow = 1<<n;

    int i,j;
    for(i=1; i<size_pow-1; i++)
    {
        sum=0;
        for (j=0; j<n; j++) sum += (i&(1<<j))?A[j]:0;
        if(sum==0) return true;

    }
     return false;

}

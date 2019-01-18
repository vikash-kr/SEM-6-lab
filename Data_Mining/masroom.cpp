#include <bits/stdc++.h> 
using namespace std;
string arr[100];
int SUPPORT1 = 50; 

void splitFn(string str){
   
   int count =0;
   string word = ""; 
   for (auto x : str) 
   { 
       if (x == ' ') 
       { 
           //cout << word << " "; 
           arr[count] = word;
           count++;
           word = ""; 
       } 
       else
       { 
           word = word + x; 
       } 
   }
   arr[count] = word;
} 


int main () {
   std::ifstream input( "mushroom.dat" );
   string inputData[9000];
   int count =0;
   for( std::string line; getline( input, line ); )
   {
       inputData[count] = line;
       //cout<<inputData[count]<<endl;
       count++;
   }
   cout<<"No of transaction is"<<count<<endl;
   map <string, int> frequency;
   //map <string, int> frequency;

   for(int i=0;i<(count-1);i++){
      splitFn(inputData[i]);
      int tmp =0;
      while(tmp<16){
         frequency[arr[tmp]]++;
         tmp++;
      }
   }

   std::map<string,int>::iterator it;
   cout<<"showing result with support "<<SUPPORT1<<endl;
   for (it=frequency.begin(); it!=frequency.end(); ++it){
      if(((it->second)*100)/count > SUPPORT1)
         std::cout << it->first << " => " << it->second << '\n';
   }
   

   return 0;
}
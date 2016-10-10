#include<iostream.h> 
#include<fstream.h>
#include<stdlib.h> //system();
#include<vector>
#include<string>


int main( int argc, char** argv )
{
 ifstream in( "estrazioni_nospazio.txt" );
 string line;
 string lineout;
 ofstream out( "output.txt" );

 while( getline(in,line) ){
        if( line.length() == 26 )
            for( int i=0; i < 26; i++ )
                 if( i <= 9 || i >= 12 )
                     out << line[ i ];
        if( line.length() == 27 )
            for( int i=0; i < 27; i++ )
                 if( i <= 9 || i >= 13 )
                     out << line[ i ];
        out << endl;
 }


 system( "PAUSE" );
 return 0;
}

int load_database()
{
}

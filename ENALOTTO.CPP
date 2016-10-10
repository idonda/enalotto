#include<iostream.h> 
#include<fstream.h>
#include<stdlib.h> //system(); atoi();
#include<vector>
#include<string>

class database
{
 public:
 int numeri[ 90 ];
 vector<string>estrazioni;
 vector<string>estrazioni_date;
 vector<string>estrazioni_concorsi;
 vector<string>estrazioni_numeri;
 vector< vector<int> >estrazioni_numeri_int;

}adatabase;

int main( int argc, char** argv )
{
 //Controllo apertura database =================================================
 if( argc <= 1 ) return 0;
 ifstream in( argv[ 1 ] );
 if( !in ){
     cout << "Impossibile aprire: " << argv[ 1 ] << endl;
     return 0;
 }

 //Caricamento Database ========================================================
 string line;
 while( getline( in, line ) )
        adatabase.estrazioni.push_back( line );


 //Caricamento estrazioni_date,estrazioni_concorsi,estrazioni_numeri,numeri ====
 for( int i=0; i < adatabase.estrazioni.size(); i++ ){
      //Carica la prima parte della stringa: la data
      line = "";
      for( int j=0; j <= 9; j++ ) line += adatabase.estrazioni[ i ][ j ];
      adatabase.estrazioni_date.push_back( line );
      //Carica il numero di concorso
      line = "";
      for( int j=11; adatabase.estrazioni[ i ][ j ] != ' ' && j < 13; j++ ) line += adatabase.estrazioni[ i ][ j ];
           adatabase.estrazioni_concorsi.push_back( line );
      //Carica l'ultima parte della stringa: i numeri + jolly
      line = "";
      if( adatabase.estrazioni[ i ][ 12 ] == ' ' ){
      for( int j=13; j < adatabase.estrazioni[ i ].length(); j++ ) line += adatabase.estrazioni[ i ][ j ];
           adatabase.estrazioni_numeri.push_back( line );
      }else{
            for( int j=14; j < adatabase.estrazioni[ i ].length(); j++ ) line += adatabase.estrazioni[ i ][ j ];
           adatabase.estrazioni_numeri.push_back( line );
      }
 }

 //Estrazione dei numeri da string a int =======================================
 for( int i=0; i < adatabase.estrazioni.size(); i++ ){
      line = "";
      vector<int>temp;
      for( int j=0; j < adatabase.estrazioni_numeri[ i ].length(); j++ ){
           if( adatabase.estrazioni_numeri[ i ][ j ] == ' ' || j == adatabase.estrazioni_numeri[ i ].length()-1 ){
               temp.push_back( atoi( &line[ 0 ] ) );
               line = "";
               continue;
           }
           line += adatabase.estrazioni_numeri[ i ][ j ];
      }
      adatabase.estrazioni_numeri_int.push_back( temp );
      //delete &temp;
      cout << adatabase.estrazioni_numeri_int[i][0] << endl;
      system( "pause" );
 }

 system( "PAUSE" );
 return 0;
}



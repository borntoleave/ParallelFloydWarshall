/*--------------------------------------------------*/
/* FILE:  io_dat.c                                  */
/*--------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "io_idat.h"

void read_idat( char * fname, int * mp, int * np, int *&zzp )
{
   FILE * fp ;
   int m, n  ;
   int mn ;
   int * zp ;
   int dummy ;

   fp = fopen( fname, "rb" ) ;
   if ( fp == NULL ) {
      fprintf(stderr,"read_idat():  Unable to read file '%s'\n", fname ) ;
      exit(7) ;
   }
   dummy = fread( &m, sizeof(int), 1, fp ) ; 
   dummy = fread( &n, sizeof(int), 1, fp ) ; 
   mn = m * n ;
   zp = (int *) malloc( mn * sizeof(int) ) ;
   if ( zp == NULL ) {
      fprintf(stderr,"read_idat():  malloc failed !!!\n") ;
      exit(20) ;
   } 
   dummy = fread( zp, sizeof(int), mn, fp ) ; 
   fclose(fp) ;
   *mp = m ;  
   *np = n ; 
   zzp = zp ;
}

void write_idat( int m, int n, int * zp, char * fname ) 
{
   FILE * fp ;
   int mn ;
   int dummy ;

   fp = fopen( fname, "wb" ) ;
   if ( fp == NULL ) {
      fprintf(stderr,"write_idat():  Unable to write file '%s'\n", fname ) ;
      exit(3) ;
   }
   dummy = fwrite( &m, sizeof(int), 1, fp ) ; 
   dummy = fwrite( &n, sizeof(int), 1, fp ) ; 
   mn = m * n ;
   dummy = fwrite( zp, sizeof(int), mn, fp ) ; 
   fclose(fp) ;
}

#include "gryphflix.h"



FILE *openFileForReading(char *fileName)
{
 FILE * file;
 file = fopen (fileName, "r");

 if (file == NULL)
  {
    printf("File doesnt exist.\n");
    return NULL;
  }

  else
  {
    return file;
  }

}



int readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR] )
{

 int i;

  if (file == NULL)
  {
    return 0;
  }

  for(i=0 ; i<NUMBER_MOVIES;i++)
  {
   fgets( movieNames[i], MAX_STR , file );
   movieNames[i][strlen(movieNames[i])-1]='\0';
  }

  fclose (file);

 if (i> NUMBER_MOVIES)
 {
   return 0;
 }
 return 1;
}


int readReviews( FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS] )
{
  int i =0;
  char swapReview;

  if (file == NULL )
  {
    return 0;
  }

  else
  {


    while(!feof(file))
    {

      if(i>=NUMBER_REVIEWERS)
      {
        return 0;
      }

      fscanf(file,"%s",reviews[i].reviewer);

      for (int j=0 ;j<NUMBER_MOVIES ; j++)
      {
        fgetc(file);
        fscanf(file,"%c",&swapReview);
        if ((swapReview == 'Y' || swapReview =='y'))
        {
          reviews[i].feedback[j]=1;
        }
        else
        {
          reviews[i].feedback[j]=0;
        }
      }
     i++;
     fgetc(file);
    }


   if(i<NUMBER_REVIEWERS)
   {
     return 0;
   }

  }
  return 1;
}


int getMostCriticalReviewers( struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR] )
{

  int minReview =0;
  int numReviews =0;


  for(int i =0; i<NUMBER_REVIEWERS;i++)
  {
    int countZero = 0;

    for (int j = 0; j<NUMBER_MOVIES;j++)
    {
      if (reviews[i].feedback[j]==0)
      {
        countZero = countZero +1;
      }
    }

    if ( countZero > minReview )
    {
      minReview = countZero;
    }

  }

  for(int i =0; i<NUMBER_REVIEWERS;i++)
  {
    int countZero = 0;

    for (int j = 0; j<NUMBER_MOVIES;j++)
    {
      if (reviews[i].feedback[j]==0)
      {
        countZero = countZero +1;
      }
    }

    if ( countZero == minReview )
    {
      strcpy(mostCriticalReviewers[numReviews], reviews[i].reviewer );
      numReviews++;
    }

  }

  return numReviews;
}

int getMostRecommendedMovies( const char movies[NUMBER_MOVIES][MAX_STR], const struct reviewStruct reviews[NUMBER_REVIEWERS],char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR])
{

  int z = 0;
  int movie1 = 0;
  int movie2 = 0;
  int movie3 = 0;

  int i;
  for (i = 0; i < NUMBER_REVIEWERS; i++)
  {
    movie1 = movie1 + reviews[i].feedback[0];
    movie2 = movie2 + reviews[i].feedback[1];
    movie3 = movie3 + reviews[i].feedback[2];

  }

  if ( movie1 > (movie2 && movie3) )
  {
    strcpy(mostRecommendedMovies[z], movies[0]);
    z = z + 1;
  }

  if (movie2 > (movie1 && movie3) )
  {
    strcpy(mostRecommendedMovies[z], movies[1]);
    z = z + 1;
  }

  if (movie3 > (movie1 && movie2) )
  {
    strcpy(mostRecommendedMovies[z], movies[2] );
    z = z + 1;
  }


 return z;

}


int predictMovie(const char movie[MAX_STR])
{
  return 1;
}

int enumerateMovie( const char movie[MAX_STR], int charCounts[MAX_WORDS] ) 
{
  return 1;
}
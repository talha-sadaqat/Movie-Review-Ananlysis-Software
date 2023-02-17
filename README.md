# Movie-Review-Ananlysis-Software
A movie review analysis software ,  The program reads in movie titles and reviews from files, and performs various analyses on the data, including identifying the most critical reviewers and the most recommended movies. The program also includes functions for predicting the success of a movie and enumerating the words in a given movie title.


This code implements a movie review analysis program that determines the most critical reviewers and the most recommended movies. It also provides a function for predicting movies and enumerating movies.

Functions
openFileForReading(char *fileName): This function takes a filename as input and returns a file pointer. It returns NULL if the file doesn't exist.

readMovies(FILE *file, char movieNames[NUMBER_MOVIES][MAX_STR]): This function reads the movie names from a file and stores them in an array.

readReviews(FILE *file, struct reviewStruct reviews[NUMBER_REVIEWERS]): This function reads the movie reviews from a file and stores them in a structure.

getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR]): This function determines the most critical reviewers based on their reviews and returns their names.

getMostRecommendedMovies(const char movies[NUMBER_MOVIES][MAX_STR], const struct reviewStruct reviews[NUMBER_REVIEWERS], char mostRecommendedMovies[NUMBER_REVIEWERS][MAX_STR]): This function determines the most recommended movies based on their reviews and returns their names.

predictMovie(const char movie[MAX_STR]): This function predicts the success of a given movie.

enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS]): This function enumerates the words in a given movie.

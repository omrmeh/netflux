#ifndef FILMS_H
#define FILMS_H

#include <QObject>
#include <string>

class FILMS
{
public:
    FILMS(string title, int year, int ratings, string poster, string synopsis, int length);

    QString title();
    QString genre();
    int year();
    int ratings();
    QString poster();
    QString synopsis();
    int length();

    Genre *genre ();


private :
    QString mTitle;
    QString mGenre;
    int mYear;
    int mRatings;
    QString mPoster;
    QString mSynopsis;
    int mLength;

    Genre* mGenre;

};

#endif // FILMS_H

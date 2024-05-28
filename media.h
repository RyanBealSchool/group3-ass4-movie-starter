#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
using namespace std;

class Media {
protected:
	void initalizeMedia(const char& mediaType, const int& mediaStock, const string& mediaTitle); //used for constuctor var assignment of children classes
	virtual void readObjFromStream(istream& stream); //virtual function used in operator>> to make reading in objects virtual

	string title; // the name of the media
	char type; //the type of media
	int stock; // the current stock of the media
	string hashTableLookUpID; //Id used to search Hash table
	/*
	* Media hashTableLookUpID key (no spaces except between the words in a title and first and last name):
	* Comedy: titleYear
	* Drama: directorTitle
	* Classic: monthYearActor
	*/

public:
	explicit Media(); //default constructor
	bool borrowMedia(); //borrow the media (true:stock was taken | false:there was no more stock)
	void returnMedia(); //return the media
	virtual string toMediaString() const = 0; //get the media as a string (formatted by children)

	string getTitle() const;
	string getMediaID() const;
	
	int getStock() {
		return stock;
	}


	virtual bool operator<(const Media& compMedia) const; //compare if this media is less than the passed in
	virtual bool operator==(const Media& compMedia) const; //compare if this media is greater than the passed in
	friend istream& operator>>(istream& stream, Media &inMedia); //read in a media from the stream
};
#endif
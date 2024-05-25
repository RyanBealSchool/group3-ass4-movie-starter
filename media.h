#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
using namespace std;

class Media {
public:
	explicit Media(); //default constructor
	bool borrowMedia(); //borrow the media (true:stock was taken | false:there was no more stock)
	void returnMedia(); //return the media
	virtual string toMediaString() const = 0; //get the media as a string (formatted by children)

	virtual bool operator<(const Media& compMedia) const = 0; //compare if this media is less than the passed in
	virtual bool operator==(const Media& compMedia) const = 0; //compare if this media is greater than the passed in
	friend istream& operator>>(istream& stream, Media &inMedia); //read in a media from the stream

protected:
	void initalizeMedia(const int& mediaStock, const string& mediaTitle); //used for constuctor var assignment of children classes
	virtual void readObjFromStream(istream& stream); //virtual function used in operator>> to make reading in objects virtual

	string title; // the name of the media
	int stock; // the current stock of the media
};
#endif
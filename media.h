#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
using namespace std;

class Media {
public:
	Media(string mediaTitle, int mediaStock); //constructor for media class
	bool borrowMedia(); //borrow the media (true:stock was taken | false:there was no more stock)
	void returnMedia(); //return the media
	virtual string toMediaString() = 0; //get the media as a string

	virtual bool operator<(Media compMedia) = 0; //compare if this media is less than the passed in
	virtual bool operator==(Media compMedia) = 0; //compare if this media is greater than the passed in
	friend istream& operator>>(istream& stream, Media &inMedia); //read in a media from the stream

private:
	virtual void readObjFromStream(istream& stream); //virtual function sued in operator>> to make reading in objects virtual

	string title; // the name of the media
	int stock; // the current stock of the media
};
#endif
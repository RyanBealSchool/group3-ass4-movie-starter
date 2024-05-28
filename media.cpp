#include "media.h"

Media::Media() // default constructor
{
	title = "";
	stock = 0;
}

bool Media::borrowMedia() //borrow a copy of the media
{
	//if there is stock left, remove one a  return successful
	if (this->stock > 0)
	{
		this->stock--;
		return true;
	}
	//if there is no more stock, return unsuccessful
	else
	{
		return false;
	}
}

void Media::returnMedia() //return a copy of the media
{
	this->stock++;
}

string Media::getTitle() const{
	return this->title;
}

string Media::getMediaID() const{
	return hashTableLookUpID;
}

bool Media::operator<(const Media& compMedia) const{
	if (this->type == 'F') {
		return false;
	}
	else if (compMedia.type == 'F'){
		return true;
	}
	else if (this->type == 'D') {
		return false;
	}
	else if (compMedia.type == 'D'){
		return true;
	}
	else {
		return false;
	}

}

bool Media::operator==(const Media& compMedia) const{
	if (this->type == compMedia.type){
		return true;
	}
	else{
		return false;
	}
}

void Media::initalizeMedia(const char& mediaType, const int& mediaStock, const string& mediaTitle) //initalize the media variables
{
	this->type = mediaType;
	this->title = mediaTitle;
	this->stock = mediaStock;
}

void Media::readObjFromStream(istream& stream) //media objects should not be read from streams. definition only in place for use as virtual function
{
	stream >> type; // read in the movie type
}

istream& operator>>(istream& stream, Media& inMedia) // read a child object from the passed in stream
{
	inMedia.readObjFromStream(stream);
	return stream;
}

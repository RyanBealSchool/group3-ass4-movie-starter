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

void Media::initalizeMedia(const int& mediaStock, const string& mediaTitle) //initalize the media variables
{
	this->title = mediaTitle;
	this->stock = mediaStock;
}

void Media::readObjFromStream(istream& stream) //media objects should not be read from streams. definition only in place for use as virtual function
{
}

istream& operator>>(istream& stream, Media& inMedia) // read a child object from the passed in stream
{
	inMedia.readObjFromStream(stream);
	return stream;
}

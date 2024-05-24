#include "media.h"

Media::Media(string mediaTitle, int mediaStock) {
	this->title = mediaTitle;
	this->stock = mediaStock;
}

bool Media::borrowMedia()
{
	if (this->stock > 0)
	{
		this->stock--;
		return true;
	}
	else
	{
		return false;
	}
}

void Media::returnMedia()
{
	this->stock++;
}

void Media::readObjFromStream(istream& stream)
{
}

istream& operator>>(istream& stream, Media& inMedia)
{
	inMedia.readObjFromStream(stream);
	return stream;
}

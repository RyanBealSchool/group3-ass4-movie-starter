#include "transaction.h"

Transaction::Transaction()
{
    type = "";
    id = -1;
    medt = "";
    movt = "";
    this->title = "";
    this->director = "";
    this->year = "";
    this->actor = "";
}

Transaction::Transaction(string t)
{
    type = t;
    id = -1;
    medt = "";
    movt = "";
    this->title = "";
    this->director = "";
    this->year = "";
    this->actor = "";
}

Transaction::Transaction(string t, int id)
{
    type = t;
    this->id = id;
    medt = "";
    movt = "";
    this->title = "";
    this->director = "";
    this->year = "";
    this->actor = "";
}

Transaction::Transaction(string t, int id, string medt, string movt, int stock, string director, string title, int year)
{
    type = t;
    this->id = id;
    this->medt = medt;
    this->movt = movt;
    this->title = title;
    this->director = director;
    this->year = year;
    this->actor = actor;
}

Transaction::Transaction(string t, int id, string medt, string movt, int stock, string director, string actor, int year, string c)
{
    type = t;
    id = id;
    this->medt = medt;
    this->movt = movt;
    this->title = title;
    this->director = director;
    this->year = year;
    this->actor = actor;
}

string Transaction::getType()
{
    return type;
}

string Transaction::getMediaType()
{
    return medt;
}

string Transaction::getMovieType()
{
    return movt;
}

int Transaction::getId()
{
    return id;
}

string Transaction::getMovieTitle()
{
    return this->title;
}
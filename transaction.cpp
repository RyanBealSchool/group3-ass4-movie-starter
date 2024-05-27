#include "transaction.h"

Transaction::Transaction()
{
    type = "";
    id = -1;
    medt = "";
    movt = "";
}

Transaction::Transaction(string t)
{
    type = t;
    id = -1;
    medt = "";
    movt = "";
}

Transaction::Transaction(string t, int id)
{
    type = t;
    this->id = id;
    medt = "";
    movt = "";
}

Transaction::Transaction(string t, int id, string medt, string movt, int stock, string director, string title, int year)
{
    type = t;
    this->id = id;
    this->medt = medt;
    this->movt = movt;
    
}

Transaction::Transaction(string t, int id, string medt, string movt, int stock, string director, string title, int year, string actor, int date)
{
    type = t;
    id = id;
    this->medt = medt;
    this->movt = movt;
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

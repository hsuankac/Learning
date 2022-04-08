#include "Movie.h"
#include <iostream>

Movie::Movie(std::string name, std::string rating, int watched)
    :name{name}, rating{rating}, watched{watched}
{
}

// Implementation of the copy constructor
Movie::Movie(const Movie &source)
    :Movie(source.name, source.rating, source.watched)
{

}

Movie::~Movie()
{
}

// Implementation of the display method
void Movie::display() const
{
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}


#include <string>
#include "song.h"
#include <iostream>
using namespace std;

Song::Song()
{
  title = " ";
  artist = " ";
  album = " ";
} //default constructor

istream& operator >> (istream &is, Song &s)
{
  getline(is, s.title, '_');
  is.ignore(2);
  getline(is, s.artist, '_');
  is.ignore(2);
  is.ignore(1000, '_');
  is.ignore(2);
  getline(is, s.album, '\n'); 
  return is;
} // overloaded >>()

ostream& operator << (ostream &os, Song &s)
{
  os << s.title << ":" << s.artist << ":" << s.album;
  return os;
} //overloaded <<()

void Song::removeCd()
{
  string cd = "CD+G";
  size_t found = album.find(cd);

  if (found != string::npos)
  {
    album = album.substr(0, found-1);
  } //if "CD+G" was found

}// removeCd()

void Song::convertCase()
{
  string::iterator itr = artist.begin();
  itr++;

  while(itr != artist.end())
  {

    if (*itr == ' ')
    {
      itr++;

      if (*itr == '&')
      {
        --itr;
      } //if the character is &

      itr++;
    } //if the character is a space

    if (itr >= artist.end())
      break;

    if (*itr && *itr >= 'A' && *itr <= 'Z')
      *itr += 32;

    itr++;
  } //while it's not past the end of the string

} // convertCase()

void Song::move()
{
  string temp = " ";
  size_t find = title.find(' ');

  if (find != string::npos)
    temp = title.substr(0, find);

  if (temp.compare("A") == 0)
  {
    title.erase(0, 2);
    title += ", A";
  } //if the title is preceded by A

  if (temp.compare("THE") == 0)
  {
    title.erase(0, 4);
    title += ", THE";
  } //if the title is preceded by THE

} //move()

string Song::getArtist()
{
  return artist;
} //getArtist()

string Song::getTitle()
{
  return title;
} //getTitle()

string Song::getAlbum()
{
  return album;
} //getAlbum()


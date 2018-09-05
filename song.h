#ifndef SONG_H
  #define SONG_H

#include <string>
#include <vector>
using namespace std;

class Song
{
  string title;
  string artist;
  string album;
 public:
  Song(); //constructor set
  friend istream& operator >> (istream &is, Song &s);
  friend ostream& operator << (ostream &os, Song &s);
  void removeCd();
  void convertCase();
  void move();
  string getArtist();
  string getTitle();
  string getAlbum();
  friend vector<Song> sortTitle(vector<Song> sortMe);
  friend vector<Song> sortArtist(vector<Song> sortMe);
}; // Song class

#endif

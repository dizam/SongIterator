#include "song.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

vector<Song> sortTitle(vector <Song> sortMe)
{

  if (sortMe.size() <= 1)
  {
    return sortMe;
  } //if 0 or 1 elements

  vector<Song>::iterator itr1;
  vector<Song>::iterator itr2;
  vector<Song>::iterator temp;
  itr1 = sortMe.begin();
  itr1++;

  while (itr1 != sortMe.end())
  {

    itr2 = itr1;
    temp = --itr2;
    itr2++;

    while (itr2 != sortMe.begin() && (*temp).title.compare((*(itr2)).title) > 0)
    {

      swap((*temp).artist, (*itr2).artist);
      swap((*temp).title, (*itr2).title);
      swap((*temp).album, (*itr2).album);
      --itr2;
      --temp;
    } //while elements to the left are bigger and it's not at the beginning

    itr1++;
  } //while it's not at the end of the vector

  return sortMe; 
} //sortTitle()

vector<Song> sortArtist(vector <Song> sortMe)
{

  if (sortMe.size() <= 1)
  {
    return sortMe;
  } //if 0 or 1 elements

  vector<Song>::iterator itr1;
  vector<Song>::iterator itr2;
  vector<Song>::iterator temp;
  itr1 = sortMe.begin();
  itr1++;

  while (itr1 != sortMe.end())
  {
    itr2 = itr1;
    temp = --itr2;
    itr2++;

    while (itr2 != sortMe.begin() && 
           (*temp).artist.compare((*(itr2)).artist) > 0)
    {
      swap((*temp).artist, (*itr2).artist);
      swap((*temp).title, (*itr2).title);
      swap((*temp).album, (*itr2).album);
      --itr2;
      --temp;
    } //while elements on the left are bigger and it's not at the beginning

    itr1++;
  } //while it's not at the end of the vector

  return sortMe; 
} //sortArtist()

int main()
{
  vector <Song> all;
  Song read;
  ifstream inf("songs.txt");

  while (inf >> read)
  {
    read.removeCd();
    read.convertCase();
    read.move();    
    all.push_back(read);
  } //while there is file left to read from

  int choice = 5;
  cout << "\n";

  while (choice != 0)
  {
    cout << "Song Menu\n";
    cout << "0. Done.\n";
    cout << "1. Search for Artist.\n";
    cout << "2. Search for Title.\n";
    cout << "3. Search for Album.\n";
    cout << "4. Search for title phrase.\n\n";
   
    cout << "Your choice: ";
    cin >> choice;

    if (choice < 0 || choice > 4)
    {
      cout << "Your choice must be between 0 and 4.\n";
      cout << "Please try again.\n\n\n";
    } //if invalid choice

    if (choice >= 1 && choice <= 4)
    {
      vector <Song> found;
      vector<Song>::iterator itr; 
      string input;

      if (choice == 1)
      {
        cout << "Please enter the artist's name: ";
        cin.ignore();
        getline(cin, input);

        for (itr = all.begin(); itr != all.end(); itr++)
        {         

          if ((*itr).getArtist().compare(input) == 0)
          {    
            found.push_back(*itr);
          } //if song found with matching artist

        } //for every song

        sortTitle(found);
      } //if the user looked for an artist

      if (choice == 2)
      { 
        cout << "Please enter the title: ";
        cin.ignore();
        getline(cin, input);

        for (itr = all.begin(); itr != all.end(); itr++)
        {

          if ((*itr).getTitle().compare(input) == 0)
          {
            found.push_back(*itr);
          } //if song found with matching title

        } //for every song

        sortTitle(found);
      } //if the user looked for a title

      if (choice == 3)
      {
        cout << "Please enter the album: ";
        cin.ignore();
        getline(cin, input);

        for (itr = all.begin(); itr != all.end(); itr++)
        {

  	  if ((*itr).getAlbum().compare(input) == 0)
          {
            found.push_back(*itr);
          } //if song found with matching album

        } //for every song

        sortTitle(found);
      } //if the user looked for an album

      if (choice == 4)
      {
        cout << "Please enter the phrase: ";
        cin.ignore();
        getline(cin, input);

        for (itr = all.begin(); itr != all.end(); itr++)
        {
          
          if ((*itr).getTitle().find(input) != string::npos)
          {
            found.push_back(*itr);
  	  } //if song found containing phrase

        } //for every song

        found = sortArtist(found);
      } //if the user looked for a phrase in a song

      vector <Song>::iterator itr2;

      for (itr2 = found.begin(); itr2 != found.end(); itr2++)
      {
        cout << *itr2 << "\n";
      } //for every found song

      cout << "\n";
    } //if choice was between 1 and 4
  } //while the user is not done
} //main() 


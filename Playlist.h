#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <string>

using namespace std;

class PlaylistNode{

public:
PlaylistNode();
PlaylistNode(string id,string sName,string aName,int sLength);
void InsertAfter(PlaylistNode* ptr);
void SetNext(PlaylistNode *ptr);
string GetID();
string GetSongName();
string GetArtistName();
int GetSongLength();
PlaylistNode* GetNext();
void PrintPlaylistNode();

private:
string uniqueID; 
string songName;
string artistName;
int songLength;
PlaylistNode *nextNodePtr;
};

class Playlist{

public:
  
  Playlist(){
    head = nullptr;
    tail = nullptr;
}

void AddSong(string id, string song, string artist, int length);
bool RemoveSong(string removedSong);
bool ChangePosSong(int currentPos, int newPos);
void OutputSongs(string artistName);
int OutputTotalTime();
void PrintPlaylist();

private:
PlaylistNode *head;
PlaylistNode *tail;
};

#endif

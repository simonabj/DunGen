#include "stdafx.h"
#include "door.h"
#include <vector>
#include <iostream>

vector<Door*> Door::doors;

Door::Door(int posX, int posY) : 
	SubCell::SubCell(posX, posY){

	this->type = 'D';
	doors.push_back(this);
}


Door::~Door(){

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ship.cpp
 * Author: Bug Buggy
 * 
 * Created on 29. April 2018, 00:41
 */

#include "Ship.h"
Ship::Ship() : Sprite("data/rock_cruiser_3_floor.png") {
    x = 300;
    y = 360;
}

Ship::~Ship() {
}


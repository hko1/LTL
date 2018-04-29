     /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sprite.cpp
 * Author: Bug Buggy
 * 
 * Created on 29. April 2018, 00:59
 */

#include "Sprite.h"
#include "Image.h"

Sprite::Sprite(const std::string &imagePath) :
    numFramesX_(1),
    numFramesY_(1),
    frameIndexX_(0),
    frameIndexY_(0)
{
    x=0;
    y=0; 
    image=new Image(imagePath);
}

Sprite::Sprite(const std::string &imagePath,
        GLuint numFramesX,
        GLuint numFramesY) :
    numFramesX_(numFramesX),
    numFramesY_(numFramesY),
    frameIndexX_(0),
    frameIndexY_(0)
{
    x=0;
    y=0; 
    image=new Image(imagePath);
}

void Sprite::nextFrame() {
    // advance x-index
    frameIndexX_ += 1;
    if(frameIndexX_>numFramesX_) {
        numFramesX_ = 0;
        // advance y-index
        frameIndexY_ += 1;
        if(frameIndexY_>numFramesY_) {
            numFramesY_ = 0;
        }
    }
}

void Sprite::draw(){
    GLfloat img_width  = image->width();
    GLfloat img_height = image->height();
    GLfloat frame_width  = img_width/numFramesX_;
    GLfloat frame_height = img_height/numFramesY_;
    GLfloat frame_pos_x  = (frameIndexX_*frame_width)/img_width;
    GLfloat frame_pos_y  = (frameIndexY_*frame_height)/img_height;
    GLfloat frame_size_w = frame_width/img_width;
    GLfloat frame_size_h = frame_height/img_height;
    
    image->draw(x,y,
            frame_pos_x,
            frame_pos_y,
            frame_size_w,
            frame_size_h);
}

Sprite::~Sprite() {
    delete image;
}
#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <raylib.h>

#include "parser.h"

typedef struct Coordinate {
    
    float x;
    float y;
    
} Coordinate;

/**
 * @brief Returns the coordinate to which you should attach the left child
 * 
 * @param coord The coordinate of the node to which we are attaching a child
 * 
 * @returns The coordinate to which to attach the child (rcos(4pi/3), rsin(4pi/3))
*/
Coordinate* getLeftCoord(Coordinate* coord);

/**
 * @brief Returns the coordinate to which you should attach the right child
 * 
 * @param coord The coordinate of the node to which we are attaching a child
 * 
 * @returns The coordinate to which to attach the child (rcos(5pi/3), rsin(5pi/3))
*/
Coordinate* getRightCoord(Coordinate* coord);

/**
 * @brief Draws a node and the edges to connect it to its children
 * 
 * @param node The TokenNode* to be drawn
 * @param coord The coordinate at which to draw the node
*/
void drawNode (TokenNode* node, Coordinate* coord);

/**
 * @brief Given the TokenNode* representing the root of a tree, displays the tree
 * 
 * @param root The root node of the tree
*/
void showTree(TokenNode* root);

void drawLineBetweenNodes(Coordinate* from, Coordinate* to, float radius);

#endif
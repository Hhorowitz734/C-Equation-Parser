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
 * @param depth The depth of the node. This is given for purposes of setting a "horizontal offset" to prevent nodes from overlapping.
 * 
 * @returns The coordinate to which to attach the child (rcos(4pi/3), rsin(4pi/3))
*/
Coordinate* getLeftCoord(Coordinate* coord, int depth);

/**
 * @brief Returns the coordinate to which you should attach the right child
 * 
 * @param coord The coordinate of the node to which we are attaching a child
 * @param depth The depth of the node. This is given for purposes of setting a "horizontal offset" to prevent nodes from overlapping.
 * 
 * @returns The coordinate to which to attach the child (rcos(5pi/3), rsin(5pi/3))
*/
Coordinate* getRightCoord(Coordinate* coord, int depth);

/**
 * @brief Draws a node and the edges to connect it to its children
 * 
 * @param node The TokenNode* to be drawn
 * @param coord The coordinate at which to draw the node
 * @param depth The depth of the node. This is given for purposes of setting a "horizontal offset" to prevent nodes from overlapping.
*/
void drawNode(TokenNode* node, Coordinate* coord, int depth);

/**
 * @brief Given the TokenNode* representing the root of a tree, displays the tree
 * 
 * @param root The root node of the tree
*/
void showTree(TokenNode* root);

/**
 * @brief Given the coordinate points of two nodes, draws a line between them.
 * 
 * @param from The node from which to draw
 * @param to The node to draw to
 * @param radius The radius of the nodes
*/
void drawLineBetweenNodes(Coordinate* from, Coordinate* to, float radius);

#endif



///  NEXT STEP -> implement horizontal offset by depth in the function definitions
// Then make the changes to the functions in visualizer.c
#include "../include/visualizer.h"

#include <math.h>

Coordinate* getLeftCoord(Coordinate* coord, int depth) {

    if (depth == 1) { depth = -3; }
    
    //MAGIC NUMBERS
    const float cos_4pi_3 = -.5;
    const float sin_4pi_3 = -.866;

    float horizontalOffset = 50 * (5 - depth); // Dynamic offset

    Coordinate* return_coord = (Coordinate*)malloc(sizeof(Coordinate));
    if (return_coord != NULL) {
        return_coord->x = coord->x - horizontalOffset + (30 * 2 * cos_4pi_3); //x + 3rcostheta
        return_coord->y = coord->y - (30 * 3 * sin_4pi_3); //y + 3rsintheta
    }

    return return_coord;

}


Coordinate* getRightCoord(Coordinate* coord, int depth) {

    if (depth == 1) { depth = -3; }

    //MAGIC NUMBERS
    const float cos_5pi_3 = 0.5;
    const float sin_5pi_3 = -0.866;

    float horizontalOffset = 50 * (5 - depth);

    Coordinate* return_coord = (Coordinate*)malloc(sizeof(Coordinate));
    if (return_coord != NULL) {
        return_coord->x = coord->x + horizontalOffset + (30 * 2 * cos_5pi_3); // x + 3rcos(5π/3)
        return_coord->y = coord->y - (30 * 3 * sin_5pi_3); // y + 3rsin(5π/3)
    }

    return return_coord;
}


void drawLineBetweenNodes(Coordinate* from, Coordinate* to, float radius) {
    // Calculate direction vector from 'from' to 'to'
    float dx = to->x - from->x;
    float dy = to->y - from->y;
    float distance = sqrt(dx * dx + dy * dy);

    // Normalize direction vector
    dx /= distance;
    dy /= distance;

    // Calculate start and end points
    float startX = from->x + dx * radius;
    float startY = from->y + dy * radius;
    float endX = to->x - dx * radius;
    float endY = to->y - dy * radius;

    // Draw line
    DrawLine(startX, startY, endX, endY, WHITE);
}


void drawNode(TokenNode* node, Coordinate* coord, int depth) {
    if (node == NULL) return;

    Coordinate *leftCoord = NULL, *rightCoord = NULL;

    if (node->left != NULL) {
        leftCoord = getLeftCoord(coord, depth + 1);
    }

    if (node->right != NULL) {
        rightCoord = getRightCoord(coord, depth + 1);
    }

    // Draw the current node
    DrawCircle(coord->x, coord->y, 30, WHITE);
    DrawCircle(coord->x, coord->y, 28, BLACK);
    DrawText(node->token->lexeme, coord->x - 15, coord->y - 25, 30, GREEN);

    // Now draw lines to children
    if (leftCoord != NULL) {
        drawLineBetweenNodes(coord, leftCoord, 30);
        drawNode(node->left, leftCoord, depth + 1);
        free(leftCoord);
    }

    if (rightCoord != NULL) {
        drawLineBetweenNodes(coord, rightCoord, 30);
        drawNode(node->right, rightCoord, depth + 1);
        free(rightCoord);
    }
}


void showTree(TokenNode* root) {

    const int screenWidth = 1500;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Equation Tree");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(BLACK);

        Coordinate* initial_coord = (Coordinate*)malloc(sizeof(Coordinate));
        initial_coord->x = screenWidth / 2;
        initial_coord->y = 100;


        drawNode(root, initial_coord, 0);


        EndDrawing();
    }


}
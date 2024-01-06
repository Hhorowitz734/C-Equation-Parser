#include "../include/visualizer.h"

#include <math.h>


Coordinate* getLeftCoord(Coordinate* coord) {
    
    //MAGIC NUMBERS
    const float cos_4pi_3 = -.5;
    const float sin_4pi_3 = -.866;

    Coordinate* return_coord = (Coordinate*)malloc(sizeof(Coordinate));
    if (return_coord != NULL) {
        return_coord->x = coord->x + (50 * 5 * cos_4pi_3); //x + 3rcostheta
        return_coord->y = coord->y - (50 * 5 * sin_4pi_3); //y + 3rsintheta
    }

    return return_coord;

}

Coordinate* getRightCoord(Coordinate* coord) {

    //MAGIC NUMBERS
    const float cos_5pi_3 = 0.5;
    const float sin_5pi_3 = -0.866;

    Coordinate* return_coord = (Coordinate*)malloc(sizeof(Coordinate));
    if (return_coord != NULL) {
        return_coord->x = coord->x + (50 * 5 * cos_5pi_3); // x + 3rcos(5π/3)
        return_coord->y = coord->y - (50 * 5 * sin_5pi_3); // y + 3rsin(5π/3)
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
    DrawLine(startX, startY, endX, endY, BLACK);
}


void drawNode (TokenNode* node, Coordinate* coord) {
    DrawCircle(coord->x, coord->y, 50, BLACK);
    DrawCircle(coord->x, coord->y, 48, WHITE);
    DrawText(node->token->lexeme, coord->x - 15, coord->y - 25, 50, RED);

    if (node->left != NULL) {
        Coordinate* leftCoord = getLeftCoord(coord);
        drawNode(node->left, leftCoord);
        drawLineBetweenNodes(coord, leftCoord, 50);
        free(leftCoord);
    }

    if (node->right != NULL) {
        Coordinate* rightCoord = getRightCoord(coord);
        drawNode(node->right, rightCoord);
        drawLineBetweenNodes(coord, rightCoord, 50);
        free(rightCoord);
    }
}

void showTree(TokenNode* root) {

    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Equation Tree");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();


        Coordinate* initial_coord = (Coordinate*)malloc(sizeof(Coordinate));
        initial_coord->x = screenWidth / 2;
        initial_coord->y = 100;


        drawNode(root, initial_coord);

        ClearBackground(RAYWHITE);

        EndDrawing();
    }


}
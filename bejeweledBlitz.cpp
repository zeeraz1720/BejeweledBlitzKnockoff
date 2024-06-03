// Name:			Zeeshan Raza & Syed Taha Ahmed
// Roll No:			22L - 6677   & 22L - 6638
// Section:			1B(1) (both students)
// Program:			BS-CS
// Course:			Programming Fundamentals
// Submitted to:	Aamir Wali

#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include "bejeweled_drawhandler.h"

using namespace std;

// Creator notes:
// 
// Maximum size of the Command window: 960 x 480 pixels
// Size of the board (in squares) = 9 x 8 spaces
// Default width of lines = 2 pixels
//
//

void jewelBoard_draw() {

	myRectangle_filled(0, 0, 960, 480, 190, 0, 255, 190, 0, 255);	// size of the whole screen
	myRectangle_filled(430, 20, 870, 460, 0, 0, 128, 0, 0, 128);	// size of the whole board ( outer border )

	for (int i = 0; i < 9; i++) {
		myLine(430, 20 + (i * 55), 868, 20 + (i * 55), 200);		// this for-loop draws
		myLine(430 + (i * 55), 20, 430 + (i * 55), 458, 200);		// the lines on the board
	}

}

void jewel_drawer(int candyNum, int jewelType, int i, int j) {			// function that prints jewels

	if (candyNum == 0) {
		myRectangle_filled(435 + (i * 55), 25 + (j * 55), 480 + (i * 55), 70 + (j * 55), 0, 0, 128, 0, 0, 128);		// nothing
	}
	else if (jewelType == 4) {
		myEllipse_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 255, 255, 255, 0, 0, 128);		// outer circle
		myRectangle_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 100, 100, 200);		// inner rectangle
	}
	else if (candyNum == 1) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myRectangle_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 255, 0, 0);		// red
		}
		else if (jewelType == 2) {
			myRectangle_filled(435 + (i * 55), 25 + (j * 55), 480 + (i * 55), 70 + (j * 55), 0, 0, 128, 0, 0, 128);
			myRectangle_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 210, 150, 0, 210, 150, 0);
			myRectangle_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 0, 0);		// red (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(435 + (i * 55), 25 + (j * 55), 480 + (i * 55), 70 + (j * 55), 0, 0, 128, 0, 0, 128);
			myRectangle_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 100, 210, 0, 100, 210);
			myRectangle_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 0, 0);		// red (destroyer)
		}

	}
	else if (candyNum == 2) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myHexagon_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 255, 115, 0);		// orange
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myHexagon_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 210, 150, 0, 210, 150, 0);
			myHexagon_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 115, 0);		// orange (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myHexagon_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 0, 100, 210, 0, 100, 210);
			myHexagon_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 115, 0);		// orange (destroyer)
		}

	}
	else if (candyNum == 3) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDiamond_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 255, 255, 0);		// yellow
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDiamond_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 210, 150, 0, 210, 150, 0);
			myDiamond_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 255, 0);		// yellow (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDiamond_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 0, 100, 210, 0, 100, 210);
			myDiamond_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 255, 255, 0);		// yellow (destroyer)
		}

	}
	else if (candyNum == 4) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDecagon_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 0, 200, 0);			// green
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDecagon_filled(437 + (i * 55), 27 + (j * 55), 477 + (i * 55), 67 + (j * 55), 210, 150, 0, 210, 150, 0);
			myDecagon_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 0, 200, 0);			// green (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myDecagon_filled(437 + (i * 55), 27 + (j * 55), 477 + (i * 55), 67 + (j * 55), 0, 100, 210, 0, 100, 210);
			myDecagon_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 0, 200, 0);			// green (destroyer)
		}

	}
	else if (candyNum == 5) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myEmerald_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 0, 100, 255);		// blue
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myEmerald_filled(438 + (i * 55), 29 + (j * 55), 477 + (i * 55), 67 + (j * 55), 210, 150, 0, 210, 150, 0);
			myEmerald_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 0, 100, 255);		// blue (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myEmerald_filled(438 + (i * 55), 29 + (j * 55), 477 + (i * 55), 67 + (j * 55), 0, 100, 210, 0, 100, 210);
			myEmerald_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 0, 100, 255);		// blue (destroyer)
		}

	}
	else if (candyNum == 6) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myTriangle_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 150, 0, 255);		// purple
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myTriangle_filled(437 + (i * 55), 27 + (j * 55), 477 + (i * 55), 65 + (j * 55), 210, 150, 0, 210, 150, 0);
			myTriangle_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 150, 0, 255);		// purple (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myTriangle_filled(437 + (i * 55), 27 + (j * 55), 477 + (i * 55), 65 + (j * 55), 0, 100, 210, 0, 100, 210);
			myTriangle_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 150, 0, 255);		// purple (destroyer)
		}

	}
	else if (candyNum == 7) {

		if (jewelType == 1) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myEllipse_filled(440 + (i * 55), 30 + (j * 55), 475 + (i * 55), 65 + (j * 55), 0, 0, 0, 200, 200, 200);		// white
		}
		else if (jewelType == 2) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myEllipse_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 210, 150, 0, 210, 150, 0);
			myEllipse_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 200, 200, 200);		// white (flame)
		}
		else if (jewelType == 3) {
			myRectangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 68 + (j * 55), 0, 0, 128, 0, 0, 128);
			myTriangle_filled(437 + (i * 55), 27 + (j * 55), 478 + (i * 55), 67 + (j * 55), 0, 100, 210, 0, 100, 210);
			myEllipse_filled(442 + (i * 55), 32 + (j * 55), 473 + (i * 55), 63 + (j * 55), 0, 0, 0, 150, 150, 150);		// white (destroyer)
		}

	}

}

void jewelRandomizer(int arr2D[][8], int arr2D_2[][8]) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			arr2D[i][j] = (rand() % 7) + 1;								// randomly creates jewels for all positions
																		// and starts all of them off as normal
			arr2D_2[i][j] = 1;

		}
	}

}

void jewelsOnBoard_drawer(int arr2D[][8], int arr2D_2[][8]) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			jewel_drawer(arr2D[i][j], arr2D_2[i][j], i, j);				// draws the jewels in every location

		}

	}

}

void updating_drawer(int num, int x_coor, int y_coor) {

	if (num == 0) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 40, 90, 200, 180, 90, 200, 180);		// rectangles to make number 0
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 40, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 1) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 10, y_coor, x_coor + 20, y_coor + 50, 90, 200, 180, 90, 200, 180);	// rectangles to make number 1
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 2) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 2
		myRectangle_filled(x_coor, y_coor + 30, x_coor + 10, y_coor + 40, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 3) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 3
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 4) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 25, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 4
	}
	else if (num == 5) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 30, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 5
		myRectangle_filled(x_coor + 20, y_coor + 30, x_coor + 30, y_coor + 40, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 6) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 6
		myRectangle_filled(x_coor + 20, y_coor + 30, x_coor + 30, y_coor + 40, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 7) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 20, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);	// rectangles to make number 7
	}
	else if (num == 8) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 8
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}
	else if (num == 9) {
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 50, 160, 125, 70, 160, 125, 70);
		myRectangle_filled(x_coor, y_coor, x_coor + 30, y_coor + 10, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor, x_coor + 10, y_coor + 30, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 20, x_coor + 30, y_coor + 30, 90, 200, 180, 90, 200, 180); 	// rectangles to make number 9
		myRectangle_filled(x_coor + 20, y_coor, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
		myRectangle_filled(x_coor, y_coor + 40, x_coor + 30, y_coor + 50, 90, 200, 180, 90, 200, 180);
	}

}

void drawScoreBoard() {														// prints the place where the scoreboard will be

	myRectangle_filled(100, 80, 400, 200, 160, 125, 70, 200, 160, 90);
	myRectangle_filled(110, 90, 390, 190, 160, 125, 70, 160, 125, 70);

	myRectangle_filled(115, 95, 130, 100, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(115, 100, 120, 105, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(115, 105, 130, 110, 90, 200, 180, 90, 200, 180);		// the s in score
	myRectangle_filled(125, 110, 130, 115, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(115, 115, 130, 120, 90, 200, 180, 90, 200, 180);

	myRectangle_filled(135, 95, 150, 100, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(135, 100, 140, 115, 90, 200, 180, 90, 200, 180);		// the c in score
	myRectangle_filled(135, 115, 150, 120, 90, 200, 180, 90, 200, 180);

	myRectangle_filled(155, 95, 170, 100, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(155, 100, 160, 115, 90, 200, 180, 90, 200, 180);		// the o in score
	myRectangle_filled(155, 115, 170, 120, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(165, 100, 170, 115, 90, 200, 180, 90, 200, 180);

	myRectangle_filled(175, 95, 190, 100, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(175, 100, 180, 120, 90, 200, 180, 90, 200, 180);		// the r in score
	myRectangle_filled(175, 105, 190, 110, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(185, 100, 190, 110, 90, 200, 180, 90, 200, 180);
	for (int k = 0; k < 5; k++) { myAdvLine(180 - k, 105, 189 - k, 119, 2, 90, 200, 180); }

	myRectangle_filled(195, 95, 210, 100, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(195, 100, 200, 115, 90, 200, 180, 90, 200, 180);		// the e in score
	myRectangle_filled(195, 105, 210, 110, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(195, 115, 210, 120, 90, 200, 180, 90, 200, 180);
	
}

void UpdateScore(int score) {

	int num;
	int x_coor = 350, y_coor = 135;								// score printing starting point

	while (score != 0) {

		num = score % 10;										// calculates every digit in score and prints it
		score /= 10;

		updating_drawer(num, x_coor, y_coor);					// calls updating_drawer to print num
		x_coor -= 40;
		if (x_coor < 110) { x_coor = 110; }
	}

}

void drawTimeBoard() {

	myRectangle_filled(100, 280, 400, 400, 160, 125, 70, 200, 160, 90);			// time background (outer)
	myRectangle_filled(110, 290, 390, 390, 160, 125, 70, 160, 125, 70);			// (inner)

	myRectangle_filled(115, 295, 130, 300, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(120, 300, 125, 320, 90, 200, 180, 90, 200, 180);			// the t in time

	myRectangle_filled(135, 295, 140, 320, 90, 200, 180, 90, 200, 180);			// the i in time

	myRectangle_filled(145, 295, 150, 320, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(165, 295, 170, 320, 90, 200, 180, 90, 200, 180);
	for (int k = 0; k < 5; k++) {												// the m in time
		myAdvLine(150, 295 + k, 157, 310 + k, 2, 90, 200, 180);
		myAdvLine(156, 310 + k, 164, 295 + k, 2, 90, 200, 180);
	}

	myRectangle_filled(175, 295, 190, 300, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(175, 300, 180, 315, 90, 200, 180, 90, 200, 180);		// the e in time
	myRectangle_filled(175, 305, 190, 310, 90, 200, 180, 90, 200, 180);
	myRectangle_filled(175, 315, 190, 320, 90, 200, 180, 90, 200, 180);

}

void UpdateTime(int timeDiff) {

	int sec, min, sec2;
	int x_coor = 350, y_coor = 335;			// starting point for printing time

	min = (60 - timeDiff) / 60;				// calculates minutes and seconds
	sec = (60 - timeDiff) % 60;
	
	sec2 = sec % 10;
	sec /= 10;

	updating_drawer(sec2, x_coor, y_coor);		// draws the seconds
	x_coor -= 40;
	updating_drawer(sec, x_coor, y_coor);

	myRectangle_filled(290, 345, 300, 355, 90, 200, 180, 90, 200, 180);			// two square to seperate seconds and minutes
	myRectangle_filled(290, 370, 300, 380, 90, 200, 180, 90, 200, 180);
	x_coor -= 60;

	updating_drawer(min, x_coor, y_coor);		// draws the minutes

}

void explodeGem(int arr2D[][8], int arr2D_2[][8], int i, int j, int &score) {

	if (arr2D_2[i][j] == 3) {						// if destroyer gem found

		arr2D[i][j] = 0; arr2D_2[i][j] = 1;

		for (int k = 0; k < 8; k++) {
			//arr2D[k][j] = 0; arr2D_2[k][j] = 1;
			explodeGem(arr2D, arr2D_2, k, j, score);		// adds score and explodes gem
			score += 20;
		}

		for (int l = 0; l < 8; l++) {
			//arr2D[i][l] = 0; arr2D_2[i][l] = 1;
			explodeGem(arr2D, arr2D_2, i, l, score);		// adds score and explodes gem
			score += 20;
		}

	}
	else if (arr2D_2[i][j] == 2) {						// if flame gem found
														// (needed to create a way to manage all locations without
		arr2D[i][j] = 0; arr2D_2[i][j] = 1;				// breaking the game and corrupting arrays)
		if (i == 0 && j == 0) {
			for (int k = i; k <= (i + 1); k++) {
				for (int l = j; l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (top-right corner)
				}
			}
		}
		else if (i == 7 && j == 0) {
			for (int k = (i - 1); k <= i; k++) {
				for (int l = j; l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (top-left corner)
				}
			}
		}
		else if (i == 0 && j == 7) {
			for (int k = i; k <= (i + 1); k++) {
				for (int l = (j - 1); l <= j; l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (bottom-right corner)
					score += 30;
				}
			}
		}
		else if (i == 7 && j == 7) {
			for (int k = (i - 1); k <= i; k++) {
				for (int l = (j - 1); l <= j; l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (bottom-left corner)
				}
			}
		}
		else if (i == 0) {
			for (int k = i; k <= (i + 1); k++) {
				for (int l = (j - 1); l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);			// adds score and explodes gem (left vertical row)
				}
			}
		}
		else if (i == 7) {
			for (int k = (i - 1); k <= i; k++) {
				for (int l = (j - 1); l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (right vertical row)
				}
			}
		}
		else if (j == 0) {
			for (int k = (i - 1); k <= (i + 1); k++) {
				for (int l = j; l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (top horizontal row)
				}
			}
		}
		else if (j == 7) {
			for (int k = (i - 1); k <= (i + 1); k++) {
				for (int l = (j - 1); l <= j; l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (bottom horizontal row)
				}
			}
		}
		else {
			for (int k = (i - 1); k <= (i + 1); k++) {
				for (int l = (j - 1); l <= (j + 1); l++) {
					//arr2D[k][l] = 0; arr2D_2[i][l] = 1;
					explodeGem(arr2D, arr2D_2, k, l, score);		// adds score and explodes gem (anywhere otherwise)
				}
			}
		}
		
		score += 30;

	}
	else if (arr2D_2[i][j] == 1 || arr2D_2[i][j] == 4) {						// if normal gem found

		arr2D[i][j] = 0;
		arr2D_2[i][j] = 1;
		score += 20;

	}
}

void frame_drawer(int topright_x, int topright_y, int col1, int col2, int col3) {			// function to draw the user movement frame

	myAdvLine(topright_x + 2, topright_y + 2, topright_x + 50, topright_y + 2, 2, col1, col2, col3);
	myAdvLine(topright_x + 2, topright_y + 2, topright_x + 2, topright_y + 50, 2, col1, col2, col3);
	myAdvLine(topright_x + 2, topright_y + 50, topright_x + 50, topright_y + 50, 2, col1, col2, col3);
	myAdvLine(topright_x + 50, topright_y + 2, topright_x + 50, topright_y + 50, 2, col1, col2, col3);

}

bool matchesFoundH(int arr2D[][8], int x_pos, int y_pos) {				// checks to see if any 3-gem matches are found horizontally

	if (x_pos == 0) {
		if (arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos] && arr2D[x_pos + 1][y_pos] == arr2D[x_pos + 2][y_pos]) {
			return true;
		}
	}
	else if (x_pos == 1) {
		if (arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos] && arr2D[x_pos + 1][y_pos] == arr2D[x_pos + 2][y_pos]) {
			return true;
		}
	}
	if (x_pos == 6) {
		if (arr2D[x_pos - 2][y_pos] == arr2D[x_pos - 1][y_pos] && arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos]) {
			return true;
		}
	}
	else if (x_pos == 7) {
		if (arr2D[x_pos - 2][y_pos] == arr2D[x_pos - 1][y_pos] && arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos]) {
			return true;
		}
	}
	else {
		if (arr2D[x_pos - 2][y_pos] == arr2D[x_pos - 1][y_pos] && arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos - 1][y_pos] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos] == arr2D[x_pos + 1][y_pos] && arr2D[x_pos + 1][y_pos] == arr2D[x_pos + 2][y_pos]) {
			return true;
		}
	}

	return false;

}

bool matchesFoundV(int arr2D[][8], int x_pos, int y_pos) {				// checks to see if any 3-gems matches are found vertically

	if (y_pos == 0) {
		if (arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1] && arr2D[x_pos][y_pos + 1] == arr2D[x_pos][y_pos + 2]) {
			return true;
		}
	}
	else if (y_pos == 1) {
		if (arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1] && arr2D[x_pos][y_pos + 1] == arr2D[x_pos][y_pos + 2]) {
			return true;
		}
	}
	if (y_pos == 6) {
		if (arr2D[x_pos][y_pos - 2] == arr2D[x_pos][y_pos - 1] && arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1]) {
			return true;
		}
	}
	else if (y_pos == 7) {
		if (arr2D[x_pos][y_pos - 2] == arr2D[x_pos][y_pos - 1] && arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos]) {
			return true;
		}
	}
	else {
		if (arr2D[x_pos][y_pos - 2] == arr2D[x_pos][y_pos - 1] && arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos - 1] == arr2D[x_pos][y_pos] && arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1]) {
			return true;
		}
		else if (arr2D[x_pos][y_pos] == arr2D[x_pos][y_pos + 1] && arr2D[x_pos][y_pos + 1] == arr2D[x_pos][y_pos + 2]) {
			return true;
		}
	}

	return false;

}

bool matchesFound(int arr2D[][8], int x_pos, int y_pos) {			// a function combining both matchesFound for ease

	bool matchFound;
	
	matchFound = matchesFoundH(arr2D, x_pos, y_pos) || matchesFoundV(arr2D, x_pos, y_pos);

	return matchFound;

}

void DiscoBallDestruction(int arr2D[][8], int arr2D_2[][8], int x1, int y1, int x2, int y2, int &score) {

	int gemColor;												// function to handle the 5-in-a-row

	if (arr2D_2[x1][y1] == 4 && arr2D_2[x2][y2] == 4) {
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				arr2D[i][j] = (rand() % 7) + 1; arr2D_2[i][j] = 1;			// if two 5-in-a-row gems are swapped,
																			// complete board wipe

			}																// (didn't use jewelRandomizer() to ensure good results)
		}

		score += (64 * 20);

	}
	else {

		if (arr2D_2[x1][y1] == 4) {
			gemColor = arr2D[x2][y2];										// if just one 5-in-a-row gem is swapped with a color
		}
		else { 
			gemColor = arr2D[x1][y1];
		}

		arr2D[x1][y1] = 0; arr2D_2[x1][y1] = 1;								// the swapped gems disappear (or explode)
		arr2D[x2][y2] = 0; arr2D_2[x2][y2] = 1;
		score += 120;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {

				if (arr2D[i][j] == gemColor) {
					explodeGem(arr2D, arr2D_2, i, j, score);				// and all gems of that gem color (the non 5-in-a-row gem)
				}															// will explode as well

			}
		}

	}

}

int userMovement(int arr2D[][8], int arr2D_2[][8], int& keyPressed, int& x_coor, int& y_coor, int& x_sq, int& y_sq, int &score) {

	int swapValues, temp;
	bool wasPressed = isCursorKeyPressed(keyPressed);

	if (wasPressed) {

		frame_drawer(x_coor, y_coor, 0, 0, 128);

		if (keyPressed == 1) {								// when left key is pressed
			x_coor -= 55;

			if (x_coor < 431) { x_coor = 431; }
			else { x_sq--; }
		}
		else if (keyPressed == 2) {							// when up key is pressed
			y_coor -= 55;

			if (y_coor < 22) { y_coor = 22; }
			else { y_sq--; }
		}
		else if (keyPressed == 3) {							// when right key is pressed
			x_coor += 55;

			if (x_coor > 816) { x_coor = 816; }
			else { x_sq++; }
		}
		else if (keyPressed == 4) {							// when down key is pressed
			y_coor += 55;

			if (y_coor > 407) { y_coor = 407; }
			else { y_sq++; }
		}
		else if (keyPressed == 5) {							// if Space Key is pressed

			return 0;

		}
		else if (keyPressed == 6) {							// if Enter Key is pressed

			frame_drawer(x_coor, y_coor, 0, 0, 0);			// position has been selected
			swapValues = 1;

			while (swapValues == 1) {

				isCursorKeyPressed(keyPressed);

				if (keyPressed == 1) {				// when left key is pressed
					
					if (arr2D_2[x_sq][y_sq] == 4 || arr2D_2[x_sq - 1][y_sq] == 4) {
						DiscoBallDestruction(arr2D, arr2D_2, x_sq, y_sq, x_sq - 1, y_sq, score);
					}
					else if (x_sq > 0) {

						temp = arr2D[x_sq][y_sq];
						arr2D[x_sq][y_sq] = arr2D[x_sq - 1][y_sq];
						arr2D[x_sq - 1][y_sq] = temp;

						/*temp = arr2D_2[x_sq][y_sq];
						arr2D_2[x_sq][y_sq] = arr2D_2[x_sq - 1][y_sq]; // <<<<<<<<< enable this for testing (devs only)
						arr2D_2[x_sq - 1][y_sq] = temp;*/						// it lets you move gems wherever you want

						if (matchesFound(arr2D, x_sq, y_sq) || matchesFound(arr2D, x_sq - 1, y_sq)) {
							temp = arr2D_2[x_sq][y_sq];
							arr2D_2[x_sq][y_sq] = arr2D_2[x_sq - 1][y_sq];
							arr2D_2[x_sq - 1][y_sq] = temp;										// this part makes sure
						}																		// that gems are only swapped
						else {																	// when at least one 3-in-a-row
							temp = arr2D[x_sq][y_sq];											// exists, otherwise swapped back
							arr2D[x_sq][y_sq] = arr2D[x_sq - 1][y_sq];
							arr2D[x_sq - 1][y_sq] = temp;
						}										// will be marked with "***" for all similar functioning code below.
					}
					swapValues = 0;
				}
				else if (keyPressed == 2) {				// when up key is pressed
					
					if (arr2D_2[x_sq][y_sq] == 4 || arr2D_2[x_sq][y_sq - 1] == 4) {
						DiscoBallDestruction(arr2D, arr2D_2, x_sq, y_sq, x_sq, y_sq - 1, score);
					}
					else if (y_sq > 0) {
						temp = arr2D[x_sq][y_sq];
						arr2D[x_sq][y_sq] = arr2D[x_sq][y_sq - 1];
						arr2D[x_sq][y_sq - 1] = temp;

						/*temp = arr2D_2[x_sq][y_sq];
						arr2D_2[x_sq][y_sq] = arr2D_2[x_sq][y_sq - 1];			// <<<<<<<<< enable this for testing (devs only)
						arr2D_2[x_sq][y_sq - 1] = temp;*/

						if (matchesFound(arr2D, x_sq, y_sq) || matchesFound(arr2D, x_sq, y_sq - 1)) {
							temp = arr2D_2[x_sq][y_sq];
							arr2D_2[x_sq][y_sq] = arr2D_2[x_sq][y_sq - 1];
							arr2D_2[x_sq][y_sq - 1] = temp;									// "***" << marked, check line 696
						}
						else {
							temp = arr2D[x_sq][y_sq];
							arr2D[x_sq][y_sq] = arr2D[x_sq][y_sq - 1];
							arr2D[x_sq][y_sq - 1] = temp;
						}
					}
					swapValues = 0;
				}
				else if (keyPressed == 3) {				// when right key is pressed
					
					if (arr2D_2[x_sq][y_sq] == 4 || arr2D_2[x_sq + 1][y_sq] == 4) {
						DiscoBallDestruction(arr2D, arr2D_2, x_sq, y_sq, x_sq + 1, y_sq, score);
					}
					else if (x_sq < 7) {
						temp = arr2D[x_sq][y_sq];
						arr2D[x_sq][y_sq] = arr2D[x_sq + 1][y_sq];
						arr2D[x_sq + 1][y_sq] = temp;

						/*temp = arr2D_2[x_sq][y_sq];
						arr2D_2[x_sq][y_sq] = arr2D_2[x_sq + 1][y_sq];				// <<<<<<<<< enable this for testing (devs only)
						arr2D_2[x_sq + 1][y_sq] = temp;*/

						if (matchesFound(arr2D, x_sq, y_sq) || matchesFound(arr2D, x_sq + 1, y_sq)) {
							temp = arr2D_2[x_sq][y_sq];
							arr2D_2[x_sq][y_sq] = arr2D_2[x_sq + 1][y_sq];
							arr2D_2[x_sq + 1][y_sq] = temp;									// "***" << marked, check line 696
						}
						else {
							temp = arr2D[x_sq][y_sq];
							arr2D[x_sq][y_sq] = arr2D[x_sq + 1][y_sq];
							arr2D[x_sq + 1][y_sq] = temp;
						}

					}
					swapValues = 0;
				}
				else if (keyPressed == 4) {				// when down key is pressed
					
					if (arr2D_2[x_sq][y_sq] == 4 || arr2D_2[x_sq][y_sq + 1] == 4) {
						DiscoBallDestruction(arr2D, arr2D_2, x_sq, y_sq, x_sq, y_sq + 1, score);
					}
					else if (y_sq < 7) {
						temp = arr2D[x_sq][y_sq];
						arr2D[x_sq][y_sq] = arr2D[x_sq][y_sq + 1];
						arr2D[x_sq][y_sq + 1] = temp;

						/*temp = arr2D_2[x_sq][y_sq];
						arr2D_2[x_sq][y_sq] = arr2D_2[x_sq][y_sq + 1];				// <<<<<<<<< enable this for testing (devs only)
						arr2D_2[x_sq][y_sq + 1] = temp;*/

						if (matchesFound(arr2D, x_sq, y_sq) || matchesFound(arr2D, x_sq, y_sq + 1)) {
							temp = arr2D_2[x_sq][y_sq];
							arr2D_2[x_sq][y_sq] = arr2D_2[x_sq][y_sq + 1];
							arr2D_2[x_sq][y_sq + 1] = temp;									// "***" << marked, check line 696
						}
						else {
							temp = arr2D[x_sq][y_sq];
							arr2D[x_sq][y_sq] = arr2D[x_sq][y_sq + 1];
							arr2D[x_sq][y_sq + 1] = temp;
						}
					}

					swapValues = 0;

				}
			}
		}

	}

	frame_drawer(x_coor, y_coor, 255, 255, 255);
	keyPressed = -1;
	Sleep(100);

	return 1;

}

bool searchForFrame(int arr2D[][8], int i, int j, int x_sq, int y_sq) {			// searches for frame all around the gem position
	
	if (i == x_sq && j == y_sq) {										// center
		return true;
	}
	else if (i < 7 && (i + 1) == x_sq && j == y_sq) {									// right
		if (arr2D[i][j] != arr2D[x_sq][y_sq] && i != x_sq) { return true; }
		else { return false; }
	}
	else if (i > 0 && (i - 1) == x_sq && j == y_sq) {									// left
		if (arr2D[i][j] != arr2D[x_sq][y_sq] && i != x_sq) { return true; }
		else { return false; }
	}
	else if (j < 7 && i == x_sq && (j + 1) == y_sq) {									// up
		if (arr2D[i][j] != arr2D[x_sq][y_sq] && j != y_sq) { return true; }
		else { return false; }
	}
	else if (j > 0 && i == x_sq && (j - 1) == y_sq) {									// down
		if (arr2D[i][j] != arr2D[x_sq][y_sq] && j != y_sq) { return true; }
		else { return false; }
	}
	else { return false; }															// otherwise returns false
	
}

void frameNearbyV(int arr2D[][8], int i, int j, int x_sq, int y_sq, int matchNum, int &gemPosx, int &gemPosy) {
																	// this function checks for the frame for vertical matches
	bool frameFound = false;

	if (matchNum == 4) {

		for (int k = 0; k < 5 && frameFound == false; k++) { 
			frameFound = searchForFrame(arr2D, i, j + k, x_sq, y_sq);				// checks for frame around 4-in-rows

			if (frameFound) {
				gemPosx = i; gemPosy = j + k;
			}
		}
		
		frameFound = false;

	}
	else if (matchNum == 5) {

		for (int k = 0; k < 4 && frameFound == false; k++) {

			frameFound = searchForFrame(arr2D, i, j + k, x_sq, y_sq);				// checks for frame around 5-in-rows

			if (frameFound) {
				gemPosx = i; gemPosy = j + k;
			}
		}

		frameFound = false;

	}
	
}

void frameNearbyH(int arr2D[][8], int i, int j, int x_sq, int y_sq, int matchNum, int& gemPosx, int& gemPosy) {
																// this function checks for the frame for horizontal matches
	bool frameFound = false;
	
	if (matchNum == 4) {

		for (int k = 0; k < 5 && frameFound == false; k++) {
			frameFound = searchForFrame(arr2D, i + k, j, x_sq, y_sq);				// checks for frame around 4-in-rows

			if (frameFound) {
				gemPosx = i + k; gemPosy = j;
			}
		}

		frameFound = false;

	}
	else if (matchNum == 5) {

		for (int k = 0; k < 5 && frameFound == false; k++) {

			frameFound = searchForFrame(arr2D, i + k, j, x_sq, y_sq);				// checks for frame around 5-in-rows

			if (frameFound) {
				gemPosx = i + k; gemPosy = j;
			}
		}

		frameFound = false;

	}

}

void elbowGems_Handler(int arr2D[][8], int arr2D_2[][8], int x_sq, int y_sq, int &score) {
	
	int matchType = 0;
	int gemColor;												// complete function for handling elbows and making
	bool elbowFound = false;									// destroyer gems

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
																// first checks if the elbow exists at all and if so, gives the
			if (arr2D[i][j] == arr2D[i + 1][j]					// match type a number	
				&& arr2D[i + 1][j] == arr2D[i + 2][j]
				&& arr2D[i + 2][j] == arr2D[i + 2][j + 1] 
				&& arr2D[i + 2][j + 1] == arr2D[i + 2][j + 2]) { elbowFound = true; matchType = 1; score += 100; }

			else if (arr2D[i][j] == arr2D[i + 1][j] 
				&& arr2D[i + 1][j] == arr2D[i + 2][j] 
				&& arr2D[i][j] == arr2D[i][j + 1] 
				&& arr2D[i][j + 1] == arr2D[i][j + 2]) { elbowFound = true; matchType = 2; score += 100; }

			else if (arr2D[i][j + 2] == arr2D[i + 1][j + 2] 
				&& arr2D[i + 1][j + 2] == arr2D[i + 2][j + 2] 
				&& arr2D[i][j] == arr2D[i][j + 1] 
				&& arr2D[i][j + 1] == arr2D[i][j + 2]) { elbowFound = true; matchType = 3; score += 100; }

			else if (arr2D[i][j + 2] == arr2D[i + 1][j + 2] 
				&& arr2D[i + 1][j + 2] == arr2D[i + 2][j + 2] 
				&& arr2D[i + 2][j] == arr2D[i + 2][j + 1] 
				&& arr2D[i + 2][j + 1] == arr2D[i + 2][j + 2]) { elbowFound = true; matchType = 4; score += 100; }


			if (elbowFound) {						// then if match was found, it checks the integer and hence, removes the
													// required gems and places the special destroyer gem at the elbow of the elbow
				if (matchType == 1) {																// (FIXED LOCATION)
					gemColor = arr2D[i + 2][j];

					explodeGem(arr2D, arr2D_2, i, j, score);
					explodeGem(arr2D, arr2D_2, i + 1, j, score);
					explodeGem(arr2D, arr2D_2, i + 2, j + 1, score);
					explodeGem(arr2D, arr2D_2, i + 2, j + 2, score);
					arr2D[i + 2][j] = gemColor; arr2D_2[i + 2][j] = 3;
					
				}
				else if (matchType == 2) {
					gemColor = arr2D[i][j];

					explodeGem(arr2D, arr2D_2, i + 1, j, score);
					explodeGem(arr2D, arr2D_2, i + 2, j, score);
					explodeGem(arr2D, arr2D_2, i, j + 1, score);
					explodeGem(arr2D, arr2D_2, i, j + 2, score);
					arr2D_2[i][j] = gemColor; arr2D_2[i][j] = 3;
					
				}
				else if (matchType == 3) {
					gemColor = arr2D[i][j + 2];

					explodeGem(arr2D, arr2D_2, i, j, score);
					explodeGem(arr2D, arr2D_2, i, j + 1, score);
					explodeGem(arr2D, arr2D_2, i + 1, j + 2, score);
					explodeGem(arr2D, arr2D_2, i + 2, j + 2, score);
					arr2D_2[i][j + 2] = gemColor; arr2D_2[i][j + 2] = 3;
					
				}
				else if (matchType == 4) {
					gemColor = arr2D[i + 2][j + 2];

					explodeGem(arr2D, arr2D_2, i, j + 2, score);
					explodeGem(arr2D, arr2D_2, i + 1, j + 2, score);
					explodeGem(arr2D, arr2D_2, i + 2, j + 1, score);
					explodeGem(arr2D, arr2D_2, i + 2, j, score);
					arr2D_2[i + 2][j + 2] = gemColor; arr2D_2[i + 2][j + 2] = 3;
					
				}

			}

			elbowFound = false;

		}
	}

}

void Fivegems_Handler(int arr2D[][8], int arr2D_2[][8], int x_sq, int y_sq, int &score) {

	int gemPosx = -1, gemPosy = -1;										// complete function for handling 5-in-rows and making
																		// "disco balls" / candy bombs / most special gems
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {

			if (arr2D[i][j] == arr2D[i][j + 1] &&
				arr2D[i][j + 1] == arr2D[i][j + 2] &&					// vertical match
				arr2D[i][j + 2] == arr2D[i][j + 3] &&					
				arr2D[i][j + 3] == arr2D[i][j + 4]) {

				frameNearbyV(arr2D, i, j, x_sq, y_sq, 5, gemPosx, gemPosy);						// checks to see if frame is nearby

				if (gemPosx == -1 && gemPosy == -1) {

					arr2D[i][j + 2] = 9; arr2D_2[i][j + 2] = 4;							// if not, it explodes all gems
																						// and places special gem in the middle
					for (int k = 0; k < 5; k++) {
						if (k != 2) {
							explodeGem(arr2D, arr2D_2, i, j + k, score);
						}
					}
				}
				else {
					arr2D[gemPosx][gemPosy] = 9; arr2D_2[gemPosx][gemPosy] = 4;					// if found, explodes all other gems

					for (int k = 0; k < 5; k++) {												// and places special gem according to
						if (gemPosy != (j + k)) {												// frame location
							explodeGem(arr2D, arr2D_2, i, j + k, score);
						}
					}
				}

				score += 100;

				jewelsOnBoard_drawer(arr2D, arr2D_2);
				Sleep(50);

			}

			else if (arr2D[j][i] == arr2D[j + 1][i] &&
				arr2D[j + 1][i] == arr2D[j + 2][i] &&				// horizontal match
				arr2D[j + 2][i] == arr2D[j + 3][i] &&				
				arr2D[j + 3][i] == arr2D[j + 4][i])
			{

				frameNearbyH(arr2D, j, i, x_sq, y_sq, 5, gemPosx, gemPosy);						// checks to see if frame is nearby

				if (gemPosx == -1 && gemPosy == -1) {

					arr2D[i][j + 2] = 9; arr2D_2[j + 2][i] = 4;

					for (int k = 0; k < 5; k++) {
						if (k != 2) {													// if not, it explodes all gems
							explodeGem(arr2D, arr2D_2, j + k, i, score);				// and places special gem in the middle
						}
					}
				}
				else {

					arr2D[gemPosx][gemPosy] = 9; arr2D_2[gemPosx][gemPosy] = 4;				// if found, explodes all other gems

					for (int k = 0; k < 5; k++) {
						if (gemPosx != (j + k)) {
							explodeGem(arr2D, arr2D_2, j + k, i, score);		 			// and places special gem according to
						}																	// frame location
					}
				}

				score += 100;

				jewelsOnBoard_drawer(arr2D, arr2D_2);
				Sleep(50);

			}

		}
	}

}

void Fourgems_Handler(int arr2D[][8], int arr2D_2[][8], int x_sq, int y_sq, int &score) {

	int gemColor, addedNum;
	int gemPosx = -1, gemPosy = -1;										// complete function for handling 4-in-rows and making
																		// flame gems
	addedNum = (rand() % 2) + 1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 5; j++) {

			if (arr2D[i][j] == arr2D[i][j + 1] &&
				arr2D[i][j + 1] == arr2D[i][j + 2] &&					// vertical match
				arr2D[i][j + 2] == arr2D[i][j + 3]) {
				
				frameNearbyV(arr2D, i, j, x_sq, y_sq, 4, gemPosx, gemPosy);						// checks to see if frame is nearby

				if (gemPosx == -1 && gemPosy == -1) {

					arr2D_2[i][j + addedNum] = 2;					// if not, it explodes all gems
																	// and places special gem in randomly set location
					for (int k = 0; k < 4; k++) {
						if (addedNum != k) { 
							explodeGem(arr2D, arr2D_2, i, j + k, score);
						}
					}
				}
				else { 
					arr2D_2[gemPosx][gemPosy] = 2;							// otherwise, it makes the special gem
																			// in accordance to the frame
					for (int k = 0; k < 4; k++) {							// and then explodes the rest
						if (gemPosy != (j + k)) {
							explodeGem(arr2D, arr2D_2, i, j + k, score);
						}
					}
				}

				score += 50;

				jewelsOnBoard_drawer(arr2D, arr2D_2);
				Sleep(50);

			}

			else if (arr2D[j][i] == arr2D[j + 1][i] &&
				arr2D[j + 1][i] == arr2D[j + 2][i] &&				// horizontal match
				arr2D[j + 2][i] == arr2D[j + 3][i])
			{

				frameNearbyH(arr2D, j, i, x_sq, y_sq, 4, gemPosx, gemPosy);						// checks to see if frame is nearby

				if (gemPosx == -1 && gemPosy == -1) {

					arr2D_2[j + addedNum][i] = 2;					// if not, it explodes all gems
																	// and places special gem in randomly set location
					for (int k = 0; k < 4; k++) {
						if (addedNum != k) {
							explodeGem(arr2D, arr2D_2, j + k, i, score);
						}
					}
				}
				else {

					arr2D_2[gemPosx][gemPosy] = 2;							// otherwise, it makes the special gem
																			// in accordance to the frame
					for (int k = 0; k < 4; k++) {							// and then explodes the rest
						if (gemPosx != (j + k)) {
							explodeGem(arr2D, arr2D_2, j + k, i, score);
						}
					}
				}

				score += 50;
				
				jewelsOnBoard_drawer(arr2D, arr2D_2);
				Sleep(50);

			}

		}
	}

}

void Threegems_Handler(int arr2D[][8], int arr2D_2[][8], int &score) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {

			if (arr2D[i][j] == arr2D[i][j + 1] && arr2D[i][j + 1] == arr2D[i][j + 2]) { 
				explodeGem(arr2D, arr2D_2, i, j, score);
				explodeGem(arr2D, arr2D_2, i, j + 1, score);
				explodeGem(arr2D, arr2D_2, i, j + 2, score);
			}
				
			if (arr2D[j][i] == arr2D[j + 1][i] && arr2D[j + 1][i] == arr2D[j + 2][i]) { 
				explodeGem(arr2D, arr2D_2, j, i, score);
				explodeGem(arr2D, arr2D_2, j + 1, i, score);
				explodeGem(arr2D, arr2D_2, j + 2, i, score);
			}

		}
	}

}

void replaceBlankSpaces(int arr2D[][8], int arr2D_2[][8]) {

	int temp;												// function that either randomly creates gems at the top of the 
															// game or it brings the gems down from the top
	for (int i = 0; i < 8; i++) {							// to fill in all the places where the gems exploded
		for (int j = 0; j < 8; j++) {

			if (arr2D[i][j] == 0) {
				if (j == 0) {
					arr2D[i][j] = (rand() % 7) + 1; 
					arr2D_2[i][j] = 1;
				}
				else if (j > 0) {
					temp = arr2D[i][j];
					arr2D[i][j] = arr2D[i][j - 1];
					arr2D[i][j - 1] = temp;
					
					temp = arr2D_2[i][j];
					arr2D_2[i][j] = arr2D_2[i][j - 1];
					arr2D_2[i][j - 1] = temp;
				}

				i = 0; j = -1;
			}

		}
	}

}

int checkForTime(time_t t1, time_t &t2) {

	t2 = time(0);

	if (t2 - t1 == 60) { return 0; }							// checks for time and returns 1 if the timer hits 60 seconds
	return 1;

}

int main() {

	srand(0);

	int jewelBoard[8][8] = { 0 };
	int specialJewelBoard[8][8] = { 0 };												// creates arrays

	int keyPressed = 0;
	int x_coor = 431, y_coor = 22, x_sq = 0, y_sq = 0, keepLooping = 1, score = 0;		// variable creation

	jewelRandomizer(jewelBoard, specialJewelBoard);										// randomizes jewels

	jewelBoard_draw();
	jewelsOnBoard_drawer(jewelBoard, specialJewelBoard);								// draws the jewels out accordingly

	drawScoreBoard();
	drawTimeBoard();																	// draws the scoreboard and timeboard

	time_t start = time(0), end = 0;

	while (keepLooping == 1) {

		elbowGems_Handler(jewelBoard, specialJewelBoard, x_sq, y_sq, score);
		Fivegems_Handler(jewelBoard, specialJewelBoard, x_sq, y_sq, score);
		Fourgems_Handler(jewelBoard, specialJewelBoard, x_sq, y_sq, score);					// all the exploding gem handlers
		Threegems_Handler(jewelBoard, specialJewelBoard, score);

		jewelsOnBoard_drawer(jewelBoard, specialJewelBoard);								// draws board again to see empty spaces
		
		replaceBlankSpaces(jewelBoard, specialJewelBoard);									// removes blank spaces

		if (userMovement(jewelBoard, specialJewelBoard, keyPressed, x_coor, y_coor, x_sq, y_sq, score) == 0 || checkForTime(start, end) == 0) {
			keepLooping = 0;
		}

		UpdateScore(score);
		UpdateTime(end - start);

	}

	cout << "Just in case you didn't see your info: " << endl << endl;
	cout << (end - start) << " seconds have passed." << endl;				// if Space key is pressed or timer runs out
	cout << "Total score : " << score;										// the game ends and
	cout << endl << endl;													// this will be printed out for player to see

	_getch();
	system("PAUSE");
	return 0;
}
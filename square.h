#pragma once

const char EMPTY = 'u';
class square
{
private:
	char piece;
	char color;
public:
	square();
	square(char newPiece, char newColor);
	char getColor();
	char getPiece();
	void setColor(char newColor);
	void setPiece(char newPiece);

};


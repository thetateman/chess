#include "square.h"

square::square(char newPiece, char newColor)
{
	piece = newPiece;
	color = newColor;
}
square::square()
{
	piece = EMPTY;
	color = EMPTY;

}
char square::getColor()
{
	return color;
}
char square::getPiece()
{
	return piece;
}
void square::setColor(char newColor)
{
	color = newColor;
}
void square::setPiece(char newPiece)
{
	piece = newPiece;
}
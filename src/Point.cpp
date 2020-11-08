#include "Point.h"

Point::Point(){
    xp = yp = 0;
}

Point::Point(int xp, int yp){
    this->set_point(xp, yp);
}

Point::Point(const Point& p){
    this->set_point(p);
}

/*
 * Sets position components
 * 
 * args:
 * 	 xp: int containing x position
 *	 yp: int containing y position
 * 
 * return: void
 */
void Point::set_point(int xp, int yp){
    this->xp = xp;
    this->yp = yp;
}

/*
 * Sets position components
 * 
 * args:
 * 	 p: Point containing position to set
 * 
 * return: void
 */
void Point::set_point(const Point& p){
    *this = p;
}

void Point::operator=( const Point& p ){
    this->set_point(p.xp, p.yp);
}

std::ostream& operator<<( std::ostream& output, const Point& p ){
    output << "(" << p.xp << "," << p.yp << ")";
    return output;
}

/*
 * Calculates the distance to another point
 * 
 * args:
 * 	 p: Point containing point to calculate distance to
 * 
 * return: double containined distance in pixels
 */
double Point::distance( const Point& p ) const{
    return sqrt( pow( this->xp - p.xp, 2.0 ) + pow( this->yp - p.yp, 2.0 ) );
}
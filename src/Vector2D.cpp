#include "Vector2D.h"

Vector2D::Vector2D(){
    p = Point();
    xv = yv = 0.0;
}

Vector2D::Vector2D( double xv, double yv ){
    p = Point();
    this->set_vector(xv, yv);
}

Vector2D::Vector2D( const Point& p, double xv, double yv ){
    this->p = p;
    this->set_vector(xv, yv);
}

Vector2D::Vector2D( const Vector2D& v ){
    this->set_vector(v);
}

/*
 * Sets position components
 * 
 * args:
 * 	 xv: double containing x component
 *	 yv: double containing y component
 * 
 * return: void
 */
void Vector2D::set_vector( double xv, double yv )
{
    this->xv = xv;
    this->yv = yv;
}

/*
 * Sets position components
 * 
 * args:
 * 	 p: Point containing position
 *   xv: double containing x component
 *	 yv: double containing y component
 * 
 * return: void
 */
void Vector2D::set_vector( const Point& p, double xv, double yv ){
    this->p = p;
    this->xv = xv;
    this->yv = yv;
}

/*
 * Sets position components
 * 
 * args:
 * 	 v: Vector2D containining vector to set
 * 
 * return: void
 */
void Vector2D::set_vector( const Vector2D &v )
{
    *this = v;
}

void Vector2D::operator=( const Vector2D &v ){
    this->set_vector(v.p, v.xv, v.yv);
}

std::ostream &operator<<( std::ostream &output, const Vector2D &v ){
    output << "(" << v.xv << "," << v.yv << ")@" << v.p;
    return output;
}

/*
 * Makes a horizontal unit vector at a point on x-axis
 * 
 * args:
 * 	 x: Int containing position to make line at
 * 
 * return: Vector2D containing unit vector
 */
Vector2D make_vert_vector(int x){
    return Vector2D(Point(x, 0), 0, 1);
}

/*
 * Makes a horizontal unit vector at a point on x-axis
 * 
 * args:
 * 	 y: Int containing position to make line at
 * 
 * return: Vector2D containing unit vector
 */
Vector2D make_horiz_vector(int y){
    return Vector2D(Point(0, y), 1, 0);
}

/*
 * Calculates point-to-point vector from p1 to p2
 * 
 * args:
 * 	 p1: Point containing to initial position
 *	 p2: Point containing to final position
 * 
 * return: Vector2D containing point-to-point vector
 */
Vector2D p2p_vector( const Point& p1, const Point& p2 )
{
	return Vector2D( p1, p2.xp - p1.xp, p2.yp - p1.yp );
}

/*
 * Normalizes a vector
 * 
 * args:
 * 	 v: Vector2D* pointing to vector to normalize
 * 
 * return: void
 */
void Vector2D::normalize()
{
	double mag = sqrt( this->xv * this->xv + this->yv * this->yv );
	this->set_vector( this->xv / mag, this->yv / mag );
}

/*
 * Calculates dot product: this * v
 * 
 * args:
 * 	 v: Vector2D containined RHS
 * 
 * return: double containing dot product result
 */
double Vector2D::dot_prod( const Vector2D& v ) const
{
	return this->xv * v.xv + this->yv * v.yv;
}

/*
 * Reflects vector over v
 * 
 * args:
 * 	 v: Vector2D* pointing to vector to reflect over
 * 
 * return: void
 */
void Vector2D::reflect( const Vector2D& v )
{
    if(v.is_vertical()){
        this->p.set_point(2*v.p.xp - this->p.xp, this->p.yp);
    }
    else if(v.is_horizontal()){
        this->p.set_point(this->p.xp, 2*v.p.yp - this->p.yp);
    }
    else{
        double m = v.yv/v.xv, ms = -1/m;
        int b = v.p.yp - m*v.p.xp,
            t = this->p.yp - ms*this->p.xp,
            x0 = (b - t)/(ms - m),
            y0 = m*x0 + b;
        this->p.set_point(2*x0 - this->p.xp, 2*y0 - this->p.yp);
    }
	this->set_vector( 2 * this->dot_prod( v ) * v.xv - this->xv,
					2 * this->dot_prod( v ) * v.yv - this->yv);
}

bool Vector2D::is_vertical() const{
    return this->xv < this->yv && this->xv/this->yv <= VERT_CUTOFF;
}

bool Vector2D::is_horizontal() const{
    return this->yv < this->xv && this->yv/this->xv <= VERT_CUTOFF;
}
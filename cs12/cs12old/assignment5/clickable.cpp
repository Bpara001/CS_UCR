// Course: CS 12 quarter 2 , 2010
//
// First Name: Christopher
// Last Name: Wong
// Login id: wongc
// email address: cwong030@student.ucr.edu
// Student id: 860 923 521
//
// Lecture Section: 001
// Lab Section: 021
// TA: Denise Duma
//
// Assignment: Programming Assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.


// clickable.cpp
#include "clickable.h"


// \brief Default constructor for the Clickable class.
Clickable::Clickable()
:  shown(),border()
{
}

  // \brief Constructor for the Clickable class.
  // \param ul_corner The position of the upper left corner of the object.
  // \param height The height of the object.
  // \param width The width of the object.
Clickable::Clickable(const Point & ll_corner,double height,double width)
: shown(false),border(ll_corner,height,width)
{
}

 // \brief Draw the object in the drawing area.
 // \return void.
void Clickable::draw() const
{
   win << border;
}

  // \brief Test to see if the object has been clicked.
  //
  // Only visible objects can be clicked.
  // \param click The point corresponding to the mouse click to test.
  // \return Whether the object has been clicked.
bool Clickable::is_clicked(const Point & click) const
{
   double xclick = click.get_x();
   double yclick = click.get_y();
   Point lowerleft = border.get_lower_left();

   double x_ll = lowerleft.get_x();
   double y_ll = lowerleft.get_y();
   double height = border.get_height();
   double width = border.get_width();



   if(yclick > y_ll && yclick < y_ll + height && xclick > x_ll
      && xclick < x_ll + width)
     {
          return true;
     }
    else return false;

}


  // \brief Test to see if the object is currently shown.
  // \return Whether the object is currently shown.
bool Clickable::is_shown() const
{
   if (shown == true)
   {
      return true;
   }
   else
   {
      return false;
   }

}

  // \brief Make the object visible in the drawing window when drawn.
  // \return void.
void Clickable::show()
{
   shown = true;
}

  // \brief Make the object invisible in the drawing area when drawn.
  // \return void.
void Clickable::hide()
{
   shown = false;
}


  // \brief Move the object by a displacement.
  // \param x_displace The distance to move the object in the x-direction.
  // \param y_displace The distance to move the object in the y-direction.
  // \return void.
void Clickable::move(double x_displace, double y_displace)
{
border.move(x_displace,y_displace);

}

  // \brief Move the upper left corner of the object to a position.
  // \param loc The location to move the object to.
  // \return void.
void Clickable::move_to(const Point & loc)
{
   Point ll_corner = border.get_lower_left();
   double xpoint = ll_corner.get_x();
   double ypoint = ll_corner.get_y();

   move(loc.get_x()-xpoint,loc.get_y()-ypoint);
}

  // \brief Center the object about a point.
  // \param loc The location about which to center the object.
  // \return void.
void Clickable::center(const Point & loc)
{
   Point ll_corner = border.get_lower_left();
   double xpoint = ll_corner.get_x();
   double ypoint = ll_corner.get_y();

   move(loc.get_x()-xpoint-border.get_width()/2,
        loc.get_y()-ypoint-border.get_height()/2);

}


  // \brief Destructor for the Clickable class.
Clickable::~Clickable()
{


}

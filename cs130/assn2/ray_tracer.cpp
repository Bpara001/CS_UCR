/* Course: CS 130 winter quarter , 2013

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Assignment 2

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/





/**
 * ray_tracer.cpp
 * CS230 Assignment 2, Winter 2012
 * -------------------------------
 * Implement ray tracer here.
 */

#define SET_RED(P, C)   (P = (((P) & 0x00ffffff) | ((C) << 24)))
#define SET_GREEN(P, C)  (P = (((P) & 0xff00ffff) | ((C) << 16)))
#define SET_BLUE(P, C) (P = (((P) & 0xffff00ff) | ((C) << 8)))

#include "ray_tracer.h"

using namespace std;

const double Object::small_t=1e-6;
//--------------------------------------------------------------------------------
// utility functions
//--------------------------------------------------------------------------------
double sqr(const double x)
{
    return x*x;
}

Pixel Pixel_Color(const Vector_3D<double>& color)
{
    Pixel pixel=0;
    SET_RED(pixel,(unsigned char)(min(color.x,1.0)*255));
    SET_GREEN(pixel,(unsigned char)(min(color.y,1.0)*255));
    SET_BLUE(pixel,(unsigned char)(min(color.z,1.0)*255));
    return pixel;
}
//--------------------------------------------------------------------------------
// Shader
//--------------------------------------------------------------------------------
Vector_3D<double> Phong_Shader::
Shade_Surface(const Ray& ray,const Object& intersection_object,const Vector_3D<double>& intersection_point,const Vector_3D<double>& same_side_normal) const
{
    Vector_3D<double> color;

    // TODO: determine the color

    return color;
}

Vector_3D<double> Reflective_Shader::
Shade_Surface(const Ray& ray,const Object& intersection_object,const Vector_3D<double>& intersection_point,const Vector_3D<double>& same_side_normal) const
{
    Vector_3D<double> color;

    // TODO: determine the color

    return color;
}

Vector_3D<double> Flat_Shader::
Shade_Surface(const Ray& ray,const Object& intersection_object,const Vector_3D<double>& intersection_point,const Vector_3D<double>& same_side_normal) const
{
    return color;
}

//--------------------------------------------------------------------------------
// Objects
//--------------------------------------------------------------------------------
// determine if the ray intersects with the sphere
// if there is an intersection, set t_max, current_object, and semi_infinite as appropriate and return true
bool Sphere::
Intersection(Ray& ray) const{
    // TODO
    //tmax = t
    //smei_infinite = true if it doesnt hit antyhing
    
   			
	//sclae by the increment
	//Vector_3D x2 = x * x_incr;
	//Vector_3D y2 = y * y_incr;
				
	//calculate d
	Vector3_3D d = (pixelgridCenter - cameraPos) + x2 + y2;
	d.Normalize();
				
	//calculate a,b,c
	double a = Dot_Product(d,d);
	double b = Dot_Product(2*d,cameraPos - center);
	double c = Dot_Product(cameraPos - center,cameraPos - center) - radius;
			
	//calculate discriminate
	double discrim = b*b - 4*a*c;
				
	//If roots are negative, there are no intersections
	if(discrim < 0){
	}
				
	//If roots are zero, there is only 1 intersection
	else if(discrim == 0){
	}
				
	//If roots are positive, there are 2 intersections
	else if(discrim > 0){
						
	}
				
    

    
    return false;
}

Vector_3D<double> Sphere::
Normal(const Vector_3D<double>& location) const
{
    Vector_3D<double> normal;
    // TODO: set the normal
    return normal;
}

// determine if the ray intersects with the Plane
// if there is an intersection, set t_max, current_object, and semi_infinite as appropriate and return true
bool Plane::
Intersection(Ray& ray) const
{
    // TODO
    return false;
}

Vector_3D<double> Plane::
Normal(const Vector_3D<double>& location) const
{
    return normal;
}
//--------------------------------------------------------------------------------
// Camera
//--------------------------------------------------------------------------------
// Find the world position of the input pixel
Vector_3D<double> Camera::
World_Position(const Vector_2D<int>& pixel_index){
	
	//Convert index
	double x_fixed = film.pixel_grid.X(pixel_index).x;
	double y_fixed = film.pixel_grid.X(pixel_index).y;
	
    //convert TV to their vectors
    Vector_3D<double> hor(horizontal_vector.x,horizontal_vector.y,horizontal_vector.z);
    Vector_3D<double> ver(vertical_vector.x,vertical_vector.y,vertical_vector.z);
    Vector_3D<double> center(focal_point.x,focal_point.y,focal_point.z);
    
    //calculate
    Vector_3D<double> result((hor* x_fixed) + (ver* y_fixed) + center);
    
    //return result
    return result;
}
//--------------------------------------------------------------------------------
// Render_World
//--------------------------------------------------------------------------------
// Find the closest object of intersection and return a pointer to it
//   if the ray intersects with an object, then ray.t_max, ray.current_object, and ray.semi_infinite will be set appropriately
//   if there is no intersection do not modify the ray and return 0
const Object* Render_World::
Closest_Intersection(Ray& ray)
{
	int index = -1;
    
    //If the new object is closer (smaller t-value) then it it is the object intersected with
    for(unsigned int i = 0; i < objects.size(); i++)
		if (objects[i]->small_t > ray.current_object->small_t)
			index = i;
	
	//if the ray intersects with an object, then ray.t_max, ray.current_object, and ray.semi_infinite will be set appropriately
	if(index != -1){
		ray.current_object = objects[index];
		ray.t_max = 1;
		ray.semi_infinite = false;
		return ray.current_object;
	}
	else{
		
		ray.semi_infinite = true;
	}
	
    return 0;
}

// set up the initial view ray and call 
void Render_World::
Render_Pixel(const Vector_2D<int>& pixel_index){
	
	
    // TODO
    Ray ray; // TODO: set up the initial view ray here
	
    Ray dummy_root;
    
    
    Vector_3D<double> color=Cast_Ray(ray,dummy_root);
    camera.film.Set_Pixel(pixel_index,Pixel_Color(color));
    
    
}

// cast ray and return the color of the closest intersected surface point, 
// or the background color if there is no object intersection
Vector_3D<double> Render_World::
Cast_Ray(Ray& ray,const Ray& parent_ray){
	
	Vector_3D<double> color;
    
    //cast the ray
    const Object* closest = Closest_Intersection(ray);
    
    
    const Vector_3D <double>interpnt(0,0,0);
    const Vector_3D <double> ss_normal(0,0,0);
    
    //return the color of the closest intersected surface point, 
    if( closest != 0){
		return closest->material_shader->Shade_Surface(ray,*closest, interpnt,ss_normal);
	}
	else return background_shader->Shade_Surface(ray,*closest,interpnt,ss_normal);
    
    

    // determine the color here

    return color;
}

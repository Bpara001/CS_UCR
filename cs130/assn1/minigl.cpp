/* Course: CS 130 winter quarter , 2013

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Assignment 1

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
 * This file defines the API to be implemented for MiniGL.
 * Implement miniGL here.
 * Do not use any additional files
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "minigl.h"
#include <cmath>
#include <vector>
#include <stack>
#define PI 3.14159265
using namespace std;


/**
 * Classes
 */


 //!Matrix Class
 //A fixed, 4x4 matrix used for graphics manipulation.
 //Esentially a four by four array of floats, MGLfloats
 //Does basic operations and prints contents.
class matrix4x4
{
public:
	MGLfloat data[4][4];
	matrix4x4(){ for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) data[i][j] = 0;}
	matrix4x4(const matrix4x4 &m){for(int i = 0; i < 4;i++)for(int j = 0; j < 4; j++)data[i][j] = m.data[i][j];}
	matrix4x4 operator=(const matrix4x4 &m){for(int i = 0; i < 4;i++)for(int j = 0; j < 4; j++)data[i][j] = m.data[i][j];return *this;}
	matrix4x4 operator*(matrix4x4 m){ MGLfloat sum;matrix4x4 temp;for (int i=0;i<4;i++)
	for (int j=0;j<4;j++){sum=0;for (int e=0;e<4;e++)sum+=data[i][e]*m.data[e][j];temp.data[i][j]=sum;}return temp;}
	matrix4x4 operator+(matrix4x4 m){for (int i=0;i<4;i++)for(int j=0;j<4;j++) data[i][j] += m.data[i][j]; return *this;}
	void print(){for(int i = 0; i < 4; i++){std::cout <<std::endl; for(int j=0;j<4;j++) std::cout <<data[i][j]<<",";}std::cout<<std::endl;}

};

 //!Vector class
 //A fixed, 4 sized vector used for graphics manipulation and holding vertices
 //Esentially a 4unit array of floats, MGLfloats.
 //Does basic operations and prints contents.
class vector4{
public:
	vector4(){}
	vector4(MGLfloat x, MGLfloat y) : x(x), y(y), z(0), w(1) {}
	vector4(MGLfloat x, MGLfloat y, MGLfloat z) : x(x), y(y), z(z), w(1) {}
	vector4(MGLfloat x, MGLfloat y, MGLfloat z, MGLfloat w) : x(x), y(y), z(z), w(w) {}
	vector4 operator+(vector4 v){ return vector4(x+v.x, y+v.y, z+v.z, w+v.w); }
	vector4 operator-(vector4 v){ return vector4(x-v.x, y-v.y, z-v.z, w-v.w); }
	vector4 operator*(MGLfloat s){ return vector4(s*x, s*y, s*z, s*w); }
	bool operator!=(vector4 v){ return (x!=v.x or y!=v.y or z!=v.z or w!=v.w); }
	bool operator==(vector4 v){ return (x==v.x and y==v.y and z==v.z and w==v.w); }
	void print(){std::cout<<"("<<x<<","<<y << ","<< z <<","<< w <<")"<< std::endl;}
public:
	MGLfloat x,y,z,w;
};


//!RGB class
//A fixed, container used for manipulation of colors
//Esentially a 3 unit container of bytes.
//Prints, adds and multiplies.
class Rgb{
	public:
		Rgb(){}
		Rgb(MGLbyte r, MGLbyte g,MGLbyte b) : r(r),g(g),b(b) {}
		Rgb operator*(double s){ return Rgb( MGLbyte(r*s), MGLbyte(g*s), MGLbyte(b*s) ); }
		Rgb operator+(Rgb v){return Rgb(r+v.r, g+v.g, b+v.b );}
		void print(){std::cout<<"("<<(int)r<<","<<(int)g << ","<< (int)b <<")"<< std::endl;}
	public:
	MGLbyte r,g,b;
};


/**
 * Global variables
 */

 //! given varibles from template
stack<matrix4x4> modelview;
stack<matrix4x4> projection;
stack<matrix4x4>* stack_pointer = &modelview;
vector<vector4> vertexList; //holds vertices for the mglVertex3 calls
MGLpixel framebuffer[MGL_SCREEN_WIDTH][MGL_SCREEN_HEIGHT];
MGLfloat depthbuffer[MGL_SCREEN_WIDTH][MGL_SCREEN_HEIGHT];

//!Added varibles
MGLpoly_mode current_MGLpoly_mode; //tells which mode is active (triangle or quad)
matrix4x4 *current_matrix; //pointer to the current matrix
int tiebreaker = 0;       //tie breaker coordinates (0,0) for rasteriation puposes
MGLfloat xoffset = 0;	//(x)offset used to center screen
MGLfloat yoffset = 0;	//(y)offset used to center screen
MGLfloat zoffset = 0;	//(z)offset used to center screen
bool isorth = false;	//extra, redudent varbile to determine which mode is on for coding purposes
vector<Rgb> colorList;	//container to hold all verticies color's
Rgb current_color(255,255,255);//current color declared by user



/**
 * This is a helper function. It plots a white pixel on the frame buffer.
 */
void plot(unsigned int x, unsigned int y, Rgb coloring)
{
	//you may need to modify this function to suit your needs
	if(x >= MGL_SCREEN_WIDTH or y >= MGL_SCREEN_HEIGHT) return;
	MGLpixel color = 0;
	MGL_SET_RED(color, coloring.r);
	MGL_SET_GREEN(color, coloring.g);
	MGL_SET_BLUE(color, coloring.b);
	framebuffer[x][y] = color;
}

/**
 * Initializes the miniGL system.
 */
void mglInit()
{

	current_MGLpoly_mode = nil; //declare no vertice creation is going on

	//Setup the matrix stacks
	matrix4x4 identity;
	identity.data[0][0] = 1;
	identity.data[1][1] = 1;
	identity.data[2][2] = 1;
	identity.data[3][3] = 1;
	current_matrix =  new matrix4x4 (identity);

	//you need to set the variable 'identity' to the identity matrix right here.
	modelview.push(identity);
	projection.push(identity);


	//clear the frame buffer and the depth buffer
	MGLpixel color = 0;
	for(unsigned x = 0; x < MGL_SCREEN_WIDTH; x++){
		for(unsigned y = 0; y < MGL_SCREEN_HEIGHT; ++y){
			framebuffer[x][y] = color;
			depthbuffer[x][y] = -99999.0f; //set depth buffer to -infininity
		}
	}
}

/**
 * Standard macro to report errors
 */
inline void MGL_ERROR(const char* description) {
    printf("%s\n", description);
    exit(1);
}

/**
 * Read pixel data starting with the pixel at coordinates
 * (0, 0), up to (width,  height), into the array
 * pointed to by data.  The boundaries are lower-inclusive,
 * that is, a call with width = height = 1 would just read
 * the pixel at (0, 0).
 */
void mglReadPixels(MGLsize width,MGLsize height,MGLpixel *data){
	for(unsigned x = 0; x < width; x++)
		for(unsigned y = 0; y < height; ++y)
			data[y*width+x] = framebuffer[x][y];
}

/**
 * Start specifying the vertices for a group of primitives,
 * whose type is specified by the given mode.
 */
void mglBegin(MGLpoly_mode mode){

	//if mode is triangle set current mode to triangle
	if(mode ==  MGL_TRIANGLES) current_MGLpoly_mode = mode;

	//if mode is quads
	else if(mode == MGL_QUADS) current_MGLpoly_mode = mode;

	//if something else
	else std::cout << "ERROR: mglBegin: Incorrect mode" << std::endl;

}


//!Implicit line equation
//Line equation derived from class.
//Param: integers for the appropiate points
//Returns double
 double f(int x, int y, int x1, int y1, int x2, int y2){
	 return ( ((y1-y2)*x) + ((x2-x1)*y) +(x1*y2)-(x2*y1));
 }

//!Rasterization shading function
//Colors appropriate pixels with given vertices from class.
//Param: Final  three vertex coordinates, with cooresponding colors
void shade(int x,int y,int x1,int y1,int x2,int y2,int x3,int y3,
			Rgb c1, Rgb c2, Rgb c3,
			double z1, double z2, double z3) {

	//calculate baycentric coordinates
	double v1 = f(x,y,x2,y2,x3,y3) / f(x1,y1,x2,y2,x3,y3);
	double v2 = f(x,y,x3,y3,x1,y1) / f(x2,y2,x3,y3,x1,y1);
	double v3 = f(x,y,x1,y1,x2,y2) / f(x3,y3,x1,y1,x2,y2);

	//Check tie breaking
	double r1 = f(x1,y1,x2,y2,x3,y3) * f(tiebreaker,tiebreaker,x2,y2,x3,y3);
	double r2 = f(x2,y2,x3,y3,x1,y1) * f(tiebreaker,tiebreaker,x3,y3,x1,y1);
	double r3 = f(x3,y3,x1,y1,x2,y2) * f(tiebreaker,tiebreaker,x1,y1,x2,y2);

	//See if point must be colored
	if(v1 >= 0 && v2 >= 0 && v3 >= 0){
		if( (v1 > 0 || r1 > 0) &&  (v2 > 0 || r2 > 0) && (v3 > 0 || r3 > 0)){

				//Finally, check zbuffer; color if needed
				MGLfloat zdepth = ( (v1*z1 + v2*z2 + v3*z3) /3);
				if(depthbuffer[x][y] <= zdepth){
						depthbuffer[x][y] = zdepth;
						plot((unsigned int)(x),(unsigned int)(y), ((c1*v1) + (c2*v2) + (c3*v3)));
				}
		}
	}
}


/**
 * Stop specifying the vertices for a group of primitives.
 */
void mglEnd(){

	//If current polygon mode was triangles, begin drawing to screen
	if(current_MGLpoly_mode == MGL_TRIANGLES){

		//Get every 3 vertices
		for(unsigned int i = 0; i < vertexList.size(); i = i+3){
			int x1 = (int)vertexList[i].x;    int y1 = (int)vertexList[i].y;   double z1 = vertexList[i].z;
			int x2 = (int)vertexList[i+1].x;  int y2 = (int)vertexList[i+1].y; double z2 = vertexList[i+1].z;
			int x3 = (int)vertexList[i+2].x;  int y3 = (int)vertexList[i+2].y; double z3 = vertexList[i+2].z;
			for(unsigned x = 0; x < MGL_SCREEN_WIDTH; x++)
				for(unsigned y = 0; y < MGL_SCREEN_HEIGHT; y++)
					shade(x,y,x1,y1,x2,y2,x3,y3,colorList[i],colorList[i+1],colorList[i+2],z1,z2,z3);
		}
	}

	//If current polygon mode was quad, begin drawing to screen
	else if(current_MGLpoly_mode == MGL_QUADS){

		//Get every 4 vertices
		for(unsigned int i = 0; i < vertexList.size(); i = i+4){
			int x4 = (int)vertexList[i].x;    int y4 = (int)vertexList[i].y;	double z4 = vertexList[i].z;
			int x3 = (int)vertexList[i+1].x;  int y3 = (int)vertexList[i+1].y; 	double z3 = vertexList[i].z;
			int x2 = (int)vertexList[i+2].x;  int y2 = (int)vertexList[i+2].y;	double z2 = vertexList[i].z;
			int x1 = (int)vertexList[i+3].x;  int y1 = (int)vertexList[i+3].y;	double z1 = vertexList[i].z;
			for(unsigned x = 0; x < MGL_SCREEN_WIDTH; x++){
				for(unsigned y = 0; y < MGL_SCREEN_HEIGHT; y++){
					shade(x,y,x1,y1,x2,y2,x3,y3,colorList[i+3],colorList[i+2],colorList[i+1],z1,z2,z3);
					shade(x,y,x1,y1,x4,y4,x3,y3,colorList[i+3],colorList[i],colorList[i+1],z1,z4,z3);}}
		}
	}

	current_MGLpoly_mode = nil; //set current polygon mode to null
	colorList.clear(); //clear color list
	vertexList.clear(); //clear vertex list
}

//!Transforms corrdinates to screen coordinates through lots of matrix multiplication
//Param: Point coordinates needed to be converted
//Returns: vertex with transformed coordinates that can be dislayed on screen.
vector4 viewpoint_transform(MGLfloat x, MGLfloat y, MGLfloat z){

	//Create a 4x4 matrix with the point coordinates
	matrix4x4 temp;
	//temp.data[0][0] = x;temp.data[1][1] = y;temp.data[2][2] = z;temp.data[3][3] = 1;
	temp.data[0][3] = x;temp.data[1][3] = y;temp.data[2][3] = z;temp.data[3][3] = 1;
	
	//Load the projection matrix
	matrix4x4 temp2 = projection.top();
	
	//Load matrix that translates screen down .5 left .5
	matrix4x4 temp3;
	temp3.data[0][0] = 1;temp3.data[1][1] = 1;temp3.data[2][2] = 1;temp3.data[3][3] = 1;
	temp3.data[0][3] = -.5;temp3.data[1][3] = -.5;temp3.data[3][3] = 1;

	//Load matrix that scales the screen
	matrix4x4 temp4;
	temp4.data[0][0] = MGL_SCREEN_WIDTH/2; temp4.data[1][1] = MGL_SCREEN_HEIGHT/2;
	temp4.data[2][2] = 1; temp4.data[3][3] = 1;
	

	//Load matrix that translate screen up 1 right 1
	matrix4x4 temp5;
	temp5.data[0][0] = 1;temp5.data[1][1] = 1;temp5.data[2][2] = 1;temp5.data[3][3] = 1;
	temp5.data[0][3] = 1;temp5.data[1][3] = 1;temp5.data[2][3] = 1;temp5.data[3][3] = 1;

	//Multiply everything together, return the correct values
	
	temp = temp2*temp;
	temp = temp5*temp;
	temp = temp4*temp;
	temp = temp3*temp;
	
	
	return vector4(temp.data[0][3]/temp.data[3][3],temp.data[1][3]/temp.data[3][3],temp.data[2][3]/temp.data[3][3]);
	
	
	
}

//!multiplies a point by the current transformation matrix on the stack
//Param: Point coordinates needed to be transformed
//Returns: transformed vertex
vector4 transformation_correction(MGLfloat x, MGLfloat y, MGLfloat z){

	//Load current transformation matrix
	matrix4x4 temp6 = *current_matrix;

	//Convert vertex into matrix
	matrix4x4 temp8;
	temp8.data[0][3] = x;temp8.data[1][3] = y;temp8.data[2][3] = z;temp8.data[3][3] = 1;

	//Multiply and return
	matrix4x4 temp = temp6*temp8;
	return vector4(temp.data[0][3],temp.data[1][3],temp.data[2][3]);
}


/**
 * Specify a two-dimensional vertex; the x- and y-coordinates
 * are explicitly specified, while the z-coordinate is assumed
 * to be zero.  Must appear between calls to mglBegin() and
 * mglEnd().
 */
void mglVertex2(MGLfloat x,MGLfloat y){
	if(current_MGLpoly_mode != nil){

		vector4 temp = transformation_correction(x,y,0);
		vector4 temp2 = viewpoint_transform(temp.x,temp.y,temp.z);
		std::cout <<"v"<<vertexList.size()<<" ("<<temp2.x<<","<<temp2.y<<","<<temp2.z<<")"<<std::endl;
		vertexList.push_back(vector4(temp2.x,temp2.y,temp2.z));
		colorList.push_back(current_color);
	}
}

/**
 * Specify a three-dimensional vertex.  Must appear between
 * calls to mglBegin() and mglEnd().
 */
void mglVertex3(MGLfloat x,MGLfloat y,MGLfloat z){
	if(current_MGLpoly_mode != nil){

		vector4 temp = transformation_correction(x,y,z);
		vector4 temp2 = viewpoint_transform(temp.x,temp.y,temp.z);
		std::cout <<"v"<<vertexList.size()<<" ("<<temp2.x<<","<<temp2.y<<","<<temp2.z<<")"<<std::endl;
		vertexList.push_back(vector4(temp2.x,temp2.y,z+1));
		colorList.push_back(current_color);
	}
}

/**
 * Set the current matrix mode (modelview or projection).
 */
void mglMatrixMode(MGLmatrix_mode mode){

	mglPushMatrix();
	if(mode == MGL_MODELVIEW)stack_pointer = &modelview;
	else if(mode == MGL_PROJECTION)stack_pointer = &projection;

}

/**
 * Push a copy of the current matrix onto the stack for the
 * current matrix mode.
 */
void mglPushMatrix(){
	
	if(stack_pointer == &modelview) modelview.push(*current_matrix);
	else if(stack_pointer == &projection) projection.push(*current_matrix);
}

/**
 * Pop the top matrix from the stack for the current matrix
 * mode.
 */
void mglPopMatrix(){
	
	//stack_pointer->pop();
	current_matrix =  new matrix4x4 (stack_pointer->top());
}

/**
 * Replace the current matrix with the identity.
 */
void mglLoadIdentity(){

	//Setup the matrix stacks
	matrix4x4 identity;
	identity.data[0][0] = 1;identity.data[1][1] = 1;identity.data[2][2] = 1;identity.data[3][3] = 1;
	current_matrix =  new matrix4x4 (identity);
}

/**
 * Replace the current matrix with an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglLoadMatrix(const MGLfloat *matrix){

	matrix4x4 temp;
	int count = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j<4; j++){
			temp.data[j][i] = matrix[count];
			count++;
		}
	}

	current_matrix =  new matrix4x4 (temp);
}

/**
 * Multiply the current matrix by an arbitrary 4x4 matrix,
 * specified in column-major order.  That is, the matrix
 * is stored as:
 *
 *   ( a0  a4  a8  a12 )
 *   ( a1  a5  a9  a13 )
 *   ( a2  a6  a10 a14 )
 *   ( a3  a7  a11 a15 )
 *
 * where ai is the i'th entry of the array.
 */
void mglMultMatrix(const MGLfloat *matrix){
	matrix4x4 temp;
	int count = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j<4; j++){
			temp.data[j][i] = matrix[count];
			count++;
		}
	}
	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
}

/**
 * Multiply the current matrix by the translation matrix
 * for the translation vector given by (x, y, z).
 */
void mglTranslate(MGLfloat x,MGLfloat y,MGLfloat z){

	matrix4x4 temp;
	temp.data[0][3] = x;temp.data[1][3] = y;temp.data[2][3] = z;temp.data[3][3] = 1;
	temp.data[0][0] = 1;temp.data[1][1] = 1;temp.data[2][2] = 1;temp.data[3][3] = 1;

	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
}

/**
 * Multiply the current matrix by the rotation matrix
 * for a rotation of (angle) degrees about the vector
 * from the origin to the point (x, y, z).
 */
void mglRotate(MGLfloat angle,MGLfloat x,MGLfloat y,MGLfloat z){

	matrix4x4 temp;

	MGLfloat c = cos(angle * PI/180);
	MGLfloat s = sin(angle * PI/180);
	
	
	MGLfloat x1 = x;
	MGLfloat y1 = y;
	MGLfloat z1 = z;
	
	x /= sqrt( (x1*x1) + (y1*y1) + (z1*z1));
	y /= sqrt( (x1*x1) + (y1*y1) + (z1*z1));
	z /= sqrt( (x1*x1) + (y1*y1) + (z1*z1));
	temp.data[3][3] = 1;
	

	temp.data[0][0] =(x*x) *(1-c)  +c;
	temp.data[0][1] =(x*y) *(1-c)  -(z*s);
	temp.data[0][2] =(x*z) *(1-c)  +(y*s);

	temp.data[1][0] =(y*x) *(1-c)  +(z*s);
	temp.data[1][1] =(y*y) *(1-c)  +c;
	temp.data[1][2] =(y*z) *(1-c)  -(x*s);

	temp.data[2][0] =(x*z) *(1-c)  -(y*s);
	temp.data[2][1] =(y*z) *(1-c)  +(x*s);
	temp.data[2][2] =(z*z) *(1-c)  +c;
	
	temp.data[3][3] = 1;

/*
	


	temp.data[0][0] =(x*x) *(1-c)  +c;
	temp.data[1][0] =(x*y) *(1-c)  -(z*s);
	temp.data[2][0] =(x*z) *(1-c)  +(y*s);

	temp.data[0][1] =(y*x) *(1-c)  +(z*s);
	temp.data[1][1] =(y*y) *(1-c)  +c;
	temp.data[2][1] =(y*z) *(1-c)  -(x*s);

	temp.data[0][2] =(x*z) *(1-c)  -(y*s);
	temp.data[1][2] =(y*z) *(1-c)  +(x*s);
	temp.data[2][2] =(z*z) *(1-c)  +c;
*/

	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
}

/**
 * Multiply the current matrix by the scale matrix
 * for the given scale factors.
 */
void mglScale(MGLfloat x,MGLfloat y,MGLfloat z){
	matrix4x4 temp;
	temp.data[0][0] = x;
	temp.data[1][1] = y;
	temp.data[2][2] = z;
	temp.data[3][3] = 1;

	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
}

/**
 * Multiply the current matrix by the perspective matrix
 * with the given clipping plane coordinates.
 */
void mglFrustum(MGLfloat left,MGLfloat right,MGLfloat bottom,MGLfloat top,
                MGLfloat near,MGLfloat far){

	matrix4x4 temp;
	temp.data[0][0] = (2*near)/(right-left);
	temp.data[1][1] = (2*near)/(top-bottom);
	temp.data[2][2] = (far+near)/(far-near); //c
	temp.data[3][3] = 0;

	temp.data[0][2] = (right+left)/(right-left); //a
	temp.data[1][2] = (top+bottom)/(top-bottom); //b
	temp.data[2][3] = (2*far*near)/(far-near);
	temp.data[3][2] = -1;

	//matrix4x4 temp3 = temp* (*current_matrix);
	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
	isorth = false;
}

/**
 * Multiply the current matrix by the orthographic matrix
 * with the given clipping plane coordinates.
 */
void mglOrtho(MGLfloat left,MGLfloat right,MGLfloat bottom,MGLfloat top,
              MGLfloat near,MGLfloat far){
	matrix4x4 temp;
	temp.data[0][3] = -(right+left)/(right-left);
	temp.data[1][3] = -(top+bottom)/(top-bottom);
	temp.data[2][3] = -(far+near)/(far-near);
	temp.data[3][3] = 1;

	temp.data[0][0] = 2/(right-left);
	temp.data[1][1] = 2/(top-bottom);
	temp.data[2][2] = 2/(far-near);

	//matrix4x4 temp3 = temp* (*current_matrix);
	matrix4x4 temp3 = (*current_matrix) * temp;
	current_matrix =  new matrix4x4 (temp3);
	isorth = true;
	
	
	
	
}

/**
 * Set the current color for drawn shapes.
 */
void mglColor(MGLbyte red,MGLbyte green,MGLbyte blue){
	current_color.r = red; current_color.g = green; current_color.b = blue;
}



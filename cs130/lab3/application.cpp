#include "application.h"

#include <iostream>
#include <cassert>

using namespace std;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void draw_grid();
    
application::application() 
    : solid(true)
{
}

application::~application()
{
}

// triggered once after the OpenGL context is initialized
void application::init_event()
{

    cout << "CAMERA CONTROLS: \n  LMB: Rotate \n  MMB: Pan \n  LMB: Dolly" << endl;
    cout << "KEYBOARD CONTROLS: \n  '=': Toggle wireframe mode" << endl;

    const GLfloat ambient[] = { 0.15, 0.15, 0.15, 1.0 };
    const GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1.0 };
    const GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    
    // enable a light
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
    glEnable(GL_LIGHT1);
    
    // enable depth-testing, colored materials, and lighting
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    // normalize normals so lighting calculations are correct
    // when using GLUT primitives
    glEnable(GL_NORMALIZE);
    
    // enable smooth shading
    glShadeModel(GL_SMOOTH);

    // set the cameras default coordinates
    camera.set_distance(20);
    camera.set_elevation(35);
    camera.set_twist(45);

    t.reset();
}

// triggered each time the application needs to redraw
void application::draw_event()
{
	
	
	/*
    // apply our camera transformation
    camera.apply_gl_transform();
    
    // set the position of the light
    const GLfloat light_pos1[] = { 0.0, 10.0, 0.0, 1 };   
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
    
    // draws the grid and frame at the origin
    draw_grid();

    //
    // create some various objects in the world
    //
    
	//Set up variables
	double sun_xpos = 0;
	double sun_ypos = 2;
	double sun_zpos = 0;
	double sun_radius = 2;
	
	int sphere_stacks = 20;
	int sphere_slices = 20;
	
	double orbit_speed = .2;
	
	
	//float x = r*cos(t) + h;
	//float y = r*sin(t) + k;
	
	//Create the sun
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(sun_xpos, sun_ypos, sun_zpos);
    glRotatef(t.elapsed()*45, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    glScalef(2, 2, 2); 					//scale it by 2x
    solid ? glutSolidSphere(sun_radius/2, sphere_slices, sphere_stacks) : glutWireSphere(sun_radius/2, sphere_slices, sphere_stacks);
    glPopMatrix();
    
    //Create mercury
	glPushMatrix();
    glColor3f(1, 0, 0);
    double planet1_x= 4*cos(t.elapsed() *orbit_speed ) + sun_xpos;
    double planet1_y= sun_ypos;
    double planet1_z= 4*sin(t.elapsed() *orbit_speed) + sun_zpos;
    glTranslatef(planet1_x, planet1_y, planet1_z); //create circular orbit
	glRotatef(t.elapsed()*45, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    solid ? glutSolidSphere(sun_radius/5, sphere_slices, sphere_stacks) : glutWireSphere(sun_radius/5, sphere_slices, sphere_stacks);
    glPopMatrix();
    
    //Create venus(cube)
	glPushMatrix();
    glColor3f(1, .65, 0);
    double planet2_x= 6.5*cos(t.elapsed() * (orbit_speed *1.3)) + sun_xpos;
    double planet2_y= sun_ypos - .5;
    double planet2_z= 6.5*sin(t.elapsed() * (orbit_speed *1.3)) + sun_zpos;
    glTranslatef(planet2_x,planet2_y ,planet2_z); //create circular orbit
	glRotatef(t.elapsed()*65, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    solid ? glutSolidCube(sun_radius/4.5) : glutWireCube(sun_radius/4.5);
    glPopMatrix();
    
    //Create Earth
    glPushMatrix();
    glColor3f(.3, .25, 1);
    double planet3_x= 9.5*cos(t.elapsed() * (orbit_speed *.65)) + sun_xpos;
    double planet3_y= sun_ypos;
    double planet3_z= 9.5*sin(t.elapsed() * (orbit_speed *.65)) + sun_zpos;
    glTranslatef(planet3_x,planet3_y ,planet3_z); //create circular orbit
	glRotatef(t.elapsed()*45, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    solid ? glutSolidSphere(sun_radius/3, sphere_slices, sphere_stacks) : glutWireSphere(sun_radius/3, sphere_slices, sphere_stacks);
    glPopMatrix();
    
    //Create a moon for earth
    glPushMatrix();
    glColor3f(.9, .9, .9);
    double planet3a_x= 2*cos(t.elapsed() * (orbit_speed *7.5)) + planet3_x;
    double planet3a_y= planet3_y;
    double planet3a_z= 2*sin(t.elapsed() * (orbit_speed *7.5)) + planet3_z;
    glTranslatef(planet3a_x,planet3a_y ,planet3a_z); //create circular orbit
	glRotatef(t.elapsed()*45, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    solid ? glutSolidSphere(sun_radius/8, sphere_slices, sphere_stacks) : glutWireSphere(sun_radius/8, sphere_slices, sphere_stacks);
    glPopMatrix();
    
    //Create a moon #2for earth
    glPushMatrix();
    glColor3f(.9, .9, .9);
    double planet3b_x= 2.6*cos(t.elapsed() * (orbit_speed *9.5)) + planet3_x;
    double planet3b_y= planet3_y;
    double planet3b_z= 2.6*sin(t.elapsed() * (orbit_speed *9.5)) + planet3_z;
    glTranslatef(planet3b_x,planet3b_y ,planet3b_z); //create circular orbit
	glRotatef(t.elapsed()*45, 0, 1, 0); // rotate 30 degrees/second about the y-axis
    solid ? glutSolidCube(sun_radius/8) : glutSolidCube(sun_radius/8);
    glPopMatrix();
    */
    static GLfloat trans[6][3] = {
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0},
    {1.0, 0.0, 0.0},
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, -1.0, 0.0}
};
static GLfloat rots[6][4] = {
    {0.0, 0.0, 1.0, 0.0},
    {180.0, 0.0, 1.0, 0.0},
    {90.0, 0.0, 1.0, 0.0},
    {-90.0, 0.0, 1.0, 0.0},
    {-90.0, 1.0, 0.0, 0.0},
    {90.0, 1.0, 0.0, 0.0}
};
static GLbyte cols[6][3] = {
    {255, 0, 0},
    {0, 255, 255},
    {0, 255, 0},
    {255, 0, 255},
    {0, 0, 255},
    {255, 255, 0}
};

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glTranslatef(0.0, 0.0, -5.0);
glRotatef(-60, -1.0, 1.0, -1.0);

for (int i = 0; i < 3; ++i) {
    GLfloat* tran = trans[i];
    GLfloat* rot = rots[i];
    GLbyte* col = cols[i];

    glPushMatrix();

    glTranslatef(tran[0], tran[1], tran[2]);
    glRotatef(rot[0], rot[1], rot[2], rot[3]);

    //glColor3b(col[0], col[1], col[2]);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glPopMatrix();
}

    
    
}

// triggered when mouse is clicked
void application::mouse_click_event(
    mouse_button button, mouse_button_state button_state, 
    
    int x, int y
    )
{
}
    
// triggered when mouse button is held down and the mouse is
// moved
void application::mouse_move_event(
    int x, int y
    )
{
}

// triggered when a key is pressed on the keyboard
void application::keyboard_event(unsigned char key, int x, int y)
{
    if (key == '=')
        solid = !solid;
}

void draw_grid()
{
    glDisable(GL_LIGHTING);
    glLineWidth(2.0);

    //
    // Draws the coordinate frame at origin
    //
    glPushMatrix();
    glScalef(0.5, 0.5, 0.5); 
    glBegin(GL_LINES);

    // x-axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    
    // y-axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    
    // z-axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glEnd();
    glPopMatrix();
    
    //
    // Draws a grid along the x-z plane
    //
    glLineWidth(1.0);
    glColor3f(.20, .20, .20);
    glBegin(GL_LINES);

    int ncells = 60;
    int ncells2 = ncells/2;

    for (int i= 0; i <= ncells; i++)
    {
        int k = -ncells2;
        k +=i;
        glVertex3f(ncells2,0,k);
        glVertex3f(-ncells2,0,k);
        glVertex3f(k,0,ncells2);
        glVertex3f(k,0,-ncells2);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

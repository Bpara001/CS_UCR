#include <GL/gl.h> //OpenGL
#include <GL/glu.h> //Extra utilities for opengl
#include <SDL/SDL.h> //windowing stuff
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>


using namespace std;


class BadConversion : public std::runtime_error {
public:
  BadConversion(std::string const& s)
    : std::runtime_error(s)
    { }
};


inline double convertToDouble(std::string const& s)
{
  std::istringstream i(s);
  double x;
  if (!(i >> x))
    throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}


//Here is some boilerplate code. It's not the most object oriented thing in the
//world but it should get you started. Feel free to use and modify.
int main(int nArgs, char** args)
{
	//Initialize the window
	//Setup SDL: http://www.libsdl.org/cgi/docwiki.cgi/SDL_API_by_name
	SDL_Init(SDL_INIT_VIDEO);
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	//setting up 24-bit framebuffer: http://en.wikipedia.org/wiki/Framebuffer
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); //8 bits for red
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8); //8 bits for green
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8); //8 bits for blue

	//enable double buffering: http://en.wikipedia.org/wiki/Page_flipping
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //enable page flipping

	//Create a 800 by 600 window with 32 bits per pixel and uses OpenGL
	SDL_SetVideoMode(800, 600, 32, SDL_OPENGL);

	SDL_WM_SetCaption("CS130 Lab", NULL); //Set the window caption



	//Set up Opengl stuff
	//http://www.opengl.org/sdk/docs/man/

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION); //This is like setting up our camera lens (all future matrix stuff will modify our "camera lens")
	gluPerspective(45, 4.0/3.0, 1, 100); //field of view, aspect ratio, near plane and far plane(aka min and max view distance)

	glMatrixMode(GL_MODELVIEW); //set it back to modelview (this is for setting the matrix transformations for all of our objects



	//Extra variables for main loop
	double x = 0;
	double y = 0;
	double zoom=10;
	//Main loop
	while(true)
	{
		////////////////////////////////////////////////////////////////////
		//LOGIC
		///////////////////////////////////////////////////////////////////
		//Update platform specific stuff
		SDL_Event event;
		SDL_PollEvent(&event); //Get events
		if(event.type == SDL_QUIT) //if you click the [X] exit out
			break;

		//Handle some input
		int mouseX, mouseY;
		char buttons = SDL_GetRelativeMouseState(&mouseX, &mouseY);
		bool leftClick = buttons & SDL_BUTTON(1);
		bool rightClick = buttons & SDL_BUTTON(3);

		// handle camera rotation with left-click
		const float sensitivity = 0.1;
		if(leftClick){
		    x += mouseX*sensitivity;
		    y += mouseY*sensitivity;
		}
		//handle camera zoom with right-click
		if(rightClick){
		    zoom=max(zoom+mouseY*sensitivity,0.0);
		}

		////////////////////////////////////////////////////////////
		//GRAPHICS
		////////////////////////////////////////////////////////////
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the color buffer and the depth buffer

		// http://fly.srk.fer.hr/~unreal/theredbook/chapter03.html <---information regarding viewing/transformation
		//setup the camera
		glLoadIdentity(); //Load the identity matrix
		gluLookAt(0, 0, zoom, //camera position
			  0, 0, 0, //target position(where the camera is looking)
		          0, 1, 0); //up vector(where is up)
		// Make camera rotate
		glRotatef(x, 0,1,0); // x angle, followed by the axis of rotation
		glRotatef(y, 1,0,0); // y angle, followed by the axis of rotation
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); // this will enable wire-frame mode


	  //open the monkey file
	  string line;


	  ifstream myfile ("monkey.raw");
	  if (myfile.is_open()){

		for(int i = 0; i < 968; i++){

			  getline (myfile,line);

			  string xpos1 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string ypos1 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string zpos1 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);

			  string xpos2 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string ypos2 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string zpos2 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);

			  string xpos3 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string ypos3 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);
			  string zpos3 = line.substr(0,line.find(" ") );
			  line = line.substr(line.find(" ") +1);

			  //glTranslatef(1.25,0,0);
			  //glRotatef(x, 0,1,0); //angle, followed by the axis of rotation
			  glBegin(GL_TRIANGLES);
			  glColor3f(1,1,1); glVertex3f(convertToDouble(xpos1),convertToDouble(ypos1),convertToDouble(zpos1));
			  glColor3f(1,1,1); glVertex3f(convertToDouble(xpos2),convertToDouble(ypos2),convertToDouble(zpos2));
			  glColor3f(1,1,1); glVertex3f(convertToDouble(xpos3),convertToDouble(ypos3),convertToDouble(zpos3));
			  glEnd();
		      glPopMatrix();
		  }

	  }





		myfile.close();

		//Swap the buffers(yes we are using double buffering)
		//To avoid this: http://en.wikipedia.org/wiki/Screen_tearing
		//We are doing this: http://en.wikipedia.org/wiki/Multiple_buffering
		//otherwise we just use single buffering and we won't need this function call
		SDL_GL_SwapBuffers(); //Finished drawing




	}



	//Exit out
	SDL_Quit();
	return 0;
}

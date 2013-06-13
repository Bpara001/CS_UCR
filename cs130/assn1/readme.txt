

-----------Note----
My MGL passes all tests specified in the "tests/" folder
did not implement extra credit
implemented color interpertation.


--------TO USE----
To use, direct your terminal to wongc_assn1/ directory,
type the following:
"make clean"
"make"
"minigl"
a .tga file has been created, 'render.tga' has all contents


--------Design choices--------
I tried to follow the OPENGL standards as much possible, although 
I made a custom changes.

Instead of using the given matrix multiplyer function, I created my own
custom matrix4x4 class, and overloaded several useful operators. It
functions the same as specificed, but cuts down on the amount of text 
used to demostrate the same thing.

Also, i created a RGB class, a container holding 3 MGLbyte values.
I also overloaded a few operators to make my life eaiser when doing the 
color interpertation.

To figure out what color attaches to which vertex, i created a sepearte
colorList, a 1d Vector containing all colors, with the same position as 
the VertexList, to eaisly differentiate which vertex goes to which color

Calculating the z-depth value for the zbuffer array, I used the same
formula as the color interlopation as seen in lecture. IT gave correct results.
The only difference is that I added, then averaged the 3 specified Z vertex
values.

Any other design choices will be seen in my comments!.

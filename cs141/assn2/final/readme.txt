README FILE

1. PROGRAMMING LANGUAGE:
C++

2. DESCRIPTION OF ALGORITHM
NOTE: I assume correct input

num_matrixes = number of matrixes

//Do this for each matrix
while(cnt < num_matrixes)
    width = width of matrix
    height = height of matrix
    first_largest = 0
    second_largest = 0
    vector<int> v
    vector<int> v2
    vector<int> v3

    //populate vector
    for(int i = 0; i < width * height; i++)
        if(input == "F") v[i] = 1
        else v[i] = 0

    //Calculate squares length at lowerleft
    for(int i = 0; i < width * height; i++)
        if(v[i] != 0)
            v[i] += min(v[i-1],v[i-width],v[i-1-width])

    //Find largest
    for(int i = 0; i < width * height; i++)
        if(v[i] > first_largest)
            first_largest = v[i]

    //Find number of largest squares
    for(int i = 0; i < width * height; i++)
        if(v[i] == first_largest)
            v2.push_back(i)

    //Calculate second largest
    for(int i = 0; i < v2.size(); i++)
        delete_square at location v2[i]
        vector<int> vtemp = v
        v3.push_back(vtemp.find_largest)

    //find second largest
    for(int i = 0; i < v3.size(); i++)
        if(second_largest > v3[i]
            second_largest = v3[i]

    //output to console and outfile
    console: first_largest << " " << second largest << "\n"
    outfile: first_largest << " " << second largest << "\n"

3.ANALYSIS

let n = height of matrix, let m = width of matrix

populating the vector will take: n * m + c1
calculating the squares will take: 3(n * m + c2)
calculating the max num will take: n * m + c3
so, calculating the size of the first largest number will take
= n * m + c1 + 3(n * m + c2) + n * m + c3
= nm + c1 + 3nm + c2 + nm + c3
= 5nm + c1 + c2 + c3
= O(nm)
big Oh for finding the first largest square is O(nm)

calculating num of same large squares: n * m + c4
calculating the second largest of the sub-square: nm(5nm + c1 + c2 + c3)
finding the largest num in the vector: n*m+c5
= n * m + c4 + nm(5nm + c1 + c2 + c3) + n*m+c5
= nm + nm(nm) + c
= (nm)^2 + c
= O((nm)^2)
so, the worst-case time complexity for finding the second largest and largest
is O((nm)^2)

let x = number of matrixes
thus, the worst-case time complexity for the entire program is
= x * O((nm)^2)
= O(x((nm)^2)))

4. HOW TO USE
 -First, untar using "-xzvf assn2.tgz"
 -to compile: type "make" in console
 -to invoke: "square [input_file] [output_file]
    where 'input_file' is the corresponding text file with correct input
    where 'output_file' is the name of the text file which to be outputed
    ex, "square input.txt output.txt"
 -output will be written to txt file and outputed to console

5. Final note:
entire program is written in one file; class decleartion and main test harness
are in square.cpp; to aviod multiple files and amek it more user friendly

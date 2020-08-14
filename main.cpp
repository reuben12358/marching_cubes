#include <iostream>
#include <utility>      // for pair
#include <vector>       // for vector
#include <cmath>        // for pow and abs

using namespace std;

//  Coordinate system
//
//       y
//       |
//       |
//       |
//       0-----x
//      /
//     /
//    z
//
//       4-------------------5
//      /|                  /|
//     / |                 / |
//    /  |                /  |
//   7-------------------6   |
//   |   |               |   |
//   |   |               |   |
//   |   |               |   |
//   |   |               |   |
//   |   0---------------|---1
//   |  /                |  /
//   | /                 | /
//   |/                  |/
//   3-------------------2
/*
//       o--------4----------o
//      /|                  /|
//     7 |                 5 |
//    /  |                /  |
//   o--------6----------o   |
//   |   8               |   9
//   |   |               |   |
//   |   |               |   |
//   11  |               10  |
//   |   o--------0------|---o
//   |  /                |  /
//   | 3                 | 1
//   |/                  |/
//   o--------2----------o
*/

class point {
    private:
        float x;
        float y;
        float z;
    public:
        point() {};
        point(float a, float b, float c) { x = a; y = b; z = c;}
        float getx() {return x;}
        float gety() {return y;}
        float getz() {return z;}
};

class triangle {
    private:
    public: 
        point x;
        point y;
        point z;
        triangle() {};
        triangle(point a, point b, point c) { x = a; y = b; z = c;}
};

class lookup {
    private:
        // vector<bool>vertices[8];
        // vector<bool>edges[12];
    public:
        vector<pair<int, int>>X;        // edges in X plane
        vector<pair<int, int>>Y;        // edges in Y plane
        vector<pair<int, int>>Z;        // edges in Z plane
        vector<triangle> triangle_pts;      // vector of possible triangles
        lookup() {};
        lookup(vector<pair<int, int>>x, vector<pair<int, int>>y, vector<pair<int, int>>z) {X = x; Y = y; Z = z;}
};

float interpolate (float v1, float v2) {
    if (v1 > v2) {
        return abs(v2)/(abs(v1) + abs(v2));
    }
    else {
        return abs(v1)/(abs(v1) + abs(v2));
    }
}

vector<lookup> table = {
/*0*/   lookup(),
/*1*/   lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*2*/   lookup({make_pair(0, 1)}, {make_pair(1, 5)}, {make_pair(1, 2)}), 
/*3*/   lookup({}, {make_pair(0, 4), make_pair(1, 5)}, {make_pair(0, 3), make_pair(1, 2)}),
/*4*/   lookup({make_pair(3, 2)}, {make_pair(6, 2)}, {make_pair(1, 2)}),
/*5*/   lookup({make_pair(0, 1), make_pair(2, 3)}, {make_pair(0, 4), make_pair(2, 6)}, {make_pair(0, 3), make_pair(1, 2)}),
/*6*/   lookup({make_pair(0, 1), make_pair(3, 2)}, {make_pair(1, 5), make_pair(2, 6)}, {}),
/*7*/   lookup({make_pair(3, 2)}, {make_pair(0, 4), make_pair(1, 5), make_pair(2, 6)}, {make_pair(0, 3)}),
/*8*/   lookup({make_pair(3, 2)}, {make_pair(3, 7)}, {make_pair(0, 3)}),
/*9*/   lookup({make_pair(0, 1), make_pair(3, 2)}, {make_pair(0, 4), make_pair(3, 7)}, {}),
/*10*/  lookup({make_pair(0, 1), make_pair(2, 3)}, {make_pair(1, 5), make_pair(3, 7)}, {make_pair(0, 3), make_pair(1, 2)}),
/*11*/  lookup({make_pair(3, 2)}, {make_pair(0, 4), make_pair(1, 5), make_pair(3, 7)}, {make_pair(1, 2)}),
/*12*/  lookup({}, {make_pair(3, 7), make_pair(2, 6)}, {make_pair(0, 3), make_pair(1, 2)}), 
/*13*/  lookup({make_pair(0, 1)}, {make_pair(0, 4), make_pair(3, 7), make_pair(2, 6)}, {make_pair(1, 2)}),
/*14*/  lookup({make_pair(0, 1)}, {make_pair(1, 5), make_pair(2, 6), make_pair(3, 7)}, {make_pair(0, 3)}),
/*15*/  lookup({}, {make_pair(0, 4), make_pair(1, 5), make_pair(2, 6), make_pair(3, 7)}, {}),
/*16*/  lookup({make_pair(4, 5)}, {make_pair(0, 4)}, {make_pair(4, 7)}),
/*17*/  lookup({make_pair(0, 1), make_pair(4, 5)}, {}, {make_pair(0, 3), make_pair(4, 7)}),
/*18*/  lookup({make_pair(0, 1), make_pair(4, 5)}, {make_pair(0, 4), make_pair(1, 5)}, {make_pair(1, 2), make_pair(4, 7)}),
/*19*/  lookup({make_pair(4, 5)}, {make_pair(1, 5)}, {make_pair(0, 3), make_pair(4, 7), make_pair(1, 2)}),
/*20*/  lookup({make_pair(4, 5), make_pair(2, 3)}, {make_pair(0, 4), make_pair(2, 6)}, {make_pair(0, 3), make_pair(1, 2)}),

/*21*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*22*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*23*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*24*/  lookup({make_pair(3, 2), make_pair(4, 5)}, {make_pair(0, 4), make_pair(3, 7)}, {make_pair(0, 3), make_pair(4, 7)}),
/*25*/  lookup({make_pair(0, 1), make_pair(3, 2), make_pair(4, 5)}, {make_pair(3, 7)}, {make_pair(4, 7)}),

/*26*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*27*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*28*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*29*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*30*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*31*/  lookup({make_pair(4, 5)}, {make_pair(1, 5), make_pair(2, 6), make_pair(3, 7)}, {make_pair(4, 7)}),
/*32*/  lookup({make_pair(4, 5)}, {make_pair(1, 5)}, {make_pair(5, 6)}),
/*33*/  lookup({make_pair(4, 5), make_pair(0, 1)}, {make_pair(1, 5), make_pair(0, 4)}, {make_pair(5, 6), make_pair(0, 3)}),
/*34*/  lookup({make_pair(4, 5), make_pair(0, 1)}, {}, {make_pair(5, 6), make_pair(1, 2)}),
/*35*/  lookup({make_pair(4, 5)}, {make_pair(0, 4)}, {make_pair(0, 3), make_pair(1, 2), make_pair(5, 6)}),
/*36*/  lookup({make_pair(4, 5), make_pair(2, 3)}, {make_pair(1, 5), make_pair(2, 6)}, {make_pair(1, 2), make_pair(5, 6)}),

/*37*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*38*/  lookup({make_pair(0, 1), make_pair(4, 5), make_pair(3, 2)}, {make_pair(2, 6)}, {make_pair(5, 6)}),

/*39*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*40*/  lookup({make_pair(4, 5), make_pair(2, 3)}, {make_pair(1, 5), make_pair(3, 7)}, {make_pair(0, 3), make_pair(5, 6)}),

/*41*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*42*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*43*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*44*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*45*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*46*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*47*/  lookup({make_pair(4, 5)}, {make_pair(0, 4), make_pair(3, 7), make_pair(2, 6)}, {make_pair(5, 6)}),
/*48*/  lookup({}, {make_pair(0, 4), make_pair(1, 5)}, {make_pair(4, 7), make_pair(5, 6)}),        
/*49*/  lookup({make_pair(0, 1)}, {make_pair(1, 5)}, {make_pair(0, 3), make_pair(4, 7), make_pair(5, 6)}),
/*50*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(1, 2), make_pair(4, 7), make_pair(5, 6)}),

/*51*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*52*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*53*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*54*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*55*/  lookup({make_pair(3, 2)}, {make_pair(2, 6)}, {make_pair(0, 3), make_pair(5, 6), make_pair(4, 7)}),

/*56*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*57*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*58*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*59*/  lookup({make_pair(3, 2)}, {make_pair(3, 7)}, {make_pair(4, 7), make_pair(5, 6), make_pair(1, 2)}),

/*60*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*61*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*62*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*63*/  lookup({}, {make_pair(3, 7), make_pair(2, 6)}, {make_pair(4, 7), make_pair(5, 6)}),
/*64*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*65*/  lookup({make_pair(0, 1), make_pair(6, 7)}, {make_pair(0, 4), make_pair(2, 6)}, {make_pair(0, 3), make_pair(5, 6)}),
/*66*/  lookup({make_pair(0, 1), make_pair(6, 7)}, {make_pair(1, 5), make_pair(2, 6)}, {make_pair(2, 4), make_pair(5, 6)}),

/*67*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*68*/  lookup({make_pair(3, 2), make_pair(6, 7)}, {}, {make_pair(1, 2), make_pair(5, 6)}),

/*69*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*70*/  lookup({make_pair(0, 1), make_pair(3, 2), make_pair(7, 6)}, {make_pair(1, 5)}, {make_pair(5, 6)}),

/*71*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*72*/  lookup({make_pair(2, 3), make_pair(6, 7)}, {make_pair(3, 7), make_pair(2, 6)}, {make_pair(0, 3), make_pair(5, 6)}),

/*73*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*74*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*75*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*76*/  lookup({make_pair(7, 6)}, {make_pair(3, 7)}, {make_pair(5, 6), make_pair(1, 2), make_pair(0, 3)}),

/*77*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*78*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*79*/  lookup({make_pair(7, 6)}, {make_pair(0, 4), make_pair(1, 5), make_pair(3, 7)}, {make_pair(5, 6)}),
/*80*/  lookup({make_pair(4, 5), make_pair(6, 7)}, {make_pair(0, 4), make_pair(2, 6)}, {make_pair(4, 7), make_pair(5, 6)}),

/*81*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*82*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*83*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*84*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*85*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*86*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*87*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*88*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*89*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*90*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*91*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*92*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*93*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*94*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*95*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*96*/  lookup({make_pair(4, 5), make_pair(6, 7)}, {make_pair(1, 5), make_pair(2, 6)}, {}),

/*97*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*98*/  lookup({make_pair(0, 1), make_pair(4, 5), make_pair(7, 6)}, {make_pair(2, 6)}, {make_pair(1, 2)}),

/*99*/  lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*100*/ lookup({make_pair(3, 2), make_pair(4, 5), make_pair(7, 6)}, {make_pair(1, 5)}, {make_pair(1, 2)}),

/*101*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*102*/ lookup({make_pair(0, 1), make_pair(3, 2), make_pair(4, 5), make_pair(7, 6)}, {}, {}),
/*103*/ lookup({make_pair(3, 2), make_pair(7, 6), make_pair(4, 5)}, {make_pair(0, 4)}, {make_pair(0, 3)}),

/*104*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*105*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*106*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*107*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*108*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*109*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*110*/ lookup({make_pair(0, 1), make_pair(7, 6), make_pair(4, 5)}, {make_pair(3, 7)}, {make_pair(0, 3)}),
/*111*/ lookup({make_pair(4, 5), make_pair(6, 7)}, {make_pair(0, 4), make_pair(3, 7)}, {}),
/*112*/ lookup({make_pair(7, 6)}, {make_pair(0, 4), make_pair(1, 5), make_pair(2, 6)}, {make_pair(4, 7)}),

/*113*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*114*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*115*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*116*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*117*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*118*/ lookup({make_pair(0, 1), make_pair(3, 2), make_pair(7, 6)}, {make_pair(0, 4)}, {make_pair(4, 7)}),
/*119*/ lookup({make_pair(6, 7), make_pair(3, 2)}, {}, {make_pair(0, 3), make_pair(4, 7)}),

/*120*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped
/*121*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),
/*122*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*123*/ lookup({make_pair(3, 2), make_pair(7, 6)}, {make_pair(2, 6), make_pair(3, 7)}, {make_pair(1, 2), make_pair(4, 7)}),

/*124*/ lookup({make_pair(0, 1)}, {make_pair(0, 4)}, {make_pair(0, 3)}),        // skipped

/*125*/ lookup({make_pair(0, 1), make_pair(6, 7)}, {make_pair(1, 5), make_pair(3, 7)}, {make_pair(1, 2), make_pair(4, 7)}),
/*126*/ lookup({make_pair(0, 1), make_pair(6, 7)}, {make_pair(0, 4), make_pair(3, 7)}, {make_pair(0, 3), make_pair(4, 7)}),
/*127*/ lookup({make_pair(6, 7)}, {make_pair(3, 7)}, {make_pair(4, 7)}),
};

void rune(int lookup_index, vector<int> vertex) {

    // step 1: take input (adapt for multiple sample)
    // step 2: determine which lookup (done)
        // step 2.1: pass in 8 numbers
        // step 2.2: check if corner > 0
        // step 2.3: allocate values from 0-255
        // step 2.4: return lookup value
    // step 3: call lookup 
        // step 3.1: complete lookup table
            // step 3.1.1: complete lookup with 1 point (done)
            // step 3.1.2: complete lookup with 2 points (done)
            // step 3.1.3: complete lookup with 3 points in same face (done)
            // step 3.1.4: complete lookup with 3 points, 1 outside (in progress)
            // step 3.1.5: complete lookup with 3 points, all outside
            // step 3.1.6: complete lookup with 4 points, same plane
            // step 3.1.7: complete lookup with 4 points, 2 in same face, 2 in 2 different faces
            // step 3.1.8: whatever is left
        // step 3.2: draw the figures
            // step 3.2.1: iterate over each cube and draw a shape in each cube 
            // step 3.2.2: join points between edges
            // step 3.2.3: draw shape in 1 cube
            // step 3.2.4: repeat for all cubes in opengl
            // intermediate step: draw triangles with 3 points (3*xyz = 9 co-ords) in opengl        
    // step 4: do interpolation (really not hard tbh)
        // step 4.1: get co-ordinates
        // step 4.2: take 0.5 and interpolate to get x,y,z
        // step 4.3: extend it to co-ordinate space

    lookup cube = table[lookup_index];

    point x;
    point y;
    point z;
    
    cout << "cube.X.size(): " << cube.X.size() << endl;
    cout << "cube.Y.size(): " << cube.Y.size() << endl;
    cout << "cube.Z.size(): " << cube.Z.size() << endl;

    for (int a = 0; a < cube.X.size(); ++a) {
        if (cube.X.at(a).first == 0) {
            x = point(interpolate(vertex.at(cube.X.at(a).first), vertex.at(cube.X.at(a).second)), 0, 0);            
        }
        else if (cube.X.at(a).first == 3) {
            x = point(interpolate(vertex.at(cube.X.at(a).first), vertex.at(cube.X.at(a).second)), 0, 1);
        }
        else if (cube.X.at(a).first == 4) {
            x = point(interpolate(vertex.at(cube.X.at(a).first), vertex.at(cube.X.at(a).second)), 1, 0);            
        }
        else {
            x = point(interpolate(vertex.at(cube.X.at(a).first), vertex.at(cube.X.at(a).second)), 1, 1);            
        }
        for (int b = 0; b < cube.Y.size(); ++b) {
            if (cube.Y.at(b).first == 0) {
                y = point(0, interpolate(vertex.at(cube.Y.at(b).first), vertex.at(cube.Y.at(b).second)), 0);            
            }
            else if (cube.Y.at(b).first == 1) {
                y = point(1, interpolate(vertex.at(cube.Y.at(b).first), vertex.at(cube.Y.at(b).second)), 0);
            }
            else if (cube.Y.at(b).first == 2) {
                y = point(1, interpolate(vertex.at(cube.Y.at(b).first), vertex.at(cube.Y.at(b).second)), 1);            
            }
            else {
                y = point(0, interpolate(vertex.at(cube.Y.at(b).first), vertex.at(cube.Y.at(b).second)), 1);            
            }
            for (int c = 0; c < cube.Z.size(); ++c) {
                if (cube.Z.at(c).first == 0) {
                    z = point(0, 0, interpolate(vertex.at(cube.Z.at(c).first), vertex.at(cube.Z.at(c).second)));
                }
                else if (cube.Z.at(c).first == 1) {
                    z = point(1, 0, interpolate(vertex.at(cube.Z.at(c).first), vertex.at(cube.Z.at(c).second)));
                }
                else if (cube.Z.at(c).first == 5) {
                    z = point(1, 1, interpolate(vertex.at(cube.Z.at(c).first), vertex.at(cube.Z.at(c).second)));
                }
                else {
                    z = point(0, 1, interpolate(vertex.at(cube.Z.at(c).first), vertex.at(cube.Z.at(c).second)));
                }
                cube.triangle_pts.push_back(triangle(x, y, z));
            }
        }
    }
    cout << "triangle_pts.size(): " << cube.triangle_pts.size() << endl;

    cout << "done interpolate\n";

    // glColor3f(1,0,0);
    // glBegin(GL_TRIANGLES);

    for (int i = 0; i < cube.triangle_pts.size(); ++i) {
        cout << "point x: ";
        cout << cube.triangle_pts.at(i).x.getx() << ", "
             << cube.triangle_pts.at(i).x.gety() << ", "
             << cube.triangle_pts.at(i).x.getz() << endl;
        cout << "point y: ";
        cout << cube.triangle_pts.at(i).y.getx() << ", "
             << cube.triangle_pts.at(i).y.gety() << ", "
             << cube.triangle_pts.at(i).y.getz() << endl;
        cout << "point z: ";
        cout << cube.triangle_pts.at(i).z.getx() << ", "
             << cube.triangle_pts.at(i).z.gety() << ", " 
             << cube.triangle_pts.at(i).z.getz() << endl;
        cout << "triangle " << i + 1 << " complete" << endl;

        // glVertex3f(cube.triangle_pts.at(i).x.getx(),cube.triangle_pts.at(i).x.gety(),cube.triangle_pts.at(i).x.getz());
        // glVertex3f(cube.triangle_pts.at(i).y.getx(),cube.triangle_pts.at(i).y.gety(),cube.triangle_pts.at(i).y.getz());
        // glVertex3f(cube.triangle_pts.at(i).z.getx(),cube.triangle_pts.at(i).z.gety(),cube.triangle_pts.at(i).z.getz());
    }

    // glEnd();
}
int main() {
    cout << "hello world" << endl;

    vector <int> sample = {1,-2,3,4,5,6,7,8};

    int lookup_index = 0;

    for (int i = 0; i < sample.size(); ++i) {
        cout << sample[i] << "\t";
        if (sample[i] > 0) {
            lookup_index |= (int)pow(2, i);
        }
        cout << lookup_index << endl;
    }
    if (lookup_index > 127) {
        lookup_index = 255 - lookup_index;
    }
    cout << "lookup_index: " << lookup_index << endl;
    rune(lookup_index, sample);
    
    return 0;
}
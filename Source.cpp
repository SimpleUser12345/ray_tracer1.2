#include "scene.h"
#include "sphere.h"
#include "vect.h"
#include "color.h"

#include <iostream>
#include <fstream>

using namespace std;


int main() {

    int Height = 700;
    int Width = 700;

    Color_t pix_col(0, 0, 0);

    Scene scene = Scene();

    Sphere sphere1(Vec3(200, 250, 220), 40, Color_t(255, 10, 20));
    Sphere sphere2(Vec3(400, 450, 230), 80, Color_t(40, 255, 100));
   

    Lightsource light1 = Lightsource(Vec3(0, 0, 0), Color_t(255, 255, 255));

    scene.add(&sphere1);
    scene.add(&sphere2);
    
    scene.add(light1);

    ofstream my_Image("result.ppm");

    if (my_Image.is_open()) {
        my_Image << "P3\n" << Width << " " << Height << " 255\n";
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {

                pix_col = scene.trace(i, j);


                my_Image << (int)pix_col.r << ' ' << (int)pix_col.g << ' ' << (int)pix_col.b << "\n";
            }
        }
        my_Image.close();
    }
    else
        cout << "ne mogy otkrit file";

    return 0;
}
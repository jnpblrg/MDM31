#include <ooml/core.h>
#include <ooml/components.h>
#include <ooml/parts.h>

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double ancho_ppal , largo_ppal, altura_ppal , grosor_paredes ;

    ancho_ppal = 40;
    largo_ppal = 15;
    altura_ppal = 8;
    grosor_paredes = 5;
    // Cube of lengths: 10, 20, 30
    Component bloque_ppal = RoundedTablet(largo_ppal,ancho_ppal, altura_ppal+grosor_paredes*2,2)
            & RoundedTablet (4,ancho_ppal-22,altura_ppal+grosor_paredes*2,2).translate(-23-largo_ppal/2,0,0)
    ;
    Component carcasaMDM31 = bloque_ppal- Cube (200,200,20).translate(0,0,-10)
            - Cube(15,24,altura_ppal).translate(-1,0,0)//delantero
            - Cube(15,24,altura_ppal).translate(1,0,0)//delantero arriba adelantado
            - Cube(3,ancho_ppal-5,altura_ppal).translate(5,0,-0)//ranura conector
            - Cube(3,ancho_ppal-5,altura_ppal).translate(7,0,-2)//ranura conector arriba adelantado
            - Cube(22,14,altura_ppal+1).translate(-17,0,0)//trasero
            - Cube(22,12,altura_ppal+1).translate(-17,0,2)//trasero mas bajo (estrecho)
            - Cylinder(8,16).translate(1.5,0,-25).rotate(0,90,0)//agujero cable
            - Cylinder(1.7,20).translate(-12,9.5,0)//agujero tornillo
            - Cylinder(1.7,20).translate(-12,-9.5,0)//agujero tornillo
            - Cylinder(3.4,5).translate(-12,9.5,7.5)//encaje tornillo
            - Cylinder(3.4,5).translate(-12,-9.5,7.5)//encaje tornillo
            + Cylinder(3.4,0.3).translate(-12,9.5,4.9)//encaje tornillo base sustentacion
            + Cylinder(3.4,0.3).translate(-12,-9.5,4.9)//encaje tornillo base sustentacion
            //- Cylinder(1.1,40).translate(-0.2,14.5,-10).rotate(0,90,0)
            //- Cylinder(1.1,40).translate(-0.2,-14.5,-10).rotate(0,90,0)
            - Cylinder(2.2,30).translate(-0.2,14.5,-15).rotate(0,90,0)//cabeza tornillo horizontal
            - Cylinder(2.2,30).translate(-0.2,-14.5,-15).rotate(0,90,0)//cabeza tornillo horizontal
            - Cube(3,4.3,2).translate(-1.9/2,14.5,3).rotate(0,90,0).color(1,0,0)//tuerca
            - Cube(3,4.3,2).translate(-1.9/2,-14.5,3).rotate(0,90,0).color(1,0,0)//tuerca
            //- Cube (20,10,20).translate(-17,-17.4,0).color(1,0,0)
            //- Cube (20,10,20).translate(-17,17.4,0).color(1,0,0);
            ;
    carcasaMDM31.rotate(180,0,0);


        IndentWriter writer;
        writer << carcasaMDM31;

    ofstream file("carcasaMDM31.scad");
    if (file){
        //generate OpenScad code of the translated cube and save it into file;
        file << writer;
        file.close();
    }else{
        cerr << "Error, cannot open the file" << endl;
    }

    cout << "Done" << endl;

    return 0;
}

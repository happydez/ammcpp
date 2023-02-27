#include <iostream>
#include <cmath>
#include <string>

using namespace std;

enum FigureType {Circle, Rhomb, Square};

struct figure {
    double area,perimetr;
    int type;
    union {
        double radius;
        double a[2];
        double b[3];
    } geom_fig;

    void Result() {
        cout << string(32, '-') << endl;
        cout << "Area: " << area << endl;
        cout << "Perimetr: " << perimetr << endl;
    }
 };

int main() {
    figure fig;

    cout << "1 - Circle" << endl;
    cout << "2 - Rhomb" << endl;
    cout << "3 - Square" << endl;
    cout << string(32, '-') << endl;
    cout << "Input figure type >> ";
    cin >> fig.type;

    switch (fig.type - 1)
    {
    case Circle:
        cout << "Radius >> "; cin >> fig.geom_fig.radius;
        fig.area = M_PI * fig.geom_fig.radius * fig.geom_fig.radius;
        fig.perimetr = 2 * M_PI * fig.geom_fig.radius;
        break;
    case Rhomb:
        cout << "Side >> "; cin >> fig.geom_fig.a[0];
        cout << "Height >> "; cin >> fig.geom_fig.a[1];
        fig.area = fig.geom_fig.a[0] * fig.geom_fig.a[1];
        fig.perimetr = fig.geom_fig.a[0] * 4;
        break;
    case Square:
        cout << "Side >> "; cin >> fig.geom_fig.a[0];
        fig.area = fig.geom_fig.a[0] * fig.geom_fig.a[0];
        fig.perimetr = fig.geom_fig.a[0] * 4;
        break;
    default:
        cout << "Only Circle, Rhomb and Square are proceseed" << endl;
        return -1;
    }

    fig.Result();

    return 0;
}
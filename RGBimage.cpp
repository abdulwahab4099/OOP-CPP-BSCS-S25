#include <iostream>
using namespace std;

struct Pixel {
    int r, g, b;
};

const int HEIGHT = 3;
const int WIDTH = 3;

int main() {
    Pixel image[HEIGHT][WIDTH] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}}, // Red, Green, Blue
        {{128, 128, 128}, {255, 255, 255}, {0, 0, 0}}, // Gray, White, Black
        {{100, 50, 200}, {90, 180, 75}, {50, 100, 150}} // Random colors
    };

    // Displaying the image as RGB values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << "(" << image[i][j].r << ", " 
                      << image[i][j].g << ", " 
                      << image[i][j].b << ") ";
        }
        cout << endl;
    }

    return 0;
}


#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 800  // 画面の横幅
#define FOV 60.0          // 視野角（°）
#define DEG_TO_RAD (M_PI / 180.0)  // 度 → ラジアン変換

int main() {
    double	start_angle = -FOV / 2.0;
    double	step_angle = FOV / SCREEN_WIDTH;

    for (int i = 0; i < SCREEN_WIDTH; i++) {
        double theta = start_angle + i * step_angle;
        printf("Pixel %d: θ = %.3f°\n", i, theta);
    }
}

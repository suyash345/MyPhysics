#include <raylib.h>

class Shape {

};
class cir : public Shape {
    public:
        cir(Vector2 centre, float radius, Color color)
        : centre(centre),radius(radius), color(color)
        {}
        void Update(float delta) {
            speed += acceleration;
            centre.y += speed;
        }
        void Draw() {
            DrawCircleV(centre,radius,color);
        }
    public:
        Vector2 centre;
        float radius;
        Color color;

        //
        float speed = 0;
        float acceleration = 9.81;

};


class rec : public Shape{
    public:
        rec(Vector2 pos, Vector2 size, Color color)
        : pos(pos), size(size), color(color),
        r{pos.x, pos.y, size.x, size.y} {}
        
        void Update(float delta) {
            return;
        }
        void Draw() {
            DrawRectangleV(pos,size,color);
        }
    public:
        Vector2 pos;
        Vector2 size;
        Color color;
        Rectangle r; 
};


int main() {
    InitWindow(1920,1080,"Bouncing Ball");
    cir c({1100,0},100,RED);
    rec r({1000,1000},{500,500},BLUE);

    while(!WindowShouldClose()) {
        float delta = GetFrameTime();
        c.Update(delta);
        r.Update(delta);
        if(CheckCollisionCircleRec(c.centre,c.radius,r.r)) {
            c.speed = c.speed*-1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        c.Draw();
        r.Draw();
        EndDrawing();
    }
    CloseWindow();
}           
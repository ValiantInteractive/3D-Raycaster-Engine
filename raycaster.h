#ifndef RAYCASTERENGINE_RAYCASTER_H
#define RAYCASTERENGINE_RAYCASTER_H

float degToRad(float a) {
    return a * M_PI / 180.0;
}

float FixAng(float a) {
    if (a > 359) {
        a -= 360;
    }
    if (a < 0) {
        a += 360;
    }
    return a;
}

float dist(float ax, float ay, float bx, float by) {
    return (sqrt(bx - ax) * (bx - ay) + (by - ay) * (by - ay));
}

void drawRays2D() {
    // Draw ceiling
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(526, 0);
    glVertex2i(1006, 0);
    glVertex2i(1006, 720);
    glVertex2i(526, 720);
    glEnd();

    // Draw floor
    glColor3f(0.5f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(526, 720);
    glVertex2i(1006, 720);
    glVertex2i(1006, 240);
    glVertex2i(526, 240);
    glEnd();

    int r, mx, my, mp, dof;
    float vx, vy, rx, ry, ra, xo, yo, distV, distH;

    ra = FixAng(player.angle + 30);

    for (r = 0; r < 60; r++) {
        // Draw horizontal rays
        dof = 0;
        distV = 100000;
        float Tan = tanf(degToRad(ra));
        if (cosf(degToRad(ra)) > 0.001) {
            rx = (((int) player.posX >> 6) << 6) + 64;
            ry = (player.posX - rx) * Tan + player.posY;
            xo = 64;
            yo = -xo * Tan;
        } else if (cosf(degToRad(ra)) < -0.001) {
            rx = (((int) player.posX >> 6) << 6) - 0.0001;
            ry = (player.posX - rx) * Tan + player.posY;
            xo = -64;
            yo = -xo * Tan;
        } else {
            rx = player.posX;
            ry = player.posY;
            dof = 8;
        }

        while (dof < 8) {
            mx = (int) (rx) >> 6;
            my = (int) (ry) >> 6;
            mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) {
                dof = 8;
                distV = cosf(degToRad(ra)) * (rx - player.posX) - sinf(degToRad(ra)) * (ry - player.posY);
            } else {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        vx = rx;
        vy = ry;

        // Draw vertical rays
        dof = 0;
        distH = 100000;
        Tan = 1.0f / Tan;
        if (sinf(degToRad(ra)) > 0.001) {
            ry = (((int) player.posY >> 6) << 6) - 0.0001;
            rx = (player.posY - ry) * Tan + player.posX;
            yo = -64;
            xo = -yo * Tan;
        } else if (sinf(degToRad(ra)) < -0.001) {
            ry = (((int) player.posY >> 6) << 6) + 64;
            rx = (player.posY - ry) * Tan + player.posX;
            yo = 64;
            xo = -yo * Tan;
        } else {
            rx = player.posX;
            ry = player.posY;
            dof = 8;
        }

        while (dof < 8) {
            mx = (int) (rx) >> 6;
            my = (int) (ry) >> 6;
            mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1) {
                dof = 8;
                distH = cosf(degToRad(ra)) * (rx - player.posX) - sinf(degToRad(ra)) * (ry - player.posY);
            } else {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }

        glColor3f(0, 0, 0);
        if (distV < distH) {
            rx = vx;
            ry = vy;
            distH = distV;
            glColor3f(0.25f, 0, 0);
        }
        glLineWidth(10);
        glBegin(GL_LINES);
        glVertex2i(player.posX, player.posY);
        glVertex2i(rx, ry);
        glEnd();

        int ca = FixAng(player.angle - ra);
        distH = distH * cosf(degToRad(ca));
        int lineH = (mapS * 360) / (distH);

        if (lineH > 2400) {
            lineH = 2400;
        }

        int lineOff = 240 - (lineH >> 1);

        glLineWidth(10);
        glBegin(GL_LINES);
        glVertex2i(r * 8 + 530, lineOff);
        glVertex2i(r * 8 + 530, lineOff + lineH);
        glEnd();

        ra = FixAng(ra - 1);
    }
}

#endif //RAYCASTERENGINE_RAYCASTER_H
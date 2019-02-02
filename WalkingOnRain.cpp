/*
    MINI-PROJECT ABOUT THE MAN WALKING ON THE RAIN
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void manStands(int xc, int yc, int r){
    line(0,350,630,350); // Path where a man is walking
    circle(xc, yc, r); // Head
    ellipse(xc, 235, 180, 360, 8, 5);
    line(xc - 8, 235, xc + 8, 235);
    circle(xc - 6, 226, 3);
    circle(xc + 6, 226, 3);

    line(xc,245,xc,300); // Body
    line(xc,260,xc-30,290);// Right hand
    line(xc,260,xc+30,290); // Left hand
    line(xc,300,xc-30,350); // Right leg
    line(xc,300,xc+30,350); // Left leg
}

void manWalks(int xc, int yc, int r){
    line(0,350,630,350); // Path where a man is walking
    circle(xc, yc, r); // Head
    ellipse(xc, 235, 180, 360, 8, 5);
    line(xc - 8, 235, xc + 8, 235);
    circle(xc - 6, 226, 3);
    circle(xc + 6, 226, 3);
    line(xc, 245, xc, 300); // Body
    //line(xc, 260, xc + 30, 290);// Right hand
    //line(xc, 300, xc + 1, 350);// Right leg
    line(xc, 260, xc , 290);// Left hand
    line(xc, 300, xc , 350);//Left leg
}

void rain(int xc, int yc){
    int i, rx, ry;
    int xmax = getmaxx();
    int ymax = getmaxy();
    for(i=0;i < 200;i++)
    {
        rx = rand() % xmax;
        ry = rand() % ymax;
        if(rx>=(xc-30) && rx<=(xc+30)){
            if(ry>=(yc-30) && ry<=350)
                continue;
        }
        if(ry > 350) continue;
        line(rx-5,ry+5,rx,ry);
    }
}

int main()
{
    int gd=DETECT,gm;
    int xc=30, yc=230, r=15;
    int x = rand();
    initgraph(&gd,&gm,"");
    int i, rx, ry;
    int xmax = getmaxx();
    int ymax = getmaxy();
    int flag = 0;
    while(xc < xmax-30){

    /*    line(0,350,630,350); // Path where a man is walking
        circle(xc, yc, r); // Head
        line(xc,245,xc,300); // Body
        line(xc,260,xc-30,290);// Right hand
        line(xc,260,xc+30,290); // Left hand
        line(xc,300,xc-30,350); // Right leg
        line(xc,300,xc+30,350); // Left leg
    */
        if(flag % 2 == 0){
            cleardevice();
            manStands(xc, yc, r);
            rain(xc, yc);


        }

    /*for(i=0;i<500;i++)
    {
        rx = rand() % xmax;
        ry = rand() % ymax;
        if(rx>=(xc-30) && rx<=(xc+60)){
        if(ry>=(yc-30) && ry<=350)
            continue;
        }
        line(rx-5,ry+5,rx,ry);

    }*/
    if(flag % 2 == 1){
        cleardevice();
        manWalks(xc, yc, r);
        rain(xc, yc);

    }
        /*line(xc, 260, xc + 20, 290);// Right hand
    line(xc, 260, xc - 20, 290);// Left hand
    line(xc, 300, xc + 20, 350);// Right leg
    line(xc, 300, xc - 20, 350);//Left leg
    */
    xc +=10;
    flag++;
    delay(200);
        if(xc >= xmax-30){
            xc=30;
            flag = 0;
        }

    }
    getch();
    closegraph();
    return 0;
}



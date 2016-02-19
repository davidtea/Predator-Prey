#include "mypanelopengl.h"
#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
using namespace std;

Grid G(1000, 20000, 100, 10);
//Grid G(1,1,0,0);
int** grid = G.returngrid();

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
    x=-0.9;
    y=-0.9;
}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //    static float i(0.01),j(0.007);

//    int set[Size];
//    setInt(set);

//    Creature* ptr = G.returngrid();

    grid = G.returngrid();

    float length = 0.9/(XLEN/2);
    float ylength = 0.9/(YLEN/2);
    for(int i=0; i<XLEN; i++)
    {
        for (int j=0; j<YLEN; j++)
        {
            //rgb
            if(grid[i][j] == 0)//hunter
                glColor3f(1.9f, 0.0f, 0.0f);//red
            else if(grid[i][j] == 1)//prey
                glColor3f(0.0f, 0.0f, 1.9f);//blue
            else if(grid[i][j] == 2)//wall
                glColor3f(0.0f, 0.0f, 0.0f);//black
            else if(grid[i][j] == 3)//null
                glColor3f(1.9f, 1.9f, 1.9f);//white
            else if(grid[i][j] == 4)//teleport
                glColor3f(1.9f, 1.9f, 0.0f);//yellow
            else if(grid[i][j] == 5)//op pred
                glColor3f(0.0f, 1.9f, 0.0f);//green
            else if(grid[i][j] == 6)//plague
                glColor3f(0.0f, 0.0f, 0.0f);//black
            else
                glColor3f(0.0f, 0.0f, 0.0f);//white

//            if(G.grid[i][j]->Face() == 'h')
//                glColor3f(1.9f, 0.0f, 0.0f);
//            else if(G.grid[i][j]->IsPrey())
//                glColor3f(0.0f, 0.0f, 1.9f);
//            else if(G.grid[i][j]->Face() == 'w')
//                glColor3f(0.0f, 0.0f, 0.0f);
//            else
//                glColor3f(1.9f, 1.9f, 1.9f);

            glBegin(GL_QUADS);
            glVertex2f(x+i*length,y+j*ylength);
            glVertex2f(x+(i+1.0)*length,y+j*ylength);
            glVertex2f(x+(i+1.0)*length,y+(j+1.0)*ylength);
            glVertex2f(x+i*length,y+(j+1.0)*ylength);
            glEnd();
        }
    }
    G.NextTurn();
    for(int i=0; i<XLEN; i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
}

void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Down:
        run();
        break;
    case Qt::Key_Up:
        stop();
        break;
    }

}

void MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(100);
    }
}

void MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process()
{
    repaint();
    updateGL();
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height, 1.0f, 100.0f );

}

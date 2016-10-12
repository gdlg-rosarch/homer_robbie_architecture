/*******************************************************************************
 *  VectorObject2D.cpp
 *
 *  (C) 2007 AG Aktives Sehen <agas@uni-koblenz.de>
 *           Universitaet Koblenz-Landau
 *
 *  Additional information:
 *  $Id: $
 *******************************************************************************/

#include <homer_robbie_architecture/Workers/VectorGraphics/VectorObject2D.h>

#define THIS VectorObject2D

#include <GL/glu.h>

using namespace std;

//Change the class version when modifying member variables ( needed for serialization / deserialization )

const unsigned short THIS::ClassVersion=12;


THIS::THIS( const vector<Point2D> vertices, float r, float g, float b, float lineWidth, StyleT style )
{
  m_Vertices=vertices;
  m_R=r;
  m_G=g;
  m_B=b;
  m_LineWidth=lineWidth;
  m_Style=style;
}


THIS::~THIS()
{
}

void THIS::paintGl()
{
  glColor3f( m_R, m_G, m_B );
  int glStyle = GL_LINE_STRIP;
  switch ( m_Style )
  {
    case Lines:
      glLineWidth( m_LineWidth );
      glStyle = GL_LINE_STRIP;
      break;
    case Dots:
      glPointSize( m_LineWidth );
      glStyle = GL_POINTS;
      break;
  }
  glBegin( glStyle );
  for(unsigned i=0;i<m_Vertices.size();i++)
  {
    if ( m_Vertices[i].isValid() )
    {
      glVertex3f( m_Vertices[i].x(), m_Vertices[i].y(), 0 );
    }
    else
    {
      glEnd();
      glBegin( glStyle );
    }
  }
  glEnd();
}

#undef THIS

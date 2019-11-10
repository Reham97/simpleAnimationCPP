#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <time.h>
class Point{
  int x;
  int y;
public:
  Point();
  Point(int x,int y);
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();
};
Point::Point()
{
this->x=0;
this->y=0;
}
Point::Point(int x,int y)
{
this->x=x;
this->y=y;
}
void Point::setX(int x)
{
this->x=x;
}
void Point::setY(int y)
{
this->y=y;
}
int Point::getX()
{
return this->x;
}

int Point::getY()
{
return this->y;
}

//*********************************************************//

class Line{
  Point start;
  Point end;
public:

  Line():start(),end()
  {   }
  Line(int x1,int y1,int x2,int y2):start(x1,y1),end(x2,y2)
  {//cout<<" at line const"<<endl;
  }
  void draw()
  {
   line(start.getX(),start.getY(),end.getX(),end.getY());
  }

   void LAnimation1(int var)
  {
   start.setX(start.getX()+var);
   end.setX(end.getX()+var);
  }
   void LAnimation2(int var)
  {
   start.setX(start.getX()+var);
   end.setX(end.getX()+var);
   start.setY(start.getY()+var);
   end.setY(end.getY()+var);
  }


};
//*********************************************************//

class Rect{
  Point ul;
  Point lr;
public:
  Rect():ul(),lr()
  {}
  Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2)
  {//cout<<" at Rec const"<<endl;
  }
  void draw()
  {
   rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
  }
   void RAnimation1(int var)
  {
   ul.setX(ul.getX()+var);
   lr.setX(lr.getX()+var);
  }
  void RAnimation2(int var)
  {
   ul.setX(ul.getX()+var);
   lr.setX(lr.getX()+var);
   ul.setY(ul.getY()+var);
   lr.setY(lr.getY()+var);

  }


};
//*********************************************************//


class Circle{
  Point center;
  int rad;
public:
  Circle():center()
  {rad=0;//cout<<" at Rec const"<<endl;
  }
  Circle(int m,int n,int r):center(m,n)
  {rad=r;//cout<<" at Rec const"<<endl;
  }
  void draw()
  {
   circle(center.getX(),center.getY(),rad);
  }
  void CAnimation1(int var)
  {
   center.setX(center.getX()+var);
  }
   void CAnimation2(int var)
  {
   center.setX(center.getX()+var);
   center.setY(center.getY()+var);
  }
};
//*********************************************************//
class Picture{
  int cNum;
  int rNum;
  int lNum;
  Circle *pCircles;
  Rect *pRects;
  Line * pLines;
  int cColor;
  int rColor;
  int lColor;
public:

  Picture()
  { cNum=0;
	rNum=0;
	lNum=0;
	pCircles=NULL;
	pRects=NULL;
	pLines=NULL;
	cColor=RED;
	rColor=RED;
	lColor=RED;
  //cout<<" at Pic const"<<endl;
  }
  Picture(int cn,int rn,int ln,Circle *pC,Rect *pR,Line *pL,int cCol,int rCol,int lCol )
  { cNum=cn;
	rNum=rn;
	lNum=ln;
	pCircles=pC;
	pRects=pR;
	pLines=pL;
	cColor=cCol;
	rColor=rCol;
	lColor=lCol;
  //cout<<" at Pic const"<<endl;
  }
  void setCircles(int,Circle*,int);
  void setRects(int,Rect*,int);
  void setLines(int,Line*,int);
  void paint(int var);
  void accedent(int var1,int var2,int var3);

};

void Picture::setCircles(int cn,Circle*cptr,int cCol)
{
 cNum=cn;
 pCircles=cptr;
 cColor=cCol;
}

void Picture::setRects(int rn,Rect * rptr,int rCol)
{
 rNum=rn;
 pRects=rptr;
 rColor=rCol;
}

void Picture::setLines(int ln,Line*lptr,int lCol)
{
 lNum=ln;
 pLines=lptr;
 lColor=lCol;
}

void Picture::paint(int var)
{

  int i;
  setcolor(cColor);
  for(i=0;i<cNum;i++)
  {
  pCircles[i].draw();
  pCircles[i].CAnimation1(var);
  }

  setcolor(rColor);
  for(i=0;i<rNum;i++)
  {
  pRects[i].draw();
  pRects[i].RAnimation1(var);
  }

  setcolor(lColor);
  for(i=0;i<lNum;i++)
  {
  pLines[i].draw();
  pLines[i].LAnimation1(var);
  }
}

void Picture::accedent(int var1,int var2,int var3)
{
  int i;
  setcolor(cColor);
  for(i=0;i<cNum;i++)
  {
  pCircles[i].draw();
  pCircles[i].CAnimation2(var1);
  }

  setcolor(rColor);
  for(i=0;i<rNum;i++)
  {
  pRects[i].draw();
  pRects[i].RAnimation2(var2);
  }

  setcolor(lColor);
  for(i=0;i<lNum;i++)
  {
  pLines[i].draw();
  pLines[i].LAnimation2(var3);
  }
}

//*********************************************************//

void delay(int numSec,int conv)
{
int milliSec=conv*numSec;
clock_t startTime=clock();
while(clock()<startTime+milliSec)
{}

}






int main() {
 int gdrive =DETECT,gmode,errorcode;
 initgraph(&gdrive,&gmode,"C:\\BORLANDC\\BGI");
 errorcode = graphresult();

 if(errorcode!=grOk)
  { cout<<"there is error in graph"<<endl; }
 else
  {//cout<<"Done"<<endl;

   /*	Rect rec(60,60,150,140);
	rec.draw();
	getch();
	*/
	Picture body;
	Picture car;

	Circle cArr[3]={Circle(100,300,10),Circle(170,300,10),Circle(175,155,5)};
	Rect rArr[1]={Rect(100,140,170,180)};
	Line lArr[3]={Line(135,180,135,240),Line(135,240,100,290),Line(135,240,170,290)};

	Circle cArr2[2]={Circle(450,280,20),Circle(550,280,20)};
	Rect rArr2[4]={Rect(420,145,580,200),Rect(400,200,600,280),Rect(440,160,500,180),Rect(370,210,400,250)};
   //	Line lArr2[3]={Line(100,100,100,200),Line(100,200,30,300),Line(100,200,160,300)};


	body.setCircles(3,cArr,RED);
	body.setRects(1,rArr,YELLOW);
	body.setLines(3,lArr,WHITE);

	car.setCircles(2,cArr2,GREEN);
	car.setRects(4,rArr2,BLUE);
   //	myPic2.setLines(3,lArr);

	int i=0;

	while(i<13)
	{cleardevice();
	car.paint(-10);
	body.paint(10);
	  delay(1,10);
	  i++;
	}


	i=0;
	while(i<35)
	{
	cleardevice();
	car.paint(-10);
	body.accedent(10,-10,20);
	  delay(1,1);
	  i++;
	}
	cleardevice();
	gotoxy(50,50);
	//font,orientation,size
	settextstyle(3,0,12);
	outtextxy(100,100,"END");

	}


 getch();
 return 0;
}

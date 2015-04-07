///////////////////////////////////////////////////////////
//  Curve2D.h
//  Реализация	Class Curve2D
//  Создано:    22-ноя-2012 15:53:32
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_14543849_71D5_429b_B271_210A5CD19802__INCLUDED_)
#define GPD_14543849_71D5_429b_B271_210A5CD19802__INCLUDED_

#include "..\BasicMath\GPDVector2d.h"
#include "..\BasicMath\GPDPoint2dn.h"
#include "..\BasicMath\basicFuncs.h"
#include <math.h>

#define Round ceil

namespace Gepard
{
    namespace Curves
    {
        using namespace Gepard::BasicMath;

        /**
         * Класс вычисления кривой - Метод натуральной параметризации
         */
        class Curve_2D
        {

        public:
            /**
             * Начальная точка
             */
            Gepard::BasicMath::GPDPoint2dn P0;
            /**
             * Конечная точка
             */
            Gepard::BasicMath::GPDPoint2dn P1;

            /**
             * Массив точек кривой
             */
            Gepard::BasicMath::GPDPoint2dnArray Points;


            /**
             * Вектор касательной в точке A
             */
            Gepard::BasicMath::GPDVector2d a1;
            /**
             * Вектор касательной в точке B
             */
            Gepard::BasicMath::GPDVector2d a2;
            /**
             * Количество точек, которые надо просчитать
             */
            int PointsCount;
            
                        
            Curve_2D(	Gepard::BasicMath::GPDPoint2dn _p1, 
                        Gepard::BasicMath::GPDPoint2dn _p2, 
                        Gepard::BasicMath::GPDVector2d _v1, 
                        Gepard::BasicMath::GPDVector2d _v2, 
                        int numPoints=0 );
            ~Curve_2D();
            /**
             * посчитать кривую. Параметры были заданы в конструкторе
             */
            void calcCurve2D();
            void calcCurve2D_new();

        private:

            unsigned int defaultPointsCount;

            bool isChange;

//             int Round(double x){
// 
//                 int a;
//                 _asm {
//                     fld x
//                     fistp dword ptr a
//                 }
//                     return a;
//             }
            /**
             * получить тип кривой - возвращает например так 113 - значит случай 1.1.3
             */
            int getCurveType(double alpha, double betta);
            /**
             * Посчитать кривую. Cлучай 1.1.3. Параметры берем из атрибутов класса
             */
            void calcCurve2D_113(double alpha, double betta, double gamma);
            
            void calcCurve2D_113_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.2.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_121(double alpha, double betta, double gamma);
            void calcCurve2D_121_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.3.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_131(double alpha, double betta, double gamma);
            void calcCurve2D_131_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.4.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_141(double alpha, double betta, double gamma);
            void calcCurve2D_141_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.5.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_151(double alpha, double betta, double gamma);
            void calcCurve2D_151_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.6.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_161(double alpha, double betta, double gamma);
            void calcCurve2D_161_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.7.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_171(double alpha, double betta, double gamma);
            void calcCurve2D_171_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * Посчитать кривую. Случай 1.8.1 Параметры берем и атрибутов класса
             */
            void calcCurve2D_181(double alpha, double betta, double gamma);
            void calcCurve2D_181_new(double alpha, double beta, double rotate_angle, double b);
            /**
             * INLINE функция получения DS. Случай 1.1.3
             */
            inline double getDeltaS_113(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2;
                double cs, c, fi, ds,b;
                GPDVector2d a3;
    
                if (alpha<0 && betta>0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
    
                m=Round(sin(alpha)+sin(betta)*(this->PointsCount+1))/(sin(betta)-sin(alpha));
                if (m==0) d1=0; else d1=-sin(alpha)/m;
                if (this->PointsCount-m==0) d2=0; else d2=sin(betta)/(this->PointsCount-m);
                cs=0;
                for (int i=0; i<this->PointsCount-2; i++)
                {
                    if ((i>=0)&&(i<=m)) 					c=sin(alpha)+i*d1;
                    if(i==m+1)								c=d2;
                    if((i>=m+2)&&(i<=this->PointsCount-2))	c=d2+(i-m-1)*d2;
                    if(i==this->PointsCount)				c=sin(betta);
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if(i==0)									fi=alpha;
                    if((i>0)&&(i<this->PointsCount))			fi=asin(c);
                    if(i==this->PointsCount)					fi=betta;
                    cs+=cos(fi);
                } 
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.2.1
             */
            inline double getDeltaS_121(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2,d3;
                double cs, c, fi, ds,b;
                double k,l;
                GPDVector2d a3;
    
                if (alpha<0 && betta>0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
    
                k=Round(
                    ( (sin(alpha)-1)*(sin(alpha)+sin(betta)+this->PointsCount*sin(betta)) )/
                    ( 2-sqr(sin(alpha))-2*sin(betta)+sin(alpha)*sin(betta) )
                    );
                l=Round(
                    -( sin(alpha)+sin(betta)+this->PointsCount*sin(betta) )/
                    ( 2-sqr(sin(alpha))-2*sin(betta)+sin(alpha)*sin(betta) )
                    );
                m=this->PointsCount-k-l;
    
                if (k==0) d1=0; else d1=(1-sin(alpha))/k;
                if (l==0) d2=0; else d2=-1/l;
                if (m==0) d3=0; else d3=sin(betta)/m;
    
    
                cs=0;
                for (int i=0;i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))						c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=k+l))					c=1+(i-k)*d2;
                    if ((i>=k+l+1)&&(i<=this->PointsCount))	c=(i-k-l)*d3;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if ((i>=0)&&(i<k))						fi=Pi-asin(c);
                    if ((i>=k)&&(i<=this->PointsCount))		fi=asin(c);
    
                    cs+=cos(fi);
    
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.3.1
             */
            inline double getDeltaS_131(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2,d3;
                double cs, c, fi, ds,b;
                double k,l;
                GPDVector2d a3;
    
                if (alpha<0 && betta>0)  {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
    
                k=Round(
                    -( -2*this->PointsCount+2*sin(alpha)+2*sin(betta)+sin(alpha)*sin(betta)+sqr(sin(betta))+this->PointsCount*sqr(sin(betta)) )/
                    ( 2+2*sin(alpha)+sin(alpha)*sin(betta)-sqr(sin(betta)) )
                    );
                l=Round(
                    -( sin(alpha)+sin(betta)+this->PointsCount*sin(alpha) )/
                    ( -2-2*sin(alpha)-sin(alpha)*sin(betta)+sqr(sin(betta)) )
                    );
    
                m=this->PointsCount-k-l;
    
                if (k==0) d1=0; else d1=-sin(alpha)/k;
                if (l==0) d2=0; else d2=-1/l;
                if (m==0) d3=0; else d3=(sin(betta)+1)/m;
    
                cs=0;
                for(int i=0; i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))						c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=k+l))					c=(i-k)*d2;
                    if ((i>=k+l+1)&&(i<=this->PointsCount))	c=-1+(i-k-l)*d3;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if (i==0)								fi=alpha;
                    if ((i>0)&&(i<=k+l))					fi=asin(c);
                    if ((i>=k+l+1)&&(i<=this->PointsCount))	fi=-Pi-asin(c);
    
                    cs+=cos(fi);
    
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.4.1
             */
            inline double getDeltaS_141(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2,d3,d4;
                double cs, c, fi, ds,b,ckl;
                double k,l,m1;
                GPDVector2d a3;

                isChange=false;
                if (alpha<0 && betta>0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
                k=Round(
                    ( 2*(1-sin(alpha))*(-2*this->PointsCount+2*sin(betta)+(1+this->PointsCount)*sqr(sin(betta))+sin(alpha)*(2+sin(betta)) ) )/
                    ( sin(alpha)*(3+cos(2*betta))+2*sqr(sin(alpha))*(2+sin(betta))-2*(7+cos(2*betta)+2*sin(betta)) )
                    );
                l=Round(
                    ( 2*(-2*this->PointsCount+2*sin(betta)+(1+this->PointsCount)*sqr(sin(betta))+sin(alpha)*(2+sin(betta)) ) )/
                    ( sin(alpha)*(3+cos(2*betta))+2*sqr(sin(alpha))*(2+sin(betta))-2*(7+cos(2*betta)+2*sin(betta)) )
                    );
                m=Round(
                    ( 2*((1+this->PointsCount)*sqr(sin(alpha))+sin(alpha)*(-2+sin(betta))-2*(this->PointsCount+sin(betta)) ) )/
                    ( sin(alpha)*(3+cos(2*betta))+2*sqr(sin(alpha))*(2+sin(betta))-2*(7+cos(2*betta)+2*sin(betta)) )
                    );
                int MM=(int)(this->PointsCount-k-l-m);
    
                if (k==0) d1=0; else d1=(1-sin(alpha))/k;
                if (l==0) d2=0; else d2=-1/l;
                if (m==0) d3=0; else d3=-1/m;
                if (MM!=0) d4=-(1+sin(betta))/MM; else d4=0;
    
                cs=0;ckl=0;
                for (int i=0; i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))							{
                        c=sin(alpha)+i*d1;ckl=c;}
                    if ((i>=k+1)&&(i<=k+l))						{
                        c=ckl+(i-k)*d2;
                        m1=c;}
                    if ((i>=k+l+1)&&(i<=k+l+m))					{c=m1+(i-k-l)*d3;ckl=c;}
                    if ((i>=k+l+m+1)&&(i<=this->PointsCount))	c=ckl-(i-k-l-m)*d4;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if ((i>=0)&&(i<=k))							fi=Pi-asin(c);
                    if ((i>=k+1)&&(i<=k+l+m))					fi=asin(c);
                    if ((i>=k+l+m+1)&&(i<=this->PointsCount))	fi=-Pi-asin(c);
                    cs+=cos(fi);
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.5.1
             */
            inline double getDeltaS_151(double alpha, double betta){

                this->isChange=false;
    
                bool isBetta=false;
                double m, d1, d2,d3,d4;
                double cs, c, fi, ds,b,ckl;
                double k,l;
                GPDVector2d a3;

                isChange=false;
                if ((alpha==betta)&&(alpha!=0)&&(betta!=0)) {
                    k=Round((this->PointsCount-2)/4); 
                    l=k; 
                    m=l;
                }
                if ((alpha==0)&&(betta!=0)) {
                    k=0;
                    l=Round(this->PointsCount-sqrt((double) 2*this->PointsCount*(this->PointsCount+1))/2);
                    m=this->PointsCount-2-2*l;
                }
                if ((alpha!=0)&&(betta==0)) {
    
                    isBetta=true;
    
                    m=0;
                    l=Round(this->PointsCount-sqrt((double) 2*this->PointsCount*(this->PointsCount+1))/2);
                    k=this->PointsCount-2-2*l;
                }
                if ((alpha!=betta)&&(alpha*betta!=0)) {
    
                    if	(alpha<0 && betta<0) {isChange=true; alpha*=-1; betta*=-1;}
    
                    cs=0;
                    ckl=0;
                    k	=Round(
                        (-(this->PointsCount+1)*sqr(sin(alpha)) + 
                        sin(alpha)*(-(this->PointsCount+1)*sin(betta)+
                        sqrt((double) 2*(this->PointsCount+1)*(this->PointsCount*sqr(sin(alpha))+
                        2*sin(alpha)*sin(betta)+this->PointsCount*sqr(sin(betta))))))/
                        sqr(sin(alpha)-sin(betta))
                        );
                    l	=Round(
                        (2*this->PointsCount*sqr(sin(alpha))+4*sin(alpha)*sin(betta)+2*this->PointsCount*sqr(sin(betta))-
                        (sin(alpha)+sin(betta))*sqrt(2.0)*sqrt((double)this->PointsCount+1)*sqrt((double)this->PointsCount*sqr(sin(alpha))+ 
                        2*sin(alpha)*sin(betta)+this->PointsCount*sqr(sin(betta))))/
                        (2*sqr(sin(alpha)-sin(betta)))
                        );
                    m	= this->PointsCount-2-2*l-k;
                }
                //-------------------------------------------------------------------------------------------------
                if ((alpha==betta)&&(alpha==0)&&(betta==0)) {
    
                    ds=sqrt(sqr(P1.u - P0.u)+sqr(P1.v - P0.v))/this->PointsCount;
                    return ds;
                }
                if (k==0) d1=0; else d1=-sin(alpha)/k;
                if (m==0) d4=0; else d4=sin(betta)/m;
                d2=-d4;
                d3=d4;
    
                if (isBetta) {d2=d1; d3=-d1;}
    
                cs=0;ckl=0;
                for (int i=0; i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))				c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=k+l))			{c=(i-k)*d2;ckl=c;}
                    if ((i>=k+l+1)&&(i<=k+2*l+1))		c=ckl+(i-k-l-1)*d3;
                    if ((i>=k+2*l+2)&&(i<=this->PointsCount))		c=(i-k-2*l-1)*d4;
    
                    if (c<-1) c=-1;
                    if (c>1) c=1;
                    fi = asin(c);
                    cs+=cos(fi);
    
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
    
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.6.1
             */
            inline double getDeltaS_161(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2,d3,d4;
                double cs, c, fi, ds,b,ckl;
                double k,l;
                GPDVector2d a3;
    
                if (alpha<0 && betta<0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
                l=Round(
                    ( 3*sin(alpha)-(3+this->PointsCount)*sin(betta) )/
                    ( 3*sqr(sin(alpha))+sin(alpha)*sin(betta)-2*(3+sin(betta)) )
                    );
                m=Round(
                    ( (this->PointsCount+1)*sqr(sin(alpha))-sin(alpha)*(2+sin(betta))+2*(-this->PointsCount+sin(betta)) )/
                    ( 3*sqr(sin(alpha))+sin(alpha)*sin(betta)-2*(3+sin(betta)) )
                    );
                k=this->PointsCount-l-3*m;
    
                if (k==0) d1=0; else d1=(1-sin(alpha))/k;
                if (l==0) d2=0; else d2=-1/l;
                if (m==0) d4=0; else d4=sin(betta)/m;
                d3=-d4;
    
                cs=0;ckl=0;
                for (int i=0; i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))							c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=k+l))						c=1+(i-k)*d2;
                    if ((i>=k+l+1)&&(i<=k+l+m))					{c=(i-k-l)*d3;ckl=c;}
                    if ((i>=k+l+m+1)&&(i<=k+l+2*m+1))			c=ckl+(i-k-l-m-1)*d4;
                    if ((i>=k+l+2*m+2)&&(i<=this->PointsCount)) c=(i-k-l-2*m-1)*d4;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if ((i>=0)&&(i<=k))				fi=Pi-asin(c);
                    if ((i>=k+1)&&(i<=this->PointsCount))			fi=asin(c);
    
                    cs+=cos(fi);
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
    
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.7.1
             */
            inline double getDeltaS_171(double alpha, double betta){

                this->isChange=false;
    
                double m, d1, d2,d3,d4;
                double cs, c, fi, ds,b;
                double k,l;
                GPDVector2d a3;
    
                if (alpha<0 && betta<0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
    
                l=Round(
                    ( (3+this->PointsCount)*sin(alpha)-3*sin(betta) )/
                    (  sin(alpha)*(2-sin(betta))+3*(2-sqr(sin(betta))) )
                    );
                k=Round(
                    ( 2*this->PointsCount-sin(alpha)*(2-sin(betta))+2*sin(betta)-(1+this->PointsCount)*sqr(sin(betta)) )/
                    ( sin(alpha)*(2-sin(betta))+3*(2-sqr(sin(betta))) )
                    );
    
                m=this->PointsCount-l-3*k;
    
                if (k==0) d1=0; else d1=-sin(alpha)/k;
                //!!!!!							//d2=d1;
                d2=-d1;							//d3
                if (l==0) d3=0; else d3=1/l;	///d4
                if (m==0) d4=0; else d4=(sin(betta)-1)/m;///d5
    
                cs=0;
                for (int i=0; i<this->PointsCount-2; i++) {
    
                    if ((i>=0)&&(i<=k))						  c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=2*k))					  c=(i-k)*d1;
                    if ((i>=2*k+1)&&(i<=3*k+1))				  c=-sin(alpha)+(i-2*k-1)*d2;
                    if ((i>=3*k+2)&&(i<=3*k+l+1))			  c=(i-3*k-1)*d3;
                    if ((i>=3*k+l+2)&&(i<=this->PointsCount)) c=1+(i-3*k-l-1)*d4;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if ((i>=0)&&(i<=3*k+l+1))		fi=asin(c);
                    if ((i>=3*k+l+2)&&(i<=this->PointsCount))	fi=Pi-asin(c);
    
                    cs+=cos(fi);
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }
            /**
             * INLINE функция получения DS. Случай 1.8.1
             */
            inline double getDeltaS_181(double alpha, double betta){

                this->isChange=false;
    
                double d1, d2,d3,d4;
                double cs, c, fi, ds,b,ckl;
                double k,l,l1,m1,m2;
                GPDVector2d a3;
    
                if (alpha<0 && betta<0) {
                    isChange=true;
                    alpha*=-1;
                    betta*=-1;
                }
    
                l=Round(
                    ( ((this->PointsCount+2)*sin((alpha+betta)/2)-2*sin(alpha))*(2-sqr(sin(betta)))-
                    sin((alpha+betta)/2)*(2*sin(alpha)-2*sin(betta)-sin(alpha)*sin(betta)+sqr(sin(betta))) )/
                    ( ((2-sin(alpha))*sin((alpha+betta)/2)+2*(2-sqr(sin(alpha))))*(2-sqr(sin(betta)))+
                    sin((alpha+betta)/2)*(4-2*sqr(sin(alpha))-2*sin(betta)+sqr(sin(alpha))*sin(betta) ) )
                    );
                k=Round(
                    (1-sin(alpha))*l
                    );
                m1=Round(
                    ( l*(2-sqr(sin(alpha)))+sin(alpha)-sin(betta) )/
                    ( 2-sqr(sin(betta)) )
                    );
                l1=Round(
                    ( l*(2-sqr(sin(alpha)))+sin(alpha)-sin((alpha+betta)/2) )/
                    ( sin((alpha+betta)/2) )
                    );
                m2=this->PointsCount-k-l-2*l1-m1;
    
                if (k!=0) d1=(1-sin(alpha))/k; else d1=0;
                //d2=-1/l;
                if (l1!=0) d2=-(sin((alpha+betta)/2))/l1; else d2=0; ///d3!!!!
                ////d4=-d3!!!!
                if (m1!=0) d3=1/m1;	else d3=0;		//d5!!!!
                if (m2!=0) d4=(sin(betta)-1)/m2; else d4=0;	//d6!!!
    
                cs=0;ckl=0;
                for (int i=0; i<this->PointsCount-2; i++){
    
                    if ((i>=0)&&(i<=k))								c=sin(alpha)+i*d1;
                    if ((i>=k+1)&&(i<=k+l))							c=1+(i-k)*(-1/l);
                    if ((i>=k+l+1)&&(i<=k+l+l1))					{c=(i-k-l)*d2;ckl=c;}
                    if ((i>=k+l+l1+1)&&(i<=k+l+2*l1+1))				c=-sin((alpha+betta)/2)+(i-k-l-l1-1)*(-d2);
                    if ((i>=k+l+2*l1+2)&&(i<=k+l+2*l1+m1+1))		c=(i-k-l-2*l1-1)*d3;
                    if ((i>=k+l+2*l1+m1+2)&&(i<=this->PointsCount))	c=1+(i-k-l-2*l1-m1-1)*d4;
    
                    if (c>1) c=1;
                    if (c<-1) c=-1;
    
                    if ((i>=0)&&(i<=k))						fi=Pi-asin(c);
                    if ((i>=k+1)&&(i<=k+l+2*l1+m1+1))			fi=asin(c);
                    if ((i>=k+l+2*l1+m1+2)&&(i<=this->PointsCount))			fi=Pi-asin(c);
    
                    cs+=cos(fi);
                }
                a3.setCoords(this->P1.u-this->P0.u,this->P1.v-this->P0.v);
                b=a3.getLength();
                ds=b/cs;
                return ds;
            }

        };

    }

}
#endif // !defined(GPD_14543849_71D5_429b_B271_210A5CD19802__INCLUDED_)

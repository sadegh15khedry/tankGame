#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define N 20
int count1=0;
int volume=5 , speed=5 , j ,i , k , flag , count2=0;
char up , down , right , left ;
int map[N][N];
int level=1;
int p=0;
int score=0;
int jahat=0 ,jahat1=1,jahat2=1,in1,in2;
int tir_q=0,tir_q1=0 , tir_q2;
int tir_jahat,tir_jahat1 , tir_jahat2 ;
int s_jahat1;
int gun[2],gun1[2] ,gun2[2];
int q;
int life=3;
int mokhtasat [6][2]={{14,3},{15,2},{15,3},{15,4},{16,2},{16,4}};
int mokhtasat1[6][2]={{5,3},{4,4},{4,3},{4,2},{3,4},{3,2}};
int mokhtasat2[6][2]={{5,16},{4,17},{4,16},{4,15},{3,17},{3,15}};
void shoot2 (int o)
{
    if (o==0)
    {
        gun2[0]=mokhtasat2[0][0]-1;
        gun2[1]=mokhtasat2[0][1];
        tir_jahat2=0;
    }
    else if (o==1)
    {
        gun2[0]=mokhtasat2[0][0]+1;
        gun2[1]=mokhtasat2[0][1];
        tir_jahat2=1;
    }
    else if (o==2)
    {
        gun2[0]=mokhtasat2[0][0];
        gun2[1]=mokhtasat2[0][1]-1;
        tir_jahat2=2;
    }
    else if (o==3)
    {
        gun2[0]=mokhtasat2[0][0];
        gun2[1]=mokhtasat2[0][1]+1;
        tir_jahat2=3;
    }
}
void shoot1 (int o)
{
    if (o==0)
    {
        gun1[0]=mokhtasat1[0][0]-1;
        gun1[1]=mokhtasat1[0][1];
        tir_jahat1=0;
    }
    else if (o==1)
    {
        gun1[0]=mokhtasat1[0][0]+1;
        gun1[1]=mokhtasat1[0][1];
        tir_jahat1=1;
    }
    else if (o==2)
    {
        gun1[0]=mokhtasat1[0][0];
        gun1[1]=mokhtasat1[0][1]-1;
        tir_jahat1=2;
    }
    else if (o==3)
    {
        gun1[0]=mokhtasat1[0][0];
        gun1[1]=mokhtasat1[0][1]+1;
        tir_jahat1=3;
    }
}
void moving_tir2(int m)
{
    map [gun2[0]][gun2[1]]=0;
    if (m==0)
        gun2[0]--;
    else if (m==1)
        gun2[0]++;
    else if (m==2)
        gun2[1]--;
    else if (m==3)
            gun2[1]++;

    map [gun2[0]][gun2[1]]=7;
}
void moving_tir1(int m)
{
    map [gun1[0]][gun1[1]]=0;
    if (m==0)
        gun1[0]--;
    else if (m==1)
        gun1[0]++;
    else if (m==2)
        gun1[1]--;
    else if (m==3)
        gun1[1]++;


    map [gun1[0]][gun1[1]]=8;
}
void moving_tir(int m)
{
    map [gun[0]][gun[1]]=0;
    if (m==0)
        gun[0]--;
    else if (m==1)
        gun[0]++;
    else if (m==2)
        gun[1]--;
    else if (m==3)
        gun[1]++;

    map [gun[0]][gun[1]]=7;
}

void num1 (int l)
{
    map [mokhtasat1[0][0]] [mokhtasat1[0][1]]=l;
    map [mokhtasat1[1][0]] [mokhtasat1[1][1]]=l;
    map [mokhtasat1[2][0]] [mokhtasat1[2][1]]=l;
    map [mokhtasat1[3][0]] [mokhtasat1[3][1]]=l;
    map [mokhtasat1[4][0]] [mokhtasat1[4][1]]=l;
    map [mokhtasat1[5][0]] [mokhtasat1[5][1]]=l;

}
void num (int l)
{
    map [mokhtasat[0][0]] [mokhtasat[0][1]]=l;
    map [mokhtasat[1][0]] [mokhtasat[1][1]]=l;
    map [mokhtasat[2][0]] [mokhtasat[2][1]]=l;
    map [mokhtasat[3][0]] [mokhtasat[3][1]]=l;
    map [mokhtasat[4][0]] [mokhtasat[4][1]]=l;
    map [mokhtasat[5][0]] [mokhtasat[5][1]]=l;
}
void num2 (int l)
{
    map [mokhtasat2[0][0]] [mokhtasat2[0][1]]=l;
    map [mokhtasat2[1][0]] [mokhtasat2[1][1]]=l;
    map [mokhtasat2[2][0]] [mokhtasat2[2][1]]=l;
    map [mokhtasat2[3][0]] [mokhtasat2[3][1]]=l;
    map [mokhtasat2[4][0]] [mokhtasat2[4][1]]=l;
    map [mokhtasat2[5][0]] [mokhtasat2[5][1]]=l;

}




void shoot (int o)
{
    if (o==0)
    {
        gun[0]=mokhtasat[0][0]-1;
        gun[1]=mokhtasat[0][1];
        tir_jahat=0;
    }
    else if (o==1)
    {
        gun[0]=mokhtasat[0][0]+1;
        gun[1]=mokhtasat[0][1];
        tir_jahat=1;
    }
    else if (o==2)
    {
        gun[0]=mokhtasat[0][0];
        gun[1]=mokhtasat[0][1]-1;
        tir_jahat=2;
    }
    else if (o==3)
    {
        gun[0]=mokhtasat[0][0];
        gun[1]=mokhtasat[0][1]+1;
        tir_jahat=3;
    }
}
void my_movement()
{
    //up buttom--------------------------------------------------------------------------
    if ((q==87||q==119)&&jahat==1)
    {
            num(0);
            mokhtasat[0][0]-=2;
            mokhtasat[4][0]+=2;
            mokhtasat[5][0]+=2;
            int t1=mokhtasat[4][1];
            mokhtasat[4][1]=mokhtasat[5][1];
            mokhtasat[5][1]=t1;
            int t2=mokhtasat[1][1];
            mokhtasat[1][1]= mokhtasat[3][1];
            mokhtasat[3][1]=t2;
            num(4);
            jahat=0;
    }
    else if ((q==87||q==119)&&jahat==2)
    {
            num(0);
            mokhtasat[0][0]--;
            mokhtasat[0][1]++;
            mokhtasat[1][0]--;
            mokhtasat[1][1]--;
            mokhtasat[3][0]++;
            mokhtasat[3][1]++;
            mokhtasat[4][1]-=2;
            mokhtasat[5][0]+=2;
            num(4);
            jahat=0;

    }
    else if((q==87||q==119)&&jahat==3)
    {
            num(0);
            mokhtasat[0][0]--;
            mokhtasat[0][1]--;
            mokhtasat[1][0]++;
            mokhtasat[1][1]--;
            mokhtasat[3][0]--;
            mokhtasat[3][1]++;
            mokhtasat[5][1]+=2;
            mokhtasat[4][0]+=2;
            num(4);
            jahat=0;
    }
    else if ((q==87||q==119)&&jahat==0&&map[mokhtasat[0][0]-1][mokhtasat[0][1]]==0&&map[mokhtasat[1][0]-2][mokhtasat[1][1]]==0&&map[mokhtasat[3][0]-2][mokhtasat[3][1]]==0 )
    {
            num(0);
            mokhtasat[0][0]--;
            mokhtasat[1][0]--;
            mokhtasat[2][0]--;
            mokhtasat[3][0]--;
            mokhtasat[4][0]--;
            mokhtasat[5][0]--;
            num(4);


    }
    //down buttom-------------------------------------------------------------------------------------------------------------------
    else if ((q==83||q==115)&&jahat==0)
    {
            num(0);
            mokhtasat[0][0]+=2;
            mokhtasat[4][0]-=2;
            mokhtasat[5][0]-=2;
            int temp2=mokhtasat[4][1];
            mokhtasat[4][1]=mokhtasat[5][1];
            mokhtasat[5][1]=temp2;
            int temp4=mokhtasat[1][1];
            mokhtasat[1][1]=mokhtasat[3][1];
            mokhtasat[3][1]=temp4;
            num(4);
            jahat=1;

    }
    else if ((q==83||q==115)&&jahat==2)
    {
            num(0);
            mokhtasat[0][0]++;
            mokhtasat[0][1]++;
            mokhtasat[1][0]--;
            mokhtasat[1][1]++;
            mokhtasat[3][0]++;
            mokhtasat[3][1]--;
            mokhtasat[4][0]-=2;
            mokhtasat[5][1]-=2;
            num(4);
            jahat=1;
    }
    else if ((q==83||q==115)&&jahat==3)
    {
            num(0);
            mokhtasat[0][0]++;
            mokhtasat[0][1]--;
            mokhtasat[1][0]++;
            mokhtasat[1][1]++;
            mokhtasat[3][0]--;
            mokhtasat[3][1]--;
            mokhtasat[4][1]+=2;
            mokhtasat[5][0]-=2;
            num(4);
            jahat=1;

    }
     else if ((q==83||q==115)&&jahat==1&&map[mokhtasat[0][0]+1][mokhtasat[0][1]]==0&&map[mokhtasat[1][0]+2][mokhtasat[1][1]]==0&&map[mokhtasat[3][0]+2][mokhtasat[3][1]]==0)
     {
            num(0);
            mokhtasat[0][0]++;
            mokhtasat[1][0]++;
            mokhtasat[2][0]++;
            mokhtasat[3][0]++;
            mokhtasat[4][0]++;
            mokhtasat[5][0]++;
            num(4);
     }
     //left buttom-----------------------------------------------
     else if ((q==65||q==97)&&jahat==0)
     {
            num(0);
            mokhtasat[0][0]++;
            mokhtasat[0][1]--;
            mokhtasat[3][0]--;
            mokhtasat[3][1]--;
            mokhtasat[1][0]++;
            mokhtasat[1][1]++;
            mokhtasat[4][1]+=2;
            mokhtasat[5][0]-=2;
            num(4);
            jahat=2;

     }
     else if ((q==65||q==97)&&jahat==1)
     {
            num(0);
            mokhtasat[0][0]--;
            mokhtasat[0][1]--;
            mokhtasat[1][0]++;
            mokhtasat[1][1]--;
            mokhtasat[3][0]--;
            mokhtasat[3][1]++;
            mokhtasat[4][0]+=2;
            mokhtasat[5][1]+=2;
            num(4);
            jahat=2;

     }
     else if ((q==65||q==97)&&jahat==3)
     {
            num(0);
            mokhtasat[0][1]-=2;
            int t1=mokhtasat[1][0];
            mokhtasat[1][0]=mokhtasat[3][0];
            mokhtasat[3][0]=t1;
            int t2=mokhtasat[4][0];
            mokhtasat[4][0]=mokhtasat[5][0];
            mokhtasat[5][0]=t2;
            mokhtasat[5][1]+=2;
            mokhtasat[4][1]+=2;
            num(4);
            jahat=2;
     }
     else if ((q==65||q==97)&&jahat==2&&map[mokhtasat[0][0]][mokhtasat[0][1]-1]==0&&map[mokhtasat[1][0]][mokhtasat[1][1]-2]==0&&map[mokhtasat[3][0]][mokhtasat[3][1]-2]==0)
     {
            num(0);
            mokhtasat[0][1]--;
            mokhtasat[1][1]--;
            mokhtasat[2][1]--;
            mokhtasat[3][1]--;
            mokhtasat[4][1]--;
            mokhtasat[5][1]--;
            num(4);
     }
     //right buttom-------------------------------------------------------------
     else if ((q==68||q==100)&&jahat==0)
     {
            num(0);
            mokhtasat[0][0]++;
            mokhtasat[0][1]++;
            mokhtasat[3][0]++;
            mokhtasat[3][1]--;
            mokhtasat[1][0]--;
            mokhtasat[1][1]++;
            mokhtasat[4][0]-=2;
            mokhtasat[5][1]-=2;
            num(4);
            jahat=3;

     }
    else if ((q==68||q==100)&&jahat==1)
    {
            num(0);
            mokhtasat[0][0]--;
            mokhtasat[0][1]++;
            mokhtasat[1][0]--;
            mokhtasat[1][1]--;
            mokhtasat[3][0]++;
            mokhtasat[3][1]++;
            mokhtasat[4][1]-=2;
            mokhtasat[5][0]+=2;
            num(4);
            jahat=3;
    }
    else if ((q==68||q==100)&&jahat==2)
    {
            num(0);
            mokhtasat[0][1]+=2;
            mokhtasat[5][1]-=2;
            mokhtasat[4][1]-=2;
            int t1=mokhtasat[1][0];
            mokhtasat[1][0]=mokhtasat[3][0];
            mokhtasat[3][0]=t1;
            int t2=mokhtasat[4][0];
            mokhtasat[4][0]=mokhtasat[5][0];
            mokhtasat[5][0]=t2;
            num(4);
            jahat=3;
    }
    else if ((q==68||q==100)&&jahat==3&&map[mokhtasat[0][0]][mokhtasat[0][1]+1]==0&&map[mokhtasat[1][0]][mokhtasat[1][1]+2]==0
             &&map[mokhtasat[3][0]][mokhtasat[3][1]+2]==0)
    {
            num(0);
            mokhtasat[0][1]++;
            mokhtasat[1][1]++;
            mokhtasat[2][1]++;
            mokhtasat[3][1]++;
            mokhtasat[4][1]++;
            mokhtasat[5][1]++;
            num(4);
    }
    //tir ------------------------------------------------------------------------------------

    if (tir_q==0&&q==32)
    {
        tir_jahat=jahat;
        shoot(tir_jahat);
        tir_q=1;
        map[gun[0]][gun[1]]=7;
    }
    else if (tir_q==1)
    {
                if ((tir_jahat==0&&map[gun[0]-1][gun[1]]==6)||(tir_jahat==1&&map[gun[0]+1][gun[1]]==6)||(tir_jahat==2&&map[gun[0]][gun[1]-1]==6)||(tir_jahat==3&&map[gun[0]][gun[1]+1]==6))
                {
                    map [gun[0]][gun[1]]=0;
                    num2(0);
                    mokhtasat2[0][0]=5;
                    mokhtasat2[0][1]=16;
                    mokhtasat2[1][0]=4;
                    mokhtasat2[1][1]=17;
                    mokhtasat2[2][0]=4;
                    mokhtasat2[2][1]=16;
                    mokhtasat2[3][0]=4;
                    mokhtasat2[3][1]=15;
                    mokhtasat2[4][0]=3;
                    mokhtasat2[4][1]=17;
                    mokhtasat2[5][0]=3;
                    mokhtasat2[5][1]=15;
                    num2(6);
                    score++;
                    jahat2=1;
                    tir_q=0;
                }
                else if ((tir_jahat==0&&map[gun[0]-1][gun[1]]==5)||(tir_jahat==1&&map[gun[0]+1][gun[1]]==5)||(tir_jahat==2&&map[gun[0]][gun[1]-1]==5)||(tir_jahat==3&&map[gun[0]][gun[1]+1]==5))
                {
                    map [gun[0]][gun[1]]=0;
                    num1(0);
                    mokhtasat1[0][0]=5;
                    mokhtasat1[0][1]=3;
                    mokhtasat1[1][0]=4;
                    mokhtasat1[1][1]=4;
                    mokhtasat1[2][0]=4;
                    mokhtasat1[2][1]=3;
                    mokhtasat1[3][0]=4;
                    mokhtasat1[3][1]=2;
                    mokhtasat1[4][0]=3;
                    mokhtasat1[4][1]=4;
                    mokhtasat1[5][0]=3;
                    mokhtasat1[5][1]=2;
                    num1(5);
                    score++;
                    jahat1=1;
                    tir_q=0;
                }
                else if ((tir_jahat==0&&map[gun[0]-1][gun[1]]==5)||(tir_jahat==1&&map[gun[0]+1][gun[1]]==5)||(tir_jahat==2&&map[gun[0]][gun[1]-1]==5)||(tir_jahat==3&&map[gun[0]][gun[1]+1]==5))
                {
                    map [gun[0]][gun[1]]=0;
                    num1(0);
                    mokhtasat1[0][0]=5;
                    mokhtasat1[0][1]=3;
                    mokhtasat1[1][0]=4;
                    mokhtasat1[1][1]=4;
                    mokhtasat1[2][0]=4;
                    mokhtasat1[2][1]=3;
                    mokhtasat1[3][0]=4;
                    mokhtasat1[3][1]=2;
                    mokhtasat1[4][0]=3;
                    mokhtasat1[4][1]=4;
                    mokhtasat1[5][0]=3;
                    mokhtasat1[5][1]=2;
                    num1(5);
                    score++;
                    jahat1=1;
                    tir_q=0;
                }
                else if ((tir_jahat==0&&map[gun[0]-1][gun[1]]==1)||(tir_jahat==1&&map[gun[0]+1][gun[1]]==1)||
                         (tir_jahat==2&&map[gun[0]][gun[1]-1]==1)||(tir_jahat==3&&map[gun[0]][gun[1]+1]==1))
                    {
                        printf("how");
                        map [gun[0]][gun[1]]=0;
                        tir_q=0;
                    }
                else
                    moving_tir(tir_jahat);

    }
}
void e2_movement ()
{
    count2++;
    //tank2 movement$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

    if (jahat2==0&&map[mokhtasat2[0][0]-1][mokhtasat2[0][1]]==0&&map[mokhtasat2[1][0]-2][mokhtasat2[1][1]]==0&&map[mokhtasat2[3][0]-2][mokhtasat2[3][1]]==0 )
    {
            num2(0);
            mokhtasat2[0][0]--;
            mokhtasat2[1][0]--;
            mokhtasat2[2][0]--;
            mokhtasat2[3][0]--;
            mokhtasat2[4][0]--;
            mokhtasat2[5][0]--;
            num2(6);

    }
    else if (jahat2==1&&map[mokhtasat2[0][0]+1][mokhtasat2[0][1]]==0&&map[mokhtasat2[1][0]+2][mokhtasat2[1][1]]==0&&map[mokhtasat2[3][0]+2][mokhtasat2[3][1]]==0)
     {
            num2(0);
            mokhtasat2[0][0]++;
            mokhtasat2[1][0]++;
            mokhtasat2[2][0]++;
            mokhtasat2[3][0]++;
            mokhtasat2[4][0]++;
            mokhtasat2[5][0]++;
            num2(6);
     }
     else if (jahat2==2&&map[mokhtasat2[0][0]][mokhtasat2[0][1]-1]==0&&map[mokhtasat2[1][0]][mokhtasat2[1][1]-2]==0&&map[mokhtasat2[3][0]][mokhtasat2[3][1]-2]==0)
     {
            num2(0);
            mokhtasat2[0][1]--;
            mokhtasat2[1][1]--;
            mokhtasat2[2][1]--;
            mokhtasat2[3][1]--;
            mokhtasat2[4][1]--;
            mokhtasat2[5][1]--;
            num2(6);
     }
     else if (jahat2==3&&map[mokhtasat2[0][0]][mokhtasat2[0][1]+1]==0&&map[mokhtasat2[1][0]][mokhtasat2[1][1]+2]==0&&map[mokhtasat2[3][0]][mokhtasat2[3][1]+2]==0)
    {
            num2(0);
            mokhtasat2[0][1]++;
            mokhtasat2[1][1]++;
            mokhtasat2[2][1]++;
            mokhtasat2[3][1]++;
            mokhtasat2[4][1]++;
            mokhtasat2[5][1]++;
            num2(6);
    }

    //in2==0--------------------------------------------------------------------------

    else if (in2==0&&jahat2==1)
    {
            num2(0);
            mokhtasat2[0][0]-=2;
            mokhtasat2[4][0]+=2;
            mokhtasat2[5][0]+=2;
            int t1=mokhtasat2[4][1];
            mokhtasat2[4][1]=mokhtasat2[5][1];
            mokhtasat2[5][1]=t1;
            int t2=mokhtasat2[1][1];
            mokhtasat2[1][1]= mokhtasat2[3][1];
            mokhtasat2[3][1]=t2;
            num2(6);
            jahat2=0;
    }
    else if (in2==0&&jahat2==2)
    {
            num2(0);
            mokhtasat2[0][0]--;
            mokhtasat2[0][1]++;
            mokhtasat2[1][0]--;
            mokhtasat2[1][1]--;
            mokhtasat2[3][0]++;
            mokhtasat2[3][1]++;
            mokhtasat2[4][1]-=2;
            mokhtasat2[5][0]+=2;
            num2(6);
            jahat2=0;

    }
    else if(in2==0&&jahat2==3)
    {
            num2(0);
            mokhtasat2[0][0]--;
            mokhtasat2[0][1]--;
            mokhtasat2[1][0]++;
            mokhtasat2[1][1]--;
            mokhtasat2[3][0]--;
            mokhtasat2[3][1]++;
            mokhtasat2[5][1]+=2;
            mokhtasat2[4][0]+=2;
            num2(6);
            jahat2=0;
    }

    //in2==1 ---------------------------------------------------------------------------------------------------------------

    else if (in2==1&&jahat2==0)
    {
            num2(0);
            mokhtasat2[0][0]+=2;
            mokhtasat2[4][0]-=2;
            mokhtasat2[5][0]-=2;
            int temp2=mokhtasat2[4][1];
            mokhtasat2[4][1]=mokhtasat2[5][1];
            mokhtasat2[5][1]=temp2;
            int temp4=mokhtasat2[1][1];
            mokhtasat2[1][1]=mokhtasat2[3][1];
            mokhtasat2[3][1]=temp4;
            num2(6);
            jahat2=1;

    }
    else if (in2==1&&jahat2==2)
    {
            num2(0);
            mokhtasat2[0][0]++;
            mokhtasat2[0][1]++;
            mokhtasat2[1][0]--;
            mokhtasat2[1][1]++;
            mokhtasat2[3][0]++;
            mokhtasat2[3][1]--;
            mokhtasat2[4][0]-=2;
            mokhtasat2[5][1]-=2;
            num2(6);
            jahat2=1;
    }
    else if (in2==1&&jahat2==3)
    {
            num2(0);
            mokhtasat2[0][0]++;
            mokhtasat2[0][1]--;
            mokhtasat2[1][0]++;
            mokhtasat2[1][1]++;
            mokhtasat2[3][0]--;
            mokhtasat2[3][1]--;
            mokhtasat2[4][1]+=2;
            mokhtasat2[5][0]-=2;
            num2(6);
            jahat2=1;

    }

     //in2==2-----------------------------------------------------------------

     else if (in2==2&&jahat2==0)
     {
            num2(0);
            mokhtasat2[0][0]++;
            mokhtasat2[0][1]--;
            mokhtasat2[3][0]--;
            mokhtasat2[3][1]--;
            mokhtasat2[1][0]++;
            mokhtasat2[1][1]++;
            mokhtasat2[4][1]+=2;
            mokhtasat2[5][0]-=2;
            num2(6);
            jahat2=2;

     }
     else if (in2==2&&jahat2==1)
     {
            num2(0);
            mokhtasat2[0][0]--;
            mokhtasat2[0][1]--;
            mokhtasat2[1][0]++;
            mokhtasat2[1][1]--;
            mokhtasat2[3][0]--;
            mokhtasat2[3][1]++;
            mokhtasat2[4][0]+=2;
            mokhtasat2[5][1]+=2;
            num2(6);
            jahat2=2;

     }
     else if (in2==2&&jahat2==3)
     {
            num2(0);
            mokhtasat2[0][1]-=2;
            int t1=mokhtasat2[1][0];
            mokhtasat2[1][0]=mokhtasat2[3][0];
            mokhtasat2[3][0]=t1;
            int t2=mokhtasat2[4][0];
            mokhtasat2[4][0]=mokhtasat2[5][0];
            mokhtasat2[5][0]=t2;
            mokhtasat2[5][1]+=2;
            mokhtasat2[4][1]+=2;
            num2(6);
            jahat2=2;
     }

     //in2==3  --------------------------------------------------------------------------------------------

     else if (in2==3&&jahat2==0)
     {
            num2(0);
            mokhtasat2[0][0]++;
            mokhtasat2[0][1]++;
            mokhtasat2[3][0]++;
            mokhtasat2[3][1]--;
            mokhtasat2[1][0]--;
            mokhtasat2[1][1]++;
            mokhtasat2[4][0]-=2;
            mokhtasat2[5][1]-=2;
            num2(6);
            jahat2=3;

     }
    else if (in2==3&&jahat2==1)
    {
            num2(0);
            mokhtasat2[0][0]--;
            mokhtasat2[0][1]++;
            mokhtasat2[1][0]--;
            mokhtasat2[1][1]--;
            mokhtasat2[3][0]++;
            mokhtasat2[3][1]++;
            mokhtasat2[4][1]-=2;
            mokhtasat2[5][0]+=2;
            num2(6);
            jahat2=3;
    }
    else if (in2==3&&jahat2==2)
    {
            num2(0);
            mokhtasat2[0][1]+=2;
            mokhtasat2[5][1]-=2;
            mokhtasat2[4][1]-=2;
            int t1=mokhtasat2[1][0];
            mokhtasat2[1][0]=mokhtasat2[3][0];
            mokhtasat2[3][0]=t1;
            int t2=mokhtasat2[4][0];
            mokhtasat2[4][0]=mokhtasat2[5][0];
            mokhtasat2[5][0]=t2;
            num2(6);
            jahat2=3;
    }
    if (tir_q2==0&&count2%3==0)
    {
        tir_jahat2=jahat2;

        if ((tir_jahat2==0&&map[mokhtasat2[0][0]-1][mokhtasat2[0][1]]==0)||(tir_jahat2==1&&map[mokhtasat2[0][0]+1][mokhtasat2[0][1]]==0)||(tir_jahat2==2&&map[mokhtasat2[0][0]][mokhtasat2[0][1]+1]==0)||(tir_jahat2==3&&map[mokhtasat2[0][0]-1][mokhtasat2[0][1]-1]==0))
            {
                shoot2(tir_jahat2);
                tir_q2=1;
                map[gun2[0]][gun2[1]]=7;
            }
    }
    else if (tir_q2==1)
    {
                if ((tir_jahat2==0&&map[gun2[0]-1][gun2[1]]==6)||(tir_jahat2==1&&map[gun2[0]+1][gun2[1]]==6)||(tir_jahat2==2&&map[gun2[0]][gun2[1]-1]==6)||(tir_jahat2==3&&map[gun2[0]][gun2[1]+1]==6))
                {
                    map [gun2[0]][gun2[1]]=0;
                    tir_q2=0;
                }
                else if ((tir_jahat2==0&&map[gun2[0]-1][gun2[1]]==4)||(tir_jahat2==1&&map[gun2[0]+1][gun2[1]]==4)||(tir_jahat2==2&&map[gun2[0]][gun2[1]-1]==4)||(tir_jahat2==3&&map[gun2[0]][gun2[1]+1]==4))
                {
                    map [gun2[0]][gun2[1]]=0;
                    num(0);
                    mokhtasat[0][0]=14;
                    mokhtasat[0][1]=3;
                    mokhtasat[1][0]=15;
                    mokhtasat[1][1]=2;
                    mokhtasat[2][0]=15;
                    mokhtasat[2][1]=3;
                    mokhtasat[3][0]=15;
                    mokhtasat[3][1]=4;
                    mokhtasat[4][0]=16;
                    mokhtasat[4][1]=2;
                    mokhtasat[5][0]=16;
                    mokhtasat[5][1]=4;
                    num(4);
                    life--;
                    jahat=0;
                    tir_q2=0;
                }
                else if ((tir_jahat2==0&&map[gun2[0]-1][gun2[1]]==1)||(tir_jahat2==1&&map[gun2[0]+1][gun2[1]]==1)||(tir_jahat2==2&&map[gun2[0]][gun2[1]-1]==1)||(tir_jahat2==3&&map[gun2[0]][gun2[1]+1]==1))
                    {
                        map [gun2[0]][gun2[1]]=0;
                        tir_q2=0;
                    }
                else
                    moving_tir2(tir_jahat2);

    }


}
void e1_movement ()
{
    //tank1 movement$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    count1++;
    //moving up
    if (jahat1==0&&map[mokhtasat1[0][0]-1][mokhtasat1[0][1]]==0&&map[mokhtasat1[1][0]-2][mokhtasat1[1][1]]==0&&map[mokhtasat1[3][0]-2][mokhtasat1[3][1]]==0)
    {
            num1(0);
            mokhtasat1[0][0]--;
            mokhtasat1[1][0]--;
            mokhtasat1[2][0]--;
            mokhtasat1[3][0]--;
            mokhtasat1[4][0]--;
            mokhtasat1[5][0]--;
            num1(5);
    }
    //moving down
    else if (jahat1==1&&map[mokhtasat1[0][0]+1][mokhtasat1[0][1]]==0&&map[mokhtasat1[1][0]+2][mokhtasat1[1][1]]==0&&map[mokhtasat1[3][0]+2][mokhtasat1[3][1]]==0)
    {
            num1(0);
            mokhtasat1[0][0]++;
            mokhtasat1[1][0]++;
            mokhtasat1[2][0]++;
            mokhtasat1[3][0]++;
            mokhtasat1[4][0]++;
            mokhtasat1[5][0]++;
            num1(5);
     }
     //moving left
     else if (jahat1==2&&map[mokhtasat1[0][0]][mokhtasat1[0][1]-1]==0&&map[mokhtasat1[1][0]][mokhtasat1[1][1]-2]==0&&map[mokhtasat1[3][0]][mokhtasat1[3][1]-2]==0)
     {
            num1(0);
            mokhtasat1[0][1]--;
            mokhtasat1[1][1]--;
            mokhtasat1[2][1]--;
            mokhtasat1[3][1]--;
            mokhtasat1[4][1]--;
            mokhtasat1[5][1]--;
            num1(5);
     }
     else if (jahat1==3&&map[mokhtasat1[0][0]][mokhtasat1[0][1]+1]==0&&map[mokhtasat1[1][0]][mokhtasat1[1][1]+2]==0&&map[mokhtasat1[3][0]][mokhtasat1[3][1]+2]==0)
    {
            num1(0);
            mokhtasat1[0][1]++;
            mokhtasat1[1][1]++;
            mokhtasat1[2][1]++;
            mokhtasat1[3][1]++;
            mokhtasat1[4][1]++;
            mokhtasat1[5][1]++;
            num1(5);
    }




    //in1==0 -------------------------------------------------------------------
    else if (jahat1==1&&in1==0)
    {
            num1(0);
            mokhtasat1[0][0]-=2;
            mokhtasat1[4][0]+=2;
            mokhtasat1[5][0]+=2;
            int t1=mokhtasat1[4][1];
            mokhtasat1[4][1]=mokhtasat1[5][1];
            mokhtasat1[5][1]=t1;
            int t2=mokhtasat1[1][1];
            mokhtasat1[1][1]= mokhtasat1[3][1];
            mokhtasat1[3][1]=t2;
            num1(5);
            jahat1=0;
    }
    else if (jahat1==2&&in1==0)
    {
            num1(0);
            mokhtasat1[0][0]--;
            mokhtasat1[0][1]++;
            mokhtasat1[1][0]--;
            mokhtasat1[1][1]--;
            mokhtasat1[3][0]++;
            mokhtasat1[3][1]++;
            mokhtasat1[4][1]-=2;
            mokhtasat1[5][0]+=2;
            num1(5);
            jahat1=0;
    }
    else if (jahat1==3&&in1==0)
    {
            num1(0);
            mokhtasat1[0][0]--;
            mokhtasat1[0][1]--;
            mokhtasat1[1][0]++;
            mokhtasat1[1][1]--;
            mokhtasat1[3][0]--;
            mokhtasat1[3][1]++;
            mokhtasat1[5][1]+=2;
            mokhtasat1[4][0]+=2;
             num1(5);
            jahat1=0;
    }



    //in1==1 -------------------------------------------------------------------------------------------------------------------
    else if (in1==1&&jahat1==0)
    {
            num1(0);
            mokhtasat1[0][0]+=2;
            mokhtasat1[4][0]-=2;
            mokhtasat1[5][0]-=2;
            int temp2=mokhtasat1[4][1];
            mokhtasat1[4][1]=mokhtasat1[5][1];
            mokhtasat1[5][1]=temp2;
            int temp4=mokhtasat1[1][1];
            mokhtasat1[1][1]=mokhtasat1[3][1];
            mokhtasat1[3][1]=temp4;
            num1(5);
            jahat1=1;

    }
    else if (in1==1&&jahat1==2)
    {
            num1(0);
            mokhtasat1[0][0]++;
            mokhtasat1[0][1]++;
            mokhtasat1[1][0]--;
            mokhtasat1[1][1]++;
            mokhtasat1[3][0]++;
            mokhtasat1[3][1]--;
            mokhtasat1[4][0]-=2;
            mokhtasat1[5][1]-=2;
            num1(5);
            jahat1=1;
    }
    else if (in1==1&&jahat1==3)
    {
            num1(0);
            mokhtasat1[0][0]++;
            mokhtasat1[0][1]--;
            mokhtasat1[1][0]++;
            mokhtasat1[1][1]++;
            mokhtasat1[3][0]--;
            mokhtasat1[3][1]--;
            mokhtasat1[4][1]+=2;
            mokhtasat1[5][0]-=2;
            num1(5);
            jahat1=1;

    }

     //in1== 2 -----------------------------------------------
     else if (in1==2&&jahat1==0)
     {
            num1(0);
            mokhtasat1[0][0]++;
            mokhtasat1[0][1]--;
            mokhtasat1[3][0]--;
            mokhtasat1[3][1]--;
            mokhtasat1[1][0]++;
            mokhtasat1[1][1]++;
            mokhtasat1[4][1]+=2;
            mokhtasat1[5][0]-=2;
            num1(5);
            jahat1=2;

     }
     else if (in1==2&&jahat1==1)
     {
            num1(0);
            mokhtasat1[0][0]--;
            mokhtasat1[0][1]--;
            mokhtasat1[1][0]++;
            mokhtasat1[1][1]--;
            mokhtasat1[3][0]--;
            mokhtasat1[3][1]++;
            mokhtasat1[4][0]+=2;
            mokhtasat1[5][1]+=2;
            num1(5);
            jahat1=2;

     }
     else if (in1==2&&jahat1==3)
     {
            num1(0);
            mokhtasat1[0][1]-=2;
            int t1=mokhtasat1[1][0];
            mokhtasat1[1][0]=mokhtasat1[3][0];
            mokhtasat1[3][0]=t1;
            int t2=mokhtasat1[4][0];
            mokhtasat1[4][0]=mokhtasat1[5][0];
            mokhtasat1[5][0]=t2;
            mokhtasat1[5][1]+=2;
            mokhtasat1[4][1]+=2;
            num1(5);
            jahat1=2;
     }

     //in1==3 -------------------------------------------------------------------------------------------
     else if (in1==3&&jahat1==0)
     {
            num1(0);
            mokhtasat1[0][0]++;
            mokhtasat1[0][1]++;
            mokhtasat1[3][0]++;
            mokhtasat1[3][1]--;
            mokhtasat1[1][0]--;
            mokhtasat1[1][1]++;
            mokhtasat1[4][0]-=2;
            mokhtasat1[5][1]-=2;
            num1(5);
            jahat1=3;

     }
    else if (in1==3&&jahat1==1)
    {
            num1(0);
            mokhtasat1[0][0]--;
            mokhtasat1[0][1]++;
            mokhtasat1[1][0]--;
            mokhtasat1[1][1]--;
            mokhtasat1[3][0]++;
            mokhtasat1[3][1]++;
            mokhtasat1[4][1]-=2;
            mokhtasat1[5][0]+=2;
            num1(5);
            jahat1=3;
    }
    else if (in1==3&&jahat1==2)
    {
            num1(0);
            mokhtasat1[0][1]+=2;
            mokhtasat1[5][1]-=2;
            mokhtasat1[4][1]-=2;
            int t1=mokhtasat1[1][0];
            mokhtasat1[1][0]=mokhtasat1[3][0];
            mokhtasat1[3][0]=t1;
            int t2=mokhtasat1[4][0];
            mokhtasat1[4][0]=mokhtasat1[5][0];
            mokhtasat1[5][0]=t2;
            num1(5);
            jahat1=3;
    }
    //tir------------------------------------------------------------
    if (tir_q1==0&&count1%3==0)
    {
        tir_jahat1=jahat1;

        if ((tir_jahat1==0&&map[mokhtasat1[0][0]-1][mokhtasat1[0][1]]==0)||(tir_jahat1==1&&map[mokhtasat1[0][0]+1][mokhtasat1[0][1]]==0)||(tir_jahat1==2&&map[mokhtasat1[0][0]][mokhtasat1[0][1]+1]==0)||(tir_jahat1==3&&map[mokhtasat1[0][0]-1][mokhtasat1[0][1]-1]==0))
            {
                shoot1(tir_jahat1);
                tir_q1=1;
                map[gun1[0]][gun1[1]]=7;
            }
    }
    else if (tir_q1==1)
    {
                if ((tir_jahat1==0&&map[gun1[0]-1][gun1[1]]==6)||(tir_jahat1==1&&map[gun1[0]+1][gun1[1]]==6)||
                    (tir_jahat1==2&&map[gun1[0]][gun1[1]-1]==6)||(tir_jahat1==3&&map[gun1[0]][gun1[1]+1]==6))
                {
                    map [gun1[0]][gun1[1]]=0;
                    tir_q1=0;
                }
                else if ((tir_jahat1==0&&map[gun1[0]-1][gun1[1]]==4)||(tir_jahat1==1&&map[gun1[0]+1][gun1[1]]==4)||
                         (tir_jahat1==2&&map[gun1[0]][gun1[1]-1]==4)||(tir_jahat1==3&&map[gun1[0]][gun1[1]+1]==4))
                {
                    map [gun1[0]][gun1[1]]=0;
                    num(0);
                    mokhtasat[0][0]=14;
                    mokhtasat[0][1]=3;
                    mokhtasat[1][0]=15;
                    mokhtasat[1][1]=2;
                    mokhtasat[2][0]=15;
                    mokhtasat[2][1]=3;
                    mokhtasat[3][0]=15;
                    mokhtasat[3][1]=4;
                    mokhtasat[4][0]=16;
                    mokhtasat[4][1]=2;
                    mokhtasat[5][0]=16;
                    mokhtasat[5][1]=4;
                    num(4);
                    life--;
                    jahat=0;
                    tir_q1=0;
                }
                else if ((tir_jahat1==0&&map[gun1[0]-1][gun1[1]]==1)||(tir_jahat1==1&&map[gun1[0]+1][gun1[1]]==1)||
                         (tir_jahat1==2&&map[gun1[0]][gun1[1]-1]==1)||(tir_jahat1==3&&map[gun1[0]][gun1[1]+1]==1))
                    {
                        map [gun1[0]][gun1[1]]=0;
                        tir_q1=0;
                    }
                else
                    moving_tir1(tir_jahat1);

    }
}
void movement ()
{
    in1=rand()%4;
    in2=rand()%4;
    while (_kbhit())
    {
        q=getch();
    }

    e1_movement();
    e2_movement();
    my_movement();
    q=0;
}
void mapfile (int level)
{
    FILE *levelmap;
    if (level==1)
            levelmap=fopen("D://Program Files (x86)/CodeBlocks/c/tank game/maps/level1.txt" , "r");


    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            fscanf(levelmap , "%d" , &map[i][j] );
            fclose(levelmap);


}
void printmap()
{
    system("cls");
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            if (map[i][j]==1)
                printf(" %c" ,254);
            else if (map[i][j]==2)
                printf(" @");
            else if (map[i][j]==3)
                printf(" *");
            else if (map[i][j]==4)
                printf(" o");
            else if (map[i][j]==5)
                printf(" $");
            else if (map[i][j]==6)
                printf(" $");
            else if (map[i][j]==7)
                printf(" .");
            else if (map[i][j]==8)
                printf(" .");
            else if (map[i][j]==0)
                    printf("  ");


        }
        printf("\n");
    }
    printf("\n\nscore = %d\n\n" , score);
    printf("life = %d" , life);
}
void playgame ()
{
    int ch=0;
    mapfile(level);
    while (ch!=52&&life)
    {
        printmap();

        movement();
        Sleep(300);
    }
    while (life==0)
    {
        system("cls");
        printf("you lose");
    }
}
void printsetting ()
{
    system("cls");
    printf("1-game settings\n\n2-sound setting\n\n3-keybord setting\n\n4-main menu ");
}
void loadgame ()
{
    system("cls");
    printf("loads are loading...");
    int ch=getch();
}
void printmenu()
{
    system("cls");
 printf("1-play game \n\n2-load game\n\n3-settings\n\n4-exit ");
}
void gamesetting ()
{
    system("cls");
    printf("enter speed form 0 to 10:");
    scanf("%d" , &speed);
}
void soundsetting ()
{

    system("cls");
    printf("enter volumeform 0 to 10:");
    scanf("%d" , &volume);

}
void keyboardsetting()
{
    system("cls");
    printf("enter up buttom");
    up=getch();
    printf("\nenter down buttom");
    down=getch();
    printf("\nenter right buttom");
    right=getch();
    printf("\nenter left buttom");
    left=getch();
}
void setting ()
{
    printsetting();
     char a=9;
    while (a!=52)
    {
    a=getch ();
    if (a==49)
        {
            gamesetting();
            printsetting();
        }
    else if (a==50)
        {   soundsetting();
            printsetting();
         }
    else if (a==51)
        {
            keyboardsetting ();
            printsetting();
        }

    }

}
void menu ()
{
    printmenu();
    char ch=9;

    while (ch!=52)

    {
        ch=getch();
        if (ch==49)
            {
                playgame();
                printmenu();
            }
        else if (ch==50)
            {   loadgame();
                printmenu();
            }
        else if (ch==51)
            {
                setting();
                printmenu();
            }
    }

}

int main ()
{
    srand(time(NULL));
    menu();
    return 0;
}

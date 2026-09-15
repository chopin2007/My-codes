#include<stdio.h>
#include<string.h>

typedef struct {
    char heroName[30];
    double life;
    double magic;
    double attack;
    double attackSpeed;
}hero;
int main(int argc,char const *argv[]){
    hero hs[4];
    hero h1;
    strcpy(h1.heroName,"刘备");
    h1.life=5000;
    h1.magic=2000;
    h1.attack=1500;
    h1.attackSpeed=100;
    
    hero h2;
    strcpy(h2.heroName,"关羽");
    h2.life=5000;
    h2.magic=2000;
    h2.attack=1500;
    h2.attackSpeed=100;

    hero h3;
    strcpy(h3.heroName,"张飞");
    h3.life=5000;
    h3.magic=2000;
    h3.attack=1500;
    h3.attackSpeed=100;
    
    hero h4;
    strcpy(h4.heroName,"赵云");
    h4.life=5000;
    h4.magic=2000;
    h4.attack=1500;
    h4.attackSpeed=100;
    
    hs[0]=h1;
    hs[1]=h2;
    hs[2]=h3;
    hs[3]=h4;
    
    for(int i=0;i<4;++i){
        printf("%s->%lf->%lf->%lf->%lf\n",hs[i].heroName,hs[i].life,hs[i].magic,hs[i].attack,hs[i].attackSpeed);
    }
    return 0;
}
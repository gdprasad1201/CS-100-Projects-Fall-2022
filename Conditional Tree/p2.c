#include <stdio.h>
#include<string.h>
int main() {
    char direction[6],yn[4],lr[6],fs[5],bs[6],color[6],ud[5],eh[5],lcr[7],bd[8],oc[7],sc[7];
    int n;
    printf("north,south,east,or west:"); 
    scanf("%s",direction);
    if(strcmp(direction,"north")==0){
        printf("Enter a positive integer:"); scanf("%d",&n);
        if(n%2==0){
            printf("yes or no:");  scanf("%s", &yn);
            if(strcmp(yn,"yes")==0) printf("lake");
            if(strcmp(yn,"no")==0) printf("pool");
        }
        else printf("beach");
    }
    if(strcmp(direction,"south")==0){
        printf("left or right:"); scanf("%s", &lr);
        if(strcmp(lr,"left")==0) printf("jog");
        if(strcmp(lr,"right")==0){
            printf("fast or slow:");  scanf("%s", &fs);
            if(strcmp(fs,"fast")==0) printf("bike");
            if(strcmp(fs,"slow")==0){
                printf("big or small:"); scanf("%s", &bs);
                if(strcmp(bs,"big")==0) printf("run");
                if(strcmp(bs,"small")==0) printf("walk");
            }
        }
    }
    if(strcmp(direction,"east")==0){
        printf("red,white,or gray:"); scanf("%s", &color);
        if(strcmp(color,"red")==0){
            printf("yes or no:");  scanf("%s", &yn);
            if(strcmp(yn,"yes")==0) printf("tree-climb");
            if(strcmp(yn,"no")==0){
                printf("up or down:"); scanf("%s", &ud);
                if(strcmp(ud,"up")==0) printf("top-rope");
                if(strcmp(ud,"down")==0) printf("boulder");
            }
        }
        if(strcmp(color,"white")==0){
          printf("easy or hard:"); scanf("%s", &eh);
          if(strcmp(eh,"easy")==0) printf("longboard");
          if(strcmp(eh,"hard")==0) printf("workout");
        }
        if(strcmp(color,"gray")==0){ 
            printf("left,center or right:"); scanf("%s", &lcr);
            if(strcmp(lcr,"left")==0){
                printf("build or destroy:");  scanf("%s", &bd);
                if(strcmp(bd,"build")==0) printf("hike");
                if(strcmp(bd,"destroy")==0) printf("spelunk");
            }
            if(strcmp(lcr,"center")==0){
                printf("open or closed"); scanf("%s", &oc);
                if(strcmp(oc,"open")==0) printf("zoo");
                if(strcmp(oc,"closed")==0) printf("aquarium");
            }
            if(strcmp(lcr,"right")==0) printf("museum");
        }
    }
    if(strcmp(direction,"west")==0){
        printf("Enter an integer:");  scanf("%d",&n);
        if(n>=0) printf("frisbee");
        else{
            printf("sunny or cloudy:"); scanf("%s", &sc);
            if(strcmp(sc,"sunny")==0) printf("tennis");
            if(strcmp(sc,"cloudy")==0) printf("racquetball");
        }
    }
    return 0;
}

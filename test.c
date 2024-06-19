#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define shapeText(TYPE) char name[10]; \
    int (*perimeter)(struct TYPE*); \
    int (*area)(struct TYPE*);
    typedef struct shape_s { shapeText(shape_s); } shape_t;

typedef struct circle_s {
    shapeText(circle_s);
    int radius;
} circle_t;

typedef struct rectangle_s{
    shapeText(rectangle_s);
    int width, height;
} rectangle_t;

typedef struct square_s{
    shapeText(square_s);
    int side;
} square_t;

typedef struct triangle_s {
    shapeText(triangle_s);
    int s1, s2, s3;
} triangle_t;

int circlePerimeter(circle_t *c){return 8*c->radius;}
int circleArea(circle_t *c){return 4*c->radius*c->radius;}
int rectanglePerimeter(rectangle_t *r){ return 2*(r->height +r->width);}
int rectangleArea(rectangle_t *r){ return (r->height *r->width);}
int squarePreimeter(square_t *s){return s->side *4;}
int squareArea(square_t *s){return s->side *s->side ;}
int trianglePerimeter(triangle_t *t){return (t->s1 + t->s2 +t->s3);}
int triangleArea(triangle_t *t ){
    int s = (t->s1 + t->s2 +t->s3)/2;
    return sqrt(s * (s - t->s1) * (s - t->s2) * (s - t->s3));}
shape_t *newShapes(char *type){
    if(strcmp(type, "circle") == 0){
        circle_t *c = (circle_t *) malloc (sizeof(circle_t));
        c->perimeter = circlePerimeter;
        c->area = circleArea;
        strcpy(c->name, type);
        return (shape_t*)c;
    }else if (strcmp(type, "rectangle") == 0){
        rectangle_t*c = (rectangle_t *) malloc (sizeof(rectangle_t));
        c->perimeter = rectanglePerimeter;
        c->area = rectangleArea;
        strcpy(c->name, type);
        return (shape_t*)c;
    }else if (strcmp(type, "square") == 0){
        square_t*c = (square_t *) malloc (sizeof(square_t));
        c->perimeter = squarePreimeter;
        c->area = squareArea;
        strcpy(c->name, type);
        return (shape_t*)c;
    }else if (strcmp(type, "triangle") == 0){
        triangle_t*c = (triangle_t *) malloc (sizeof(triangle_t));
        c->perimeter = trianglePerimeter;
        c->area = triangleArea;
        strcpy(c->name, type);
        return (shape_t*)c;
    }else return NULL;
}
void sort(shape_t *shapes[], int count){
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if( (shapes[j]->perimeter(shapes[j]) < (shapes[j+1]->perimeter(shapes[j+1]))) || 
            ((shapes[j]->perimeter(shapes[j])  == (shapes[j+1]->perimeter(shapes[j+1]))) && (shapes[j]->area(shapes[j]) < (shapes[j+1]->area(shapes[j+1])))  )){
                shape_t *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %d\n", shapes[i]->name, shapes[i]->perimeter(shapes[i]),shapes[i]->area(shapes[i]) );
    }
    
}
int main(){
    int count = 0;
    scanf("%d",&count);
    shape_t *shapes[count];
    for (int i = 0; i < count; i++)
    {
        char type[100];
        scanf("%s", type);
        shapes[i] = newShapes(type);
        if(strcmp(type, "circle") == 0){
            circle_t *c = (circle_t *)shapes[i];
            scanf("%d", &c->radius);
        }else if (strcmp(type, "rectangle") == 0){
            rectangle_t*c = (rectangle_t *) shapes[i];
            scanf("%d %d", &c->height, &c->width);
        }else if (strcmp(type, "square") == 0){
            square_t*c = (square_t *)shapes[i];
            scanf("%d", &c->side);
        }else if (strcmp(type, "triangle") == 0){
            triangle_t*c = (triangle_t *)shapes[i];
            scanf("%d %d %d", &c->s1, &c->s2,&c->s3);
        }
    }
    sort(shapes, count);
    
}
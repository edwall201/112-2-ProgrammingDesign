#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
int rectanglePerimeter(rectangle_t *r){return 2*(r->height + r->width);}
int rectangleArea(rectangle_t *r){return (r->height * r->width);}
int squarePerimeter(square_t *s){return 4*s->side ;}
int squareArea(square_t *s){return s->side*s->side ;}
int trianglePerimeter(triangle_t *t){return t->s1 +t->s2 +t->s3;}
int triangleArea(triangle_t *t){
    int s = (t->s1 +t->s2 +t->s3)/2;
    return sqrt(s * (s-t->s1) * (s-t->s2) * (s-t->s3));}

shape_t * newShape(char *data){
    if(strcmp(data, "circle") == 0){
        circle_t *c = (circle_t*)malloc(sizeof(circle_t));
        strcpy(c->name, data);
        c->perimeter = circlePerimeter;
        c->area = circleArea;
        return (shape_t *)c;
    }else if(strcmp(data, "rectangle") == 0){
        rectangle_t *c = (rectangle_t*)malloc(sizeof(rectangle_t));
        strcpy(c->name, data);
        c->perimeter = rectanglePerimeter;
        c->area = rectangleArea;
        return (shape_t *)c;
    }else if(strcmp(data, "square") == 0){
        square_t *c = (square_t*)malloc(sizeof(square_t));
        strcpy(c->name, data);
        c->perimeter = squarePerimeter;
        c->area = squareArea;
        return (shape_t *)c;
    }else if(strcmp(data, "triangle") == 0){
        triangle_t *c = (triangle_t*)malloc(sizeof(triangle_t));
        strcpy(c->name, data);
        c->perimeter = trianglePerimeter;
        c->area = triangleArea;
        return (shape_t *)c;
    }else return NULL;
}
void sort(shape_t *shapes[], int count){
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if( (shapes[j]->perimeter(shapes[j]) < shapes[j+1]->perimeter(shapes[j+1])) ||
            ((shapes[j]->perimeter(shapes[j]) == shapes[j+1]->perimeter(shapes[j+1])) && (shapes[j]->area(shapes[j]) < shapes[j+1]->area(shapes[j+1])) )){
                shape_t *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
    int primeter = 0, area =0;
    for (int i = 0; i < count; i++)
    {
        primeter += shapes[i]->perimeter(shapes[i]);
        area += shapes[i]->area(shapes[i]);
        printf("%s %d %d\n",shapes[i]->name, shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
    }
    printf("%d %d\n", primeter, area);
    
    
}
int main(){
    int count = 0;
    scanf("%d", &count);
    shape_t *shapes[count];
    for (int i = 0; i < count; i++)
    {
        char type[100];
        scanf("%s", type);
        shapes[i] = newShape(type);
        if(strcmp(type, "circle") == 0){
            circle_t *c = (circle_t *)shapes[i];
            scanf("%d", &c->radius);
        }else if(strcmp(type, "rectangle") == 0){
            rectangle_t *c = (rectangle_t*)shapes[i];
            scanf("%d %d", &c->height, &c->width);
        }else if(strcmp(type, "square") == 0){
            square_t *c = (square_t*)shapes[i];
            scanf("%d", &c->side);
        }else if(strcmp(type, "triangle") == 0){
            triangle_t *c = (triangle_t*)shapes[i];
            scanf("%d %d %d", &c->s1, &c->s2, &c->s3);
        }
    }
    sort(shapes, count);
}
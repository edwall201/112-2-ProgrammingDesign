#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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

int circlePerimeter(circle_t *c){return c->radius * 8;}
int circleArea(circle_t *c){return c->radius * c->radius *4;}
int rectanglePerimeter(rectangle_t *t){return 2 *(t->height + t->width);}
int rectangleArea(rectangle_t *t){return (t->height * t->width);}
int squarePerimeter(square_t *s){return s->side * 4;}
int squareArea(square_t *s){return s->side * s->side;}
int trianglePerimeter(triangle_t *t){return t->s1 + t->s2 + t->s3;}
int triangleArea(triangle_t *t){
    int s = (t->s1 + t->s2 + t->s3)/2;
    return sqrt(s*(s-t->s1)*(s-t->s2)*(s-t->s3));
}

shape_t *newShape(char data[]){
    if (strcmp(data, "circle")==0)
    {
        circle_t *c = (circle_t*)malloc(sizeof(circle_t));
        strcpy(c->name, data);
        c->perimeter = circlePerimeter;
        c->area = circleArea;
        return (shape_t *)c;
    }else if (strcmp(data, "rectangle")==0)
    {
        rectangle_t *r = (rectangle_t*)malloc(sizeof(rectangle_t));
        strcpy(r->name, data);
        r->perimeter = rectanglePerimeter;
        r->area = rectangleArea;
        return (shape_t *)r;
    }else if (strcmp(data, "square")==0)
    {
        square_t *s = (square_t*)malloc(sizeof(square_t));
        strcpy(s->name, data);
        s->perimeter = squarePerimeter;
        s->area = squareArea;
        return (shape_t *)s;
    }else if (strcmp(data, "triangle")==0)
    {
        triangle_t *t = (triangle_t*)malloc(sizeof(triangle_t));
        strcpy(t->name, data);
        t->perimeter = trianglePerimeter;
        t->area = triangleArea;
        return (shape_t *)t;
    }else return NULL;
    
    
}

void sort(shape_t *shapes[], int count){
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
           if( (shapes[j]->perimeter(shapes[j]) < shapes[j+1]->perimeter(shapes[j+1])) ||
           ( (shapes[j]->perimeter(shapes[j]) == shapes[j+1]->perimeter(shapes[j+1]))  && (shapes[j]->area(shapes[j]) < shapes[j+1]->area(shapes[j+1]) ) )){
                shape_t *temp = shapes[j+1];
                shapes[j + 1] = shapes[j];
                shapes[j] = temp;
           }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %d\n", shapes[i]->name, shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
    }
    
}

int main(){
    int count = 0;
    scanf("%d", &count);
    shape_t *shapes[count];
    for (int i = 0; i < count; i++)
    {
        char data[100];
        scanf("%s", data);
        shapes[i] = newShape(data);
        if(shapes[i]){
            if (strcmp(data, "circle")==0){
                circle_t *t = (circle_t *)shapes[i];
                scanf("%d",&t->radius);
            }else if (strcmp(data, "rectangle")==0){
                rectangle_t *r =(rectangle_t *)shapes[i];
                scanf("%d %d", &r->height, &r->width);
            }else if (strcmp(data, "square")==0){
                square_t *s = (square_t *)shapes[i];
                scanf("%d", &s->side);
            }else if (strcmp(data, "triangle")==0){
                triangle_t *t = (triangle_t *)shapes[i];
                scanf("%d %d %d", &t->s1, &t->s2, &t->s3);
            }
        }
    }
    sort(shapes, count);
    return 0;
}
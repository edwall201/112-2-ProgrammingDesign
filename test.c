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
int circlePerimeter(circle_t *c){return c->radius * 4 *2;}
int circleArea(circle_t *c){return c->radius * c->radius * 4;}
int rectanglePerimeter(rectangle_t *r){return 2*(r->height + r->width);}
int rectangleArea(rectangle_t *r){return (r->height * r->width);}
int squarePerimeter(square_t *s){return 4*s->side;}
int squareArea(square_t *s){return s->side*s->side;}
int trianglePerimeter(triangle_t *t){return t->s1 + t->s2 + t->s3;}
int triangleArea(triangle_t *t){
    int s = (t->s1 + t->s2 + t->s3)/2;
    return sqrt(s*(s-t->s1) * (s-t->s2) * (s-t->s3));
}


shape_t *newShape(char *name){
    if(strcmp(name, "triangle") == 0){
        triangle_t *t = (triangle_t *)malloc(sizeof(triangle_t));
        strcpy(t->name, name);
        t->perimeter = trianglePerimeter;
        t->area = triangleArea;
        return (shape_t *)t;
    }else if(strcmp(name, "square") == 0){
        square_t *s = (square_t *)malloc(sizeof(square_t));
        strcpy(s->name, name);
        s->perimeter = squarePerimeter;
        s->area = squareArea;
        return (shape_t *)s;
    }else if(strcmp(name, "rectangle") == 0){
        rectangle_t *r = (rectangle_t *)malloc(sizeof(rectangle_t));
        strcpy(r->name, name);
        r->perimeter = rectanglePerimeter;
        r->area = rectangleArea;
        return (shape_t *)r;
    }else if(strcmp(name, "circle") == 0){
        circle_t *c = (circle_t *)malloc(sizeof(circle_t));
        strcpy(c->name, name);
        c->perimeter = circlePerimeter;
        c->area = circleArea;
        return (shape_t *)c;
    }else return NULL;
}
void sort(shape_t *shapes[], int count){
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if((shapes[j]->perimeter(shapes[j]) < shapes[j+1]->perimeter(shapes[j+1])) || 
            ((shapes[j]->perimeter(shapes[j]) == shapes[j+1]->perimeter(shapes[j+1])) && (shapes[j]->area(shapes[j]) < shapes[j+1]->area(shapes[j+1])))){
                shape_t *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
}
void printShape(shape_t *shapes[], int count){
    int perimeter = 0, area = 0;
    for (int i = 0; i < count; i++)
    {

        printf("%s %d %d\n", shapes[i]->name, shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
        perimeter += shapes[i]->perimeter(shapes[i]);
        area += shapes[i]->area(shapes[i]);
    }
    printf("%d %d\n", perimeter, area);
    
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
        if(shapes[i]){
            if(strcmp(type,"triangle") == 0){
                triangle_t *t = (triangle_t*)shapes[i];
                scanf("%d %d %d", &t->s1, &t->s2, &t->s3);
            }else if(strcmp(type, "square") == 0){
                square_t *s = (square_t *) shapes[i];
                scanf("%d", &s->side);
            }else if(strcmp(type, "rectangle") == 0){
                rectangle_t *r = (rectangle_t *) shapes[i];
                scanf("%d %d", &r->height, &r->width);
            }else if(strcmp(type, "circle") == 0){
                circle_t *c = (circle_t *) shapes[i];
                scanf("%d", &c->radius);
            }
        }
    }
    sort(shapes, count);
    printShape(shapes, count);
    
}
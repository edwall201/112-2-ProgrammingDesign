#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define shapeText(TYPE) char name[10];\
        int(*perimeter)(struct TYPE*);\
        int(*area)(struct TYPE*);
typedef struct shape_s{shapeText(shape_s);} shape_t;
typedef struct circle_s{
    shapeText(circle_s);
    int radius;
}circle_t;

typedef struct rectangle_s{
    shapeText(rectangle_s);
    int width, height;
}rectangle_t;

typedef struct square_s{
    shapeText(square_s);
    int side;
}square_t;

typedef struct triangle_s{
    shapeText(triangle_s);
    int s1, s2, s3;
}triangle_t;

int circle_perimeter(circle_t *t){return t->radius * 2 * 4 ;}
int circle_area(circle_t *t){return t->radius * t->radius * 4;}
int rectangle_perimeter(rectangle_t *r){return 2 * (r->height + r->width);}
int rectangle_area(rectangle_t *r){return r->height * r->width;}
int square_perimeter(square_t *s){return s->side * 4;}
int square_area(square_t *s){return s->side * s->side;}
int triangle_area(triangle_t *t){
    int s = (t->s1 + t->s2 + t->s3)/2;
    return sqrt(s*(s-t->s1)*(s-t->s2)*(s-t->s3));
}
int triangle_perimeter(triangle_t *t){return t->s1 + t->s2 + t->s3;}

shape_t *newShape(char *type){
    if(strcmp(type, "circle") == 0){
        circle_t *c = (circle_t *)malloc(sizeof(circle_t));
        strcpy(c->name, type);
        c->perimeter = circle_perimeter;
        c->area = circle_area;
        return(shape_t *)c;
    }else if(strcmp(type, "rectangle")== 0){
        rectangle_t *r = (rectangle_t *)malloc(sizeof(rectangle_t));
        strcpy(r->name, type);
        r->perimeter = rectangle_perimeter;
        r->area = rectangle_area;
        return (shape_t *)r;
    }else if(strcmp(type, "square")== 0){
        square_t *s = (square_t *)malloc(sizeof(square_t));
        strcpy(s->name, type);
        s->perimeter = square_perimeter;
        s->area = square_area;
        return (shape_t *)s;
    }else if(strcmp(type, "triangle")== 0){
        triangle_t *t = (triangle_t *)malloc(sizeof(triangle_t));
        strcpy(t->name, type);
        t->perimeter = triangle_perimeter;
        t->area = triangle_area;
        return (shape_t *)t;
    }else return NULL;
}

void printShapes(shape_t *shapes[], int num){
    int perimeter = 0, area = 0;
    for (int i = 0; i < num; i++)
    {
        printf("%s %d %d\n", shapes[i]->name, shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
        perimeter += shapes[i]->perimeter(shapes[i]);
        area += shapes[i]->area(shapes[i]);
    }
    printf("%d %d\n", perimeter, area);
}

void sort(shape_t *shapes[], int num){
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if(shapes[j]->perimeter(shapes[j]) < shapes[j+1]->perimeter(shapes[j+1]) ||
            ((shapes[j]->perimeter(shapes[j]) == shapes[j+1]->perimeter(shapes[j+1])) && (shapes[j]->area(shapes[j]) < shapes[j+1]->area(shapes[j+1])))){
                shape_t *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
    printShapes(shapes, num);
}



int main(){
    int num = 0;
    scanf("%d", &num);
    shape_t *shapes[num];
    for (int i = 0; i < num; i++)
    {
        char type[10];
        scanf("%s", type);
        shapes[i] = newShape(type);
        if(strcmp(type, "circle") == 0){
            circle_t *c = (circle_t * )(shapes[i]);
            scanf("%d", &c->radius);
        }else if(strcmp(type, "rectangle")== 0){
            rectangle_t *r = (rectangle_t *)(shapes[i]);
            scanf("%d %d", &r->width, &r->height);
        }else if(strcmp(type, "square")== 0){
            square_t *s = (square_t *)(shapes[i]);
            scanf("%d", &s->side);
        }else if(strcmp(type, "triangle")== 0){
            triangle_t *t = (triangle_t *)(shapes[i]);
            scanf("%d %d %d", &t->s1, &t->s2, &t->s3);
        }
    }
    sort(shapes, num);
    
    return 0;
}
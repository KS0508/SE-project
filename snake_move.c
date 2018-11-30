/*
Copyright (c) 2018 ShaoWenKai, Kevin Shao. All rights reserved.
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define WALL '#'
#define BLANK ' '
#define BLANK_HEIGHT 10
#define BLANK_WEIGHT 10
#define SNAKE_HEAD '@'
#define SNAKE_TAIL '%'
#define FOOD '$'
#define SNAKE_MAX_LENGTH 40
#define SNAKE_INITIAL_LENGTH 5
#define SNAKE_INITIAL_DIRECTION_X 1
#define SNAKE_INITIAL_DIRECTION_Y 0
#define SNAKE_MOVE_SPEED_X 1
#define SNAKE_MOVE_SPEED_Y 1
#define SNAKE_MOVE_UP_KEY 'W'
#define SNAKE_MOVE_DOWN_KEY 'S'
#define SNAKE_MOVE_LEFT_KEY 'A'
#define SNAKE_MOVE_RIGHT_KEY 'D'

/**********************************
clear_map: generate an empty map
init: initialize snake's direction, snake's length, food position and the map,
      and output the whole map with snake and food
input: get legal input
snake_move: set snake's position according to the input, and eat the food
body_build: generate new snake on the map according to the position
output: print the whole map with snake and food
game_over: print message and exit
**********************************/

void clear_map();
void init();
char input();
void snake_move(int, int);
void body_build();
void output();
void game_over();

/********************************************
map: stores the map consisting of characters
snake_position_x[0] and snake_position_y[0] are the coordinates of head of the snake
lasting: flag of whether game should continue
food_eaten: flag of whether food is eaten
********************************************/

char map[BLANK_HEIGHT + 2][BLANK_WEIGHT + 2];
int snake_position_x[SNAKE_MAX_LENGTH] = {5, 4, 3, 2, 1};
int snake_position_y[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snake_length, direction_x, direction_y;
int lasting;
char direction;

int main()
{
    /*初始化*/
    init();
    while (lasting)
    {
        /*获取输入的指令*/
        direction = input();
        /*根据输入的指令向函数传入对应的参数来进行移动*/
        switch (direction)
        {
            case SNAKE_MOVE_UP_KEY: 
                snake_move(0 * SNAKE_MOVE_SPEED_X, -1 * SNAKE_MOVE_SPEED_Y);
                break;
            case SNAKE_MOVE_DOWN_KEY:
                snake_move(0 * SNAKE_MOVE_SPEED_X, 1 * SNAKE_MOVE_SPEED_Y);
                break;
            case SNAKE_MOVE_LEFT_KEY:
                snake_move(-1 * SNAKE_MOVE_SPEED_X, 0 * SNAKE_MOVE_SPEED_Y);
                break;
            case SNAKE_MOVE_RIGHT_KEY:
                snake_move(1 * SNAKE_MOVE_SPEED_X, 0 * SNAKE_MOVE_SPEED_Y);
                break;
        }
        /*输出蛇移动后的整个画面*/
        output();
    }
    /*输出游戏结束信息*/
    game_over();
    return 0;
}

void clear()
{
    /*根据系统选择清屏方式*/
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

/*生成空地图*/
void clear_map()
{
    int x, y;
    for (x = 0; x < BLANK_WEIGHT + 2; ++x)
    {
        map[0][x] = WALL;
        map[BLANK_HEIGHT + 1][x] = WALL;
    }
    for (y = 0; y < BLANK_HEIGHT + 2; ++y)
    {
        map[y][0] = WALL;
        map[y][BLANK_WEIGHT + 1] = WALL;
    }
    for (y = 1; y <= BLANK_HEIGHT; ++y)
    {
        for (x = 1; x <= BLANK_WEIGHT; ++x)
        {
            map[y][x] = BLANK;
        }
    }
}

char input()
{
    char key, enter;
    while (1)
    {
        printf("Please enter %c, %c, %c, %c:\n", SNAKE_MOVE_UP_KEY, SNAKE_MOVE_DOWN_KEY, SNAKE_MOVE_LEFT_KEY, SNAKE_MOVE_RIGHT_KEY);
        scanf("%c", &key);
        /*输入为空则重新输入*/
        if (key == '\n')
            continue;
        scanf("%c", &enter);
        /*检测输入是否合法，同时对大小写不敏感*/
        if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))
        {
            key = toupper(key);
            if (key == SNAKE_MOVE_UP_KEY || key == SNAKE_MOVE_DOWN_KEY 
                || key == SNAKE_MOVE_LEFT_KEY || key == SNAKE_MOVE_RIGHT_KEY)
            {
                return key;
            }
            else
            {
                printf("Invaild input. Please input another letter.\n");
            }
        }
        else
        {
            printf("Invaild input. Please input another letter.\n");
        }
    }
    return 0;
}

/*输出整个地图*/
void output()
{
    int x, y;
    clear();
    for (y = 0; y < BLANK_HEIGHT + 2; ++y)
    {
        for (x = 0; x < BLANK_WEIGHT + 2; ++x)
        {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void body_build()
{
    int body;
    /*生成蛇头*/
    map[snake_position_y[0]][snake_position_x[0]] = SNAKE_HEAD;
    /*生成蛇身*/
    for (body = 1; body < snake_length; body++)
    {
        map[snake_position_y[body]][snake_position_x[body]] = SNAKE_TAIL;
    }
}

void game_over()
{
    clear();
    printf("Game Over!\n");
}

void init()
{
    srand((unsigned)time(NULL));
    clear();
    lasting = 1;
    snake_length = 5;
    direction_x = SNAKE_INITIAL_DIRECTION_X;
    direction_y = SNAKE_INITIAL_DIRECTION_Y;
    clear_map();
    body_build();
    output();
}

void snake_move(int delta_x, int delta_y)
{
    /*输入指令的移动方向和当前蛇头朝向相反则无改变*/
    if ((delta_x == -direction_x && delta_x != 0) || (delta_y == -direction_y && delta_y != 0))
    {
        clear_map();
        body_build();
        return;
    }
    else
    {
        direction_x = delta_x;
        direction_y = delta_y;
    }
    int body;
    /*移动蛇，计算身体部分的新坐标*/
    for (body = snake_length - 1; body > 0; body--)
    {
        snake_position_x[body] = snake_position_x[body - 1];
        snake_position_y[body] = snake_position_y[body - 1];
        
    }
    /*检测蛇头是否和墙或自身发生碰撞，若是则将游戏继续进行的标记置为0*/
    for (body = 1; body < snake_length; body++)
    {
        if ((snake_position_x[0] + delta_x == snake_position_x[body] && snake_position_y[0] + delta_y == snake_position_y[body])
            || (map[snake_position_x[0] + delta_x][snake_position_y[0] + delta_y] == WALL))
        {
            lasting = 0;
            return;
        }
    }
    /*移动蛇头*/
    snake_position_x[0] = snake_position_x[0] + delta_x;
    snake_position_y[0] = snake_position_y[0] + delta_y;
    /*生成新的地图画面并输出*/
    clear_map();
    body_build();
}
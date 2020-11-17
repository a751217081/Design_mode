#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"
/*设置一个通用的接口*/
struct season_method
{
    void (*get_season)(void);
};

void get_season(void *this)
{
    ((struct season_method *)(this))->get_season();
}

struct season_method *season_method_init()
{
    struct season_method *tmp = malloc(sizeof(struct season_method));
    return tmp;
}

void season_method_destroy(struct season_method *this)
{
    free(this);
    this = NULL;
}

void spring_get_season(void)
{
    printf("spring!!\r\n");
}

struct Spring
{
    struct season_method method;
};

struct Spring *init_spring(void)
{
    struct Spring *tmp_spring = malloc(sizeof(struct Spring));
    struct season_method *tmp_season;
    tmp_season = season_method_init();
    tmp_season->get_season = spring_get_season;
    memcpy(&(tmp_spring->method), tmp_season, sizeof(struct season_method));
    season_method_destroy(tmp_season);
    return tmp_spring;
}

void summer_get_season(void)
{
    printf("summer!!\r\n");
}

struct Summer
{
    struct season_method method;
};

struct Summer *init_Summer(void)
{
    struct Summer *tmp_Summer = malloc(sizeof(struct Summer));
    struct season_method *tmp_season;
    tmp_season = season_method_init();
    tmp_season->get_season = summer_get_season;
    memcpy(&(tmp_Summer->method), tmp_season, sizeof(struct season_method));
    season_method_destroy(tmp_season);
    return tmp_Summer;
}

struct Autumn
{
    struct season_method method;
};

struct Winter
{
    struct season_method method;
};

void *init_season_factory(int season)
{
    switch (season)
    {
    case 1 /* constant-expression */:
        /* code */
        return init_spring();
    case 2 /* constant-expression */:
        /* code */
        return init_Summer();
    case 3 /* constant-expression */:
        /* code */
        break;
    case 4 /* constant-expression */:
        /* code */
        break;
    default:
        break;
    }
}

int main(void)
{
    void *tmp;
    tmp = init_season_factory(1);
    get_season(tmp);
    free(tmp);
    tmp = init_season_factory(2);
    get_season(tmp);
    free(tmp);
    return 0;
}
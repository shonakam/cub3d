#include "../includes/cub3d.h"

size_t map_width(char **txt)
{
    size_t i;
    size_t j;
    size_t start;
    size_t end;

    i = 0;
    start = 0;
    end = 0;
    while (txt[i])
    {
        j = 0;
        while (txt[i][j] == ' ')
            j++;
        if (txt[i][j] == '1')
        {
            if (start >= j)
                start = j;
            while (txt[i][j])
            {
                if (txt[i][j] == '1' && end <= j)
                    end = j;
                j++;
            }
        }
        i++;
    }
    if (end - start > MAP_MAX_WIDTH)
        return (0);
    return (end - start);
}

size_t map_height(char **txt)
{
    size_t i;
    size_t j;
    size_t start;
    size_t end;

    i = 0;
    start = 0;
    end = 0;
    while (txt[i])
    {
        j = 0;
        while (txt[i][j] == ' ')
            j++;
        if (txt[i][j] == '1')
        {
            if (start >= i)
                start = i;
            while (txt[i][j])
            {
                if (txt[i][j] == '1' && end <= i)
                    end = i;
                j++;
            }
        }
        i++;
    }
    if (end - start > MAP_MAX_HEIGHT)
        return (0);
    return (end - start);
}
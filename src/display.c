/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:53:47 by mhuszar           #+#    #+#             */
/*   Updated: 2024/06/15 13:44:35 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "alcu.h"
#include <unistd.h>
#include <stdlib.h>

bool update_board(t_board *board, int rm)
{
    size_t  counter;

    counter = 0;
    while (counter < board->size)
    {
        if (counter == board->size - 1
            || (board->size > (counter + 1) && !board->heaps[counter + 1]))
        {
            if (rm <= board->heaps[counter])
            {
                board->heaps[counter] -= rm;
				if (board->heaps[counter] == 0)
					board->size--;
                return (true);
            }
            else
                return (false);
        }
        counter++;
    }
    return (false);
}

void recalc_max_width(t_board *board)
{
    int     cur_max;
    size_t  counter;

    cur_max = 0;
    counter = 0;
    while (counter < board->size)
    {
        if (board->heaps[counter] > cur_max)
            cur_max = board->heaps[counter];
        counter++;
    }
    if (cur_max < board->max_width)
        board->max_width = cur_max;
}

void display_board(t_board *board)
{
    size_t  line;
    int     sticks;

    line = sticks = 0;
    while (line < board->size)
    {
        while (sticks < board->heaps[line])
        {
            write(1, "|", 1);
            sticks++;
        }
        sticks = 0;
        write(1, "\n", 1);
        if (!board->heaps[line])
            return ;
        line++;
    }
}
/*
int main(void)
{
    t_board board;

    board.heaps = malloc(sizeof(int) * 4);
    board.heaps[0] = 10;
    board.heaps[1] = 4;
    board.heaps[2] = 1;
    board.heaps[3] = 4;
    board.max_width = 10;
    board.size = 4;
    board.capacity = 0;
    display_board(&board);
    write(1, "\n", 1);
    update_board(&board, 3);
    display_board(&board);
}*/

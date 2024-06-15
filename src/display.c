/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:53:47 by mhuszar           #+#    #+#             */
/*   Updated: 2024/06/15 12:29:12 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "alcu.h"

bool update_board(t_board *board, int rm)
{
    int counter;

    counter = 0;
    while (counter < board->size)
    {
        if (counter = board->size - 1
            || (board->size > (counter + 1) && !board->heaps[counter + 1]))
        {
            if (rm <= board->heaps[counter])
            {
                board->heaps[counter] -= rm;
                return (true);
            }
            else
                return (false);
        }
        counter++;
    }
    return (false);
}


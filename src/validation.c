/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuszar <mhuszar@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:37:56 by mhuszar           #+#    #+#             */
/*   Updated: 2024/06/15 14:45:46 by mhuszar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "utils/utils.h"

bool    valid_input(char *input, int *og)
{
    int num;
    int counter;

    if (!input)
        return (false);
    counter = 0;
    while (input[counter] && input[counter] != '\n')
    {
        if (!ft_isdigit(input[counter]))
            return (false);
        counter++;
    }
    num = ft_atoi(input);
    if (num < 1 || num > 3)
        return (false);
    *og = num;
    return (true);
}
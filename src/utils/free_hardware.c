/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-pavel.de-wavrechin
** File description:
** free_hardware
*/

#include <stdlib.h>
#include "hardware.h"

void free_hardware(void *data)
{
    hardware_t *hardware = ((hardware_t *)(data));

    free(((hardware_t *)(data))->name);
    free(((hardware_t *)(data))->name);
    free(((hardware_t *)(data)));
}

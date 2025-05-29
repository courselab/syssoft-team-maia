/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 Lincoln <lincolncpp@gmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  Lincoln <lincolncpp@gmail.com>
 */

#include <stdio.h>

static void u16_to_str(unsigned short v, char *buf)
{
  char tmp[6];
  int i = 0;

  if (v == 0) {
    buf[0] = '0';
    buf[1] = '\0';
    return;
  }

  while (v > 0 && i < 5) {
    tmp[i++] = '0' + (v % 10);
    v /= 10;
  }

  for (int j = 0; j < i; ++j)
    buf[j] = tmp[i - j - 1];

  buf[i] = '\0';
}

int main(void)
{

  unsigned short mem = get_memsize();
  char buf[6];
  u16_to_str(mem, buf);
  printf("Memory KB: ");
  printf(buf);
  return 0;
}






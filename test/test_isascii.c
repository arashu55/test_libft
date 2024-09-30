/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashu <ashu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:04:58 by ashu              #+#    #+#             */
/*   Updated: 2024/09/13 07:02:02 by ashu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define SHADOW "\x1B[2m"
#define CYAN "\x1B[36m"
#define YEALLOW "\x1B[33m"
#define RESET "\x1B[0m"


void test_function_name()
{
   printf("《ft_isascii.c》");
   printf("\n");
}

void test_isascii()
{
   // int tests[];
   // int i;
   // int num;
   // tests = {-10, -1, 0, ' ', '@', 'A', 'M', 'Z', '[', '`', 'a', 'm', 'z', '{', '}', 127, 128, 150}
   // i = 0;
   int tests[] = {
    // ASCII範囲内の代表的な値
    0,    // NULL文字
    32,   // スペース
    65,   // 'A'
    97,   // 'a'
    127,  // DEL (削除) 制御文字

    // 境界値とそのすぐ外の値
    128,    // ASCII範囲外の最小値
    129,    // ASCII範囲外
    255,    // 最大の8ビット値 (非ASCII)
    256,    // 8ビットを超える値 (非ASCII)

    // 特殊な大きな数値
    1000,        // 10ビットを超える値
    32767,       // 16ビットの最大値 (非ASCII)
    32768,       // 16ビットを超える最小値 (非ASCII)
    65535,       // 最大の16ビット値 (非ASCII)
    65536,       // 16ビットを超える値 (非ASCII)
    100000,      // 非常に大きな値
    2147483647,  // 32ビット符号付き整数の最大値
    2147483648u, // 32ビット符号付き整数の最大値 + 1 (非ASCII)
    4294967295u, // 32ビット符号なし整数の最大値
    // 18446744073709551615u, // 64ビット符号なし整数の最大値
    // 18446744073709551616u, // 64ビット符号なし整数の最大値 + 1

    // 負の値（ASCIIには含まれない）
    -1,      // 最小の負の値
    -128,    // 8ビット符号付き整数の最小値
    -32768,  // 16ビット符号付き整数の最小値
    -65536,  // 16ビットを超える負の値
    -2147483648, // 32ビット符号付き整数の最小値
    // -10000000000000000000, // 大きな64ビット負の値
    // -9223372036854775808,  // 64ビット符号付き整数の最小値

    // 16進数表現
    0xFF,          // 255 (非ASCII)
    0xFFFF,        // 65535 (非ASCII)
    0xFFFFFF,      // 16777215 (非ASCII)
    0xFFFFFFFF,    // 4294967295 (非ASCII)
    0x80000000,    // -2147483648 (非ASCII)

    // NULL文字や制御文字も含めておく
    '\0',    // NULL文字
    '\n',    // 改行
    '\t',    // タブ
    '\r',    // キャリッジリターン
    };

   int num;
   int i = 0;
   num = sizeof(tests) / sizeof(tests[0]);

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_isascii(tests[i]);
      honke = isascii(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(GREEN "OK " RESET);
      }
      else
      {
         printf(RED "FAILED " RESET);
      }
      i++;
   }
   printf("\n");

   i = 0;

   while (i != num)
   {
      int ft;
      int honke;  
      ft = ft_isascii(tests[i]);
      honke = isascii(tests[i]);

      printf("【test%d】", i);
      if (ft == honke)
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(CYAN "%d" RESET,honke);
      }
      else
      {
         printf(SHADOW "libft is " RESET);
         printf(CYAN "%d" RESET,ft);
         printf(SHADOW "linux is " RESET);
         printf(YEALLOW "%d" RESET,honke);
      }
      i++;
   }
   printf("\n");
   printf("\n");
}

int main() 
{
   test_function_name();
   test_isascii();
   return 0;
}

